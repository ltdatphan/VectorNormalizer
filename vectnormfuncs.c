/* Vector Normalizer program */
/* Developed by Dat Phan */
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "vectnormfuncs.h"

/* Function name: eatLine */
/* Purpose: It is used to read and discard the rest of the line of input from stdin.*/
void eatLine(void){
    while(getchar()!='\n'); /* As long as the end of line have not reached, keep on getting the next char */
}


/* Function name: vectorPrinter */
/* Purpose: This function prints a given vector with a message to indicate what the vector represents*/
/* Parameters:
    int size        Integer that stores the size of the vector
    double A[]      The array that hold the values of the vector
    char messagep[] The message that will be printed before the array.
 */
/* Output: It will output the array along with the message
   in this format:
   message: [ ... ]    where ... represents the vector
*/
void vectorPrinter(int size, const double A[], char message[]){
    printf("%s: [ ", message);
	for(int i=0; i<size; i++){ /* For loop to iterate through each element of array */
		printf("%.3lf", A[i]);
		if (i<size-1) putchar(','); /* Make sure not to put a comma for the last element */
		putchar(' ');
	}
    printf("] ");
}


/* Function name: vectorReader */
/* Purpose: This method reads double from stdin and place it into an array */
/* Input:
    int size    The size of the vector
    double A[]  The array that would be used to store the values for the vector
 */
/* Return values:
    1   If the vector was read successfully.
    0   If one of the input was not a valid double.
   -1   If one of the input was 0 (To exit the program).
   -2   If one of the input was EOF (Ctrl+D) (To exit the program).
 */
int vectorReader(int size, double A[]){
    char word[10]; /* String holder */
    for(int count=0; count < size; count++){
            if(scanf("%9s", word)!=1) return -2;  /* Scan in the first 9 characters to prevent overflow. */
                                                  /* If the input was Ctrl+D (EOF) (Nothing was scanned) */
            if (strlen(word)==1 && word[0]=='0') return -1; /* If the input has length 1 and is '0' */

            if(doubleValidation(word)==0){  /* If the string is not a valid double */
                printf("%s\n", ERR_MSG);    /* Print the error message */
                return 0;    
            }
            double num; /* Variable to hold the number */
            sscanf(word, "%9lf", &num); /* Parse string into double */
            A[count]=num; /* Place value into array */
    }
    return 1;  /* If vector was read successfully */
}


/* Function name: intValidation */
/* Purpose: check if a string is a valid number from 0-9*/
/* Input: char strg[] The string that needs to be checked
 */
/* Return values:
    1   If the string was a number from 0-9.
    0   If it is not a valid number.
 */
int intValidation(char strg[]){
    if(strlen(strg)==1){ /* Check if its only has 1 character */
        if(isdigit(strg[0])!=0) return 1; /* Checks if its a digit */
    }
    return 0; /* Return 0 if its not */
}


/* Function name: doubleValidation*/
/* Purpose: check if a given string is a valid double*/
/* Input: char strg[]   The string that needs to be checked
 */
/* Output: 
    1   If the string is a valid double
    0   If it is not.
 */
int doubleValidation(char strg[]){
    int len = strlen(strg);   /* Length of string */

    if(len==1) return intValidation(strg); /* If the length of string is 1 (1 number), call the intValidation to check
                                              and return the result of that function
                                            */
    int count_dot = 0; /* Counter for the number of decimal point */

    if (strg[0]=='-' || isdigit(strg[0])!=0 || strg[0]=='+'); /* Checks if first char in string is a +,- or a digit */
    else if (strg[0]=='.') count_dot++; /* Increase counter if first char is '.' */
    else return 0; /* If the first character is something else, it is not valid */

    for(int i = 1; i<len; i++){ /* For loop to iterate through the string */
        if(strg[i]=='.') count_dot++; /* Check for dots and add to counter */
        else if(isdigit(strg[i])==0) return 0; /* If the character is not a digit, return 0 (not a valid double) */
        
        if (count_dot>1) return 0; /* I there are more than 1 decimal point, return 0 */
        
    }
    return 1; /* Return 1 (valid) if it passes all of the checks */
}


/* Function name: vect_length */
/* Purpose: To get the length of a vector based on a given array (which stores elements of the vector)*/
/* Input: 
    int size    The size of the vector
    double A[]  The array thats stores the vector
 */
/* Output: A double representing the length of the vector */
double vect_length(int size, double A[]){
	double result = 0; /* Holder for result */
	
	double sumOfA = 0; /* Acumulator to hold the sum of square of each element of array*/
	for(int i=0; i<size; i++){   /* For loop to go through array */
		sumOfA = sumOfA + pow(A[i],2); /* square the value of each element and add to acumulator */
	}
	
	result = sqrt(sumOfA); /* square root of acumulator */
	return result;
}


/* Function name: normalize */
/* Purpose: Normalize a vector and make changes to that array */
/* Input: 
    int size    The size of the vector
    double A[]  The array thats stores the vector
 */
/* Output: */
void normalize(int size, double A[]){
	
	double l = vect_length(size, A); /* Get the length of the vector */
	for(int i=0; i<size; i++){ /* For loop to go through each element */
		A[i] = A[i]/l; /* Store result in the same array */
	}
	vectorPrinter(size, A, "NORMALIZED"); /* Print the vector with message "NORMALIZED" */
    printf("\n\n");
}