# include <stdlib.h>
# include <fstream>
# include "lexico.cpp"

using namespace std;

void get_file() {
	char linea[500];
	ifstream fe("Expresiones.txt");
	while(fe.peek() != EOF) {
		fe.getline(linea, 500);
		Lexico obj1;
		//obj1.lex(string(linea));
		printf("%d\n", obj1.lex(string(linea)));
	};
};