#include "login.h"

void doLogin(char * buffer)
{
	char username[BUFFER_SIZE];
	char password[BUFFER_SIZE];
	
	print(USERNAME_QUESTION);
	
	askUsername(buffer,username);
	askPassword(buffer,password);
	
	checkLoginData(username,password);
}

void checkLoginData(char * username, char * password)
{
	
}
void deleteLastCharacter(char * buffer)
{
	print(DELETE);
	if(strlen(buffer)) buffer[strlen(buffer)-1]= '\0';
}
void appendToPassword(char * buffer, char * buffer_key)
{
	strcat(buffer,buffer_key); 
	print("*");
}

void askCharacter(char * buffer) { buffer = getch(); }

void askUsername(char * buffer, char * username) { 	ask(stdin,buffer); strcpy(username,buffer); }

void askPassword(char * buffer, char * password)
{
	char * buffer_key = 0;
	strcpy(buffer,"");
	
	askCharacter(buffer);
	while(*buffer_key != ENTER_KEY) 
	{ 
		if(*buffer_key == BACKSPACE_KEY) 
			deleteLastCharacter(buffer);
		else 
			appendToPassword(buffer,buffer_key);
		askCharacter(buffer);
	}
	
	strcpy(password,buffer);
}
	