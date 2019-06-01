#include <stdio.h>
#include <string.h>


#define MAX_NUMS 10
#define MAX_INT_LEN 12

char *intToStringList(const int *numArray, int arrayLen, char *buffer);

int doOpChain(char *intStrList, char op, char *res_intStr);


int main() {

    char op;
    printf("Please enter an operator (+ or *) followed by up to 10 integer numbers.\n");
    scanf("%c ", &op);

    if (op != '+' && op != '*') {
        printf("Invalid operator %c\n", op);
        return 1;
    }

    double nums[MAX_NUMS];
    int input, check, space, current;
    for (int i = 0; i < MAX_NUMS; i++) {
        check = scanf("%lf ", &nums[i]);
        input = nums[i];
        space = input - nums[i];
        if (!input || space != 0) {
            if (i == 0) {
                printf("No valid numbers were entered");
                return 1;
            }
            break;
        }
        current++;
    }

    int castNumsInt[current];

    for (int i = 0; i < current; i++) {
        castNumsInt[i] = nums[i];
    }

    char numsCastStrings[(MAX_INT_LEN * MAX_NUMS) + 1];
    intToStringList(castNumsInt, current, numsCastStrings);

    char resultString[20];
    int res = doOpChain(numsCastStrings, op, resultString);
    if (!res) {
        printf("Result is out of bound\n");
        return 1;
    }
    printf("= %s", resultString);
    return 0;
}