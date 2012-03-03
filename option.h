#ifndef OPTION_H
#define OPTION_H
typedef struct {
	char *name;
	uint8_t setting;
} option_t;

uint8_t option_value(char name[]);
#endif
