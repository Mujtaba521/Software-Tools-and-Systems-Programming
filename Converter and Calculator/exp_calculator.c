#include <stdio.h>
float power(float base, int powerRaised);//PROTOTYPE

int main(){
    float base,result; //INITILIZES VARIABLES
    int powerRaised;

    printf("Enter base number: ");//USER INPUT
    scanf("%f5678",&base);

    printf("Enter power number: ");
    scanf(" %d",&powerRaised);

    result = power(base, powerRaised);//TOTAL

    printf("%.2f ^ %d = %f", base, powerRaised, result);//PRINTS RESULT
    return 0;
}

//METHOD TO RAISE base TO powerRaised
float power(float base, int powerRaised){
    float result;//GETS TOTAL
    if (powerRaised == 0){//BASE CASE
        return 1;
    }else {
        if (powerRaised % 2 == 0){ //IF ITS EVEN
            result = power(base,powerRaised/2);//INITIAL STEP TO BREAKDOWN EQUATION INTO SIMPLER STEPS
            return result * result;
        }else{//IF ITS ODD
            return base*power(base,powerRaised-1);
        }
    }
    return 0;
}
