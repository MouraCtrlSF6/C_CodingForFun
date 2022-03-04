#include<stdio.h>
int fac(int i){
    if(i>=2) i = i*fac(i-1);
    return i;
}

int main (void) {
    int i;
    printf("Type n: ");
    scanf("%d", &i);
    printf("%d! = %d", i, fac(i));
}
