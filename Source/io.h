#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "options.h"
#include "messages.h"

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

#ifndef LABEL1
#define LABEL1 "<opcao1>"
#endif

#ifndef LABEL2
#define LABEL2 "<opcao2>"
#endif

#ifndef LABEL3
#define LABEL3 "<opcao3>"
#endif

int print(char message[]);
int printLabel(int labelNumber,char labelName[]);
int printOption(char optionName[]);

int isBufferEmpty(char * buffer);
int convertToOption(char * buffer);

int showOptions();
void executeOption(int option);

void ask(FILE * stream, char * buffer);
void askUser(char * buffer);
void askFileName(char * buffer);
void readFile(char * buffer);
