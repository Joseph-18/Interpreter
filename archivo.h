# include <stdlib.h> 

FILE *doc;
 
int get_file(){
    doc = fopen("Expresiones.txt","r");
	if (doc == NULL) {
		printf("Error al abrir el archivo \n");
		exit (EXIT_FAILURE);
	};
	char *token = (char *)malloc(sizeof(char)*1000);
	char *c;
    do{
 		c = fgets(token, 1000, doc);
        printf("El valor de la linea es: %s\n", c);
    }while(c != NULL);
    fclose(doc);
}
