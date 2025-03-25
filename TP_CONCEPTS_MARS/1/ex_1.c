#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include<stdbool.h>

typedef struct maillon //Définition de la structure maillon d'une liste chaînée 
{
    int val;            //Sa valeur qui est un entier
    struct maillon *p_suiv; //Un pointeur vers l'élément suivant 
} maillon_int;


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

maillon_int *init_elt() //Créer un nouvel élément dont la valeur est comprise entre 0 et 20 
{
    maillon_int *p_nv_elt = malloc(sizeof(maillon_int)); //Permet de générer un nouveau maillon dont la valeur est comprise netre 0 et 20, 
    p_nv_elt->val = rand() % 21;                         // le maillon possède également un pointeur vers le maillon suivant ici il n'y a pas de maillon suivant 
    p_nv_elt->p_suiv = NULL;
    return p_nv_elt;
}

maillon_int *ajout_tete_v1(maillon_int *p_tete, maillon_int *p_nv_elt) //Ajout d'un maillon en tête de liste (v1) 
{
    p_nv_elt->p_suiv = p_tete; // Le nouveau pointe vers l'actuel premier 
    p_tete = p_nv_elt; //Le premier est bien le nouveau maillon 
    return p_tete;
}

void ajout_tete_v2(maillon_int **p_p_tete, maillon_int *p_nv_elt) //Ajout d'un maillon en tête de liste (v2) 
{
    p_nv_elt->p_suiv = *p_p_tete; //Idem que v1 mais en passant par un pointeur de pointeur 
    *p_p_tete = p_nv_elt;
}

int ajout_tete_v3(maillon_int **p_p_tete, maillon_int *p_nv_elt) ////Ajout d'un maillon en tête de liste (v3) + gestion erreurs 
{
    int errorCode = -1; //code erreur 
    if (p_nv_elt != NULL) 
    {
        p_nv_elt->p_suiv = *p_p_tete; //idem v1
        *p_p_tete = p_nv_elt;         //idem v1
        errorCode = 0;
    }
    return errorCode;
}

void parcourir(maillon_int *p_tete) //afficher la liste en la parcourant élément par élément 
{
    if (p_tete == NULL)
        printf("liste vide");
    else
        while (p_tete != NULL)
        {
            printf("%d--", p_tete->val); //on affiche l'élément 
            p_tete = p_tete->p_suiv; //on avance la tête 
        }
    putchar('\n');
}

maillon_int *inserer1(maillon_int *p_tete, maillon_int *p_nv_elt)
{
    maillon_int *n, *prec;

    if (p_tete == NULL || p_nv_elt->val <= p_tete->val) //insertion croissante (cas vide ou nv val < ancienne tête)
    {
        p_nv_elt->p_suiv = p_tete; //le premier devient le suivant 
        p_tete = p_nv_elt;         //changement de tête 
    }
    else
    {
        n = prec = p_tete; //on place la tête au suivant pour traiter 
        while (n != NULL && p_nv_elt->val > n->val) //on cherche la plus grande valeur 
        {
            prec = n; //on avance 
            n = n->p_suiv; //on fixe  le suivant 
        }
        p_nv_elt->p_suiv = n; //nv maillon pointe vers le suivant 
        prec->p_suiv = p_nv_elt; //le précédent pointe vers le nv maillon 
    }
    return p_tete;
}

void inserer2(maillon_int **prem, maillon_int *e)
{
    maillon_int *n, *prec;
    if (*prem == NULL || e->val <= (*prem)->val)
    {
        e->p_suiv = *prem; //le maillon pointe vers la tête de liste 
        *prem = e; //le suivant est fixé 
    }
    else
    {
        n = prec = *prem;
        while (n != NULL && e->val > n->val) //idem v1
        {
            prec = n; //on avance 
            n = n->p_suiv; //on fixe  le suivant 
        }
        e->p_suiv = n; //nv maillon pointe vers suivant 
        prec->p_suiv = e; //le précédent pointe vers le nouveau maillon 
    }
}

