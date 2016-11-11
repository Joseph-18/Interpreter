# include <stdio.h>
# include <string>
using namespace std;

// Arreglo de todos los caracteres posibles que pueden haber en una expresion.
char elementos[77] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
					'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
					'0','1','2','3','4','5','6','7','8','9','_','(',')',
					'=','+','-','*','/','<','>','!','\\',' '};
class Lexico {
/** Clase en la cual se encuentran los metodos necesarios para comprobar el lexico de una expresion.
* Se encuentran 3 metodos que verifican si los elementos que se encuentran en la expresion son validos.
*/

public:
	bool lex(string linea) {
	/** Metodo que toma una varible de tipo cadena y verifica que todos sus caracteres sean validos para una expresion.
	* @param linea de tipo String 
	* @return un booleano que significa si los caracteres en la expresion son validos o no.
	*/

		bool logic = true;
		for (int i = 0; i < linea.length(); ++i) {
			if (logic == true){
				logic = inputElement(linea, i);
				//printf("%d\n", logic);
			}else {
				return logic;
			};
		};
		return logic;
	};
	bool inputElement(string linea, int i) {
		/** Metodo que vefica los caracteres especiales que contienen 2 caracteres.
		* @param linea de tipo string e un indice.
		* @return un booleano verificando elementos multivaluados.
		*/
		//printf("%d\n", buscarElement(char(linea[i])));
		if (buscarElement(char(linea[i]))== 1) {
			if (linea[i] == '!') {
				if (i+1 < linea.length()) {
					if (linea[i+1] == '=') {
						return true;
					}else{
						return false;
					};
				}else {
					return false;
				};
			}else {
				if (linea[i] == '\\') {
					if (i+1 < linea.length()) {
						if (linea[i+1] == 't' || linea[i+1] == 'n' || linea[i+1] == 'r' || linea[i+1] == 'f') {
							return true;
						}else{
							return false;
						};
					}else {
						return false;
					};
				};
			};
		}else{
			return false;
		};
		return true;
	};
	int buscarElement(char letter) {
		/** Metodo que verifica si existe un caracter en los elementos validos.
		* @param letter de tipo char, letra que se va a buscar.
		* @return un integer, diciendo si es valido o no.
		*/
		for (int i = 0; i < 77; ++i) {
			if (letter == elementos[i]){
				return 1;
			};
		};
		return 0;
	};
};