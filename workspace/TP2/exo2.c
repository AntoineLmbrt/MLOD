#include <stdio.h>
#include <stdbool.h>

bool estConvexe(bool tab[], int length) {
    int changements = 0;
    for(int i = 0; i < length-1; i++) {
        if(!(tab[i] == tab[i+1])) {
            changements += 1;
        }
        if(tab[0] != tab[length-1]) {
            changements += 1;
        }
    }
    return changements <= 2;
}

int main(void) {
    bool test1[] = {false, true, true, false, false}; //convexe
    bool test2[] = {true, true, false, false, true}; //convexe
    bool test3[] = {true, true, false, true, false}; //non convexe
    printf("test1 %s",estConvexe(test1, sizeof(test1)) ? "est convexe\n":"n'est PAS convexe\n");
    printf("test2 %s",estConvexe(test2, sizeof(test2)) ? "est convexe\n":"n'est PAS convexe\n");
    printf("test3 %s",estConvexe(test3, sizeof(test3)) ? "est convexe\n":"n'est PAS convexe\n");
    return 0;
}

