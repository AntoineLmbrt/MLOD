#include <stdio.h>
#include <stdbool.h>

int sommeDesDivieurs(int N) {
    int somme = 0;
    for (int i = 1; i < N; i++) {
        if (N%i == 0) {
            somme += i;
        }
    }
    return somme;
}

bool estNombreParfait(int N) {
    return N == sommeDesDivieurs(N);
}

void affichageNombresParfait(int N) {
    for (int n = 1; n <= N; n++) {
        if(estNombreParfait(n)) {
            printf("%d est parfait\n", n);
        }
    }
}

int main(void) {
    int N = 0;
    printf("Entrez un nombre entier : ");
    scanf("%d", &N);
    affichageNombresParfait(N);
}