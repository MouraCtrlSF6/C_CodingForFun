/*---------
    Exercise proposed by HackerHank in:
    30 Days of Code challenge, 
    Day 10: Binary Numbers

    Given a base 10 integer, print it and 
    denote the maximum number of consecutive 
    1's in it's binary representation.
    
    Available at: https://www.hackerrank.com/challenges/30-binary-numbers/problem?isFullScreen=true&h_r=next-challenge&h_v=zen
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int getMaxSequence(int *arr, int index){
    int log = -1, counter = 1, max = 1;

    for (int i = 0; i < index; i++) {
        if(log != -1) {
            if(*(arr + i) == log - 1){
                counter++;
                if(counter > max) 
                  max = counter;
            } else counter = 1;
        }
        log = *(arr + i);
    }
    return max;
}

int populateMemory(int num, int *arr) {
    int diff = num, index = 0;

    for(int i = 0; diff > 0; i++){
        if((diff - pow(2, i)) < 0){
            int exp = pow(2, i-1);
            diff = diff - exp;
            *(arr + index) = i - 1;
            i = 0;
            index++;
        }
    }
    return index;
}
int main() {
    int num = 0, *arr;
    
    printf("Type a number: ");
    scanf("%d", &num);
    
    int arrBits = log10(num)/log10(2) - 1;
    arr = (int*) malloc(arrBits * sizeof(int));

    int index = populateMemory(num, arr);
    printf("\n%d's maximum 1 sequence is %d.\n", num, getMaxSequence(arr, index));
}