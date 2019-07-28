#include <stdio.h>
#include <stdlib.h>

void main(){
    double precision=0;//NUMBER OF TIMES PROGRAM RUNS
    double sign = 1;//POSITIVE OR NEGATIVE
    double sum = 0;
    double pi = 0;//VALUE OF PI
    double denominator = 1;

    printf("Enter Percision Value: ");
    scanf("%lf",&precision);

    //INFINITE LOOP
    while (1){
        //GETS VALUE THAT YOU ADD OR SUBTRACT FROM PI
        sum = sign*(4.0/denominator);
        //BASE CASE
        if (sum*sign < precision){
            break;
        }
        pi += sum;
        denominator += 2;
        sign *= -1;
    }
    printf("\nSum: %lf", pi);
}
