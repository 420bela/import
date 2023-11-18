#include <stdio.h>
#include <stdlib.h>
#include "bevas.h"

int main()
{
        int nehezseg=1;
        char kerdes[100]="valami";
        char A[20]="valami";
        char B[20]="valami";
        char C[20]="valami";
        char D[20]="valami";
        char valasz='C';
        char kategoria[20]="valami";


        Adatok *elso = ujelem(nehezseg, kerdes, A, B, C, D, valasz, kategoria);
        Adatok *jelen;
        FILE* fp=fopen("C:\\Users\\Zephyrus\\Desktop\\kerdes.csv","r");
        if(fp==NULL ){
            printf("HIBA:Nem tudtam megnyitni a fajlt");
        }

        while(fscanf(fp," %d;%s;%s;%s;%s;%s; %c;%s",&nehezseg,kerdes,A,B,C,D,valasz,kategoria)!=EOF){
            hozzafuz(elso,ujelem(nehezseg,kerdes,A,B,C,D,valasz,kategoria));
        }
        fclose(fp);

        jelen=elso->kovetkezo;
    while(jelen!= NULL){
        printf("%d,%s,%s,%s,%s,%s,%c,%s\n",
               jelen->nehezseg,
               jelen->kerdes,
               jelen->A,
               jelen->B,
               jelen->C,
               jelen->D,
               jelen->valasz,
               jelen->kategoria);
        jelen=jelen->kovetkezo;
    }
    felszabadit(elso);

    return 0;
}
