#include "linkedListOfMusic.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int main(void) {

    char fileName[] = "music.csv";
    FILE* fichier;
    fichier = fopen(fileName, "r");

    Liste listOfMusic = NULL;
    char *line = calloc(MAX_LINE_SIZE, sizeof(char));

    // Écriture de la première ligne dans notre fichier de sortie
    // "Name,Artist,Album,Genre,Disc Number,Track Number,Year"
    fgets(line, MAX_LINE_SIZE, fichier);
    printf("%s", line);

    // Remplissage de notre Liste de musique
    for (int i = 0; i < NB_MUSICS; i++) {
        listOfMusic = addMusicToList(fichier, line, listOfMusic);
    }

    // Affichage (donc écriture) de notre Liste de musique
    // Retour à la ligne pour chaque musique
    afficheListe_r(listOfMusic);

    fclose(fichier);

    // Libération de la mémoire
    detruire_r(listOfMusic);
    free(line);

    return EXIT_SUCCESS;
}