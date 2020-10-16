#include<stdio.h>

void TOH(int n, char a='A', char b='B', char c='C'){
    if (n > 0){
        TOH(n-1, a, c, b);
        printf("Disk Moved from %c to %c.\n", a, c);
        TOH(n-1, b, a, c);
    }
}

int main(void){
    TOH(8);
    return 0;
}