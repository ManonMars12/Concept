#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>
#include "struct.h"

bool est_vide(pile pile){
   return (pile.sommet==NULL);

}


void empiler(pile* pile, int val){ //ptr pour l'exterieur 
    element* nv_sommet= (element*)malloc(sizeof(element)); // On alloue la mémoire, malloc renvoie un void* donc on caste 
    nv_sommet->valeur = val; //On met la valeur de sommet à val 
    nv_sommet->suivant = pile->sommet; //Le pointeur stocké dans suivant est désormais celui de l'ancien sommet
    pile->sommet = nv_sommet; //Nouveau sommet 

    // -> accès champ structure par un pointeur 

}

int depile(pile* pile, int* res){
    if (est_vide(*pile)){
        return(-1); //code erreur 
    }
    
    element* sommet_ancien = pile->sommet;
    element* sommet_nv = sommet_ancien->suivant;
    pile->sommet=sommet_nv;
    free(sommet_ancien);

    return(0); 

}
