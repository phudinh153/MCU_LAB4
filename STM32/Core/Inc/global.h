/*
 * global.h
 *
*  Created on: Nov 15, 2023
*      Author: user
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include <stdio.h>
#include <string.h>
#include "main.h"
#include "adc.h"
#include "communication.h"
#include "led.h"
#include "parser.h"
#include "software_timer.h"
#include "usart.h"

//Define constant
#define LED_PERIOD 		500
#define PARSER_TIME		3000
#define SENSOR_PERIOD	500

#define MAX_BUFFER_SIZE 30


//Define FSM state
#define LED_INIT		51
#define LED_BLINKING	52

#define SYSTEM_START	21
#define SYSTEM_PRINT	22
#define SYSTEM_WAIT		23

#define COM_INIT		11
#define COM_RUN			12
#define COM_WAIT		13


extern int LEDState;
extern int SYSState;
extern int COMState;

extern uint8_t 	temp;
extern uint32_t	ADC_value;
extern uint8_t	buffer_flag;

extern uint8_t printData;


#endif /* INC_GLOBAL_H_ */
