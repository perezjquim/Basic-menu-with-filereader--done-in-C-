#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100
#define STRING "%s"
#define READ "r"
#define MIN_CHARACTERS_FILENAME 2

/* Mostra o menu e as suas opções */
void mostrarOpcoes()
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
void executarOpcao(int opcao)
{
	// Escolha da dada opção conforme o input
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
		
		// Opção de sair do programa			
		case 0:
			exit(0);		
			break;
			
		// Opção inválida
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
		executarOpcao(atoi(buffer)); 			// A dada opção é seleccionada
		mostrarOpcoes();						// São mostradas novamente as opções
		printf(STRING,"@@Escolha uma opcao@@\n");	// É exposta uma mensagem a pedir uma opção
	}
}

/* Serve para pedir um conjunto (infinito) de opções por parte do utilizador */
void pedirOpcoesUtilizador(char * buffer)
{
	mostrarOpcoes();							// São mostradas as opções
	printf(STRING,"@@Escolha uma opcao@@\n");		// É exposta uma mensagem a pedir uma opção
	fflush(stdin);									// 
	pedirOpcoes(stdin,buffer);						// É pedido (infinitamente) a escolha de uma opção
}

/* Serve para pedir um conjunto de opções através do ficheiro */
void pedirNomeFicheiro(char * buffer)
{
	printf(STRING,"Nome do ficheiro: ");			//
	fflush(stdin);									//
	fgets(buffer,BUFFER_SIZE,stdin);				// É pedido o nome do ficheiro a ser lido
	strtok(buffer, "\n");							//
}
void lerFicheiro(char * buffer)
{
	pedirNomeFicheiro(buffer);						// É pedido o nome do ficheiro a ser lido
	
	// Caso a resposta tenha sido vazia
	// (caso não se pretenda ler um ficheiro)
	if(*buffer == '\n')
		printf(STRING,"@@Leitura do ficheiro abortada.@@\n\n");
	
	// Caso contrário
	else
	{
		printf(STRING,"\n\n@@A carregar o ficheiro...@@\n");
		FILE *fp = fopen(buffer,READ);							// É aberto o ficheiro
		
		// Caso não exista esse ficheiro
		// (ou outro tipo de erro ao abrir o ficheiro)
		if(!fp)
			printf(STRING,"@@Erro ao carregar o ficheiro.@@\n\n");
		
		// Caso contrário,
		// são lidas e executadas cada ação indicada no ficheiro
		else
		{
			pedirOpcoes(fp,buffer);
			fclose(fp);											// É fechado o ficheiro
			
			printf(STRING,"@@Carregamento do ficheiro concluido.\n\n");
		}
	}
}

/***** MAIN *****/
int main()
{
	char buffer[100];											// Buffer usado em todo o programa (para o input)
	
	lerFicheiro(buffer);										// É lido o ficheiro (caso seja o pretendido)
	pedirOpcoesUtilizador(buffer);								// São efetuadas ações pedidas pelo utilizador
	
	return 0;													// Fim do programa
}