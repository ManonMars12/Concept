#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>

typedef struct maillon //Définition de la structure maillon d'une liste chaînée 
{
    int val;            //Sa valeur qui est un entier
    struct maillon *p_suiv; //Un pointeur vers l'élément suivant 
} maillon_int;



maillon_int *init_elt(); 
maillon_int *ajout_tete_v1(maillon_int *p_tete, maillon_int *p_nv_elt); 
void ajout_tete_v2(maillon_int **p_p_tete, maillon_int *p_nv_elt); 
int ajout_tete_v3(maillon_int **p_p_tete, maillon_int *p_nv_elt); 
void parcourir(maillon_int *p_tete); 
maillon_int *inserer1(maillon_int *p_tete, maillon_int *p_nv_elt); 
void inserer2(maillon_int **prem, maillon_int *e); 
void supprimer_debut(maillon_int **prem); 

// Fonction supprimer_elt à écrire elle recherche dans une liste
// une valeur entière passée en paramètres et en supprime toutes les occurences

void detruire_liste(maillon_int **prem); 
void detruire_liste2(maillon_int **prem); 
void sauver_liste(maillon_int *prem); 
maillon_int *load_liste(); 
int supprimer_elt(maillon_int **prem,int elt);