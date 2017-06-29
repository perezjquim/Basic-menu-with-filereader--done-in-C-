#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../op/options.h"
#include "../etc/messages.h"

#ifndef true
#define true 1
#endif

#ifndef false
#define false 0
#endif

#ifndef STRING
#define STRING "%s"
#endif

#ifndef LABEL
#define LABEL "%i %s %s \n"
#endif

#ifndef OPTION
#define OPTION "%s %s \n \n"
#endif

#ifndef READ
#define READ "r"
#endif

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 100
#endif

int print(char message[]);
int printLabel(int labelNumber,char labelName[]);
int printOption(char optionName[]);

int isBufferEmpty(char * buffer);
int convertToOption(char * buffer);

void showOptions();
void executeOption(int option);

char * askOption(FILE * stream, char * buffer);
void askOptionsUser(char * buffer);