#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

Matrix matrix_construction(void){//CONSTRUCTOR USING BSTREE CONSTRUCTOR
    Matrix matrix;
    matrix = bstree_ini();
    *matrix = NULL;
    return matrix;
}

unsigned char matrix_isin(Matrix m,Index index1, Index index2){//IF IN RETURNS 1, IF NOT RETURNS 0
    if(bstree_search(m,key_gen(index1,index2)) == NULL){
        return '0';
    }else{
        return '1';
    }
}

Value *matrix_get(Matrix m, Index index1, Index index2){//RETURNS POINTER TO SPECIFIC NODE
    if(matrix_isin(m,index1,index2) == '1'){
        Value *value;
        value =bstree_search(m,key_gen(index1,index2));
        return value;
    }else{
        return NULL;
    }
}

void matrix_set(Matrix m, Index index1, Index index2,Value value){//SETS VALUE OF NODE IN MATRIX
    if(matrix_isin(m,index1,index2) == '0'){
        bstree_insert(m,key_gen(index1,index2),data_gen(value));
    }else{
        Value *change;
        change = matrix_get(m,index1,index2);
        *change = value;
    }
}

void matrix_inc(Matrix m, Index index1, Index index2, Value value){//INCREMENTS INT OF GIVEN INDEX BY # OF TIMES IT APPEARS
    if(matrix_isin(m,index1,index2)=='0'){
        printf("Unable to increment");
    }else{
        Value *oldVal;
        oldVal = matrix_get(m,index1,index2);
        *oldVal += value;
    }
}

void matrix_list(Matrix m){//TRAVERSAL
    bstree_traversal(m);
}

void matrix_destruction(Matrix m){//FREE
bstree_free(m);
}
