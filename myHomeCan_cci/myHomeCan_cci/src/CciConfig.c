/*
 * CciConfig.c
 *
 * Created: 14.03.2017 19:26:30
 *  Author: Mark Roters
 */ 

#include "CciConfig.h"
#include <avr/io.h>

void GetNodeId(void)
{
	#define NODE_ID_BITS 0b11111000
	
	CCiConfig_t.NodeId_u8 = ~(PINA & NODE_ID_BITS);
	CCiConfig_t.NodeId_u8 = CCiConfig_t.NodeId_u8 >> 3;
			
}
	
void GetFctId(void)
{
	#define FCT_ID_BITS 0b00000111
	
	switch (PINA & FCT_ID_BITS)
	{
		case SensorUnit:
		CCiConfig_t.FctId = SensorUnit;
		break;
		
		case PowerUnit:
		CCiConfig_t.FctId = PowerUnit;
		break;
		
		case InterfaceUnit:
		CCiConfig_t.FctId = InterfaceUnit;
		break;
		
		default:
		CCiConfig_t.FctId = NotConfigured;
	}	
}