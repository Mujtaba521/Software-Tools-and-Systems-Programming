#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datatype.h"

char *string_dup(char *str){//DUPLICATES STRING
    char *newStr;
    newStr =(char *)malloc(sizeof(char));
    return strcpy(newStr,str);
}
Key key_gen(char *skey1, char *skey2){//CREATES KEY USING STRING DUP
    Key newKey =(Key)malloc(sizeof(Key));
    char *key1= string_dup(skey1);
    char *key2= string_dup(skey2);
    newKey -> skey1 = key1;
    newKey -> skey2 = key2;
    return newKey;
}

int key_comp(Key key1, Key key2){//KEY COMPARISON
   if(strcmp((*key1).skey1, (*key2).skey1) == 0){//CHECKS TO SEE IF FIRST KEETS ARE EQUAL
        return(strcmp((*key1).skey2, (*key2).skey2));//IF EQUAL COMPARE SECOND KEYS
    }
    return(strcmp((*key1).skey1, (*key2).skey1));//RETURN FIRST KEY RESULTS IF NOT EQUAL

}

void key_print(Key key){//PRINTS KEY OBJECT
printf(" %.20s %.20s ", key->skey1, key->skey2);

}

void key_free(Key key){//FREES MEMORY
    if(key->skey1 ==NULL){
    free(key->skey1);
    }
    if(key->skey2 ==NULL){
    free(key->skey2);
    }
    free(key);
}

Data data_gen(int idata){//CREATES DATA OBJECT
    Data newData = (int *)malloc(sizeof(Data));
    *newData = idata;
    return newData;
}

void data_set(Data data, int idata){//CHANGES VALUE OF DATA
    data = &idata;
}

void data_print(Data data){//PRINTS DATA
    printf("%d \n",*data);
}

void data_free(Data data){//FREE DATA
    free(data);
    data = NULL;
}
