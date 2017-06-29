#include <conio.h>
#include "io_general.h"
#include "../etc/messages.h"

#define ENTER_KEY 13
#define BACKSPACE_KEY 8

#define DELETE "\b \b"

void doLogin(char * buffer);

void checkLoginData(char * username, char * password);

void deleteLastCharacter(char * buffer);
void appendToPassword(char * buffer, char * buffer_key);

void askCharacter(char * buffer);
void askUsername(char * buffer, char * username);
void askPassword(char * buffer, char * password);