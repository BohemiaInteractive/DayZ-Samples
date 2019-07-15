
modded class DayZPlayerImplement
{

	//! DayZPlayer Command handler override
	override void CommandHandler(float pDt, int pCurrentCommandID, bool pCurrentCommandFinished)
	{
		// call parent
		super.CommandHandler(pDt,pCurrentCommandID,pCurrentCommandFinished);

		// test our input :: Local Values - not transfered to server !!!
		//
		UAInput localInput = GetUApi().GetInputByName("UAPerformNewAction");
		
		// analog value (depends on controls type)
//		Print( "UAPerformNewAction - Value is:" + localInput.LocalValue() );
		
		// events (can be limited by configuration)
		if( localInput.LocalPress() )
			Print( "PRESS :: UAPerformNewAction" );
		if( localInput.LocalRelease() )
			Print( "RELEASE :: UAPerformNewAction" );
		if( localInput.LocalClick() )
			Print( "CLICK :: UAPerformNewAction" );
		if( localInput.LocalDoubleClick() )
			Print( "DOUBLE CLICK :: UAPerformNewAction" );
		if( localInput.LocalHold() )
			Print( "HOLD :: UAPerformNewAction" );
			
		// test scripted input 1
		//
		UAInput scriptedInput1 = GetUApi().GetInputByName("UAScriptedInput1");
		if( scriptedInput1.LocalValue() != 0 )
			Print( "UAScriptedInput1 :: " + scriptedInput1.LocalValue() )
		
		// test scripted input 2
		//
		UAInput scriptedInput2 = GetUApi().GetInputByName("UAScriptedInput2");
		if( scriptedInput2.LocalValue() != 0 )
			Print( "UAScriptedInput2 :: " + scriptedInput2.LocalValue() )
		
	}
	
}