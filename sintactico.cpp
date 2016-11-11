# include <stdio.h>
# include <string>
using namespace std;

string elementos2[]={""};
char operadores[8]={'+','-','*','/','<','>','=','!'};
int finalArray = 0;


class Sintactico {
/** Clase en la cual se encuentran los métodos necesarios para comprobar la sintaxis de una expresión.
* Se encuentran N métodos que verifican si los elementos que se encuentran en la expresión son válidos.
*/
public:
	
	void Items(string linea){
		
		string a;
		
		for (int i = 0; i < linea.length(); ++i){
			if (linea[i] == '(' || linea[i] == ')' || linea[i] == ' ' || BuscarOperator(linea[i])==1){
				elementos2[finalArray] = a;
				finalArray += 1; 
				a = "";
				
				if (linea[i] != ' '){
					a = linea[i];
				};

				if ((linea[i] == '!') || (linea[i] == '<' && i+1<linea.length()-1 && linea[i+1] == '=') || (linea[i] == '>' && i+1<linea.length()-1 && linea[i+1] == '=') || (linea[i] == '=' && i+1<linea.length()-1 && linea[i+1] == '=')){
					a += linea[i+1];
					i += 2;
					elementos2[finalArray] = a;
					finalArray += 1; 
				};
			
			}else{

				a += linea[i];
			};
		};
	};

	bool Sintax(string linea){
		int expr;

		if (linea != ''){
			for (int i = 0; i < sizeof(elementos2)/4; ++i){
				
			};
		};	
	};
	
	int BuscarOperator(char letter){
		
		for (int i = 0; i < 8; ++i){
			if (letter == operadores[i]){
				return 1;
			}
		}
		return 0;

	};
	
	
};
