#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h> 

//B1
//Nous n'arrivons pas à générer l'erreur cependant une récursivité infinie devrait la générer
int stack_overflow(int n){
    return(stack_overflow(n-1)); 

}