#include <stdio.h>

void echangeContenu(int *a, int *b) {
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

int main(void) {
    int a = 20;
    int b = 10;
    printf("avant: a = %d, b = %d\n", a, b);
    echangeContenu(&a,&b);
    printf("après: a = %d, b = %d\n", a, b);
}