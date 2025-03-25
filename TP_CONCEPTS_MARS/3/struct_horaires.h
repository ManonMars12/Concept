#include <stdio.h> 
#include <stdlib.h> 

typedef struct horaire { 
     char ville_dep[20]; //tableau de 10 
     char ville_arr[20];
     int heure_dep;
     int heure_arr;
     int distance;
} horaire;
