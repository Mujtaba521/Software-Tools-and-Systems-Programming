#include <stdio.h>
int main(){
    char whichOrder;//VARIABLE INITILIZATION
    int start;
	double initial;
	int keepGoing;

    printf("Converter Program");//INTRODUCTION
    printf("\n-----------------");
    printf("\n\n 1: For Kilometers To Mile");
    printf("\n 2: For Meters To Feet");
    printf("\n 3: For Centimeter To Inch");
    printf("\n 4: For Celcius to Farenheit");
    printf("\n 5: To Exit");

    printf("\n\nEnter Number For Operation: ");
    scanf("%i",&start);

    while (start != 5){//CONTINUES UNTILL USER WISHES TO EXIT PROGRAM
        keepGoing = 0;
        if (start == 1){

            printf("\nEnter K For Kilo-Mile");
            printf("\nEnter M For Mile-Kilo");
            printf("\nEnter Value: ");
            scanf(" %c",&whichOrder);

            do{//CONTINUE GETTING USER INPUT UNTILL USER CHOOSES SPECIFIED ANWSER
                initial = 0;
                if (whichOrder == 'K'){
                    printf("\nEnter Kilo Value: ");
                    scanf(" %lf",&initial);
                    if (initial/1 > 0){//CHECKS IF VALUE IS NUMERIC
                    printf("\nKilometer Value: %.2lf", initial);
                    printf("\nMile Value: %.2lf", initial*0.62137);
                    keepGoing = 1;//VARIABLE THAT ENDS CURRENT CYCLE
                    }
                }else if (whichOrder == 'M') {
                    printf("\nEnter Mile Value: ");
                    scanf(" %lf",&initial);
                    if (initial/1 > 0){
                    printf("\nMile Value: %.2lf", initial);
                    printf("\nKilometer Value: %.2lf", initial*1.609344);
                    keepGoing = 1;
                    }
                }else {//KEEPS CURRENT TASK RUNNING UNTILL USER FULFILLS REQUIREMENTS
                    printf("\nEnter K For Kilo-Mile");
                    printf("\nEnter M For Mile-Kilo");
                    printf("\nEnter Value: ");
                    scanf(" %c",&whichOrder);
                }
            } while (keepGoing != 1);//WHILE LOOP TO CONTINUE PROGRAM UNTILL ACCEPTABLE VALUES ENTERED
        }//ALL PROGRAMS FOLLOW THE SAME FORMAT AFTER SO COMMENTS ARE UNNESSECARY
        else if (start == 2){

            printf("\nEnter M For Meter-Feet");
            printf("\nEnter F For Feet-Meter");
            printf("\nEnter Value: ");
            scanf(" %c",&whichOrder);
            do {
                if (whichOrder == 'M'){
                    printf("\nEnter Meter Value: ");
                    scanf(" %lf",&initial);
                    if (initial/1 > 0){
                    printf("\nMeter Value: %.2lf", initial);
                    printf("\nFeet Value: %.2lf", initial*3.280839895);
                    keepGoing =1;
                    }
                } else if (whichOrder == 'F') {
                    printf("\nEnter Feet Value: ");
                    scanf(" %lf",&initial);
                    if (initial/1 > 0){
                    printf("\nFeet Value: %.2lf", initial);
                    printf("\nMeter Value: %.2lf", initial*0.3048);
                    keepGoing = 1;
                    }
                }else{
                    printf("\nEnter M For Meter-Feet");
                    printf("\nEnter F For Feet-Meter");
                    printf("\nEnter Value: ");
                    scanf(" %c",&whichOrder);
                }
            } while (keepGoing != 1);
        }
        else if (start == 3){

            printf("\nEnter C For Centimeter-Inch");
            printf("\nEnter I For Inch-Centimeter");
            printf("\nEnter Value: ");
            scanf(" %c",&whichOrder);
            do {
                if (whichOrder == 'C'){
                    printf("\nEnter Centimeter Value: ");
                    scanf(" %lf",&initial);
                    if (initial/1 > 0){
                    printf("\nCentimeter Value: %.2lf", initial);
                    printf("\nInch Value: %.2lf", initial*0.3937007874);
                    keepGoing = 1;
                    }
                } else if (whichOrder == 'I') {
                    printf("\nEnter Inch Value: ");
                    scanf(" %lf",&initial);
                    if (initial/1 > 0){
                    printf("\nInch Value: %.2lf", initial);
                    printf("\nCentimeter Value: %.2lf", initial*2.54);
                    keepGoing = 1;
                    }
                }else{
                    printf("\nEnter C For Centimeter-Inch");
                    printf("\nEnter I For Inch-Centimeter");
                    printf("\nEnter Value: ");
                    scanf(" %c",&whichOrder);
                }
            } while (keepGoing != 1);
        }
        else if (start == 4){

            printf("\nEnter C For Celcius-Fahrenhiet");
            printf("\nEnter F For Fahrenhiet-Celcius");
            printf("\nEnter Value: ");
            scanf(" %c",&whichOrder);
            do {
                if (whichOrder == 'C'){
                    printf("\nEnter Celcius Value: ");
                    scanf(" %lf",&initial);
                    if (initial/1 > 0){
                    printf("\nCelcius Value: %.2lf", initial);
                    printf("\nFahrenhiet Value: %.2lf",(initial*1.8)+32);
                    keepGoing = 1;
                    }
                } else if (whichOrder == 'F') {
                    printf("\nEnter Fahrenhiet Value: ");
                    scanf(" %lf",&initial);
                    if (initial/1 > 0){
                    printf("\nFahrenhiet Value: %.2lf", initial);
                    printf("\nCelcius Value: %.2lf", (initial-32)*0.55555555555);
                    keepGoing = 1;
                    }
                }else{
                    printf("\nEnter C For Celcius-Fahrenhiet");
                    printf("\nEnter F For Fahrenhiet-Celcius");
                    printf("\nEnter Value: ");
                    scanf(" %c",&whichOrder);
                }
            } while (keepGoing != 1);
        }
        printf("\n\nEnter Number For Operation: ");
        scanf(" %i",&start);
    }
    return 0;
}
