#define UTIL_RAND_H

#include <stdlib.h>
#include <time.h>

void init_random();
int random_int();
int random_int_max(int seuil_haut);
random_int_min_max(int seuil_bas, int seuil_haut); 
double random_0_1();
double random_reel_range(double seuil_bas, double seuil_haut);