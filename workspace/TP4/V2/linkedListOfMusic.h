#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_SIZE 255
#define NB_MUSICS 2701

struct music {
    char *name;
    char *artist;
    char *album;
    char *genre;
    int discNumber;
    int trackNumber;
    int year;
};

typedef struct music Music;

// FONCTIONS EXTERNES

extern Music *readMusic(char *line);
extern Liste addMusicToList(FILE *fichier, char *line, Liste listOfMusic);
extern Liste orderByYear(Liste ListOfMusic);