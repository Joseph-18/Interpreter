# include <stdlib.h>
# include <fstream>
using namespace std;

void get_file() {
	char expresion[500];
	ifstream fe("Expresiones.txt");
	while(fe.peek() != EOF) {
		fe.getline(expresion, 500);
		printf("%s\n", expresion);
	}
}