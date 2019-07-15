modded class DayZGame
{
	void DayZGame()
	{
		// register custom input from script (for debug + development)
		UAInput input1 = GetUApi().RegisterInput("UAScriptedInput1","Scripted_Input_1","core");
		UAInput input2 = GetUApi().RegisterInput("UAScriptedInput2","Scripted_Input_2","core");

		// bind UAScriptedInput1 to key 'I'
		input1.BindCombo("kI");

		// bind UAScriptedInput2 to key 'Ctrl + P'
		input2.BindCombo("kLControl");
		input2.BindCombo("kP");		
	}

	void ~DayZGame()
	{
		// release stuff
	}

	// overridden functions from DayZGame here
};


