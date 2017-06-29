#include "io_file.h"

/* Serve para pedir um conjunto (infinito) de opções por parte do utilizador */
void askOptionsFile(FILE * file, char * buffer)
{
	while(ask(file,buffer))									// Percorre todas as ações indicadas no ficheiro (linha a linha)
	{
		executeOption(convertToOption(buffer));						// Executa a ação
	}
}

/* Serve para pedir um conjunto de opções através do ficheiro */
char * askFileName(char * buffer)
{
	print(FILENAME_QUESTION);										 //
	fflush(stdin);													 //
	return (ask(stdin,buffer))? (strtok(buffer, "\n")) : NULL; // É pedido o nome do ficheiro (e devolve NULL caso tenha sido uma resposta vazia)
}
void readFile(char * buffer)
{
	// É pedido o nome do ficheiro a ser lido
	//
	// Caso a resposta tenha sido vazia
	// (caso não se pretenda ler um ficheiro)
	// Não é feito mais nada
	if(!askFileName(buffer))
		print(FILE_LOADING_ABORT);								// Mensagem de erro
	
	// Caso contrário
	else
	{
		print(FILE_LOADING);
		FILE * fp = fopen(buffer,READ);							// É aberto o ficheiro
		
		// Caso não exista esse ficheiro
		// (ou outro tipo de erro ao abrir o ficheiro)
		if(!fp)
			print(FILE_LOADING_ERROR);							// Mensagem de erro
		
		// Caso contrário,
		// são lidas e executadas cada ação indicada no ficheiro
		else
		{
			askOptionsFile(fp,buffer);							// São refeitas as ações indicadas no ficheiro (uma a uma)
			fclose(fp);											// É fechado o ficheiro
			
			print(FILE_LOADING_COMPLETE);
		}
	}
}