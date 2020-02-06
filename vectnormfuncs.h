/* Vector Normalizer program */
/* Developed by Dat Phan */
#define MAX_ARRAY_SIZE 9    /* Default array size */
#define EXITCODE_DEF 0      /* Default exit code the program will start with */
#define EXITCODE_ERR 1      /* Exit code when the program encounters an error */
#define ERR_MSG "BAD INPUT" /* Error message when the user enters something incorrect */ 

/* List of functions */
void eatLine(void);
void vectorPrinter(int size, const double A[], char message[]);
int vectorReader(int size, double A[]);
int intValidation(char strg[]);
int doubleValidation(char strg[]);
double vect_length(int size, double A[]);
void normalize(int size, double A[]);