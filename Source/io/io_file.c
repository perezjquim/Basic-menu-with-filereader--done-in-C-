#include "io_file.h"

/* Serve para pedir um conjunto (infinito) de op��es por parte do utilizador */
void askOptionsFile(FILE * file, char * buffer)
{
	while(ask(file,buffer))									// Percorre todas as a��es indicadas no ficheiro (linha a linha)
	{
		executeOption(convertToOption(buffer));						// Executa a a��o
	}
}

/* Serve para pedir um conjunto de op��es atrav�s do ficheiro */
char * askFileName(char * buffer)
{
	print(FILENAME_QUESTION);										 //
	fflush(stdin);													 //
	return (ask(stdin,buffer))? (strtok(buffer, "\n")) : NULL; // � pedido o nome do ficheiro (e devolve NULL caso tenha sido uma resposta vazia)
}
void readFile(char * buffer)
{
	// � pedido o nome do ficheiro a ser lido
	//
	// Caso a resposta tenha sido vazia
	// (caso n�o se pretenda ler um ficheiro)
	// N�o � feito mais nada
	if(!askFileName(buffer))
		print(FILE_LOADING_ABORT);								// Mensagem de erro
	
	// Caso contr�rio
	else
	{
		print(FILE_LOADING);
		FILE * fp = fopen(buffer,READ);							// � aberto o ficheiro
		
		// Caso n�o exista esse ficheiro
		// (ou outro tipo de erro ao abrir o ficheiro)
		if(!fp)
			print(FILE_LOADING_ERROR);							// Mensagem de erro
		
		// Caso contr�rio,
		// s�o lidas e executadas cada a��o indicada no ficheiro
		else
		{
			askOptionsFile(fp,buffer);							// S�o refeitas as a��es indicadas no ficheiro (uma a uma)
			fclose(fp);											// � fechado o ficheiro
			
			print(FILE_LOADING_COMPLETE);
		}
	}
}