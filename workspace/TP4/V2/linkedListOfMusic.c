#include "linkedListOfMusic.h"

Music *readMusic(char *line) {

    Music *music = malloc(sizeof(Music));

    char *buffer = strdup(line);
    char *temp;

    music->name = strsep(&buffer, ",");
    music->artist = strsep(&buffer, ",");
    music->album = strsep(&buffer, ",");
    music->genre = strsep(&buffer, ",");

    temp = strsep(&buffer, ",");
    music->discNumber = atoi(temp);
    temp = strsep(&buffer, ",");
    music->trackNumber = atoi(temp);
    temp = strsep(&buffer, ",");
    music->year = atoi(temp);

    free(buffer);

    return music;
}


Liste addMusicToList(FILE *fichier, char *line, Liste listOfMusic) {
    fgets(line, MAX_LINE_SIZE, fichier);
    Music *music = readMusic(line);
    listOfMusic = ajoutFin_r(music, listOfMusic);
    return listOfMusic;
}

Liste orderByYear(Liste listOfMusic) {
    
}

void afficheElement(Element e) {

    Music *music = (Music *)e;
    
    printf("%s,", music->name);
    printf("%s,", music->artist);
    printf("%s,", music->album);
    printf("%s,", music->genre);
    if (music->discNumber == 0) {
        printf(",");
    } else {
        printf("%i,", music->discNumber);
    }
    printf("%i,", music->trackNumber);
    printf("%i\n", music->year);
}

void detruireElement(Element e) {

    Music *music = (Music *)e;
    
    free(music);
    e = NULL;
}

bool equalsElement(Element e1, Element e2) {

    Music *music1 = (Music *)e1;
    Music *music2 = (Music *)e2;

    if (strcmp(music1->name, music2->name) != 0) {
        return false;
    }
    if (strcmp(music1->artist, music2->artist) != 0) {
        return false;
    }
    if (strcmp(music1->album, music2->album) != 0) {
        return false;
    }
    if (strcmp(music1->genre, music2->genre) != 0) {
        return false;
    }
    if (music1->discNumber != music2->discNumber) {
        return false;
    }
    if (music1->trackNumber != music2->trackNumber) {
        return false;
    }
    if (music1->year != music2->year) {
        return false;
    }

    return true;
}

