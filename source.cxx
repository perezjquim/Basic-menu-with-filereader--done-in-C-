#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100
#define STRING "%s"
#define READ "r"
#define MIN_CHARACTERS_FILENAME 2

void mostrarOpcoesMenu()
{
	printf(STRING,"@@@MENU@@@\n");
	printf(STRING,"1) <opcao1>\n");
	printf(STRING,"2) <opcao2>\n");
	printf(STRING,"3) <opcao3>\n");
	printf(STRING,"0) Sair\n");
	printf(STRING,"@@@@@@@@@@\n\n");
}
void selecionarOpcaoMenu(int opcao)
{
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
void pedirOpcoes(FILE * stream, char * buffer)
{
	while(fgets(buffer,sizeof(buffer),stream))
	{
		selecionarOpcaoMenu(atoi(buffer));
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
	printf(STRING,fgets(buffer,sizeof(buffer),stdin));
}
void lerFicheiro(char * buffer)
{
	pedirNomeFicheiro(buffer);
	if(strlen(buffer) >= MIN_CHARACTERS_FILENAME)
	{
		printf(STRING,"\n\n@@A carregar o ficheiro...@@\n");
		FILE *fp = fopen(buffer,READ);
		
		if(!fp)
		{	
			printf(STRING,"@@Erro ao carregar o ficheiro.@@\n\n");
			return;
		}
		
		pedirOpcoes(fp,buffer);
		fclose(fp);
		printf(STRING,"@@Carregamento do ficheiro concluido.\n\n");
	}
}
int main()
{
	char buffer[BUFFER_SIZE];
	
	mostrarOpcoesMenu();
	
	lerFicheiro(buffer);
	
	pedirOpcoesUtilizador(buffer);
	
	return 0;
}

