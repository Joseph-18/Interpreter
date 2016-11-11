# include <stdlib.h>
# include <fstream>
# include "lexico.cpp"
# include "sintactico.cpp"
using namespace std;

/** Archivo de cabecera para leer un archivo .txt.
* Se carga el archivo lexico.cpp para verificar el lexico de la expresion.
*/

int get_file() {
	/** Metodo que lee un archivo .txt y extrae los datos linea por linea verificando que este
	* lexicamente correcto.
	*/
	char linea[500];
	ifstream fe("Expresiones.txt");
	int j=0;
	Lexico obj1;
	Sintactico obj2;
	while(fe.peek() != EOF) {
		fe.getline(linea, 500);
		j=j+1;
		if (obj1.lex(string(linea)) == false) {
			printf("LINEA %i: Error léxico/de sintaxis\n", j);
			return (0);
		}else{
			/*obj2.items(string(linea));
			if (obj2.sintax(elementos2,0,obj2.arrayOperator(elementos2,0)) == false) {
				printf("LINEA %i: Error léxico/de sintaxis\n", j);
			}else{
				//instruciones para la semantica
			};*/
		};
		//printf("%d\n", obj1.lex(string(linea)));
	};
};