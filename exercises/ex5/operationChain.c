/*************************************************
*  operationChain.c
*  ----------
*  main function for calculate float by ops
*************************************************/

#include <stdio.h>
#include <string.h>


#define MAX_NUMS 10
#define MAX_INT_LEN 12

/********************************/
/**    FUNCTION DECLARATIONS   **/
/********************************/
/*********************************
* Problem 1.4
* Perform arithmetics on integer
* string.
*********************************/
int doOp(char *intStr1, const char *intStr2, char op);

/*********************************
* Problem 2.1
* Copy int array to list array
*********************************/
char *intToStringList(const int *numArray, int arrayLen, char *buffer);

/****************************************
* Problem 2.3
* Performs arithmetics on the int list
*****************************************/
int doOpChain(char *intStrList, char op, char *res_intStr);

/**********************************************************************************
* Problem 3
* main function for calculate float by ops Performs arithmetics on the int list
***********************************************************************************/
int main(int argc, char const *argv[])
{ 
    char op;
    printf("Please enter an operator (+ or *) followed by up to 10 integer numbers.\n");
    scanf("%c ", &op);

    if (op != '+' && op != '*') {
        printf("Invalid operator %c\n", op);
        return 1;
    }

    double nums[MAX_NUMS];
    int input, check, current;
    for (int i = 0; i < MAX_NUMS; i++) {
        input = scanf("%lf ", &nums[i]);
        check = nums[i];
        if ((!input) || (int) check - nums[i] != 0) {
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
    int status = doOpChain(numsCastStrings, op, resultString);
    if (!status) {
        printf("Result is out of bound\n");
        return 1;
    }
    printf("= %s", resultString);
    return 0;
}