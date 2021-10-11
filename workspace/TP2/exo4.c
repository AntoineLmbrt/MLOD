#include <stdio.h>

enum Mois {janvier = 1, fevrier, mars, avril, mai, juin, juillet, aout, septembre, octobre, novembre, decembre};

struct Date {
    int jour;
    enum Mois mois;
    int annee;
};

typedef enum Mois Mois;
typedef struct Date Date;

void initialiseDate(Date *d) {
    printf("Entrez le jour : ");
    scanf("%i", &d->jour);
    printf("Entrez le mois : ");
    scanf("%i", (int *)&d->mois);
    printf("Entrez l'année : ");
    scanf("%i", &d->annee);
}

void afficheDate(Date *d) {
    char *Mois;
    switch (d->mois) {
        case 1:
            Mois = "janvier";
        case 2:
            Mois = "février";
        case 3:
            Mois = "mars";
        case 4:
            Mois = "avril";
        case 5:
            Mois = "mai";
        case 6:
            Mois = "juin";
        case 7:
            Mois = "juillet";
        case 8:
            Mois = "aout";
        case 9:
            Mois = "septembre";
        case 10:
            Mois = "octobre";
        case 11:
            Mois = "novembre";
        case 12:
            Mois = "décembre";
    }
}

int main(void) {
    Date d;
    initialiseDate(&d);
    afficheDate(&d);
    return 0;
}