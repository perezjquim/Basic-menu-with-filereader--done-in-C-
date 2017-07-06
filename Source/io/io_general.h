#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../op/options.h"
#include "../etc/messages.h"

#define STRING "%s"
#define STRING_LINE "%s\n"
#define LABEL "%i) %s\n"
#define OPTION "%s escolhida.\n\n"
#define READ "r"
#define BUFFER_SIZE 500
#define ENDLINE "\n"
#define true 1
#define false 0

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