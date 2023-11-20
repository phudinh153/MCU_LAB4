/*
 * parser.c
 *
 *  Created on: Nov 15, 2023
 *      Author: user
 */


#include "parser.h"

uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t index_buffer = 0;

char * string_buffer;

int isRST = 0;
int isOK = 0;

int checkRST(){
	if (isRST == 1){
		isRST = 0;
		return 1;
	} return 0;
}

int checkOK(){
	if (isOK == 1){
		isOK = 0;
		return 1;
	} return 0;
}

uint8_t isRSTCmd(void){
	char * requestCmd = (char *)"!RST#";
	if (strcmp(string_buffer, requestCmd) == 0){
		return 1;
	} return 0;
}

uint8_t isOKCmd(void){
	char * stopCmd = (char *)"!OK#";
	if (strcmp(string_buffer, stopCmd) == 0){
		return 1;
	} return 0;
}

void updateBuffer (uint8_t updated){
	uint8_t * newLine = (uint8_t *)"\r\n";
	if (updated == *newLine){
		isRST = isRSTCmd();
		isOK = isOKCmd();
		clearBuffer();
	} else {
		buffer[index_buffer] = updated;
		index_buffer = (index_buffer+1)%MAX_BUFFER_SIZE;
	}
	string_buffer = (char *)buffer;
}

void clearBuffer(void) {
	for(uint8_t index = 0; index < index_buffer; index++){
		buffer[index] = 0;
	}
	index_buffer = 0;
}

void command_parser_fsm(void) {
	switch (SYSState) {
	case SYSTEM_START:
		if(checkRST()){
			setSYSTimer(0);
			printData = 1;
			SYSState = SYSTEM_PRINT;
		}
		break;
	case SYSTEM_PRINT:
		setSYSTimer(PARSER_TIME);
		printData = 0;
		SYSState = SYSTEM_WAIT;
		break;
	case SYSTEM_WAIT:
		if(checkRST()){
			setSYSTimer(0);
			printData = 1;
			SYSState = SYSTEM_PRINT;
			break;
		}
		if(checkOK()){
			setSYSTimer(0);
			printData = 0;
			SYSState = SYSTEM_START;
			break;
		}
		if (checkRST()){
			setSYSTimer(0);
			clearBuffer();
			printData = 1;
			SYSState = SYSTEM_PRINT;
			break;
		}
		setSYSTimer(PARSER_TIME);
		break;
	}
}


