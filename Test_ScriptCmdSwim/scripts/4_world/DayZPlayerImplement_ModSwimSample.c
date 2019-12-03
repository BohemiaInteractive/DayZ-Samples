

// *************************************************************************************
// ! Animation Graph Constants Table
// *************************************************************************************
class HumanCommandScript_SwimSampleST
{
	void HumanCommandScript_SwimSampleST(Human pHuman)
	{
		HumanAnimInterface 	hai = pHuman.GetAnimInterface();

		m_CmdStartSwimming 	= hai.BindCommand("CMD_Swim");		
		m_VarSpeed			= hai.BindVariableFloat("MovementSpeed");
		m_VarDirection		= hai.BindVariableFloat("MovementDirection");
		m_TagIsSwimming 	= hai.BindTag("TagSwimming");
	}	


	
	// TAnimGraphCommand 		m_CmdStartSwimming;		//! command to start swimming
	// TAnimGraphVariable 		m_VarSpeed;				//! float variable - 0,1,2,3 speed
	// TAnimGraphVariable 		m_VarDirection;			//! float variable - angle 
	// TAnimGraphTag			m_TagIsSwimming;		//! 
	int 					m_CmdStartSwimming;		//! command to start swimming
	int 					m_VarSpeed;				//! float variable - 0,1,2,3 speed
	int 					m_VarDirection;			//! float variable - angle 
	int 					m_TagIsSwimming;		//! 
}


// *************************************************************************************
// ! Fully Working Swimming implemented by Human Command Script
// *************************************************************************************
class HumanCommandScript_SwimSample : HumanCommandScript
{

	//! constructor
	void 	HumanCommandScript_SwimSample (DayZPlayer pPlayer, HumanCommandScript_SwimSampleST pTable)
	{
		m_pPlayer 	= pPlayer;
		m_Table 	= pTable;
		m_Input		= pPlayer.GetInputController();
		m_pSettings	= pPlayer.GetDayZPlayerType().CommandSwimSettingsW();
	}

	//!
	void 	StartSwimming()
	{
		PreAnim_CallCommand(m_Table.m_CmdStartSwimming, 1, 1);
	}

	void 	EndSwimming()
	{
		PreAnim_CallCommand(m_Table.m_CmdStartSwimming, 0, 0);
	}
	

	//	
	void 	UpdateWaterDepth()
	{
		vector 	pp = m_pPlayer.GetPosition();
		vector  wl = HumanCommandSwim.WaterLevelCheck(m_pPlayer, pp);

		m_fWaterLevelDepth = wl[0];		// whats water depth at player's position
		m_fCharacterDepth = wl[1];		// whats character depth  at player's position
	}


	//! 
	override void 	OnActivate()
	{
		StartSwimming();
		dBodyEnableGravity(m_pPlayer, false);
	}

	override void 	OnDeactivate()
	{
		Print("HumanCommandScript_SwimSample::OnDeactivate");
		dBodyEnableGravity(m_pPlayer, true);
	}

