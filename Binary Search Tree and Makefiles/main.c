#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"

void matrixTester(){
    Matrix testMatrix = matrix_construction();
    while(1){
        printf("Enter two strings, in the format str1 str2. Enter 0 0 to stop.\n");
        char string1[40], string2[40];
        scanf("%s %s",&string1,&string2);
        if (strcmp(string1,"0") == 0 && strcmp(string2,"0") == 0){
            break;
        }
        else if (matrix_isin(testMatrix,string1,string2) == '1'){
            matrix_inc(testMatrix,string1,string2,1);
        }
        else{
            matrix_set(testMatrix,string1,string2,1);
        }
    }

   if(*testMatrix != NULL){
    printf("String 1 String 2 Occurance\n");
    matrix_list(testMatrix);
    }

}

int main(){
    matrixTester();
}
