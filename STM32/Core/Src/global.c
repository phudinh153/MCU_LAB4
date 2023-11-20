 /*
 * global.c
 *
 *  Created on: Nov 15, 2023
 *      Author: user
 */

#include "global.h"

int LEDState = LED_INIT;
int SYSState = SYSTEM_START;
int COMState = COM_INIT;

uint8_t temp = 0;
uint32_t ADC_value = 0;
uint8_t buffer_flag = 0;
uint8_t printData = 0;


