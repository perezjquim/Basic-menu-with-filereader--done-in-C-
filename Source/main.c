#include "io.h"

/***** MAIN *****/
int main()
{
	char buffer[BUFFER_SIZE];											// Buffer usado em todo o programa (para o input)
	
	readFile(buffer);											// � lido o ficheiro (caso seja o pretendido)
	askUser(buffer);											// S�o efetuadas a��es pedidas pelo utilizador
	
	return 0;													// Fim do programa
}