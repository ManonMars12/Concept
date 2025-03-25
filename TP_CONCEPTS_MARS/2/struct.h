#include <stdio.h> 
#include <stdlib.h> 

typedef struct element { //Chaque élémént possède une valeur et un pointeur vers l'élément suivant
    int valeur;  
    struct element* suivant; 
} element;


typedef struct pile{
    element* sommet;
} pile; 

//On sépare les deux structures pour plus de lisibilité
