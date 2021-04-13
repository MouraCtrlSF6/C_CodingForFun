#include <stdio.h>
#include <math.h>

int main (void){
    char birth[11] = {};
    int year = 0, month = 0, day = 0;
    printf("\nType your birth date: ");
    gets(birth);

    for (int i=0; i<4; i++){
        year += (birth[i+6] - 48)*pow(10, 3-i);
        if(i<2){
            month += (birth[i] - 48)*pow(10, 1-i);
            day += (birth[i+3] - 48)*pow(10, 1-i);
        }
    }
    printf("Typed birth date was: %s", birth);
    printf("\nyear = %d", year);
    printf("\nmonth = %d", month);
    printf("\nday = %d", day);
    printf("\n\n");
}