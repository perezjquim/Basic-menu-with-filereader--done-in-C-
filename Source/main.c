#include "io/io_general.h"
#include "io/io_file.h"
#include "io/login.h"

/***** MAIN *****/
int main()
{	
	char buffer[BUFFER_SIZE];									// Buffer usado em todo o programa (para o input)
	
	doLogin(buffer);
	
	readFile(buffer);											// � lido o ficheiro (caso seja o pretendido)
	askOptionsUser(buffer);										// S�o efetuadas as a��es pedidas pelo utilizador
	
	return 0;													// Fim do programa
}