#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getLine(char *line, FILE* fichierEntree, FILE* fichierSortie) {
    int maxLineSize = 255;
    *fgets(*line, maxLineSize, fichierEntree);
    fprintf(FILE, )

}

void printCaracter(FILE* fichierEntree, FILE* fichierSortie, char c)
    while(c != EOF) {
        
    }


int linesCount(FILE* fichier, char buffer[255]) {
    int i = 0;
    while (fgetc(fichier) != EOF ) {
        getLine(fichier, buffer);
        i++;
    }
    return i;
}

int main(void) {

    char fileName[] = "turingWinnersBis.txt";
    FILE* fichierEntree;
    fichierEntree = fopen(fileName, "r");
    char buffer[255];
    int WinnersCount = (linesCount(fichierEntree, buffer) - 1) / 3;

    char out[] = "outBis.txt";
    FILE* fichierSortie;
    fichierSortie = fopen(out, "a");


}