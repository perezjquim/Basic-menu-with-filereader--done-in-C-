#include "io_file.h"

/* Leitura do ficheiro */
void readFile(char * buffer)
{
	// � pedido o nome do ficheiro a ser lido
	//
	// Caso a resposta tenha sido vazia
	// (caso n�o se pretenda ler um ficheiro)
	// N�o � feito mais nada
	if(!askFileName(buffer))
		println(FILE_LOADING_ABORT);							// Mensagem de erro
	
	// Caso contr�rio
	else
	{
		println(FILE_LOADING);
		FILE * fp = fopen(buffer,READ);							// � aberto o ficheiro
		
		// Caso n�o exista esse ficheiro
		// (ou outro tipo de erro ao abrir o ficheiro)
		if(!fp)
			println(FILE_LOADING_ERROR);						// Mensagem de erro
		
		// Caso contr�rio,
		// s�o lidas e executadas cada a��o indicada no ficheiro
		else
		{
			askOptionsFile(fp,buffer);							// S�o refeitas as a��es indicadas no ficheiro (uma a uma)
			fclose(fp);											// � fechado o ficheiro
			
			println(FILE_LOADING_COMPLETE);
		}
	}
}

/* L� e executa um dado conjunto de a��es (indicadas no ficheiro) */
void askOptionsFile(FILE * file, char * buffer)
{
	while(askFile(file,buffer))									// Percorre todas as a��es indicadas no ficheiro (linha a linha)
	{
		executeOption(convertToOption(buffer));					// Executa a a��o
	}
}

/* Pede o nome do ficheiro a ser lido */
char * askFileName(char * buffer)
{
	println(FILENAME_QUESTION);
	println(ENTER_TO_ABORT);
	fflush(stdin);												
	return (askUser(buffer)) ? (strtok(buffer, ENDLINE)) : NULL; 	// � pedido o nome do ficheiro (e devolve NULL caso tenha sido uma resposta vazia)
}

