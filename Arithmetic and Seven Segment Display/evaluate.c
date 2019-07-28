#include <stdio.h>
#include <stdlib.h>
float get_num();
float get_op();
float m_exp(float sub_exp, char op);
float s_exp(float sub_exp, char op);

int main(){
    printf("Enter an expression: ");
    float f1;
    f1 = s_exp(0, '+');
    printf("\nend: %f",f1);
}

//GETS NEXT NUMBER
float get_num(){
    float num;
    scanf("%f", &num);
    return num;
}
//GETS NEXT OPERATOR
float get_op(){
    char op;
    //KEEPS LOOKING FOR OPERATOR IF ONE WASNT GIVEN
    scanf("%c", &op);
    while (op == ' '){
        scanf("%c", &op);
    }
    return op;
}

//MULTIPLICATION AND DIVISION
float m_exp(float sub_exp, char op){
    float f1;
    char op1;
    //CHECKS IF THE OPERATOR IS EITHER A PLUS, MINUS
    if(op == '+' || op == '-' || op == '\n'){
        ungetc(op,stdin);
        return sub_exp;
    }
    else {
        //GETS NEXT NUMBER
        f1 = get_num();
        //GETS NEXT OPERATOR
        op1 = get_op();
        //CHECKS TO SEE IF INPUT IS VALID
        if (op1 != '*' && op1 != '/' && op1 != '+' && op1 != '-' && op1 != '\n'){
            printf("Invalid Input\n");
            exit(EXIT_FAILURE);
        }
        //MULTIPLIES AND DIVIDES
        if (op == '*'){
            f1 = sub_exp * f1;
        }else if (op == '/'){
            f1 = sub_exp / f1;
        }
        //RECURSIVE CALLS
        return m_exp(f1, op1);
    }
}

//ADDITION AND SUBTRACTION
float s_exp(float sub_exp, char op){
    float f1;
    char op1;
        //CHECKS TO SEE IF THE EQUATION IS AT ITS END
        if(op == '\n'){
        return sub_exp;
        }
        //GETS NEXT NUMBER AND NEXT OP
        f1 = m_exp(1,'*');
        op1 = get_op();
        //CHCKS TO SEE IF INPUT IS VALID
        if (op1 != '*' && op1 != '/' && op1 != '+' && op1 != '-' && op1 != '\n'){
            printf("Invalid Input\n");
            exit(EXIT_FAILURE);
        }
        //ADDS AND SUBTRACTS
        if (op == '+'){
            f1 = sub_exp + f1;
        }else if (op == '-'){
            f1 = sub_exp - f1;
        }
        //RECURSIVE CALL
        return s_exp(f1, op1);
}
