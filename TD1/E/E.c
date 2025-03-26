#include <stdio.h>
#include <stdlib.h>

void buffer_overflow(){
    int buffer[4];
    for (int i=0; i<1000; i++){
        buffer[i]=i*2;

    }

}

int main() {
    buffer_overflow();
    return 0;
}