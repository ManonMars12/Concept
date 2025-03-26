#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "util_rand.h"

#define N 100000
#define VAL_MAX 5

int* exercice(){
    init_random();
   static int res[VAL_MAX+1] = {0};
    for (int i = 0; i < N; i++) {
        int temp =random_int_max(N);
        res[temp]++;
        

    }


    return res;
}

int main(){

    int* res =exercice(); 
    double p0 = (res[0] / (double)N) * 100;
    double p1 = (res[1] / (double)N) * 100;
    double p2 = (res[2] / (double)N) * 100;
    double p3 = (res[3] / (double)N) * 100;
    double p4 = (res[4] / (double)N) * 100;
    double p5 = (res[5] / (double)N) * 100;
    printf("Valeur 0: %.2f%%\n", p0);
    printf("Valeur 1: %.2f%%\n", p1);
    printf("Valeur 2: %.2f%%\n", p2);
    printf("Valeur 3: %.2f%%\n", p3);
    printf("Valeur 4: %.2f%%\n", p4);
    printf("Valeur 5: %.2f%%\n", p5);


  

    
return 0; 
}