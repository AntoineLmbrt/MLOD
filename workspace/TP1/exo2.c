#include <stdio.h>

void affichageDes(int N) {
    for(int numero_un = 1; numero_un <= 6; numero_un++) {
        for(int numero_deux = 1; numero_deux <= 6; numero_deux++) {
            for(int numero_trois = 1; numero_trois <= 6; numero_trois++) {
                if(N == numero_un + numero_deux + numero_trois) {
                    printf("%d %d %d\n", numero_un, numero_deux, numero_trois);
                }
            }
        }
    }
}

int main(void){
    affichageDes(4);
    return 0;
}