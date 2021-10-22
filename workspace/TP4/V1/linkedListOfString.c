#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// FONCTIONS EXTERNES

void afficheElement(Element e) {
    printf("%s", (char *)e);
}

void detruireElement(Element e) {}

bool equalsElement(Element e1, Element e2) {
    return strcomp((char *)e1, (char *)e2)==0;
}

// MAIN

int main(void) {
    Liste l;

	l = NULL;
	printf("estVide(l) = %s\n",estVide(l)?"TRUE":"FALSE");

	l = ajoutTete("!",l);
	l = ajoutTete("!",l);
	l = ajoutTete("!",l);
	l = ajoutTete("Jedi",l);
	l = ajoutTete("est",l);
	l = ajoutTete("un",l);
	l = ajoutTete("Luke",l);

	afficheListe_i(l);

	detruire_r(l);

	return EXIT_SUCCESS;
}