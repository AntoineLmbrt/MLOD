#include <stdio.h>

enum Mois {janvier = 1, fevrier, mars, avril, mai, juin, juillet, aout, septembre, octobre, novembre, decembre};

typedef enum Mois Mois;

struct Date {
    int jour;
    Mois mois;
    int annee;
};

typedef struct Date Date;

void initialiseDate(Date *d) {
    printf("Entrez le jour : ");
    scanf("%i", &d->jour);
    printf("Entrez le mois : ");
    scanf("%i", (int*)&d->mois);
    printf("Entrez l'année : ");
    scanf("%i", &d->annee);
}

Date creerDateParCopie() {
    Date d;
    printf("Entrez le jour : ");
    scanf("%i", &d.jour);
    printf("Entrez le mois : ");
    scanf("%i", (int*)&d.mois);
    printf("Entrez l'année : ");
    scanf("%i", &d.annee);
    return d;
}

Date *newDate() {
    Date *d = (Date *)malloc(sizeof(Date));
    printf("Entrez le jour : ");
    scanf("%i", &d->jour);
    printf("Entrez le mois : ");
    scanf("%i", (int*)&d->mois);
    printf("Entrez l'année : ");
    scanf("%i", &d->annee);
    return d;
}

void afficheDate(Date *d) {
    char *Mois;
    switch (d->mois) {
        case 1:
            Mois = "janvier";
            break;
        case 2:
            Mois = "février";
            break;
        case 3:
            Mois = "mars";
            break;
        case 4:
            Mois = "avril";
            break;
        case 5:
            Mois = "mai";
            break;
        case 6:
            Mois = "juin";
            break;
        case 7:
            Mois = "juillet";
            break;
        case 8:
            Mois = "août";
            break;
        case 9:
            Mois = "septembre";
            break;
        case 10:
            Mois = "octobre";
            break;
        case 11:
            Mois = "novembre";
            break;
        case 12:
            Mois = "décembre";
            break;
    }
    printf("%i %s %i\n", d->jour, Mois, d->annee);
}

int main(void) {

    // MÉTHODE 1
    // Date d;
    // initialiseDate(&d); // RÉPONSE QUESTION (b) :
    // afficheDate(&d);

    // MÉTHODE 2
    // RÉPONSE QUESTION (e) : Cette version creerDateParCopie ne devrait pas être utilisée car le fait de copier la date utilise deux fois plus de mémoire.
    // Date d;
    // d = creerDateParCopie();
    // afficheDate(&d);

    // MÉTHODE 3
    Date *date;
    date = newDate();
    afficheDate(date);
    free(date);

    return 0;
}