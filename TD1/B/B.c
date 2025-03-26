#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h> 


int add(int a, int b, int* c){
    *c=a+b;
    return 0;
}

void stack_overflow(int n){
    return(stack_overflow(n-1));
}

int main() {
    int a_1 = 2;
    int a_2 = 3;
    int a_3;

    add(a_1, a_2, &a_3);

    printf("Somme : %i\n", a_3);

 
    int* a=(int*)malloc(sizeof(int));

    char* b=(char*)malloc(sizeof(char));

    float* c=(float*)malloc(sizeof(float));

    bool en_cours=true;
    char rep;
    while(en_cours){


    printf("Entrez un caractère: ");
        scanf(" %c", b);
        printf("Entrez un entier: ");
        scanf("%d", a);
        printf("Entrez un nombre flottant: ");
        scanf("%f", c);

        printf("Flottant : %.2f\n", *c);
        printf("Entier : %d\n", *a); 
        printf("Caractere : %c\n", *b);  
          
        free(c);
        free(a);
        free(b);

    printf("Continuer ? O/N ");
        scanf(" %c", rep);
        if (rep=="N"){
            en_cours=false; 
        }
}

    return 0;
}