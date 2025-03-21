#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "util_rand.h"

// Partie B 

int stack_overflow(int n){
    return n*stack_overflow(n-1);
}

int somme_tab(int* tab, int taille, int *computed_sum){   
    if (tab==NULL){
        return -1; 
    }

    *computed_sum=0;
    for (int i = 0; i < taille; i++) {
        *computed_sum += *(tab+i);
    }
    

    return 0; 
}

int search_array(int* tab, int taille, int cherche, int* place){
    if (tab==NULL){
        return -1; 
    }
    for (int i = 0; i < taille; i++) {
       if (*(tab + i) == cherche) { 
            *place = i; 
       }
       return 0; 
    }
}

//Exercice donné en classe 

int search_array_modif(int* tab, int taille, int cherche, int** ptr_sur_element_a_modif){
    if (tab==NULL){
        return -1; 
    }
    for (int i = 0; i < taille; i++) {
       if (*(tab + i) == cherche) { 
            *ptr_sur_element_recherche=&(*(tab+i));
            *ptr_sur_element_recherche = *(tab + i);
            *ptr_sur_element_a_modif= ptr_sur_element_recherche;
        

       }
    }
    
    return 0; 

}

// Partie C 

int rec_simp_facto(int n) {
    if (n==0 || n==1){
        return 1;
    }
    else {
        return n*rec_simp_facto(n-1);
    }
}

int rec_term_facto(int n, int acc) {
        if (n==0 || n==1){
            return acc; 
        }
        else {
            return rec_term_facto(n-1, acc*n);
        }
}

int rec_simp_pui(int n, int p) {
    if (p==0){
        return 1;
    }
    if (p==1){
        return n;
    }
    else {
        return n*rec_simp_pui(n, p-1);
    }
}

int rec_term_pui(int n, int p, int acc) {
    if (p==0){
        return acc;
    }
    else {
        return rec_term_pui(n, p-1, n*acc);
    }
}

int main() {
    printf("Test de rec_simp_facto : %d\n", rec_simp_facto(3));
    printf("Test de rec_term_facto : %d\n", rec_term_facto(3, 1));

    printf("Test de rec_simp_pui : %d\n", rec_simp_pui(2, 2));
    printf("Test de rec_term_pui : %d\n", rec_term_pui(2, 2, 1));

    //printf("Test de stack_overflow : %d\n", stack_overflow(100000));
    int tab[5]={0,10,1,3,5};


    int val = 0; 
    int place=0;

    somme_tab(tab,5,&val);

    printf("La somme du tableau est : %i", val);

    search_array(tab, 5, 10, place);
    printf("Il est en position : %i", place);


    return 0; 
}