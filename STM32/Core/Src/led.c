/*
 * led.c
 *
 *  Created on: Nov 15, 2023
 *      Author: user
 */


#include "led.h"

void ledBlink(){
	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
}

void led_fsm(){
	switch(LEDState) {
	case LED_INIT:
		//TODO: Initialize timer for debug led
		setLEDTimer(TICK);
		LEDState = LED_BLINKING;
		break;
	case LED_BLINKING:
		//TODO: Keep led blinking to check is the program working or not
		if(LED_timer_flag == 1){
			setLEDTimer(LED_PERIOD);
			LED_timer_flag = 0;
			ledBlink();
		}
		break;
	}
}
