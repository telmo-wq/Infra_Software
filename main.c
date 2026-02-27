#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int contar_matriz(FILE *file){
    int cont_linha = 0;
    int valor;
    while(fscanf(file, "%d", &valor) == 1){
        cont_linha++;
    }
    
    return (int)sqrt(cont_linha);
    
}

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++){
        int num;
        FILE *file = fopen(argv[i], "r");

        int tamanho_matriz = contar_matriz(file);
        printf("%d\n", tamanho_matriz);

        int **matriz = (int **)malloc(tamanho_matriz * sizeof(int *));

        for (int linha = 0; linha < tamanho_matriz; linha++){
            matriz[linha] = (int *)malloc(tamanho_matriz * sizeof(int));
        }

        for (int i = 0; i < tamanho_matriz; i++){
            for (int j = 0; j < tamanho_matriz; j++){
                fscanf(file, "%d", &num);
                matriz[i][j] = num;
            }
        }


        for (int i = 0; i < tamanho_matriz; i++){
            for (int j = 0; j < tamanho_matriz; j++){
                printf("%d ", matriz[i][j]);
            }
            printf("\n");
        }
        
        for (int i = 0; i < tamanho_matriz; i++){
            free(matriz[i]);
        }

        free(matriz);

        fclose(file);
    }

}