#ifndef UTIL_RAND_H
#define UTIL_RAND_H

#include <stdlib.h>
#include <time.h>

void init_random(void);
int random_int(void);
int random_int_max(int seuil_haut);
int random_int_min_max(int seuil_bas, int seuil_haut); 
double random_0_1(void);
double random_reel_range(double seuil_bas, double seuil_haut);

#endif