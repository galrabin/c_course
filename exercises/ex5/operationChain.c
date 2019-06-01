/*************************************************
*  opratioChain.c
*  ----------
*  Main inplementation
*************************************************/
#include <string.h>
#include <stdio.h>

/********************************/
/**    FUNCTION DECLARATIONS   **/
/********************************/

/********************************/
/**    FUNCTION DEFINITIONS    **/
/********************************/

/*********************************
* Problem 3
* Declare main function
* returns exit code 0
*********************************/
// Compile === gcc -Wall intString.c intStringList.c  operationChain.c -o test_ex5_3
// Test === test_ex5_3 , compare to = /share/ex_data/ex5/test_ex5_3.out

int main()
{
    char op;
    float n1, n2, n3, n4, n5, n6, n7, n8, n9, n10;
    printf("Please enter an operator (+ or *) followed by up to 10 integer numbers.\n");
    scanf("%c %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", n1, n2, n3, n4, n5, n6, n7, n8, n9, n10);
    printf("lf", n1);

    return 0;
}