	// called to set values to animation graph processing 
	override void 	PreAnimUpdate(float pDt)
	{
	    if (m_bNeedFinish)
		{
			EndSwimming();
			return;
		}
		
		// Print("HumanCommandScript_SwimSample::PreAnimUpdate: " + pDt.ToString());

		vector 	localDir;
		float 	speed;
		float 	heading;

		// get int movement 
		m_Input.GetMovement(speed, localDir);
		heading = m_Input.GetHeadingAngle();

		//! if movement moves front - remap 0,1,2,3 to 0,2,3 (in animation graph)
		float 	animSpeed = 0;

		if (speed > 0)
		{
			if (localDir[2] > 0.3)
			{
				if (speed > 2.0)
				{
					animSpeed = 3.0;
				}
				else
				{
					animSpeed = 2.0;
				}
			}
		}

		//! handle animation swimming speed 
		PreAnim_SetFloat(m_Table.m_VarSpeed, animSpeed);		// sets motion variable speed 

		//! rotate character (directly by heading angle - with filtering)
		if (animSpeed <= 0)
		{
			// idle
			PreAnim_SetFilteredHeading(heading, m_pSettings.m_fAlignIdleTimeout, m_pSettings.m_fAlignIdleMaxChanged);
		}
		else if (animSpeed <= 2)
		{	
			// normal speed
			PreAnim_SetFilteredHeading(heading, m_pSettings.m_fAlignSlowTimeout, m_pSettings.m_fAlignSlowMaxChanged);
		}
		else
		{
			// sprint
			PreAnim_SetFilteredHeading(heading, m_pSettings.m_fAlignFastTimeout, m_pSettings.m_fAlignFastMaxChanged);
		}
	
		//! udpate time
		m_fTime += pDt;


	    /* if (m_fTime >= 1.0 && m_Input.IsJumpClimb())
		{
			Print("Finished " + m_fTime.ToString());
			
			EndSwimming();
			SetFlagFinished(true);
			return;
		} */
	}


	//! called to change local translations / rotations
	//! called to get events / tags from animation graph processing 
	override void 	PrePhysUpdate(float pDt)
	{
		Print("HumanCommandScript_SwimSample::PrePhysUpdate: " + pDt.ToString());


		UpdateWaterDepth()
		// Print("Char Depth: " + m_fCharacterDepth.ToString());

		//! move from m_fCharacterDepth to m_pSettings->m_fWaterLevelSwim
		float filtCharDepth = Math.SmoothCD(m_fCharacterDepth, m_pSettings.m_fWaterLevelSwim, m_fWaterAlignV, 0.3, 1.0, pDt);		
		// Print("Filt Depth: " + filtCharDepth.ToString());

		//! get filtered part 
		float delta 		= m_fCharacterDepth - filtCharDepth;
		// Print("Filt Delta: " + delta);
		
		//! set filtered part as movement 
		vector trans		= vector.Zero;

		//! get local translations 
		PrePhys_GetTranslation(trans);		// in case this returns false ... trans is still zero 

		// waves 
		delta += Math.Sin(m_fTime * 3) * 0.003;
		
		//! height correction 
		trans[1] = trans[1] + delta;

		//! XZ side translation 
		vector 	locDir;
		float 	speed;
		float 	swimSpeedX = 0, swimSpeedZ = 0;

		// get int movement 
		m_Input.GetMovement(speed, locDir);

		if (speed > 0)
		{
			if (locDir[2] < 0)	// backwards ? 
			{
				swimSpeedZ = locDir[2] * m_pSettings.m_fMovementSpeed;
			}

			swimSpeedX = locDir[0] * m_pSettings.m_fMovementSpeed;
		} 



		// filter velocities			
		m_fSpeedX = Math.SmoothCD(m_fSpeedX, swimSpeedX, m_fSpeedXV, m_pSettings.m_fMovementSpeedFltTime, m_pSettings.m_fMovementSpeedFltMaxChange, pDt);		
		m_fSpeedZ = Math.SmoothCD(m_fSpeedZ, swimSpeedZ, m_fSpeedZV, m_pSettings.m_fMovementSpeedFltTime, m_pSettings.m_fMovementSpeedFltMaxChange, pDt);		

		// add velocity
		trans[0] = trans[0] + m_fSpeedX * pDt;
		trans[2] = trans[2] + m_fSpeedZ * pDt;

		//!
		PrePhys_SetTranslation(trans);
	}

	//! called when all animation / pre phys update is handled
	override bool	PostPhysUpdate(float pDt)
	{
		Print("HumanCommandScript_SwimSample::PostPhysUpdate: " + pDt.ToString());

		//!
		if (m_bNeedFinish)
		{
			return false;
		}

		//! finish if water level is smaller than some value (around 1m of depth)
		if (m_fWaterLevelDepth < m_pSettings.m_fWaterLevelOut)
		{
			m_bNeedFinish = true;	// let it run 1 frame more
		}

		return true;	// handled with SetFlagFinished();
	}


