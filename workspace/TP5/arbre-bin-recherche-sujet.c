#include "arbre-bin-recherche.h"
#include <stdlib.h>
#include <stdbool.h>

// retourne TRUE si a est l'arbre vide et FALSE sinon
bool estVide(ArbreBinaire a) {
	return a == NULL;
}

// initialise l'arbre a à l'arbre vide
void initialiser(ArbreBinaire* a) {
	(*a) = NULL;
}

// créer un arbre contenant un seul noeud ayant la valeur e
ArbreBinaire creer(Element e) {
	ArbreBinaire a;
	initialiser(&a);
	a = (ArbreBinaire) malloc(sizeof(Noeud));
	a->val = e;
	return a;
}

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version itérative
ArbreBinaire insere_i(ArbreBinaire a, Element e) {
	ArbreBinaire temp = a;
	if (estVide(a)) {
		return creer(e);
	}
	while (!estVide(temp)) {
		if (temp->val == e) {
			return a;
		}
		if (e < temp->val) {
			if (estVide(temp->filsGauche)) {
				temp->filsGauche = creer(e);
			}
			temp = temp->filsGauche;
		}
		if (e > temp->val) {
			if (estVide(temp->filsDroit)) {
				temp->filsDroit = creer(e);
			}
			temp = temp->filsDroit;
		}
	}
	return a;
}	

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version récursive
ArbreBinaire insere_r(ArbreBinaire a, Element e) {
	ArbreBinaire temp = a;
	if (estVide(a)) {
		return creer(e);
	}
	if (e < temp->val) {
		a->filsGauche = insere_r(temp->filsGauche, e);
	}
	if (e > temp->val) {
		a ->filsDroit = insere_r(temp->filsDroit, e);
	}		
	return a;
}

// retourne le nombre de noeud contenus dans l'arbre a
int nombreDeNoeud(ArbreBinaire a) {
	if (estVide(a)) {
		return 0;
	}
	return 1 + nombreDeNoeud(a->filsGauche) + nombreDeNoeud(a->filsDroit);
}


// retourne la profondeur du noeud ayant la valeur e dans a
// retourne -1 si a est vide ou si e n'est pas dans a
int profondeur(ArbreBinaire a, Element e) {
	ArbreBinaire temp = a;
	int profondeur = 0;
	while (!estVide(a)) {
		if (e == a->val) {
			return profondeur;
		}
		if (e < temp->val) {
			profondeur++;
			a = a->filsGauche;
		}
		if (e > temp->val) {
			profondeur++;
			a = a->filsDroit;
		}	
	}
	return -1;
}

// retourne la hauteur de l'arbre a
int hauteur(ArbreBinaire a) {
	if (estVide(a)) {
		return 0;
	}
	if (hauteur(a->filsGauche) > hauteur(a->filsDroit)) {
		return 1 + hauteur(a->filsGauche);
	}
	return 1 + hauteur(a->filsDroit);	
}

// retourne le pere de elem dans l'arbre a ou NULL s'il n'existe pas
ArbreBinaire pere(ArbreBinaire a, Element elem) {
	if (estVide(a) || a->val == elem) {
		return NULL;
	}
	if (a->val > elem) {
		if (!estVide(a->filsGauche)) {
			if (a->filsGauche->val == elem) {
				return a;
			}
			return pere(a->filsGauche, elem);

		}
	} else {
		if (!estVide(a->filsDroit)) {
			if (a->filsDroit->val == elem) {
				return a;
			}
			return pere(a->filsDroit, elem);
		}
	}
	return NULL;
}


void afficheRGD_r(ArbreBinaire a) {
	if (!estVide(a)) {
		printf("%i ", a->val);
		afficheGRD_r(a->filsGauche);
		afficheGRD_r(a->filsDroit);
	}
}

void afficheGRD_r(ArbreBinaire a) {
	if (!estVide(a)) {
		afficheGRD_r(a->filsGauche);
		printf("%i ", a->val);
		afficheGRD_r(a->filsDroit);
	}
}

void afficheGDR_r(ArbreBinaire a) {
	if (!estVide(a)) {
		afficheGRD_r(a->filsGauche);
		afficheGRD_r(a->filsDroit);
		printf("%i ", a->val);
	}
}

// retourne le noeud dont la valeur est minimum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire min(ArbreBinaire a) {
	while (!estVide(a->filsGauche)) {
		a = a->filsGauche;
	}
	return a;
}

// retourne le noeud dont la valeur est maximum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire max(ArbreBinaire a) {
	while (!estVide(a->filsDroit)) {
		a = a->filsDroit;
	}
	return a;
}


// retourne l'arbre dont la valeur de la racine est elem et NULL si elem n'existe dans a 
// version récursive
ArbreBinaire recherche_r(ArbreBinaire a, Element elem) {
	if (estVide(a)) {
		return NULL;
	}
	if (a->val == elem) {
		return a;
	}
	else if (a->val > elem) {
		return recherche_r(a->filsGauche, elem);
	} else {
		return recherche_r(a->filsDroit, elem);
	}
	return NULL;
}


// suppime x de a
ArbreBinaire supprimer_r(ArbreBinaire a,Element x) {

	ArbreBinaire temp;

	if (estVide(a)) {
		return a;
	}

	if (a->val > x) {
		a->filsGauche = supprimer_r(a->filsGauche, x);
	}
	if (a->val < x) {
		a->filsDroit = supprimer_r(a->filsDroit, x);
	}

	if (a->val == x) {
		if (estVide(a->filsGauche)) {
			temp = a->filsDroit;
			free(a);
			a = NULL;
			return temp;
		}
		else if (estVide(a->filsDroit)) {
			temp = a->filsGauche;
			free(a);
			a = NULL;
			return temp;
		}
		temp = max(a->filsGauche);
		a->val = temp->val;
		a->filsGauche = supprimer_r(a->filsGauche, temp->val);
	}
	return a;
}

void detruire_r(ArbreBinaire a) {
	if (!estVide(a)) {
		detruire_r(a->filsGauche);
		detruire_r(a->filsDroit);
		free(a);
		a = NULL;
	}
}

