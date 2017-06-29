#include "io_general.h"

/* Pausa */
void pause() { system("pause"); }

/* Limpa o buffer */
void clearBuffer(char * buffer)
{
	int i;
	for(i=0;i<BUFFER_SIZE;i++)
		buffer[i] = '\0';
}

/* Display de uma mensagem, label ou de uma op��o */
void print(char message[]) {  printf(STRING,message);  }
void printLabel(int labelNumber,char labelName[]) { printf(LABEL,labelNumber,") ",labelName); }
void printOption(char optionName[]) { printf(OPTION,optionName, " escolhida."); }

/* Serve para pedir a op��o a ser seleccionada (seja pelo ficheiro ou pelo utilizador) */
char * ask(FILE * stream, char * buffer) { return fgets(buffer,BUFFER_SIZE,stream); }

/* Converte uma string para o formato de uma op��o (n�mero) */
int convertToOption(char * buffer) { return atoi(buffer); }

/* Mostra o menu e as suas op��es */
void showOptions()
{
	// Display do menu e das suas op��es
	print(MENU_BEGIN);
	printLabel(1,LABEL1);
	printLabel(2,LABEL2);
	printLabel(3,LABEL3);
	printLabel(0,"Exit");
	print(MENU_END);
	print(CHOOSE_AN_OPTION);
}

/* Selecciona uma dada op��o (e executa a sua respetiva a��o) */
void executeOption(int option)
{
	// Escolha da dada op��o conforme o input
	switch(option)
	{
		//
		case 1: 
			printOption(LABEL1);
			option1();
			break;
		
		//
		case 2:
			printOption(LABEL2);
			option2();
			break;
		
		//
		case 3:
			printOption(LABEL3);
			option3();
			break;
		
		// Op��o de sair do programa			
		case 0:
			exit(0);
			break;
			
		// Op��o inv�lida
		default:
			print(INVALID_OPTION);
			break;
	}
}

/* Serve para pedir um conjunto (infinito) de op��es por parte do utilizador */
void askOptionsUser(char * buffer)
{
	fflush(stdin);			
	while(1)
	{
		showOptions();									// S�o mostradas as op��es
		ask(stdin,buffer);						// � pedido (infinitamente) a escolha de uma op��o
		executeOption(convertToOption(buffer));			// � executada a dada a��o
	}
}