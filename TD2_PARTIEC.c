#include <stdio.h> 
// Partie A 
int al_1(){
    return 1;
}


// Partie B 

int stack_overflow(int n){
    return n*stack_overflow(n-1);
}

// Partie C 

int rec_simp_facto(int n) {
    if (n==0 || n==1){
        return 1;
    }
    else {
        return n*rec_simp_facto(n-1);
    }
}

int rec_term_facto(int n, int acc) {
        if (n==0 || n==1){
            return acc; 
        }
        else {
            return rec_term_facto(n-1, acc*n);
        }
}

int rec_simp_pui(int n, int p) {
    if (p==0){
        return 1;
    }
    if (p==1){
        return n;
    }
    else {
        return n*rec_simp_pui(n, p-1);
    }
}

int rec_term_pui(int n, int p, int acc) {
    if (p==0){
        return acc;
    }
    else {
        return rec_term_pui(n, p-1, n*acc);
    }
}

int main() {
    printf("Test de rec_simp_facto : %d\n", rec_simp_facto(3));
    printf("Test de rec_term_facto : %d\n", rec_term_facto(3, 1));

    printf("Test de rec_simp_pui : %d\n", rec_simp_pui(2, 2));
    printf("Test de rec_term_pui : %d\n", rec_term_pui(2, 2, 1));

    //printf("Test de stack_overflow : %d\n", stack_overflow(100000));

    return 0; 
}