#include "bevas.h"


Adatok *ujelem(int nehezseg, char*kerdes,char *A,char*B,char*C,char*D,char valasz,char* kategoria){
        Adatok* uj=(Adatok*)malloc(sizeof(Adatok));
        uj->nehezseg=nehezseg;
        sprintf(uj->kerdes,"%s",kerdes);
        sprintf(uj->A,"%s",A);
        sprintf(uj->B,"%s",B);
        sprintf(uj->C,"%s",C);
        sprintf(uj->D,"%s",D);
        uj->valasz = valasz;
        sprintf(uj->kategoria,"%s",kategoria);
        uj->kovetkezo=NULL;
        return  uj;
}

void hozzafuz(Adatok* eleje, Adatok* uj) {
    Adatok *jelenlegi = eleje;
    while (jelenlegi->kovetkezo != NULL) {
        jelenlegi = jelenlegi->kovetkezo;
    }
    jelenlegi->kovetkezo = uj;
}


void felszabadit(Adatok *eleje){

    Adatok *jelenlegi=eleje;
    Adatok *kov=eleje->kovetkezo;
    while(jelenlegi!=NULL){
        free(jelenlegi);
        jelenlegi=kov;
        if(kov!=NULL)
            kov=kov->kovetkezo;
    }
}