void supprimer_debut(maillon_int **prem) //on supprime la tête de liste 
{
    maillon_int *n;
    if (*prem != NULL)
    {
        n = *prem;
        *prem = (*prem)->p_suiv; //on avance la tête 
        free(n);                 //on libère la mémoire 
    }
}

// Fonction supprimer_elt à écrire elle recherche dans une liste
// une valeur entière passée en paramètres et en supprime toutes les occurences
int supprimer_elt(maillon_int **prem,int elt){
    maillon_int *actuel = *prem;
    maillon_int* prec=NULL;

    if (*prem==NULL){
            return -1; 
        }

    while(actuel != NULL){
        if (actuel->val==elt){
            if (prec){
                prec->p_suiv = actuel->p_suiv;
            }
            else {
                *prem=actuel->p_suiv; 
            }
            maillon_int* a_sup=actuel; 
            actuel=actuel->p_suiv;
            free(a_sup);
        }
       

        else {
            prec=actuel;
            actuel=actuel->p_suiv;
        }
    }

    return 0; 


}


void detruire_liste(maillon_int **prem) //On libère un à un la mémoire allouée à chaque maillon 
{
    maillon_int *n;
    while (*prem != NULL)
    {
        n = *prem; 
        *prem = (*prem)->p_suiv; //On avance la tête de liste 
        free(n);
    }
}

void detruire_liste2(maillon_int **prem) //idem en utilisant supprimer_debut() 
{
    while (*prem != NULL)
        supprimer_debut(prem); 
}

/* Permet la sérialisation format binaire dans le fichier
"saveliste.bin" de la liste d'entier (maillon_int) dont
le pointeur sur le premier élément est passé en paramètre
@input : maillon_int * prem, pointeur sur l'élément de tête de la liste à sérialiser
@output : void
@precondition : le répertoire courant et le processus père permettent l'écriture
                le pointeur prem, est soit NULL (aucune action) soit pointe sur
                le premier élément d'une liste d'entiers
@postcondition : le fichier saveliste.bin contient les éléments de la liste
                dont le premier élément est pointé par prem.
                Nota : il n'y a pas de libération de la mémoire occupée par la
                liste. Il faut donc la détruire avant d'éventuellement la recharger.
*/
void sauver_liste(maillon_int *prem)
{
    // ouvrir un fichier binaire en écriture : suffixe b
    FILE *f = fopen("saveliste.bin", "wb");
    printf("Ouvertude du fichier %p\n", f);
    // si liste non vide
    if (prem != NULL)
    {
        if (f == NULL)
            fprintf(stderr, "erreur création fichier :%i\n", errno);
        else // parcourir la liste jusque fin
            while (prem != NULL)
            {
                // écrire chaque maillon en binaire
                if (1 != fwrite(prem, sizeof(maillon_int), 1, f))
                    fprintf(stderr, "Erreur d'écriture du maillon %p\n", prem);
                else
                    // passer au maillon suivant
                    prem = prem->p_suiv;
            }
        fclose(f); // fermer le fichier
    }
    else
        fprintf(stderr, "pas de sauvegarde pour une liste vide\n");
}

maillon_int *load_liste()
{
    FILE *f;
    maillon_int *prem = NULL, *p, e;
    if ((f = fopen("saveliste.bin", "rb")) != NULL) //ouverture du fichier en binaire et en mode lecture 
    {
        prem = malloc(sizeof(maillon_int)); //allocation mémoire 
        fread(prem, sizeof(maillon_int), 1, f); //lire et placer le contenu dans prem 
        p = prem;
        while (fread(&e, sizeof(maillon_int), 1, f)) //idem mais en parcourant le fichier et en ajoutant des maillons à chaque fois 
        {
            p->p_suiv = malloc(sizeof(maillon_int));
            p = p->p_suiv;
            *p = e;
            p->p_suiv = NULL;
        }
        fclose(f); //fermeture du fichier 
    }
    else
        printf("erreur ou fichier inexistant");
    return prem;
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
            parcourir(premier);
            printf("Quelle valeur voulez-vous supprimer ? ");
            int val_sup;
            scanf("%d", &val_sup);
            supprimer_elt(&premier, val_sup);
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