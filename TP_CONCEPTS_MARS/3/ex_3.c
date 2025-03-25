#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>
#include <string.h>
#include "struct_horaires.h"


int ajout_horaire(horaire** tab, int* taille, char* ville_dep, char* ville_arr, int heure_dep, int heure_arr, int distance) {
    *tab = realloc(*tab, (*taille + 1) * sizeof(horaire));
  
    strcpy((*tab)[*taille].ville_arr, ville_arr); //ptr sur element index taille 
    strcpy((*tab)[*taille].ville_dep, ville_dep);
    (*tab)[*taille].heure_dep = heure_dep;
    (*tab)[*taille].heure_arr = heure_arr;
    (*tab)[*taille].distance = distance;

    (*taille)=(*taille + 1 );
    return 1;
}



int rechercher_trains_depuis_ville(horaire* tab, int taille, char* ville_dep, horaire* resultat, int* nb_trouve) {
    *nb_trouve = 0;

    for (int i = 0; i < taille; i++) {
        if (strcmp(tab[i].ville_dep, ville_dep) == 0) {
            resultat[*nb_trouve] = tab[i];  
            *nb_trouve = *nb_trouve+1; 
        }
    }

    return 0; 
}


int rechercher_trajet_plus_rapide(horaire* tab, int taille, horaire* res) {
    *res=tab[0];
    double vmax=-10;
    
    for (int i=0; i<taille; i++){
        double nb_heure_dep=tab[i].heure_dep/100;
        double nb_minutes_sup_dep=tab[i].heure_dep%100;

        double nb_heure_arr=tab[i].heure_arr/100;
        double nb_minutes_sup_arr=tab[i].heure_arr%100;

        double duree_minute=((nb_heure_arr*60+nb_minutes_sup_arr)-(nb_heure_dep*60+nb_minutes_sup_dep));
        double duree_heure= duree_minute/60.0;

        //v=d/t 
        double vitesse=tab[i].distance/duree_heure;

        if (vitesse>vmax){
            vmax=vitesse;
            *res=tab[i];
        }

        if (vmax<0){
            return -1;
        }
    }
    return 0; 
}

int tri_croissant_horaire(horaire* tab, int taille, horaire* res) {
    for (int i = 0; i < taille; i++) {
        res[i] = tab[i];
    }
    for (int i = 0; i < taille - 1; i++) {
        for (int j = i + 1; j < taille; j++) {
            if (res[i].heure_dep > res[j].heure_dep) {
                horaire temp = res[i];
                res[i] = res[j];
                res[j] = temp;
            }
        }
    }
    return 0;
}
    
 




int main(){

    int taille = 0;
    int nb_trouve=0;
    horaire* tab = NULL;



    ajout_horaire(&tab, &taille, "Lille", "Paris", 800, 859 ,237);
    ajout_horaire(&tab, &taille, "Lille", "Lyon", 700, 1000 ,709);

    ajout_horaire(&tab, &taille, "Lille", "Calais", 1519, 1834, 110);
    ajout_horaire(&tab, &taille, "Paris", "Marseille", 1200, 1800 , 900);

    ajout_horaire(&tab, &taille, "Lyon", "Marseille", 1007, 1501, 450);
    ajout_horaire(&tab, &taille, "Lyon", "Marseille", 1150, 1700 , 450);
    

    horaire* res = malloc(taille * sizeof(horaire));


    printf("\n Trajets : \n");

    for (int i = 0; i < taille; i++) {
        printf("%s -> %s | %d - %d | %d km\n",
               tab[i].ville_dep, tab[i].ville_arr,
               tab[i].heure_dep, tab[i].heure_arr,
               tab[i].distance);
    }
    //voir l'affichage des heures 

    rechercher_trains_depuis_ville(tab, taille, "Lille", res, &nb_trouve);
    if (nb_trouve == 0) {
        printf("Aucun train trouvé au départ de Lille.\n");
    } else {
             printf("\n Trajets au depart de Lille : \n");

        for (int i = 0; i < nb_trouve; i++) {
            printf("%s -> %s | %04d - %04d | %d km\n",
               res[i].ville_dep, res[i].ville_arr,
               res[i].heure_dep, res[i].heure_arr,
               res[i].distance);
    }
}

    free(res);

    horaire res_trajet;



    rechercher_trajet_plus_rapide(tab, taille, &res_trajet);
     printf("\n Trajet le plus rapide : \n");
    printf("%s -> %s | %04d - %04d | %d km\n",
       res_trajet.ville_dep, res_trajet.ville_arr,
       res_trajet.heure_dep, res_trajet.heure_arr,
       res_trajet.distance);


    printf("\n Horaires avant le tri :\n");
    for (int i = 0; i < taille; i++) {
        printf("%s -> %s | %04d - %04d | %d km\n",
               tab[i].ville_dep, tab[i].ville_arr,
               tab[i].heure_dep, tab[i].heure_arr,
               tab[i].distance);
    }
    
    horaire* res_tri = malloc(taille * sizeof(horaire));
    tri_croissant_horaire(tab,taille, res_tri);

    printf("\nHoraires apres le tri croissant par heure de depart :\n");
    for (int i = 0; i < taille; i++) {
        printf("%s -> %s | %04d - %04d | %d km\n",
               res_tri[i].ville_dep, res_tri[i].ville_arr,
               res_tri[i].heure_dep, res_tri[i].heure_arr,
               res_tri[i].distance);
    }

    free(res_tri);
    free(tab);
    return 0;



}