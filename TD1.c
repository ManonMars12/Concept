#include <stdio.h>
#include <stdlib.h> //Atoi 
#include <stdbool.h> //Booléens 


int sum(int argc, char* argv[]){
        int sum=0;
        if (argc<=2){
                printf(" Au moins 2 arguments nécessaires ");
                sum=0;
        }
        else {
                 for (int i=1; i<argc; i++){
                        sum=sum+atoi(argv[i]);
        }
               
        
            
    }
    return sum; 

   }

   bool b1(int Nlv, int Nf, int Nm, int Np ){
        return ((Nlv+Nf+Nm+Np)/4>10); 
   }

   bool b2(int Nlv, int Nf, int Nm, int Np ){
        return ((Nm >((Nlv+Nf+Nm+Np)/4)) && (Nf >((Nlv+Nf+Nm+Np)/4))) ; 

   }


   bool b3(int Nlv, int Nf, int Nm, int Np ){
        return ((Nlv>10)||(Nf>10)||(Nm>10)||(Np>10)); 
   }

    bool b4(int Nlv, int Nf, int Nm, int Np ){
        return ((Nlv>10)&&(Nf>10)&&(Nm>10)&&(Np>10)); 
   }

    bool b5(int Nlv, int Nf, int Nm, int Np ){
        return ((((Nlv+Nf)/2)>10)||(((Nm+Np)/2)>10));
   }

    bool b6(int Nlv, int Nf, int Nm, int Np ){
        return ((b1(Nlv, Nf, Nm, Np )&& ((((Nlv+Nf)/2)>10)^(((Nm+Np)/2)>10)))); 
   }



int main(int argc, char* argv[]) {

    /* int res = sum(argc, argv);
    if (res!=0){
        printf("Somme : %d\n", res);

    }

     bool r1 = b1(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));
     printf("r1 : %d\n", r1);
    
     bool r2 = b2(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));
     printf("r2 : %d\n", r2);

     bool r3 = b3(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));
     printf("r3 : %d\n", r3);

     bool r4 = b4(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));
     printf("r4 : %d\n", r4);

     bool r5 = b5(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));
     printf("r5 : %d\n", r5);

     bool r6 = b6(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));
     printf("r6 : %d\n", r6);*/

    int age;
    printf("Entrez votre âge : ");

    scanf("%d", &age);

    printf("Votre âge est de : %d", age);

     char c1;
     char c2;
     char c3;
     printf("Entrez votre caractère : ");
     scanf("%c, %c, %c", &c1, &c2, &c3);
     printf("Vos caractères sont : %c, %c, %c", c1, c2, c3);

    return 0;
}