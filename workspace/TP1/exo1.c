#include <stdio.h>

float calculBillet(float prix_plein_tarif, int age) {
    if (age>12)
        return prix_plein_tarif;
    else if (age>2)
        return prix_plein_tarif*0.5;
    else
        return prix_plein_tarif*0.1;
}

#define PRIX_PLEIN_TARIF 75.99
#define AGE 5

int main(void) {
    float prix_billet = calculBillet(PRIX_PLEIN_TARIF, AGE);
    printf("Le prix du billet est: %f€\n", prix_billet);
    return 0;
}