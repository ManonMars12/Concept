#include <stdio.h>
#include <stdlib.h>



char* reverse(char *str) {
    if (str == NULL){
        return NULL;
    }
    int len = 0;
    while (str[len] != NULL) {  
        len=len+1;
    }

    int i = 0;
    int j = len - 1;
    while (i < j) {
        char actuel = str[i];
        str[i] = str[j];
        str[j] = actuel;
        i+=i+1;
        j=j-1;
    }
    return str;  
}

int main() {
    char str[] = "Hello World";  
    printf("Avant : %s\n", str);

    reverse(str);  

    printf("Apres : %s\n", str);
    return 0;
}