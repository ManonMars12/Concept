#include <stdio.h> 
#include <stdlib.h>  
#include "structres.h"


int * crea(int n){
    int* tableau = (int *)malloc(n * sizeof(int));
    return tableau;
}

int* remp(int* tab, int n){

    for(int i=0; i<n ;i++){
        tab[i]=rand() % 11; 
    }
    return tab; 
}

struct res min_max(int*tab, int n){
    struct res resultat;
    for(int i=0; i<n ;i++){
        if (tab[i]>resultat.max){
            resultat.max=tab[i];

        }
        if (tab[i]<resultat.min){
            resultat.min=tab[i];
        }

    }

    return resultat;
}

int main(){
    
    int* tab= crea(TAILLE);
    int* tab_2=remp(tab, TAILLE);
    struct res resultat=(tab, TAILLE);
}