#include "io_file.h"

/* Serve para pedir um conjunto (infinito) de opções por parte do utilizador */
void askOptionsFile(FILE * file, char * buffer)
{
	while(askOption(file,buffer))
	{
		executeOption(convertToOption(buffer));
	}
}

/* Serve para pedir um conjunto de opções através do ficheiro */
void askFileName(char * buffer)
{
	print(FILENAME_QUESTION);						//
	fflush(stdin);														//
	askOption(stdin,buffer);
	strtok(buffer, "\n");											//
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
		FILE * fp = fopen(buffer,READ);							// É aberto o ficheiro
		
		// Caso não exista esse ficheiro
		// (ou outro tipo de erro ao abrir o ficheiro)
		if(!fp)
			print(FILE_LOADING_ERROR);
		
		// Caso contrário,
		// são lidas e executadas cada ação indicada no ficheiro
		else
		{
			askOptionsFile(fp,buffer);
			fclose(fp);											// É fechado o ficheiro
			
			print(FILE_LOADING_COMPLETE);
		}
	}
}