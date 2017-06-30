#include "login.h"

/* Login propriamente dito */
void doLogin(char * buffer)
{
	// Buffers usados para o username e a pass
	char username[BUFFER_SIZE];		
	char password[BUFFER_SIZE];
	
	// � pedido ao utilizador a inser��o dos mesmos
	print(USERNAME_QUESTION);
	askUsername(username);
	print(PASSWORD_QUESTION);
	askPassword(buffer,password);
	
	// S�o verificados os dados de login
	checkLoginData(buffer,username,password);
}

/* Apaga o �ltimo carater inserido (no caso de ser clicado 'backspace') */
void deleteLastCharacter(char * buffer)
{
	if(strlen(buffer))
	{		
		print(DELETE);											// � apagado do display
		buffer[strlen(buffer)-1]= '\0';							// � apagado do buffer
	}
}

/* Acrescenta um dado caracter na password */
void appendToPassword(char * buffer, char * buffer_key)
{
	strcat(buffer,buffer_key); 								// � inserido no buffer
	print(HIDDEN_PASSWORD);									// Mostra no display que foi inserido (asterisco)
}

/* Pede um caracter ao utilizador */
void askUserCharacter(char * buffer) { *buffer = getch(); }

/* Pede o username ao utilizador */
void askUsername(char * buffer) 
{ 	
	askUser(buffer);
	strtok(buffer,"\n");
}

/* Deteta se foi premida uma determinada tecla (enter ou backspace, respetivamente) */
int isEnterPressed(char buffer) { return buffer == ENTER_KEY; }
int isBackspacePressed(char buffer) { return buffer == BACKSPACE_KEY; }

/* Guarda a password */
void storePassword(char * buffer, char * password) { strncpy(password,buffer,BUFFER_SIZE); }

/* Pede a password ao utilizador */
void askPassword(char * buffer, char * password)
{
	char buffer_key = 0;							// Buffer usado para representar a tecla premida (e o carater correspondente)
	clearBuffer(buffer);
	
	askUserCharacter(&buffer_key);					// � pedido um carater inicial
	
	// Enquanto n�o seja premido no ENTER
	while(!isEnterPressed(buffer_key)) 				
	{ 
		if(isBackspacePressed(buffer_key))			// Se for premido o BACKSPACE
			deleteLastCharacter(buffer);			// Apaga o �ltimo carater
		
		else										// Se for premida uma tecla diferente do BACKSPACE
			appendToPassword(buffer,&buffer_key);	// Insere o carater na password
		
		askUserCharacter(&buffer_key);				// � pedido outro carater
	}
	
	storePassword(buffer,password);					// � guardada a password
}

/* Compara username/password */
int isUsernameCorrect(char * buffer, char * username) { return !strcmp(buffer,username); }
int isPasswordCorrect(char * buffer, char * password) { return !strcmp(buffer,password); }

/* Verifica os dados do login */
int isLoginDataCorrect(char * buffer, char * username, char * password) 
{
	char delim[2] = LOGIN_DATA_DELIM;							// Delimitador entre o username e a password
	
	// Buffer c�pia com a linha toda do ficheiro
	char buffer_copy[BUFFER_SIZE];								
	copyBuffer(buffer_copy,buffer);
	
	char * buffer_split;										// Buffer usado para isolar username/password
	
	buffer_split = strtok(buffer_copy,delim);					// Isola o username (do ficheiro)
	if(!isUsernameCorrect(buffer_split,username)) return false;	// Compara com o username introduzido
	
	buffer_split = strtok(NULL,delim);							// Isola a password (do ficheiro)
	return isPasswordCorrect(buffer_split,password);			// Compara com a password introduzida
}

/* Verifica o login */
void checkLoginData(char * buffer, char * username, char * password)
{
	print(LOGIN_VERIFICATION_BEGIN);							// In�cio da verifica��o do login
	
	FILE * fp = fopen(LOGIN_FILE,READ);							// � aberto o ficheiro
	
	// Caso tenha ocorrido um erro ao verificar o login
	if(!fp)
		print(LOGIN_VERIFICATION_ERROR);						// Mensagem de erro
	
	// Caso contr�rio,
	// Prossegue com o login
	else
	{
		while(ask(fp,buffer))									// Percorre o ficheiro
		{
			strtok(buffer,"\n");
			if(isLoginDataCorrect(buffer,username,password)) 	// Se bater certo os dados introduzidos pelo utilizador
			{
				fclose(fp);										// � fechado o ficheiro
				print(LOGIN_SUCCESS);							// Mensagem de sucesso
				pause();
				return;											// Sai desta fun��o
			}
		}
		
		// Caso o utilizador tenha introduzido dados inv�lidos
		fclose(fp);												// � fechado o ficheiro
		print(LOGIN_FAILED);									// Fim da verifica��o do login
		pause();
		exit(0);												// Sai do programa
	}
}
