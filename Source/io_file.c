#include "io_file.h"

/* Serve para pedir um conjunto (infinito) de op��es por parte do utilizador */
void askOptionsFile(FILE * file, char * buffer)
{
	while(askOption(file,buffer))
	{
		executeOption(convertToOption(buffer));
	}
}

/* Serve para pedir um conjunto de op��es atrav�s do ficheiro */
void askFileName(char * buffer)
{
	print(FILENAME_QUESTION);						//
	fflush(stdin);														//
	askOption(stdin,buffer);
	strtok(buffer, "\n");											//
}
void readFile(char * buffer)
{
	askFileName(buffer);						// � pedido o nome do ficheiro a ser lido
	
	// Caso a resposta tenha sido vazia
	// (caso n�o se pretenda ler um ficheiro)
	if(isBufferEmpty(buffer))
		print(FILE_LOADING_ABORT);
	
	// Caso contr�rio
	else
	{
		print(FILE_LOADING);
		FILE * fp = fopen(buffer,READ);							// � aberto o ficheiro
		
		// Caso n�o exista esse ficheiro
		// (ou outro tipo de erro ao abrir o ficheiro)
		if(!fp)
			print(FILE_LOADING_ERROR);
		
		// Caso contr�rio,
		// s�o lidas e executadas cada a��o indicada no ficheiro
		else
		{
			askOptionsFile(fp,buffer);
			fclose(fp);											// � fechado o ficheiro
			
			print(FILE_LOADING_COMPLETE);
		}
	}
}