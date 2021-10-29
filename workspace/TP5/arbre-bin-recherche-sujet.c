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
int nombreDeNoeud(ArbreBinaire a){
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
	int hauteurGauche;
	int hauteurDroit;
	if (estVide(a)) {
		return 0;
	}
	hauteurGauche = hauteur(a->filsGauche);
	hauteurDroit = hauteur(a->filsDroit);
	if (hauteurGauche > hauteurGauche) {
		return 1 + hauteurGauche;
	}
	return 1 + hauteurDroit;	
}

// retourne le pere de elem dans l'arbre a ou NULL s'il n'existe pas
ArbreBinaire pere(ArbreBinaire a, Element elem){

	return NULL;
}


void afficheRGD_r(ArbreBinaire a){
	if (!estVide(a)) {
		printf("%i ", a->val);
		afficheGRD_r(a->filsGauche);
		afficheGRD_r(a->filsDroit);
	}
}

void afficheGRD_r(ArbreBinaire a){
	if (!estVide(a)) {
		afficheGRD_r(a->filsGauche);
		printf("%i ", a->val);
		afficheGRD_r(a->filsDroit);
	}
}

void afficheGDR_r(ArbreBinaire a){
	if (!estVide(a)) {
		afficheGRD_r(a->filsGauche);
		afficheGRD_r(a->filsDroit);
		printf("%i ", a->val);
	}
}

// retourne le noeud dont la valeur est minimum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire min(ArbreBinaire a){
	while (!estVide(a->filsGauche)) {
		a = a->filsGauche;
	}
	return a;
}

// retourne le noeud dont la valeur est maximum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire max(ArbreBinaire a){
	while (!estVide(a->filsDroit)) {
		a = a->filsDroit;
	}
	return a;
}


// retourne l'arbre dont la valeur de la racine est elem et NULL si elem n'existe dans a 
// version récursive
ArbreBinaire recherche_r(ArbreBinaire a, Element elem){

	return NULL;
}


// suppime x de a
ArbreBinaire supprimer_r(ArbreBinaire a,Element x)
{

	return NULL;
}

void detruire_r(ArbreBinaire a){

}

