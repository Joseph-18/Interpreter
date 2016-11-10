# include <stdio.h>
# include <string>
using namespace std;

char elementos[77] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
					'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
					'0','1','2','3','4','5','6','7','8','9','_','(',')',
					'=','+','-','*','/','<','>','!','\\',' '};


class Lexico {

public:
	bool lex(string linea) {

		bool logic = true;
		for (int i = 0; i < linea.length(); ++i) {
			if (logic == true){
				logic = inputElement(linea, i);
			}else {
				return logic;
			};
		};
		return logic;
	};
	bool inputElement(string linea, int i) {
		if (buscarElement(char(linea[i]))== 1) {
			if (linea[i] == '!') {
				if (i+1 < linea.length()-1) {
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
					if (i+1 < linea.length()-1) {
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

		for (int i = 0; i < 77; ++i) {
			if (letter == elementos[i]){
				return 1;
			}else {
				return 0;
			};
		};
	};

};