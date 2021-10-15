/**
 Compilation
 gcc --std=c99 -W -Wall -o prixTuring prixTuring.c

 Exécution
 ./prixTuring < turingWinners.txt > out.txt

 Tests
 diff out.txt turingWinners.txt

 Détection de fuites mémoires
 valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all --show-reachable=no ./prixTuring < turingWinners.txt > out.txt
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* This function scans a line of text (until \n) and returns a char* that contains all characters on the line (up to 255) excluding \n.
It also ensures the \0 termination.
**WARNING**: The result of this function has been allocated (calloc) by the function */
char* scanLine()
{
	int maxLineSize = 255;
	char c, *line = calloc(maxLineSize+1,sizeof(char));

	scanf("%250[^\n]", line);

	if ( (c = getchar()) != '\n') {
		/* we did not get all the line */
		line[250] = '[';
		line[251] = line[252] = line[253] = '.';
		line[254] = ']';
		// line[255] = '\0'; // useless because already initialized by calloc

		// let's skip all chars untli the end of line
		while (( (c = getchar()) != '\n') && c != EOF) ;
	}

	return line;
}

/* This function scans a line of text (until \n), converts it as an integer and returns this integer */
int scanLineAsInt() {
	int buf;
	scanf("%i\n",&buf);
	return buf;
}

struct TuringWinner {
	int annee;
	char *nom;
	char *commentaire;
};

typedef struct TuringWinner TuringWinner;

void readWinners(TuringWinner **Winner, int nombreGagnants) {
	*Winner = (TuringWinner *)calloc(nombreGagnants, sizeof(TuringWinner));
	for (int i = 0; i < nombreGagnants; i++) {
		(*Winner)[i].annee = scanLineAsInt();
		(*Winner)[i].nom = scanLine();
		(*Winner)[i].commentaire = scanLine();
	}
}

void printWinners(TuringWinner *Winner, int nombreGagnants) {
	printf("%i\n", nombreGagnants);
	for (int i = 0; i < nombreGagnants; i++) {
		printf("%i\n", Winner[i].annee);
		printf("%s\n", Winner[i].nom);
		printf("%s\n", Winner[i].commentaire);
	}
}

void infoAnnee(TuringWinner *Winner, int nombreGagnants, int annee) {
	for (int i = 0; i < nombreGagnants; i++) {
		if (Winner[i].annee == annee) {
			printf("L'année %i, le(s) gagnant(s) ont été: %s\nNature des travaux : %s\n", Winner[i].annee, Winner[i].nom, Winner[i].commentaire);
		}
	}
}

int main(int argc, char *argv[]){
	// int nbGagnants = scanLineAsInt();
	// printf("nbGagnants = %i\n",nbGagnants);

	int nbGagnants = scanLineAsInt();
	TuringWinner *Winner;
	readWinners(&Winner, nbGagnants);

	if (argc != 0 && (strcmp(argv[1], "infoAnnee")) == 0) {
		int annee;
		sscanf(argv[2], "%i", &annee);
		infoAnnee(Winner, nbGagnants, 2003);
	}
	else {
		printWinners(Winner, nbGagnants);
	}

	free(Winner);

	return EXIT_SUCCESS;
}
