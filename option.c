#include <stdint.h>
#include <string.h>
#include "option.h"

option_t option[] = {
	//LED,		Pin register state
	{"RED",		0b00000001},
	{"GREEN",	0b01000000},
	{"BOTH",	0b01000001},
	{NULL}
};

uint8_t option_value(char name[]) {
	uint8_t i;
	for (
		i = 0;
		option[i].name != NULL && strcmp(name,option[i].name) != 0;
		i++
	);
	return option[i].setting;
}
