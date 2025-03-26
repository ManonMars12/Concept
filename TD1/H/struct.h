#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>

typedef struct element { //Chaque élémént possède une valeur et un pointeur vers l'élément suivant
    int valeur;  
    struct element* suivant; 
} element;


typedef struct pile{
    element* sommet;
} pile; 

//On sépare les deux structures pour plus de lisibilité

bool est_vide(pile pile);
void empiler(pile* pile, int val);
int depile(pile* pile, int* res); 