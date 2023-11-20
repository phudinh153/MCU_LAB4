/*
 * software_timer.c
 *
 *  Created on: Nov 15, 2023
 *      Author: user
 */
#include "software_timer.h"

int LED_timer_counter = 0;
int LED_timer_flag = 0;

int SYS_timer_counter = 0;
int SYS_timer_flag = 0;

int COM_timer_counter = 0;
int COM_timer_flag = 0;

void setLEDTimer(int duration){
	if (TICK > 0) {
		LED_timer_counter = duration / TICK;
	} else LED_timer_counter = duration;
	LED_timer_flag = 0;
}
void setCOMTimer(int duration){
	if (TICK > 0) {
		COM_timer_counter = duration / TICK;
	} else COM_timer_counter = duration;
	COM_timer_flag = 0;
}
void setSYSTimer(int duration){
	if (TICK > 0) {
		SYS_timer_counter = duration / TICK;
	} else SYS_timer_counter = duration;
	SYS_timer_flag = 0;
}

int checkLED(){
	if (LED_timer_flag == 1) {
		LED_timer_flag = 0;
		return 1;
	}
	return 0;
}

int checkSYS(){
	if (SYS_timer_flag == 1) {
		SYS_timer_flag = 0;
		return 1;
	}
	return 0;
}

int checkCOM(){
	if (COM_timer_flag == 1) {
		COM_timer_flag = 0;
		return 1;
	}
	return 0;
}

void timerRun(void){
	if (LED_timer_counter > 0) {
		LED_timer_counter--;
		if (LED_timer_counter <= 0) LED_timer_flag = 1;
	}
	if (SYS_timer_counter > 0) {
		SYS_timer_counter--;
		if (SYS_timer_counter <= 0) SYS_timer_flag = 1;
	}
	if (COM_timer_counter > 0) {
			COM_timer_counter--;
			if (COM_timer_counter <= 0) COM_timer_flag = 1;
	}
}
