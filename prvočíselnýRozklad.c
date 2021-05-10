#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ARRAY_LEN 1000000

long readInput(void);
void decompose(long num, double maxNum, int *primeNums);
void isLastNum(long num , int i);
void fillArray(int *primeNums);
void eratosthenes(int *primeNums, double *maxNum);

enum {ERROR_INPUT = 100};

int main(void) {
    int ret = 0;
    long num;
    double maxNum = 5;
    int primeNums[ARRAY_LEN]; //Allocate a empty array
    fillArray(primeNums); //Fill the array with numbers
    eratosthenes(primeNums, &maxNum); // Leave only prime numbers

    //Reading loop
    while ((num = readInput()) > 0) {
        printf("Prvociselny rozklad cisla %ld je:\n", num);
        if (num == 1) {
            printf("1\n");
        } else {
            decompose(num, maxNum, primeNums);
        }
    }
    if (num < 0) {
        fprintf(stderr, "Error: Chybny vstup!\n");
        ret = ERROR_INPUT;
    }



    return ret;
}

//Read a number from input
long readInput(void) {
    long num;
    if (scanf("%ld", &num) != 1) {
        num = -1;
    }

    return num;
}

//Divide number by prime numbers
void decompose(long num, double maxNum, int *primeNums) {
    for (int i = 2; i <= maxNum && num != 1; ++i) {
        int exponent = 0;
        if (primeNums[i - 1] != 0) {
            while (num % primeNums[i - 1] == 0) {
                num /= i;
                ++exponent;
            }
        }   
        if (exponent > 1) {
            printf("%d^%d", i, exponent);
            isLastNum(num, i);
        } else if (exponent == 1) {
            printf("%d", i);
            isLastNum(num, i);
        }
    }
}

//Check if printing last number
void isLastNum(long num, int i) {
    if  (num >= i) {
        printf(" x ");
    } else {
        printf("\n");
    }
}

//Fill array with numbers from 1 to ARRAY_LEN
void fillArray(int *primeNums) {
    for (int i = 0; i < ARRAY_LEN; ++i) {
        primeNums[i] = i + 1;
    }
}

//Sieve of Eratosthenes
void eratosthenes(int *primeNums, double *maxNum) {
    for (int i = 1; i < ARRAY_LEN; ++i) {
        if (primeNums[i] != 0 && primeNums[i] < sqrt(*maxNum)) {
            int primeN = primeNums[i];
            for (int j = i + 1; j <= ARRAY_LEN - 1; ++j) {
                if (primeNums[j] % primeN == 0) {
                    primeNums[j] = 0;
                } else {
                    *maxNum = primeNums[j];
                }
            }
        }
    }
}
