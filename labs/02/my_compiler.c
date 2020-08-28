#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){

    int parentesis = 0;
    int corchetes = 0;
    int llaves = 0;
    int comillasSimples = 0;
    int comillasDobles = 0;

    int error = 0;

    char *linea = NULL;
    size_t line_buf_size = 0;
    ssize_t tamanoLinea = 0;
    FILE *fp = fopen(argv[1], "r");
    if (!fp){
        fprintf(stderr, "Error al abrir el archivo: '%s. '\n", argv[1]);
        return 0;
    }
    tamanoLinea = getline(&linea, &line_buf_size, fp);
    while (tamanoLinea >= 0){
        for (int i = 0; i < tamanoLinea; i++){
            if (linea[i] == '/' && linea[i+1] == '/'){
                break;
            } else {
                if (linea[i] == '{'){
                    llaves += 1;
                }
                if (linea[i] == '}'){
                    llaves -= 1;
                }

                if (linea[i] == '['){
                    corchetes += 1;
                }
                if (linea[i] == ']'){
                    corchetes -= 1;
                }

                if (linea[i] == '('){
                    parentesis += 1;
                }
                if (linea[i] == ')'){
                    parentesis -= 1;
                }

                if (linea[i] == '"'){
                    comillasDobles += 1;
                }

                if (linea[i] == ("%c",39)){
                    comillasSimples += 1;
                }
            }
        }
        tamanoLinea = getline(&linea, &line_buf_size, fp);
    }

    if (llaves != 0){
        printf("Tienes %d llaves sin cerrar.\n", abs(llaves));
        error = 1;
    }
    if (corchetes != 0){
        printf("Tienes %d corchetes sin cerrar\n", abs(corchetes));
        error = 1;
    }
    if (parentesis != 0){
        printf("Tienes %d parentesis sin cerrar.\n", abs(parentesis));
        error = 1;
    }
    if (comillasDobles % 2 != 0){
        printf("Tienes comillas dobles sin cerrar.\n");
        error = 1;
    }
    if (comillasSimples % 2 != 0){
        printf("Tienes comillas simples sin cerrar.\n");
        error = 1;
    }
    if (error == 0){
        printf("El programa no cuenta con errores, bien hecho! \n");
    }


}