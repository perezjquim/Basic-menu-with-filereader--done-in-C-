#include "io_general.h"

/* Mostra o menu e as suas opções */
void showOptions()
{
	clearScreen();
	
	// Display do menu e das suas opções
	print(MENU_BEGIN);
	printLabel(1,LABEL1);
	printLabel(2,LABEL2);
	printLabel(3,LABEL3);
	print(MENU_END);
	print(CHOOSE_AN_OPTION);
	print(EXIT_KEYS);
}

/* Selecciona uma dada opção (e executa a sua respetiva ação) */
void executeOption(int option)
{
	// Escolha da dada opção conforme o input
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
		
		// Opção de sair do programa			
		case 0:
			exit(0);
			break;
			
		// Opção inválida
		default:
			print(INVALID_OPTION);
			break;
	}
}

/* Serve para pedir a opção a ser seleccionada (seja pelo ficheiro ou pelo utilizador) */
char * ask(FILE * stream, char * buffer) { return fgets(buffer,BUFFER_SIZE,stream); }
char * askUser(char * buffer) { return ask(stdin,buffer); }
char * askFile(FILE * stream, char * buffer) { return ask(stream,buffer); }
void askOptionsUserInfinitely(char * buffer)
{
	fflush(stdin);			
	while(1)
	{
		showOptions();									// São mostradas as opções
		askUser(buffer);								// É pedido (infinitamente) a escolha de uma opção
		executeOption(convertToOption(buffer));			// É executada a dada ação
	}
}

/* Converte uma string para o formato de uma opção (número) */
int convertToOption(char * buffer) { return atoi(buffer); }


/* Display de uma mensagem, label ou de uma opção */
void print(char message[]) {  printf(STRING,message);  }
void printLabel(int labelNumber,char labelName[]) { printf(LABEL,labelNumber,labelName); }
void printOption(char optionName[]) { printf(OPTION,optionName); }

/* Limpeza do ecrã */
void clearScreen() { system("cls||clear"); }

/* Pausa */
void pause() { print(ENTER_TO_CONTINUE); getchar(); }

/* Limpa o buffer */
void clearBuffer(char * buffer)
{
	int i;
	for(i=0;i<BUFFER_SIZE;i++)
		buffer[i] = '\0';
}

/* Copia o buffer */
void copyBuffer(char * buffer_dst, char * buffer_src)
{							
	strncpy(buffer_dst,buffer_src,BUFFER_SIZE-1);
	buffer_dst[BUFFER_SIZE-1] = '\0';
}