#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void mult_matrice(int64_t result[5][5], int64_t a[5][5], int64_t b[5][5]) {
    // RÉPONSE QUESTION (b) : Cette fonction n'est pas intéressante puisqu'elle nécessite que les matrices carrées qu'on multiplie soient de taille 5.
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            result[i][j] = 0;
            for(int n = 0; n < 5; n++) {
                result[i][j] += a[i][n]*b[n][j];
            }
        }
    }
}

void mult_matrice_taille_n(int64_t **result, int64_t **A, int64_t **B) {
    int tailleLigneA = sizeof(A[0]);
    int tailleColonneA = sizeof(A);
    int tailleLigneB = sizeof(B);
    int tailleColonneB = sizeof(B[0]);
    if (tailleLigneA != tailleColonneB) {
        printf("Multiplication des matrices impossibles, veuillez vérifier les tailles.");
    }
    for(int i = 0; i < tailleLigneA; i++) {
        for(int j = 0; j < tailleColonneB; j++) {
            int x = 0;
            for(int n = 0; n < tailleLigneB; n++) {
                x += A[i][n]*B[n][j];
            }
        result[i][j] = x;
        }
    }
}

void affiche_matrice(int64_t result[5][5]) {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            printf("%ld ", result[i][j]);
        }
        printf("\n");
    }
}

void affiche_matrice_taille_n(int64_t **result) {
    int tailleLigne = sizeof(result);
    int tailleColonne = sizeof(result);
    for(int i = 0; i < tailleLigne; i++) {
        for(int j = 0; j < tailleColonne; j++) {
            printf("%ld ", result[i][j]);
        }
        printf("\n");
    }
}

//
int main(void) {
    //matrices en ligne * colonne
    int64_t matrice1[5][5]={{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
    int64_t matrice2[5][5]={{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10}};
    int64_t matrice3[3][2]={{1,2},{3,4},{5,6}};
    int64_t matrice4[4][3]={{1,2,3},{1,2,3,},{1,2,3},{1,2,3}};
    // int64_t matriceResultat[5][5];
    int64_t **matriceResultatBis;
    // mult_matrice(matriceResultat,matrice1,matrice2);
    mult_matrice_taille_n(**matriceResultatBis, **matrice3, **matrice4);
    // affiche_matrice(matriceResultat);
    affiche_matrice_taille_n(matriceResultatBis);
    return EXIT_SUCCESS;
}