	DayZPlayer 							m_pPlayer;
	HumanCommandScript_SwimSampleST 	m_Table;
	HumanInputController 				m_Input;
	float 								m_fTime;
	SHumanCommandSwimSettings			m_pSettings;			//! swim settings
	bool								m_bNeedFinish;

	float 								m_fWaterLevelDepth;		//! water depth
	float 								m_fCharacterDepth;		//! char's depth
	float 								m_fWaterAlignV[1];		//! filter value 

	float 								m_fSpeedX;				//! x speed
	float 								m_fSpeedZ;				//! x speed
	float 								m_fSpeedXV[1];			//! filter value 
	float 								m_fSpeedZV[1];			//! filter value 
}

// *************************************************************************************
// ! Fully Working Flying implemented by Human Command Script
// *************************************************************************************
class HumanCommandScript_FlySample : HumanCommandScript
{

	//! constructor
	void 	HumanCommandScript_FlySample(DayZPlayer pPlayer, HumanCommandScript_SwimSampleST pTable)
	{
		m_pPlayer 	= pPlayer;
		m_Table 	= pTable;
		m_Input		= pPlayer.GetInputController();
		m_pSettings	= pPlayer.GetDayZPlayerType().CommandSwimSettingsW();
	}

	//! 
	override void 	OnActivate()
	{
		dBodyEnableGravity(m_pPlayer, false);
	}

	override void 	OnDeactivate()
	{
		Print("HumanCommandScript_SwimSample::OnDeactivate");
		dBodyEnableGravity(m_pPlayer, true);
	}

	// called to set values to animation graph processing 
	override void 	PreAnimUpdate(float pDt)
	{
	}


	//! called to change local translations / rotations
	//! called to get events / tags from animation graph processing 
	override void 	PrePhysUpdate(float pDt)
	{
		Print("HumanCommandScript_SwimSample::PrePhysUpdate: " + pDt.ToString());
		
		vector trans = vector.Zero;

		//! get local translations 
		PrePhys_GetTranslation(trans);		// in case this returns false ... trans is still zero 
		
		trans	= vector.Zero;

		//! XZ side translation 
		vector 	locDir;
		float 	speed;
		float 	swimSpeedX = 0, swimSpeedZ = 0, swimSpeedY = 0;

		// get int movement 
		m_Input.GetMovement(speed, locDir);

		if (speed > 0)
		{
			swimSpeedZ = locDir[2] * m_pSettings.m_fMovementSpeed;
			swimSpeedX = locDir[0] * m_pSettings.m_fMovementSpeed;
		} 

		if (m_Input.IsJumpClimb())
		{
			swimSpeedY = 1;
		}
		else
		{
			// m_bNeedFinish = true;
		}


		// filter velocities			
		m_fSpeedX = Math.SmoothCD(m_fSpeedX, swimSpeedX, m_fSpeedXV, m_pSettings.m_fMovementSpeedFltTime, m_pSettings.m_fMovementSpeedFltMaxChange, pDt);		
		m_fSpeedY = Math.SmoothCD(m_fSpeedY, swimSpeedY, m_fSpeedYV, m_pSettings.m_fMovementSpeedFltTime, m_pSettings.m_fMovementSpeedFltMaxChange, pDt);		
		m_fSpeedZ = Math.SmoothCD(m_fSpeedZ, swimSpeedZ, m_fSpeedZV, m_pSettings.m_fMovementSpeedFltTime, m_pSettings.m_fMovementSpeedFltMaxChange, pDt);		

		// add velocity
		trans[0] = trans[0] + m_fSpeedX * pDt;
		trans[1] = trans[1] + m_fSpeedY * pDt;
		trans[2] = trans[2] + m_fSpeedZ * pDt;

		//!
		PrePhys_SetTranslation(trans);
	}

