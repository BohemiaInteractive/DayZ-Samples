modded class CarScript
{
	float m_Input_ForwardReverse;
	float m_Input_LeftRight;

	private float m_RPM;
	private bool m_RPMGoingUp;
	private bool m_RPMReachedForUpShift;
	private bool m_RPMReachedForDownShift;

	private int m_GearCurrent;

	private float m_SteeringWanted;
	private float m_ThrottleWanted;
	private int m_GearWanted;
	private float m_BrakeWanted;
	private float m_HandbrakeWanted;

	void Control(float dt)
	{
		m_Input_LeftRight += Math.RandomFloatInclusive(-1.0, 1.0) * 0.4;
		m_Input_LeftRight = Math.Clamp(m_Input_LeftRight, -1, 1);
		
		m_Input_ForwardReverse += Math.RandomFloatInclusive(-1.0, 1.0) * 0.4;
		m_Input_ForwardReverse = Math.Clamp(m_Input_ForwardReverse, -5, 5);
	}

	void Engine(float dt)
	{
		float currentRPM = EngineGetRPM();
		if (currentRPM < EngineGetRPMIdle())
		{
			if (currentRPM < 1.0 && EngineIsOn())
			{
				//! Engine could potentially stall, prevent it like-so
				EngineStop();
			}
			else if (!EngineIsOn())
			{
				//! Start the engine
				EngineStart();
			}
			
			return;
		}
		
		float upShiftRPM = Math.Lerp(EngineGetRPMMin(), EngineGetRPMRedline(), 0.5);
		float downShiftRPM = Math.Lerp(EngineGetRPMMin(), EngineGetRPMRedline(), 0.2);
		
		m_RPMGoingUp = currentRPM > m_RPM;
		m_RPMReachedForUpShift = currentRPM > upShiftRPM && m_RPMGoingUp;
		m_RPMReachedForDownShift = currentRPM < downShiftRPM && !m_RPMGoingUp;
		m_RPM = currentRPM;
	}

	void Steering(float dt)
	{
		m_SteeringWanted = -m_Input_LeftRight;
	}

	void Throttle(float dt)
	{
		//! Use the pitch to increase the throttle if the car is going up a hill
		float hillFactor = GetOrientation()[1] / 10.0;
		hillFactor += 1.0;
		hillFactor = Math.Clamp(hillFactor, 0.5, 5.0);
		
		//! Prevent the throttle from redlining the engine
		m_ThrottleWanted = (EngineGetRPMMin() - EngineGetRPM()) / (EngineGetRPMMin() - EngineGetRPMRedline());
		m_ThrottleWanted = 1.0 - m_ThrottleWanted;
		m_ThrottleWanted *= Math.AbsFloat(m_Input_ForwardReverse);
		m_ThrottleWanted *= hillFactor;
		m_ThrottleWanted = Math.Clamp(m_ThrottleWanted, 0.0, 1.0); 
	}

	void Brake(float dt)
	{
		float minOverSpeed = 2.0;
		float minInputDiff = 0.1;
		if ((m_Input_ForwardReverse < -minInputDiff && GetSpeedometer() > minOverSpeed) || (m_Input_ForwardReverse > minInputDiff && GetSpeedometer() < -minOverSpeed))
		{
			m_BrakeWanted = 1.0;
		}
		else
		{
			m_BrakeWanted = 0.0;
		}

		m_HandbrakeWanted = 0.0;
		if (m_Input_ForwardReverse == 0.0)
		{
			m_HandbrakeWanted = 1.0;
		}
	}

	/**
	 * This works because automatic and manual gears correspond for REVERSE, NEUTRAL and DRIVE
	 */
	void Gearbox(float dt)
	{
		int maxGears = GetGearsCount();

		m_GearCurrent = GetGear();
		if (GearboxGetType() == CarGearboxType.AUTOMATIC)
		{
			m_GearCurrent = GearboxGetMode();
		}
		
		m_GearWanted = m_GearCurrent;

		if (m_Input_ForwardReverse == 0.0)
		{
			m_ThrottleWanted = 0.0;
			m_GearWanted = CarGear.NEUTRAL;
		}
		else if (m_Input_ForwardReverse > 0.0 && m_GearWanted <= CarGear.NEUTRAL)
		{
			m_GearWanted = CarGear.FIRST;
		}
		else if (m_Input_ForwardReverse < 0.0 && m_GearWanted >= CarGear.NEUTRAL)
		{
			m_GearWanted = CarGear.REVERSE;
		}
		else if (GearboxGetType() == CarGearboxType.MANUAL)
		{
			if (m_RPMReachedForUpShift)
			{
				if (GetGear() > CarGear.NEUTRAL)
				{
					m_GearWanted++;
				}
				else if (GetGear() < CarGear.NEUTRAL)
				{
					m_GearWanted--;
				}
			}
			else if (m_RPMReachedForDownShift)
			{
				if (GetGear() > CarGear.NEUTRAL + 1)
				{
					m_GearWanted--;
				}
				else if (GetGear() < CarGear.NEUTRAL - 1)
				{
					m_GearWanted++;
				}
			}
		}

		//! Clamp to only previous and next gear of the car
		if (m_GearWanted < m_GearCurrent)
		{
			m_GearWanted = m_GearCurrent - 1;
		}
		else if (m_GearWanted > m_GearCurrent)
		{
			m_GearWanted = m_GearCurrent + 1;
		}

		//! Make sure the wanted gear is within the appropriate bounds
		if (m_GearWanted < 0)
		{
			m_GearWanted = 0;
		}
		else if (m_GearWanted >= maxGears)
		{
			m_GearWanted = maxGears - 1;
		}
	}

	void FinalizeInputs(float dt)
	{
		if (m_GearWanted != m_GearCurrent)
		{
			int gear = 0;

			//! Automatic gearbox switching 
			if (m_GearWanted > m_GearCurrent)
			{
				for (gear = m_GearCurrent; gear < m_GearWanted; gear++)
				{
					ShiftUp();
				}
			}

			if (m_GearWanted < m_GearCurrent)
			{
				for (gear = m_GearCurrent; gear >= m_GearWanted; gear--)
				{
					ShiftDown();
				}
			}

			//! Manual gearbox switching override
			ShiftTo(m_GearWanted);

			//! Event setter for when the clutch is meant to be disengaged, for purposes of this sample, we can assume it is always fired
			SetClutchState(false);
		}

		//! Disable handbrake and brakes from engaging automatically, overriding SetBrake/SetHandbrake
		SetBrakesActivateWithoutDriver(false);
		
		SetBrake(m_BrakeWanted, 0, false);
		SetHandbrake(m_HandbrakeWanted);
		SetSteering(m_SteeringWanted, false);
		SetThrust(m_ThrottleWanted, 0.0, 0.0);
	}
 
	override void OnInput(float dt)
	{
		if (!GetGame().IsServer() || CrewMember(DayZPlayerConstants.VEHICLESEAT_DRIVER))
		{
			return;
		}

		Control(dt);

		Engine(dt);
		Steering(dt);
		Throttle(dt);
		Brake(dt);
		Gearbox(dt);

		FinalizeInputs(dt);
		
		dBodyActive(this, ActiveState.ACTIVE);
	}
};
