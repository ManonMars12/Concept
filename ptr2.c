#include <stdio.h> 

int main(void){
    int i=3;
    int* pi; 
    pi=&i;

    char c='c';
    char* pc;
    pc=&c; 

    //printf("%i %i", i, pi);
    //printf(" %c %c", c, pc);

    //int pointeur_pi=&pi;
    //int pointeur_pc=&pc;

    char car='a';
    int a=256;
    int b=129;

    char *ptr_car=&car;
    int *ptr_a=&a;
    int *ptr_b=&b;


    printf("Adresse de c %p\n",ptr_car);
   
    printf("Code ASCII du caractère a = %i\n",(int)car);

    printf("Adresse de a = %p\n", ptr_a);

    printf("Adresse de b = %p\n", ptr_b);


}