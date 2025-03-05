#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "util_rand.h"

int max(int* tab, int taille, int ** ptr_ptr_max){
    if (tab==NULL){
        return -1;
    }

    
    for(int i=0; i<taille; i++){
        int max=0;
        if (*(tab+i)>** ptr_ptr_max){
           *ptr_ptr_max = tab+i;
        }
        else {
            *ptr_ptr_max= tab;
        }

    }

    return 0;
}

int main(){

    int* tab={0, 10, 2, 3, 0};
  
    int * ptr_max= tab; 

    max(tab,&ptr_max,5);


}