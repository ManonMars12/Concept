#include "util_rand.h"

void init_random() {
    srand(time(NULL)); //Pour avoir une graine diférente à chaque execution 
}

int random_int() {
    return rand();
}

int random_int_max(int seuil_haut) {
    return rand()%(seuil_haut+1);
}

int random_int_min_max(int seuil_bas, int seuil_haut) {
    return seuil_bas+rand()%(seuil_haut-seuil_bas+1);
}




double random_0_1() {
    return (double)rand()/RAND_MAX;
}

double random_reel_range(double seuil_bas, double seuil_haut) {
    return seuil_bas+((double)rand()/RAND_MAX)*((seuil_haut-seuil_bas));
}