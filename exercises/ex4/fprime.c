#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int multModulo(int a, int b, int n);
int expMod(int a, int exp, int n);
int expMod_efficient(int a, int exp, int n);
int findFermatWitness(int n, int numReps);




int main(){
    printf("expMod(2,10,5) : %d\n", expMod(2,10,5));
    printf("expMod(10,111,3) : %d\n", expMod(10,111,3));
    printf("expMod(10,1,3) : %d\n", expMod(10,1,3));
    printf("expMod(123,123,321) : %d\n", expMod(123,123,321));
    printf("expMod(3063695, 6700412, 6700413) : %d\n", expMod(3063695, 6700412, 6700413));
    printf("expMod(6700415, 6700416, 6700417) : %d\n", expMod(6700415, 6700416, 6700417));
    printf("expMod(10,0,5) : %d\n", expMod(10,0,5));
    printf("expMod(10,-1,5) : %d\n", expMod(10,-1,5));
    printf("expMod(10,3,0) : %d\n", expMod(10,3,0));
    printf("expMod(-10,3,2) : %d\n", expMod(-10,3,2));
    return 0;
}


int multModulo(int a, int b, int n){
    double x = ((double)(a%n)) * (b%n);
    return x - ((int)(x/n) * (double)n);
}


int expMod(int a, int exp, int n){
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

int expMod_efficient(int a, int exp, int n){
    return 0;
}

int findFermatWitness(int n, int numReps){
    return 0;
}