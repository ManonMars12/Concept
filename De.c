#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "util_rand.h"

void doublons(int *des, int nb_des) {
    for (int i = 0; i < nb_des - 1; i++) {
        for (int j = i + 1; j < nb_des; j++) {
            if (des[i] == des[j]) {
                des[j] = random_int_min_max(1,6);
                }
            }
        }
}

void jouer(int nb_des) {
    int des[4]; //tableau des valeurs des dés 
    int *p_des = des;  
    int total = 0;
    int max = 6 * nb_des;
    int seuil_victoire = (max / 3) * 2;

   
    for (int i = 0; i < nb_des; i++) {
         if (nb_des==5){
            break; 
        }
        *(p_des + i) = random_int_min_max(1, 6);
    }

    
    doublons(p_des, nb_des);

    for (int i = 0; i < nb_des; i++) {
        total = total + *(p_des + i);
    }

    printf("Résultats des dés : ");
    for (int i = 0; i < nb_des; i++) {
        printf("%d ", *(p_des + i));
    }
    printf("\nTotal des dés : %d\n", total);
    printf("Seuil de victoire : %d\n", seuil_victoire);

    if (total >= seuil_victoire) {
        printf("Bravo ! Vous avez gagné avec %d points en plus.\n", total - seuil_victoire);
    } else {
        printf("Dommage... Il vous manque %d points pour gagner.\n", seuil_victoire - total);
    }
}


void jeu() {
    int choix;
    printf("\n=== Jeu des dés ===\n");
    printf("1. Jouer avec 1 dé\n");
    printf("2. Jouer avec 2 dés\n");
    printf("3. Jouer avec 3 dés\n");
    printf("4. Jouer avec 4 dés\n");
    printf("5. Quitter\n");
    printf("Votre choix : ");
    scanf("%d", &choix);
    jouer(choix);
    
}


int main() {
    init_random();
    jeu();
    return 0;
}
