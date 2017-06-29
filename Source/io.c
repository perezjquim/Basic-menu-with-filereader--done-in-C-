#include "io.h"


/* Display de uma mensagem */
int print(char message[]) {  return printf(STRING,message);  }
int printLabel(int labelNumber,char labelName[]) { return printf(LABEL,labelNumber,") ",labelName); }
int printOption(char optionName[]) { return printf(OPTION,optionName, " escolhida."); }

/* Verifica se o buffer está vazio (se recebeu uma resposta vazia) */
int isBufferEmpty(char * buffer) { return (*buffer == '\n'); }

/* Converte uma string para o formato de uma opção (número) */
int convertToOption(char * buffer) { return atoi(buffer); }

/* Mostra o menu e as suas opções */
int showOptions()
{
	// Display do menu e das suas opções
	print(MENU_BEGIN);
	printLabel(1,LABEL1);
	printLabel(2,LABEL2);
	printLabel(3,LABEL3);
	printLabel(0,"Exit");
	print(MENU_END);
	
	return print(CHOOSE_AN_OPTION);
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
void ask(FILE * stream, char * buffer)
{
	// Enquanto poder ser escolhido uma opção 
	// (infinitamente, no caso do utilizador; finitamente, no caso da leitura no ficheiro)
	while(fgets(buffer,BUFFER_SIZE,stream) && showOptions())
	{
		executeOption(convertToOption(buffer)); 			// A dada opção é seleccionada
	}
}

/* Serve para pedir um conjunto (infinito) de opções por parte do utilizador */
void askUser(char * buffer)
{
	showOptions();
	fflush(stdin);							// 
	ask(stdin,buffer);						// É pedido (infinitamente) a escolha de uma opção
}

/* Serve para pedir um conjunto de opções através do ficheiro */
void askFileName(char * buffer)
{
	print(FILENAME_QUESTION);						//
	fflush(stdin);									//
	fgets(buffer,BUFFER_SIZE,stdin);				// É pedido o nome do ficheiro a ser lido
	strtok(buffer, "\n");							//
}
void readFile(char * buffer)
{
	askFileName(buffer);						// É pedido o nome do ficheiro a ser lido
	
	// Caso a resposta tenha sido vazia
	// (caso não se pretenda ler um ficheiro)
	if(isBufferEmpty(buffer))
		print(FILE_LOADING_ABORT);
	
	// Caso contrário
	else
	{
		print(FILE_LOADING);
		FILE *fp = fopen(buffer,READ);							// É aberto o ficheiro
		
		// Caso não exista esse ficheiro
		// (ou outro tipo de erro ao abrir o ficheiro)
		if(!fp)
			print(FILE_LOADING_ERROR);
		
		// Caso contrário,
		// são lidas e executadas cada ação indicada no ficheiro
		else
		{
			ask(fp,buffer);
			fclose(fp);											// É fechado o ficheiro
			
			print(FILE_LOADING_COMPLETE);
		}
	}
}
