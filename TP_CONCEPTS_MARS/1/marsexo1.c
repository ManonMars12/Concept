#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include "marslisteint.h";


int menu() //Affichage du menu et choix de l'uti sur ce qu'il veut faire 
{
    int choix = 0;
    printf("1 Creer une liste d'entiers compris entre 0 et 20 de taille aleatoire comprise entre 1 et 20\n"
           "2 Ajouter un élément entier aléatoire (compris entre 0 et 20) en tête de liste\n"
           "3 Inserer un élément entier aléatoire dans sa place dans la liste suivant l'ordre croissant des premiers éléments\n"
           "4 Supprimer l'élément de tête\n"
           "5 Supprimer tous les maillons d'une valeur donnee\n"
           "6 Detruire liste\n"
           "7 Sauver la liste courante en binaire dans le fichier \"saveliste.bin\"\n"
           "8 Charger une liste depuis le fichier \"savelist.bin\"\n");

    scanf("%d", &choix);
    rewind(stdin);

    return choix;
}



int main()
{
    maillon_int *premier = NULL;
    maillon_int *nouveau;
    int fin = 0;
    int i, nb;

    srand((unsigned)time(NULL));
    while (!fin)
    {
        i = menu();
        switch (i)
        {

        case 1: // Creer une liste de taille aleatoire 
            nb = rand() % 20 + 1;
            for (int j=0; j<nb; j++){
                ajout_tete_v2(&premier, init_elt());
            }
            parcourir(premier);
            break;

        case 2: // Ajouter
            ajout_tete_v2(&premier, init_elt());
            parcourir(premier);
            break;

        case 3: // Inserer (ordre croissant) 
            inserer2(&premier, init_elt()); 
            parcourir(premier);
            break;

        case 4: // Supprimer debut: 
            supprimer_debut(&premier);
            parcourir(premier);
            break;

        case 5: // Supprimer un maillon d'une valeur donnee 
            // Fonction à écrire...
            parcourir(premier);
            break;

        case 6: // detruire liste 
            detruire_liste2(&premier);
            parcourir(premier);
            break;

        case 7: // Sauver liste 
            sauver_liste(premier); 
            parcourir(premier);
            break;

        case 8: // Charger liste 
            premier=load_liste();
            parcourir(premier);
            break;

        default:

            break;
        }
    }

    return 0;
}