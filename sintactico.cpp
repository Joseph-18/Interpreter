# include <stdio.h>
# include <string>
using namespace std;

string elementos2[500];
char operadores[8] = {'+','-','*','/','<','>','=','!'};
int finalArray = 0;
char letters[52] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
					'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char numbers[10] = {'0','1','2','3','4','5','6','7','8','9'};
string operators[13] = {"+","-","*","/","<",">","=","!=","<=",">=","==","AND","OR"};
int parentesis = 0;

class Sintactico {
/** Clase en la cual se encuentran los métodos necesarios para comprobar la sintaxis de una expresión.
* Se encuentran N métodos que verifican si los elementos que se encuentran en la expresión son válidos.
*/
public:
	
	bool sintax(string palabra[], int i, int j) {
	/** Método que permite validar si cada posición del arreglo dinámico  
	*
	*/
		if (j > 0){
			if (j+1 < int(sizeof(palabra)/sizeof(palabra[0]))) {
				if (verificarExpresion(palabra, i, j)) {
					return sintax(palabra, j+1, arrayOperator(palabra, j+1));
				}else{
					return false;
				};
			}else{
				return false;
			};
		}else{
			if (j == 0){
				return false;
			}else{
				return verificarExpresion(palabra, i, int(sizeof(palabra)/sizeof(palabra[0])));
			};
		};
	};
	void items(string linea) {
		
		string a;
		for (int i = 0; i < linea.length(); ++i){
			if (linea[i] == '(' || linea[i] == ')' || linea[i] == ' ' || buscarOperator(linea[i])==1){
				elementos2[finalArray] = a;
				finalArray += 1; 
				a = "";
				
				if (linea[i] != ' '){
					a = linea[i];
				};
				if ((linea[i] == '!') || (linea[i] == '<' && i+1<linea.length() && linea[i+1] == '=') || (linea[i] == '>' && i+1<linea.length() && linea[i+1] == '=') || (linea[i] == '=' && i+1<linea.length() && linea[i+1] == '=')){
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
	int buscarOperator(char letter){
		
		for (int i = 0; i < int(sizeof(operadores)/sizeof(numbers[0])); ++i){
			if (letter == operadores[i]){
				return 1;
			};
		};
		return 0;
	};
	bool verificarExpresion(string palabra[], int i, int j) {

		int expr = 0;

		for (int k = i; k < j; ++k) {
			if ((palabra[k] == "NOT")||(palabra[k] == "(")) {
				if (expr > 0) {
					return false;
				};
				if (palabra[k] == "(") {
					 parentesis += 1;
				};
			}else{
				if (ident(palabra[k]) || number(palabra[k])) {
					if (expr > 0) {
						return false;	
					}else{
						expr = 1;
					};
				}else {
					if (palabra[k] == ")") {
						if (expr == 0) {
							return false;
						}else {
							if (parentesis > 0) {
								parentesis -= 1;
							}else {
								return false;
							};
						};
					};
				};
			};
		};
		if (expr == 1) {
			return true;	
		}else{
			return false;
		};
	};
	bool ident(string token) {

		if (inside_letter(token[0]) || token[0] == '_') {
			for (int i = 0; i < token.length(); ++i) {
				if (!inside_letter(token[i]) && !inside_number(token[i]) && token[i] != '_') {
					return false;
				};
			};
		}else{
			return false;
		};
		return true;
	};
	bool number(string num) {

		for (int i = 0; i < num.length(); ++i) {
			if (!inside_number(num[i])) {
				return false;
			};
		};
		return true;
	};
	bool inside_letter(char letter) {

		for (int i = 0; i < int(sizeof(letters)/sizeof(letters[0])); ++i) {
			if (letter == letters[i]) {
				return true;
			};
		};
		return false;
	};
	bool inside_number(char number) {

		for (int i = 0; i < sizeof(numbers); ++i) {
			if (number == numbers[i]) {
				return true;
			};
		};
		return false;
	};
	int arrayOperator(string palabra[], int k) {

		for (int i = k; i < int(sizeof(palabra)/sizeof(palabra[0])); ++i){
			if (inside_operator(palabra[i])) {
				return i;
			};
		};
		return -1;
	};
	bool inside_operator(string operador) {

		for (int i = 0; i < int(sizeof(operators)/sizeof(operators[0])); ++i) {
			if (operador == operators[i]) {
				return true;
			};
		};
		return false;
	};
};