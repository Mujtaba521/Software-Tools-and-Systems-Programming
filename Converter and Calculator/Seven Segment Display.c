#include <stdio.h>

int
main ()
{
    const char segments[10][3][3] = {

    {{' ', '_', ' '}, {'|', ' ', '|'}, {'|', '_', '|'}},{{' ', ' ', ' '}, {' ', ' ', '|'}, {' ', ' ', '|'}},
    {{' ', '_', ' '}, {' ', '_', '|'}, {'|', '_', ' '}},{{' ', '_', ' '}, {' ', '_', '|'}, {' ', '_', '|'}},
    {{' ', ' ', ' '}, {'|', '_', '|'}, {' ', ' ', '|'}},{{' ', '_', ' '}, {'|', '_', ' '}, {' ', '_', '|'}},
    {{' ', '_', ' '}, {'|', '_', ' '}, {'|', '_', '|'}},{{' ', '_', ' '}, {' ', ' ', '|'}, {' ', ' ', '|'}},
    {{' ', '_', ' '}, {'|', '_', '|'}, {'|', '_', '|'}},{{' ', '_', ' '}, {'|', '_', '|'}, {' ', '_', '|'}}};

    //INFINITE LOOP
    while (1 == 1) {
        //GETS USER INPUT
        int x;
        printf ("Enter an Integer: ");
        scanf (" %d", &x);

        //NEGATIVE CHECK
        int check = -1; // CHECK VARIABLE
        if (x < 0) {
	        check = 1;	//REINITILIZES VARIABLE
	        x = x * -1;	//NEEDED FOR SPACING
	    }

        char input[10];
        //STORES VALUE IN CHECK
        sprintf (input, "%d", x);
        printf (" ");

        //PRINTS TOP LINE
        int i = 0;
        while (input[i] != '\0') {
	        //LINE SEGMENTS
	        int j;
	        for (j = 0; j < 3; j++) {
                printf ("%c", segments[input[i] - 48][0][j]);	//ACSCII VALUE
	        }
	        printf (" ");
	        i++;
	    }
        printf ("\n"); //NEXT LINE


        //MIDDLE LINE
        if (check == 1) { //POSITIVE OR NEGATIVE
			printf ("_");
	    } else {
	        printf (" ");
	    }

        i = 0;
        while (input[i] != '\0') {
            int k;
	        for (k = 0; k < 3; k++) {
	            printf ("%c", segments[input[i] - 48][1][k]);
	        }
	        printf (" ");
	        i++;
	    }
        printf ("\n");

        //BOTTOM LINE
        printf (" ");
        i = 0;
        while (input[i] != '\0') {
            int l;
	        for (l = 0; l < 3; l++) {
	            printf ("%c", segments[input[i] - 48][2][l]);
	        }
	        printf (" ");
	        i++;
	    }
        printf ("\n");

        //CONTINUE
        char keepGoing;
        printf("To Continue 'Y',To Stop 'N' ");
        scanf("%c", &keepGoing);

        if(keepGoing == 'N') {
            break; //END
        }
        printf("\n");
    }
    return 0;
}
