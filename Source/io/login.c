#include "login.h"

/* Login propriamente dito */
void doLogin(char * buffer)
{
	// Buffers usados para o username e a pass
	char username[BUFFER_SIZE];		
	char password[BUFFER_SIZE];
	
	// � pedido ao utilizador a inser��o dos mesmos
	print(USERNAME_QUESTION);
	askUsername(buffer,username);
	askPassword(buffer,password);
	
	// S�o verificados os dados de login
	checkLoginData(username,password);
}

/* Verifica os dados de login */
void checkLoginData(char * username, char * password)
{
	
}

/* Apaga o �ltimo carater inserido (no caso de ser clicado 'backspace') */
void deleteLastCharacter(char * buffer)
{
	print(DELETE);											// � apagado do display
	if(strlen(buffer)) buffer[strlen(buffer)-1]= '\0';		// � apagado do buffer
}

/* Acrescenta um dado caracter na password */
void appendToPassword(char * buffer, char * buffer_key)
{
	strcat(buffer,buffer_key); 								// � inserido no buffer
	print(HIDDEN_PASSWORD);									// Mostra no display que foi inserido (asterisco)
}

/* Pede um caracter ao utilizador */
void askCharacter(char * buffer) { buffer = getch(); }

/* Pede o username ao utilizador */
void askUsername(char * buffer, char * username) { 	ask(stdin,buffer); strcpy(username,buffer); }

/* Pede a password ao utilizador */
void askPassword(char * buffer, char * password)
{
	char * buffer_key;								// Buffer usado para representar a tecla premida (e o carater correspondente)
	strcpy(buffer,EMPTY_BUFFER);					// � esvaziado o buffer principal
	
	askCharacter(buffer);							// � pedido um carater inicial
	
	// Enquanto n�o seja premido no ENTER
	while(*buffer_key != ENTER_KEY) 				
	{ 
		if(*buffer_key == BACKSPACE_KEY) 			// Se for 'backspace'
			deleteLastCharacter(buffer);			// Apaga o �ltimo carater
		
		else 										// Se for outra tecla qualquer
			appendToPassword(buffer,buffer_key);	// Insere o carater na password
		
		askCharacter(buffer);						// � pedido outro carater
	}
	
	strcpy(password,buffer);						// � guardada a password
}
	