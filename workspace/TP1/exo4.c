#include <stdio.h>

typedef unsigned long long TypeEntier;

TypeEntier factorielle(int N) {
    int produit = 1;
    for (int i = 1; i<=N; i++) {
        produit *= i;
    }
    return produit;
}

void affichageFactorielle(void) {
    int N = 0;
    printf("Entrez un nombre entier : ");
    scanf("%d", &N);
    printf("%d! = %lld\n", N, factorielle(N));
}

void calculFactorielles(void) {
    for(int i = 0; i <= 15; i++) {
        printf("%d! = %lld\n", i, factorielle(i));
    }
}

int main (void) {
//    affichageFactorielle();
    calculFactorielles();
    return 0;
}