	//! called when all animation / pre phys update is handled
	override bool	PostPhysUpdate(float pDt)
	{
		Print("HumanCommandScript_SwimSample::PostPhysUpdate: " + pDt.ToString());

		//!
		if (m_bNeedFinish)
		{
			return false;
		}

		return true;	// handled with SetFlagFinished();
	}


	DayZPlayer 							m_pPlayer;
	HumanCommandScript_SwimSampleST 	m_Table;
	HumanInputController 				m_Input;
	float 								m_fTime;
	SHumanCommandSwimSettings			m_pSettings;			//! swim settings
	bool								m_bNeedFinish;

	float 								m_fSpeedX;				//! x speed
	float 								m_fSpeedY;				//! x speed
	float 								m_fSpeedZ;				//! x speed
	float 								m_fSpeedXV[1];			//! filter value 
	float 								m_fSpeedYV[1];			//! filter value 
	float 								m_fSpeedZV[1];			//! filter value 
}



// *************************************************************************************
// ! DayZPlayerImplementScriptCommand - this is called by Player's Command Handler
// ! purpose: to start scripted swimming command 
// *************************************************************************************
modded class DayZPlayerImplement
{
	ref HumanCommandScript_SwimSampleST	m_SwimSampleST;
	SHumanCommandSwimSettings			m_pSettings;			//! swim settings

	void DayZPlayerImplement()
	{
		Print("DayZPlayerImplement - NEW SWIM INITIALIZED");		
		m_pSettings	= GetDayZPlayerType().CommandSwimSettingsW();
	}
	
	//!
	void 	InitTables()
	{
		if (m_SwimSampleST == null)
		{
			Print("DayZPlayerImplement - NEW SWIM INIT TABLES");		
			m_SwimSampleST = new HumanCommandScript_SwimSampleST(this);
		}
	}

	//! override 
	override bool ModCommandHandlerInside (float pDt, int pCurrentCommandID, bool pCurrentCommandFinished)
	{
		//! MUST BE HERE TO NOT DISABLE OTHER MODS
		if (super.ModCommandHandlerInside(pDt, pCurrentCommandID, pCurrentCommandFinished)
		{
			return true;
		}

		//! 
		if (pCurrentCommandID == DayZPlayerConstants.COMMANDID_SCRIPT)
		{
			HumanCommandScript hcs = GetCommand_Script();	
		
			if (HumanCommandScript_SwimSample.Cast(hcs) != null)
			{
				// we are running  HumanCommandScript_SwimSample
				// Print ("HumanCommandScript_SwimSample Cast Working");

				return true;		// is handled 
			}

		
			if (HumanCommandScript_FlySample.Cast(hcs) != null)
			{
				// we are running  HumanCommandScript_SwimSample
				// Print ("HumanCommandScript_SwimSample Cast Working");

				return true;		// is handled 
			}

	

			return false;			// not handled
	
		}

		// check water levels
		{
			vector 	pp = GetPosition();
			vector  wl = HumanCommandSwim.WaterLevelCheck(this, pp);
			
			//! if total water depth >= 1.5m && character is 1.5m in water 
			if (wl[0] >= m_pSettings.m_fWaterLevelIn && wl[1] >= m_pSettings.m_fWaterLevelIn)
			{
				Print("DayZPlayerImplement - NEW SWIM - start swimming");		

				//! init tables - done just once
				InitTables();

				//! allocate / new swim sample
            	HumanCommandScript_SwimSample cmdSSS = new HumanCommandScript_SwimSample(this, m_SwimSampleST);
			
				// start it now
				StartCommand_Script(cmdSSS);

				return true;
			}
		}

		/*  fly sample on jump - not working 

		if(pHic.IsJumpClimb())
		{
			//! init tables - done just once
			InitTables();

			//! allocate / new swim sample
            HumanCommandScript_FlySample cmdFS = new HumanCommandScript_FlySample(this, m_SwimSampleST);

			// start it now
			StartCommand_Script(cmdFS);
	
			return true;
		}  */

		return false;	// not handled
	}
}