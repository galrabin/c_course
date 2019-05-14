#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int multModulo(int a, int b, int n);
int expMod(int a, int exp, int n);
int expMod_efficient(int a, int exp, int n);
int findFermatWitness(int n, int numReps);
int getLSBpos(int);
int getMSBpos(int);
int getNextBitPos(int);





int main() {
    /***         USE THIS CODE FOR TESTING     ***/
    /***        YOU MAY ALSO ADD MORE TESTS.   ***/
    /***      THIS CODE NEEDS TO BE COPIED TO  ***/
    /***           YOUR FILE FOR TESTING       ***/

    // Copy these lines to test your solutions to Problem 3.1
    printf("Tests for multModulo:\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("multModulo(%7d,%7d,%7d) = %10d\n", 2, -3, 5, multModulo(2,-3, 5));
    printf("multModulo(%7d,%7d,%7d) = %10d\n", 0, 400, 11, multModulo(0,400, 11));
    printf("multModulo(%7d,%7d,%7d) = %10d\n", 12345, 67890, 30, multModulo(12345,67890,30));
    printf("multModulo(%7d,%7d,%7d) = %10d\n", -100000, 100000, 123, multModulo(-100000,100000, 123));
    printf("multModulo(%7d,%7d,%7d) = %10d\n", 100000, 100000, 123000, multModulo(100000,100000, 123000));
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

    // Copy these lines to test your solutions to Problem 3.2
    printf("\n\nTests for expMod:\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("expMod(%4d, %4d, %4d) = %4d\n",  2, 10,  5, expMod(   2,  10,  5));
    printf("expMod(%4d, %4d, %4d) = %4d\n", 10,111,  3, expMod(  10, 111,  3));
    printf("expMod(%4d, %4d, %4d) = %4d\n", 10,  1,  3, expMod(  10,   1,  3));
    printf("expMod(%4d, %4d, %4d) = %4d\n",123,123,321, expMod( 123, 123,321));
    printf("expMod(%4d, %4d, %4d) = %4d\n",3063695,6700412,6700413, expMod(3063695,6700412,6700413));
    printf("expMod(%4d, %4d, %4d) = %4d\n",6700415,6700416,6700417, expMod(6700415,6700416,6700417));
    printf("expMod(%4d, %4d, %4d) = %4d\n", 10,  0,  5, expMod(  10,   0,  5));
    printf("expMod(%4d, %4d, %4d) = %4d\n", 10, -1,  5, expMod(  10,  -1,  5));
    printf("expMod(%4d, %4d, %4d) = %4d\n", 10,  3,  0, expMod(  10,   3,  0));
    printf("expMod(%4d, %4d, %4d) = %4d\n",-10,  3,  2, expMod( -10,   3,  2));

    // Copy these lines to test your solutions to Problem 3.3
    printf("\n\nTests for findFermatWtiness:\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("findFermatWitness(%10d, %10d) = %10d\n",         5,        100, findFermatWitness(           5,       100));
    printf("findFermatWitness(%10d, %10d) = %10d\n",         4,          1, findFermatWitness(           4,         1));
    printf("findFermatWitness(%10d, %10d) = %10d\n",         3,        100, findFermatWitness(           3,       100));
    printf("findFermatWitness(%10d, %10d) = %10d\n",         2,         11, findFermatWitness(           2,        11));
    printf("findFermatWitness(%10d, %10d) = %10d\n",         1,         13, findFermatWitness(           1,        13));
    printf("findFermatWitness(%10d, %10d) = %10d\n",         0,          1, findFermatWitness(           0,         1));
    printf("findFermatWitness(%10d, %10d) = %10d\n",        10,          0, findFermatWitness(          10,         0));
    printf("findFermatWitness(%10d, %10d) = %10d\n",        10,        -10, findFermatWitness(          10,       -10));
    printf("findFermatWitness(%10d, %10d) = %10d\n",        11,        100, findFermatWitness(          11,       100));
    printf("findFermatWitness(%10d, %10d) = %10d\n",       353,       1000, findFermatWitness(         353,      1000));
    //printf("findFermatWitness(%10d, %10d) = %10d\n",   6700417,    1000000, findFermatWitness(     6700417,   1000000));
    printf("findFermatWitness(%10d, %10d) = %10d\n",   6700413,       1000, findFermatWitness(     6700413,      1000));


    printf("\n\n#####################################\n");
    printf("  3.4 User input for fermat witness\n");
    printf("#####################################\n");
    printf("Please enter a positive integer to be tested for primality\n");
    {
        double prime_user;
        int valid_num = scanf("%lf", &prime_user);
        int valid_whole = 1;
        if ((prime_user - (int)prime_user) != 0.0){
            valid_whole = 0;
        }
        if (prime_user < 0 || prime_user >= 2147483648 || valid_num != 1 || valid_whole == 0){
            printf("Not a valid positive int");
            return 1;
        }
        int numReps = 100;
        int test = findFermatWitness((int)prime_user,numReps);
        if (test != 0){
            printf("The number %d is a Fermat witness that number %d is not prime.", test, prime_user);
        } else {
            printf("The number %d is pottentially prime, No Fermat witness found.", (int)prime_user);
        }
    }

    // Copy these lines to test your solutions to Problem 3.5
    printf("Tests for expMod_efficient:\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("expMod_efficient(%4d, %4d, %4d) = %4d\n",  2, 10,  5, expMod_efficient(   2,  10,  5));
    printf("expMod_efficient(%4d, %4d, %4d) = %4d\n", 10,111,  3, expMod_efficient(  10, 111,  3));
    printf("expMod_efficient(%4d, %4d, %4d) = %4d\n", 10,  1,  3, expMod_efficient(  10,   1,  3));
    printf("expMod_efficient(%4d, %4d, %4d) = %4d\n",123,123,3, expMod_efficient( 123, 123, 321));
    printf("expMod_efficient(%4d, %4d, %4d) = %4d\n",3063695,6700412,6700413, expMod_efficient(3063695,6700412,6700413));
    printf("expMod_efficient(%4d, %4d, %4d) = %4d\n",6700415,6700416,6700417, expMod_efficient(6700415,6700416,6700417));
    printf("expMod_efficient(%4d, %4d, %4d) = %4d\n", 10,  0,  5, expMod_efficient(  10,   0,  5));
    printf("expMod_efficient(%4d, %4d, %4d) = %4d\n", 10, -1,  5, expMod_efficient(  10,  -1,  5));
    printf("expMod_efficient(%4d, %4d, %4d) = %4d\n", 10,  3,  0, expMod_efficient(  10,   3,  0));
    printf("expMod_efficient(%4d, %4d, %4d) = %4d\n",-10,  3,  2, expMod_efficient( -10,   3,  2));
    return 0;
}


int multModulo(int a, int b, int n){
    double x = ((double)(a%n)) * (b%n);
    return x - ((int)(x/n) * (double)n);
}


int expMod(int a, int exp, int n){
    /*
     * Perform (a ^ exp) mod n
     * Parameters :
     * n, exp, n = integers.
     * Returns:
     * Solution to equation Perform (a ^ exp) mod n
     */
    if (a <= 0 || exp < 0 || n <= 0){
        return 0;
    }
    int prod = a;
    if (exp == 1){
        prod = a % n;
    }
    if (exp == 0){
        prod = 1 % n;
    }
    for (int i = 1; i < exp; i++){
        prod = multModulo(prod,a,n);
    }
    return  prod;
}


int expMod_efficient(int a, int exp, int n) {
    if (a <= 0 || exp < 0 || n <= 0) {
        return 0;
    }
    if (exp == 0) {
        return 1;
    }
    if (exp == 1) {
        return a % n;
    }

    int product;
    if (exp % 2 == 1) {
        product = a % n;
    } else {
        product = 1;
    }

    exp = exp >> 1;

    while (exp > 0) {
        a = multModulo(a, a, n);

        if (exp % 2 == 1) {
            product = multModulo(product, a, n);
        }
        exp = exp >> 1;
    }
    return product;
}

int findFermatWitness(int n, int numReps){
    /*
     * This function check if number is prime or composite.
     *
     * Parameters:
     * 1. n - number to validate if prime or composite.
     * 2. numReps - number of repetitions to find witness number by fermat primality testing.
     *
     * return:
     * return 1 if number is prime, else if its composite it returns 0.
     */
    if (numReps < 1){
        return 0;
    }
    if (n <= 3){
        return 0;
    }
    for (int i = 0; i < numReps; i++){
        int rand_in_range = (rand() % (n - 2)) + 2;
        int witness_check = expMod(rand_in_range,n-1,n);
        if (witness_check != 1) {
            return rand_in_range;
        }
    }
    return 0;
}



/*********************************
* Problem 2.2
* computes the LSB of a given number
* param:
* a (int)
* returns the LSB of a
*********************************/
int getLSBpos(int a) {
    /*** Problem 2.2:                   ***/
    /*** vvvv MODIFY HERE vvvv          ***/
    if (a == 0){
        return -1;
    } else {
        if ((a & 1) == 1) {
            return 0;
        } else {
            return getLSBpos(a / 2) + 1;
        }
    }
    return 0;
    /*** ^^^^ MODIFY HERE ^^^^          ***/
}

/*********************************
* Problem 2.3
* computes the MSB of a given number
* param:
* a (int)
* returns the MSB of a
*********************************/
int getMSBpos(int a)  {
    /*** Problem 2.3:                   ***/
    /*** vvvv MODIFY HERE vvvv          ***/
    if (a == 0){
        return -1;
    } else {
        if (a > 0) {
            int move = getLSBpos(a) + 1;
            if (a == 1) {
                a = 0;
            } else {
                a = a >> move;
            }
            return getMSBpos(a) + move;
        } else if (a < 0){
            return 31;
        }
    }
    return 0;
    /*** ^^^^ MODIFY HERE ^^^^          ***/
}


/*********************************
* Problem 2.4
* computes the next bit turned on
* in the binary representation
* of a given number
* param:
* a (int)
* if parameter a equals the last number that the function was called with,
* then return the next bit position in bp(a).
* if previous bit position was the MSB, then reutrn -1.
* if parameter a is differnt from the last number that the function was called with,
* or the last position returned was -1, then return the LSB.
*********************************/
int getNextBitPos(int a) {
    /*** Problem 2.3:                                     ***/
    /*** last a the function was called with              ***/
    static int last_a   =  0;
    /*** last position that the function returned         ***/
    static int last_pos = -1;

    /***             vvvv MODIFY HERE vvvv               ***/
    if (a != last_a){
        last_a = a;
        last_pos = getLSBpos(a);
        return last_pos;
    }
    if (last_pos == getMSBpos(a)) {
        last_pos = -1;
        return last_pos;
    } else {
        int move = last_pos + 1;
        a = a >> move;
        int next_one = getLSBpos(a);
        last_pos += next_one + 1;
        return last_pos;
    }
    /***             ^^^^ MODIFY HERE ^^^^               ***/

    return last_pos;
}

/*********************************
* Problem 2.5
* prints all bit positions turned on
* in the binary representation
* of a given number
* param:
* a (int)
* uses the following format: bp(a) = pos1 pos2 ...
* there should be a single space character between every two positions
* and a newline should be printed in the end.
*********************************/
void printBP(int a){
    /***             vvvv MODIFY HERE vvvv               ***/
    int lsb = getLSBpos(a);
    int current = getNextBitPos(a);
    if (lsb != current){
        while (lsb != current){
            current = getNextBitPos(a);
        }
    }
    printf("bp(%d) =",a);
    while (current != -1){
        printf(" %d", current);
        current = getNextBitPos(a);
    }
    printf("\n");
    /***             ^^^^ MODIFY HERE ^^^^               ***/
}
