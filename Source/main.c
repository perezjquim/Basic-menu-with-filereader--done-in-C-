#include "io_general.h"
#include "io_file.h"

/***** MAIN *****/
int main()
{
	char buffer[BUFFER_SIZE];									// Buffer usado em todo o programa (para o input)
	
	readFile(buffer);											// � lido o ficheiro (caso seja o pretendido)
	askOptionsUser(buffer);										// S�o efetuadas as a��es pedidas pelo utilizador
	
	return 0;													// Fim do programa
}