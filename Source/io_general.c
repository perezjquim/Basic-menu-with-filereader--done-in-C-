#include "io_general.h"

/* Display de uma mensagem */
int print(char message[]) {  return printf(STRING,message);  }
int printLabel(int labelNumber,char labelName[]) { return printf(LABEL,labelNumber,") ",labelName); }
int printOption(char optionName[]) { return printf(OPTION,optionName, " escolhida."); }

/* Verifica se o buffer está vazio (se recebeu uma resposta vazia) */
int isBufferEmpty(char * buffer) { return (*buffer == '\n'); }

/* Converte uma string para o formato de uma opção (número) */
int convertToOption(char * buffer) { return atoi(buffer); }

/* Mostra o menu e as suas opções */
void showOptions()
{
	// Display do menu e das suas opções
	print(MENU_BEGIN);
	printLabel(1,LABEL1);
	printLabel(2,LABEL2);
	printLabel(3,LABEL3);
	printLabel(0,"Exit");
	print(MENU_END);
	print(CHOOSE_AN_OPTION);
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
char * askOption(FILE * stream, char * buffer) { return fgets(buffer,BUFFER_SIZE,stream); }

/* Serve para pedir um conjunto (infinito) de opções por parte do utilizador */
void askOptionsUser(char * buffer)
{
	fflush(stdin);			
	while(1)
	{
		showOptions();
		askOption(stdin,buffer);						// É pedido (infinitamente) a escolha de uma opção
		executeOption(convertToOption(buffer));
	}
}