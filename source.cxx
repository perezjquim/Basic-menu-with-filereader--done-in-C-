#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void mostrarOpcoesMenu()
{
	printf("%s\n","MENU");
	printf("%s\n","1) (opcao1)");
	printf("%s\n","2) (opcao2)");
	printf("%s\n","3) (opcao3)");	
}
void selecionarOpcaoMenu(int opcao)
{
	switch(opcao)
	{
		case 1: 
			printf("%s\n","escolheste a 1!!");
			//
			break;
		case 2:
			printf("%s\n","escolheste a 2!!");
			//
			break;
		case 3:
			printf("%s\n","escolheste a 3!!");
			//
			break;
		default:
			printf("%s\n","escolheste uma opcao invalida!!");
			break;
	}
}
void pedirOpcoes(FILE * stream)
{
	char buffer[100];
	while(fgets(buffer,sizeof(buffer),stream))
	{
		selecionarOpcaoMenu(atoi(buffer));
	}
}
int main()
{
	char buffer[100];
	mostrarOpcoesMenu();
	
	printf("%s","Nome do ficheiro: ");
	scanf("%s",buffer);
	
	if(strlen(buffer))
	{
		FILE *fp = fopen(buffer,"r");
		pedirOpcoes(fp);
		fclose(fp);
	}
	
	pedirOpcoes(stdin);
	return EXIT_SUCCESS;
}

