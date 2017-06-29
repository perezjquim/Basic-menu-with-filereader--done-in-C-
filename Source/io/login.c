#include "login.h"

/* Login propriamente dito */
void doLogin(char * buffer)
{
	// Buffers usados para o username e a pass
	char username[BUFFER_SIZE];		
	char password[BUFFER_SIZE];
	
	// É pedido ao utilizador a inserção dos mesmos
	print(USERNAME_QUESTION);
	askUsername(username);
	print(PASSWORD_QUESTION);
	askPassword(buffer,password);
	
	// São verificados os dados de login
	checkLoginData(buffer,username,password);
}

/* Apaga o último carater inserido (no caso de ser clicado 'backspace') */
void deleteLastCharacter(char * buffer)
{
	print(DELETE);											// É apagado do display
	if(strlen(buffer)) buffer[strlen(buffer)-1]= '\0';		// É apagado do buffer
}

/* Acrescenta um dado caracter na password */
void appendToPassword(char * buffer, char * buffer_key)
{
	strcat(buffer,buffer_key); 								// É inserido no buffer
	print(HIDDEN_PASSWORD);									// Mostra no display que foi inserido (asterisco)
}

/* Pede um caracter ao utilizador */
void askCharacter(char * buffer) { *buffer = getch(); }

/* Pede o username ao utilizador */
void askUsername(char * buffer) 
{ 	
	ask(stdin,buffer); 
	strtok(buffer,"\n");
}

/* Pede a password ao utilizador */
void askPassword(char * buffer, char * password)
{
	char buffer_key = 0;							// Buffer usado para representar a tecla premida (e o carater correspondente)
	clearBuffer(buffer);
	
	askCharacter(&buffer_key);						// É pedido um carater inicial
	
	// Enquanto não seja premido no ENTER
	while(buffer_key != ENTER_KEY) 				
	{ 
		if(buffer_key == BACKSPACE_KEY) 			// Se for 'backspace'
			deleteLastCharacter(buffer);			// Apaga o último carater
		else 										// Se for outra tecla qualquer
			appendToPassword(buffer,&buffer_key);	// Insere o carater na password
		
		askCharacter(&buffer_key);					// É pedido outro carater
	}
	strncpy(password,buffer,BUFFER_SIZE);
}

/* Compara username/password */
int isUsernameCorrect(char * buffer, char * username) { return !strcmp(buffer,username); }
int isPasswordCorrect(char * buffer, char * password) { return !strcmp(buffer,password); }

/* Verifica os dados do login */
int isLoginDataCorrect(char * buffer, char * username, char * password) 
{
	char delim[2] = LOGIN_DATA_DELIM;							// Delimitador entre o username e a password
	
	// Buffer cópia com a linha toda do ficheiro
	char buffer_copy[BUFFER_SIZE];								
	strncpy(buffer_copy,buffer,BUFFER_SIZE-1);
	buffer_copy[BUFFER_SIZE-1] = '\0';
	
	
	char * buffer_split;										// Buffer usado para isolar username/password
	
	buffer_split = strtok(buffer_copy,delim);					// Isola o username (do ficheiro)
	if(!isUsernameCorrect(buffer_split,username)) return false;	// Compara com o username introduzido
	
	buffer_split = strtok(NULL,delim);							// Isola a password (do ficheiro)
	return isPasswordCorrect(buffer_split,password);			// Compara com a password introduzida
}

/* Verifica o login */
void checkLoginData(char * buffer, char * username, char * password)
{
	print(LOGIN_VERIFICATION_BEGIN);							// Início da verificação do login
	
	FILE * fp = fopen(LOGIN_FILE,READ);							// É aberto o ficheiro
	
	// Caso tenha ocorrido um erro ao verificar o login
	if(!fp)
		print(LOGIN_VERIFICATION_ERROR);						// Mensagem de erro
	
	// Caso contrário,
	// Prossegue com o login
	else
	{
		while(ask(fp,buffer))									// Percorre o ficheiro
		{
			strtok(buffer,"\n");
			if(isLoginDataCorrect(buffer,username,password)) 	// Se bater certo os dados introduzidos pelo utilizador
			{
				fclose(fp);										// É fechado o ficheiro
				print(LOGIN_SUCCESS);							// Mensagem de sucesso
				// (delay/pausa)
				return;											// Sai desta função
			}
		}
		
		// Caso o utilizador tenha introduzido dados inválidos
		fclose(fp);												// É fechado o ficheiro
		print(LOGIN_FAILED);									// Fim da verificação do login
		// (delay/pausa)
		exit(0);												// Sai do programa
	}
}
