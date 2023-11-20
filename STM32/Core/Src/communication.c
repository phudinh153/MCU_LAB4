/*
 * UARTCommunication.c
 *
 *  Created on: Nov 15, 2023
 *      Author: user
 */


#include "communication.h"

void uart_communication_fsm(void){
	switch(COMState){
	case COM_INIT:
		setCOMTimer(TICK);
		COMState = COM_RUN;
		break;
	case COM_WAIT:
		if (printData){
			setCOMTimer(SENSOR_PERIOD);
			readSensor();
			COMState = COM_RUN;
		}
		break;
	case COM_RUN:
		if(!printData){
			COMState = COM_WAIT;
		}
		if (checkCOM()){
			setCOMTimer(SENSOR_PERIOD);
			readSensor();
		}
		break;
	}
}

void readSensor(){
	//TODO: Read value from ADC then print out terminal
	char str[50];
	ADC_value = HAL_ADC_GetValue(&hadc1);
	HAL_UART_Transmit(&huart2, (uint8_t *)str, sprintf(str, "!ADC=%ld#\r\n", ADC_value), 1000);
}
