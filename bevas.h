#ifndef BEVAS_H_INCLUDED
#define BEVAS_H_INCLUDED
#include <stdio.h>
typedef struct Adatok {
        int nehezseg;
        char kerdes[100];
        char A[20];
        char B[20];
        char C[20];
        char D[20];
        char valasz;
        char kategoria[20];
        struct Adatok *kovetkezo;

} Adatok;

Adatok *ujelem(int nehezseg, char*kerdes,char *A,char*B,char*C,char*D,char valasz,char* kategoria);

void hozzafuz(Adatok* eleje, Adatok*uj);

void felszabadit(Adatok *eleje);
#endif // BEVAS_H_INCLUDED
