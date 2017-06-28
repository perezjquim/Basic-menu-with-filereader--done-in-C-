#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100
#define STRING "%s"
#define READ "r"
#define MIN_CHARACTERS_FILENAME 2

/* Mostra o menu e as suas opções */
void mostrarOpcoesMenu()
{
	// Display do menu e das suas opções
	printf(STRING,"@@@MENU@@@\n");
	printf(STRING,"1) <opcao1>\n");
	printf(STRING,"2) <opcao2>\n");
	printf(STRING,"3) <opcao3>\n");
	printf(STRING,"0) Sair\n");
	printf(STRING,"@@@@@@@@@@\n\n");
}

/* Selecciona uma dada opção (e executa a sua respetiva ação) */
void selecionarOpcaoMenu(int opcao)
{
	// Escolha da dada opção conforme o input
	switch(opcao)
	{
		case 1: 
			printf(STRING,"<opcao1> escolhida.\n");
			//
			break;
		case 2:
			printf(STRING,"<opcao2> escolhida.\n");
			//
			break;
		case 3:
			printf(STRING,"<opcao3> escolhida.\n");
			//
			break;
		case 0:
			exit(0);
			break;
		default:
			printf(STRING,"opcao invalida.\n");
			break;
	}
}

/* Serve para pedir a opção a ser seleccionada (seja pelo ficheiro ou pelo utilizador) */
void pedirOpcoes(FILE * stream, char * buffer)
{
	// Enquanto poder ser escolhido uma opção 
	// (infinitamente, no caso do utilizador; finitamente, no caso da leitura no ficheiro)
	while(fgets(buffer,BUFFER_SIZE,stream))
	{
		selecionarOpcaoMenu(atoi(buffer)); // A dada opção é seleccionada
		mostrarOpcoesMenu();
		printf(STRING,"@@Escolha uma opcao@@\n");
	}
}

void pedirOpcoesUtilizador(char * buffer)
{
	mostrarOpcoesMenu();
	printf(STRING,"@@Escolha uma opcao@@\n");	
	fflush(stdin);
	pedirOpcoes(stdin,buffer);
}
void pedirNomeFicheiro(char * buffer)
{
	printf(STRING,"Nome do ficheiro: ");
	fflush(stdin);
	fgets(buffer,BUFFER_SIZE,stdin);
	strtok(buffer, "\n");
}
void lerFicheiro(char * buffer)
{
	pedirNomeFicheiro(buffer);
	
	if(*buffer == '\n')
		printf(STRING,"@@Leitura do ficheiro abortada.@@\n\n");
	else
	{
		printf(STRING,"\n\n@@A carregar o ficheiro...@@\n");
		FILE *fp = fopen(buffer,READ);
		
		if(!fp)
			printf(STRING,"@@Erro ao carregar o ficheiro.@@\n\n");
		else
		{
			pedirOpcoes(fp,buffer);
			fclose(fp);
			
			printf(STRING,"@@Carregamento do ficheiro concluido.\n\n");
		}
	}
}
int main()
{
	char buffer[100];
	
	mostrarOpcoesMenu();
	printf(STRING,"@@Escolha uma opcao@@\n");
	
	lerFicheiro(buffer);
	
	pedirOpcoesUtilizador(buffer);
	
	return 0;
}