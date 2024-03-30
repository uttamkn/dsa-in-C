#include <stdio.h>

void toh(int n, char source, char dest, char aux) {
    if(n==1) {
        printf("move %d from %c to %c\n", n, source, dest);
    }
    else {
        toh(n-1, source, aux, dest);
        printf("move %d from %c to %c\n", n, source, dest);
        toh(n-1, aux, dest, source);
    }
}

void main() {
    int n=3;
    toh(n, 'A', 'C', 'B');
}