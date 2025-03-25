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


int valeur_sommet(pile* pile, int* res ){
    if (est_vide(*pile)){
        return(-1); //code erreur 
    }

   element* sommet = pile->sommet;
   *res = sommet->valeur;
   return(0);

}



//Récupérer la valeur et enlever l’élément de sommet de pile

int valeur_sommet_depile(pile* pile, int* res){
    if (est_vide(*pile)){
        return(-1); //code erreur 
    }

       valeur_sommet(pile, res); 
    
    element* sommet_ancien = pile->sommet;
    element* sommet_nv = sommet_ancien->suivant;
    pile->sommet=sommet_nv;
    free(sommet_ancien);

    return(0); 

}

int reverse_pile(pile* pile_endroit, pile* pile_envers){

    int res; 

    while(!(est_vide(*pile_endroit))){
        valeur_sommet(pile_endroit,&res); 
        empiler(pile_envers,res);
        valeur_sommet_depile(pile_endroit, &res);
    }

    return(0);

}


void afficher_pile(pile* pile) {
    element* haut = pile->sommet;

    if (est_vide(*pile)) {
        printf("La pile est vide.\n");
        return;
    }

    printf("Pile : ");
    while (haut != NULL) { // Pas est_vide() sinon problème pour ligne 77
        printf("%d ", haut->valeur);
        haut = haut->suivant;
    }
    printf("\n");
}

int main() {
    pile pile_endroit = {};
    pile pile_envers = {};

    empiler(&pile_endroit, 10);
    empiler(&pile_endroit, 20);
    empiler(&pile_endroit, 30);
    empiler(&pile_endroit, 40);

    printf("Pile a l'endroit : \n");
    afficher_pile(&pile_endroit);

    reverse_pile(&pile_endroit, &pile_envers);

    printf("Pile a l'envers : \n");
    afficher_pile(&pile_envers);

    return 0;
}