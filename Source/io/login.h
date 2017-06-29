#include <conio.h>
#include "io_general.h"
#include "../etc/messages.h"

#define ENTER_KEY 13
#define BACKSPACE_KEY 8

#define DELETE "\b \b"
#define EMPTY_BUFFER ""
#define HIDDEN_PASSWORD "*"

#define LOGIN_FILE "login.txt"
#define LOGIN_DATA_DELIM " "

void doLogin(char * buffer);

void deleteLastCharacter(char * buffer);
void appendToPassword(char * buffer, char * buffer_key);

void askCharacter(char * buffer);
void askUsername(char * buffer);
void askPassword(char * buffer, char * password);

int isUsernameCorrect(char * buffer, char * username);
int isPasswordCorrect(char * buffer, char * password);
int isLoginDataCorrect(char * buffer, char * username, char * password);

void checkLoginData(char * buffer, char * username, char * password);
