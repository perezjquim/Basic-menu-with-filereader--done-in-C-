#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100
#define STRING "%s"
#define READ "r"
#define MIN_CHARACTERS_FILENAME 2

/* Mostra o menu e as suas op��es */
void mostrarOpcoes()
{
	// Display do menu e das suas op��es
	printf(STRING,"@@@MENU@@@\n");
	printf(STRING,"1) <opcao1>\n");
	printf(STRING,"2) <opcao2>\n");
	printf(STRING,"3) <opcao3>\n");
	printf(STRING,"0) Sair\n");
	printf(STRING,"@@@@@@@@@@\n\n");
}

/* Selecciona uma dada op��o (e executa a sua respetiva a��o) */
void executarOpcao(int opcao)
{
	// Escolha da dada op��o conforme o input
	switch(opcao)
	{
		//
		case 1: 
			printf(STRING,"<opcao1> escolhida.\n");
			//
			break;
		
		//
		case 2:
			printf(STRING,"<opcao2> escolhida.\n");
			//
			break;
		
		//
		case 3:
			printf(STRING,"<opcao3> escolhida.\n");
			//
			break;
		
		// Op��o de sair do programa			
		case 0:
			exit(0);		
			break;
			
		// Op��o inv�lida
		default:
			printf(STRING,"opcao invalida.\n");
			break;
	}
}

/* Serve para pedir a op��o a ser seleccionada (seja pelo ficheiro ou pelo utilizador) */
void pedirOpcoes(FILE * stream, char * buffer)
{
	// Enquanto poder ser escolhido uma op��o 
	// (infinitamente, no caso do utilizador; finitamente, no caso da leitura no ficheiro)
	while(fgets(buffer,BUFFER_SIZE,stream))
	{
		executarOpcao(atoi(buffer)); 			// A dada op��o � seleccionada
		mostrarOpcoes();						// S�o mostradas novamente as op��es
		printf(STRING,"@@Escolha uma opcao@@\n");	// � exposta uma mensagem a pedir uma op��o
	}
}

/* Serve para pedir um conjunto (infinito) de op��es por parte do utilizador */
void pedirOpcoesUtilizador(char * buffer)
{
	mostrarOpcoes();							// S�o mostradas as op��es
	printf(STRING,"@@Escolha uma opcao@@\n");		// � exposta uma mensagem a pedir uma op��o
	fflush(stdin);									// 
	pedirOpcoes(stdin,buffer);						// � pedido (infinitamente) a escolha de uma op��o
}

/* Serve para pedir um conjunto de op��es atrav�s do ficheiro */
void pedirNomeFicheiro(char * buffer)
{
	printf(STRING,"Nome do ficheiro: ");			//
	fflush(stdin);									//
	fgets(buffer,BUFFER_SIZE,stdin);				// � pedido o nome do ficheiro a ser lido
	strtok(buffer, "\n");							//
}
void lerFicheiro(char * buffer)
{
	pedirNomeFicheiro(buffer);						// � pedido o nome do ficheiro a ser lido
	
	// Caso a resposta tenha sido vazia
	// (caso n�o se pretenda ler um ficheiro)
	if(*buffer == '\n')
		printf(STRING,"@@Leitura do ficheiro abortada.@@\n\n");
	
	// Caso contr�rio
	else
	{
		printf(STRING,"\n\n@@A carregar o ficheiro...@@\n");
		FILE *fp = fopen(buffer,READ);							// � aberto o ficheiro
		
		// Caso n�o exista esse ficheiro
		// (ou outro tipo de erro ao abrir o ficheiro)
		if(!fp)
			printf(STRING,"@@Erro ao carregar o ficheiro.@@\n\n");
		
		// Caso contr�rio,
		// s�o lidas e executadas cada a��o indicada no ficheiro
		else
		{
			pedirOpcoes(fp,buffer);
			fclose(fp);											// � fechado o ficheiro
			
			printf(STRING,"@@Carregamento do ficheiro concluido.\n\n");
		}
	}
}

/***** MAIN *****/
int main()
{
	char buffer[100];											// Buffer usado em todo o programa (para o input)
	
	lerFicheiro(buffer);										// � lido o ficheiro (caso seja o pretendido)
	pedirOpcoesUtilizador(buffer);								// S�o efetuadas a��es pedidas pelo utilizador
	
	return 0;													// Fim do programa
}