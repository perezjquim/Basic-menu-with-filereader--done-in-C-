#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../op/options.h"
#include "../etc/messages.h"

#ifndef STRING
#define STRING "%s"
#endif

#ifndef STRING_LINE
#define STRING_LINE "%s\n"
#endif

#ifndef LABEL
#define LABEL "%i) %s\n"
#endif

#ifndef OPTION
#define OPTION "%s escolhida.\n\n"
#endif

#ifndef READ
#define READ "r"
#endif

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 500
#endif

#ifndef ENDLINE
#define ENDLINE "\n"
#endif

#ifndef true
#define true 1
#endif

#ifndef false
#define false 0
#endif

void showOptions();
void executeOption(int option);

char * ask(FILE * stream, char * buffer);
char * askUser(char * buffer);
char * askFile(FILE * stream, char * buffer);
void askOptionsUserInfinitely(char * buffer);

int convertToOption(char * buffer);

void print(char message[]);
void println(char message[]);
void printLabel(int labelNumber,char labelName[]);
void printOption(char optionName[]);

void pause();
void clearScreen();

void clearBuffer(char * buffer);
void copyBuffer(char * buffer_dst, char * buffer_src);