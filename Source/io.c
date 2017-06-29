#include "io.h"
#include "options.h"

/* Display de uma mensagem */
void print(char message[]) {  printf(STRING,message);  }
void printLabel(int labelNumber,char labelName[]) { printf(LABEL,labelNumber,") ",labelName,"\n"); }

/* Verifica se o buffer est� vazio (se recebeu uma resposta vazia) */
int isBufferEmpty(char * buffer) { return (*buffer == '\n'); }

/* Converte uma string para o formato de uma op��o (n�mero) */
int convertToOption(char * buffer) { return atoi(buffer); }

/* Mostra o menu e as suas op��es */
void showOptions()
{
	// Display do menu e das suas op��es
	print("@@@@@@@@@@MENU@@@@@@@@@@\n");
	printLabel(1,LABEL1);
	printLabel(2,LABEL2);
	printLabel(3,LABEL3);
	printLabel(0,"Exit");
	print("@@@@@@@@@@@@@@@@@@@@@@@\n\n");
}

/* Selecciona uma dada op��o (e executa a sua respetiva a��o) */
void executeOption(int option)
{
	// Escolha da dada op��o conforme o input
	switch(option)
	{
		//
		case 1: 
			print("<opcao1> escolhida.\n");
			option1();
			break;
		
		//
		case 2:
			print("<opcao2> escolhida.\n");
			option2();
			break;
		
		//
		case 3:
			print("<opcao3> escolhida.\n");
			option3();
			break;
		
		// Op��o de sair do programa			
		case 0:
			exit(0);
			break;
			
		// Op��o inv�lida
		default:
			print("opcao invalida.\n");
			break;
	}
}


/* Serve para pedir a op��o a ser seleccionada (seja pelo ficheiro ou pelo utilizador) */
void ask(FILE * stream, char * buffer)
{
	// Enquanto poder ser escolhido uma op��o 
	// (infinitamente, no caso do utilizador; finitamente, no caso da leitura no ficheiro)
	while(fgets(buffer,BUFFER_SIZE,stream))
	{
		executeOption(convertToOption(buffer)); 			// A dada op��o � seleccionada
		showOptions();										// S�o mostradas novamente as op��es
		print("@@Escolha uma opcao@@\n");					// � exposta uma mensagem a pedir uma op��o
	}
}

/* Serve para pedir um conjunto (infinito) de op��es por parte do utilizador */
void askUser(char * buffer)
{
	showOptions();							// S�o mostradas as op��es
	print("@@Escolha uma opcao@@\n");		// � exposta uma mensagem a pedir uma op��o
	fflush(stdin);									// 
	ask(stdin,buffer);						// � pedido (infinitamente) a escolha de uma op��o
}

/* Serve para pedir um conjunto de op��es atrav�s do ficheiro */
void askFileName(char * buffer)
{
	print("Nome do ficheiro: ");			//
	fflush(stdin);									//
	fgets(buffer,BUFFER_SIZE,stdin);				// � pedido o nome do ficheiro a ser lido
	strtok(buffer, "\n");							//
}
void readFile(char * buffer)
{
	askFileName(buffer);						// � pedido o nome do ficheiro a ser lido
	
	// Caso a resposta tenha sido vazia
	// (caso n�o se pretenda ler um ficheiro)
	if(isBufferEmpty(buffer))
		print("@@Leitura do ficheiro abortada.@@\n\n");
	
	// Caso contr�rio
	else
	{
		print("\n\n@@A carregar o ficheiro...@@\n");
		FILE *fp = fopen(buffer,READ);							// � aberto o ficheiro
		
		// Caso n�o exista esse ficheiro
		// (ou outro tipo de erro ao abrir o ficheiro)
		if(!fp)
			print("@@Erro ao carregar o ficheiro.@@\n\n");
		
		// Caso contr�rio,
		// s�o lidas e executadas cada a��o indicada no ficheiro
		else
		{
			ask(fp,buffer);
			fclose(fp);											// � fechado o ficheiro
			
			print("@@Carregamento do ficheiro concluido.\n\n");
		}
	}
}
