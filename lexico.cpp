# include <cstring>
# include <stdio.h>
using namespace std;

char elementos [27] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int digits[10] = {0,1,2,3,4,5,6,7,8,9};

class Lexico {

public:

	bool lex(string linea) {

		bool logic = true;
		for (int i = 0; i < linea.length; ++i) {
			if (logic == true){
				logic = inputElement(linea, i);
			}else {
				return logic;
			};
		};
		return logic;
	};
	bool inputElement(string linea, int i) {
		if (buscarElement(linea[i])== 1) {
			if (linea[i] == '!') {
				if (i+1 < linea.length-1) {
					if (linea[i+1] == '=') {
						return true;
					}else{
						return false;
					};
				}else {
					return false;
				};
			}else {
				if (linea[i] == '\\')
				{
					if (i+1 < linea.length-1) {
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
	};
	int buscarElement(char letter) {

		for (int i = 0; i < elementos.lenght; ++i) {
			if (letter == elementos[i]){
				return 1;
			}else {
				return 0;
			};
		};
	};
	/*bool ident(char *word) {

		int i;
		if ((inside(word[0])) || (word[0] == '_')) {
			for (i = 0; i < word.length; ++i) {
				if ((!inside_letter(word[i])) && (!inside_digit(int(word[i]))) && (word[i] != '_')) {
					return false;
				};
			};
		} else {
			return false;
		};
		return true;
	};
	bool inside_letter(char letter) {

		for (int i = 0; i < letters.length; ++i) {
			if (letter == letters[i]) {
				return true;
			};
		};
		return false;
	};
	bool inside_digit(int digit) {

		for (int i = 0; i < digits.length; ++i) {
			if (digit == digits[i]) {
				return true;
			};
		};
		return false;
	};*/

};