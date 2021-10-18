#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void freeMatrix(int ***MatrixArray) {
    for (int k = 0; k < sizeof(***MatrixArray); k++) {
        for (int i = 0; i < sizeof(*MatrixArray); i++) {
            for (int n = 0; n < sizeof(**MatrixArray); n++) {
                free(MatrixArray[k][i][n]);
            }
        }
    }
}

int nombreMatrices(void) {
    int nbMatrices;
    scanf("%i", &nbMatrices);
    return nbMatrices;
}

void readMatrix(int **Matrix) {
    int nombreLignes;
    int nombreColonnes;
    scanf("%i %i", &nombreLignes, &nombreColonnes);
    Matrix = calloc(nombreLignes*nombreColonnes, sizeof(int));
    int nombre = 0;
    for (int i = 0; i < nombreLignes; i++) {
        for (int n = 0; n < nombreColonnes; n++) {
            scanf("%i", &nombre);
            Matrix[i][n] = nombre;
        }
    }
}

void readMatrixArray(int ***MatrixArray, int nbMatrices) {
    MatrixArray = calloc(nbMatrices, sizeof(*MatrixArray));
    for (int k = 0; k < nbMatrices; k++) {
        readMatrix(*MatrixArray);
    }
}

void printMatrix(int ***MatrixArray, int nbMatrices) {
    printf("%i\n", nbMatrices);
    int nombre;
    for (int k=0; k < sizeof(***MatrixArray); k++) {
        for (int i = 0; i < sizeof(*MatrixArray); i++) {
            for (int n = 0; n < sizeof(**MatrixArray); n++) {
                nombre = MatrixArray[k][i][n];
                printf("%i ", nombre);
            }
            printf("\n");
        }
    }
}

int main(void) {
    int nbMatrices = nombreMatrices();
    int ***MatrixArray;
    readMatrixArray(***MatrixArray, nbMatrices);
    printMatrix(MatrixArray, nbMatrices);
    freeMatrix(MatrixArray);
    return EXIT_SUCCESS;
}