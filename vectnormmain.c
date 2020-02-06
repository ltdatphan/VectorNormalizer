/* Vector Normalizer program */
/* Developed by Dat Phan */

#include <stdlib.h>
#include <stdio.h>
#include "vectnormfuncs.h"

int main(void){
    printf("\n\n=== Welcome to the Vector normalizer ===\n");
    printf("Made by Dat Phan\n\n");
    printf("Start by entering the size of your vector and followed by the values of each values in your array.\nOnce you have declared a vector size of n, the program will not show any output until you have provided enough arguments.\nTo exit, provide an input of 0 or interrupt using Ctrl + C or Ctrl + D.\n\n");
    int prog_status = EXITCODE_DEF; /* This var keeps track of the state of program (if array errors occured). It is default as 0 */
    char firstWord[10]; /* string to hold the first word that will be scanned */

    while(scanf("%9s", firstWord)==1){   /* Keeps scanning until user call EOF (CTRL+D) */
        if(intValidation(firstWord)==0){ /* Checks if the string is a valid int */
            printf("%s\n", ERR_MSG);     /* If it is not valid, print err message */
            prog_status = EXITCODE_ERR;  /* Change the program status */
            eatLine(); /* Clear the rest of the input buffer */
            continue;  /* Repeat the loop */
        }
        int size; /* Size of vector */ 
        sscanf(firstWord, "%d", &size); /* Parse string to integer using sscanf */
        
        if (size==0) exit(prog_status); /* If the user enters 0, program exits */
        
        double vector[MAX_ARRAY_SIZE];  /* Declare an array to hold vector values */
        
        int read_status = vectorReader(size, vector); /* Reads in vector and store in the variable
                                                       * if it was successful or not */
    
        if (read_status != -2)eatLine(); /* If the user enters EOF, make sure not to clear buffer to avoid errors 
                                            because there is nothing to clear. Otherwise clears the buffer after vectorReader() was called
                                          */

        if(read_status==1){ /* If it was successfully read, print the vector out and normalize it*/
            printf("The size of this vector is: %d. The results are as follow:\n", size );
            vectorPrinter(size, vector, "VECTOR"); /* Print the current vector */
            normalize(size, vector); /* Normalize vector and print result */
        } else if (read_status == -1 || read_status == -2) exit(prog_status); /* If the user enters '0' or Ctrl+D then exits */
        else prog_status = EXITCODE_ERR; /* Otherwise change the prog_status if it fails to read properlly */
    }
    exit(prog_status); /* exit with program status */
}