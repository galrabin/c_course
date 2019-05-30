/*************************************************
*  intString.c
*  ----------
*  A program containing functions for safely
*  computing the product of two integer numbers
*************************************************/
#include <string.h>
#include <stdio.h>

#define MAX_INT 2147483647
#define MIN_INT -2147483648

// Compile === gcc -Wall -D TEST_1_1 /share/ex_data/ex5/test_ex5.c intString.c -o test_ex5_1_1
// Test === test_ex5_1_1 , compare to = /share/ex_data/ex5/test_ex5_1_1.out

/********************************/
/**    FUNCTION DECLARATIONS   **/
/********************************/

/*********************************
* Problem 1.1
* Chage Integer type to String 
* type.
*********************************/
int stringToInt(const char *str);

/********************************/
/**    FUNCTION DEFINITIONS    **/
/********************************/

/*********************************
* Problem 1.1
* Chage Integer type to String 
* type.
* params:
* str (pointer)
* returns integer type
*********************************/
int stringToInt(const char *str)
{
    int i = 0;
    double degree = 1;
    double convert = 0;
    int sign = 1;
    int size = strlen(str) - 1;
    if (str[0] == '-')
    {
        i = 1;
        sign = -1;
    }

    while (str[i])
    {
        if (str[i] == '-' && i == 0)
        {
            degree *= 10;
        }
        else if (str[i] > '9' || str[i] < '0')
        {
            return 0;
        }
        else if (i < size)
        {
            degree *= 10;
        }
        i++;
    }

    if (sign == -1)
    {
        i = 1;
    }
    else
    {
        i = 0;
    }

    while (str[i])
    {
        double num = (double)(str[i] - 48) * degree;
        convert += num;
        degree /= 10;
        i++;
    }

    if (sign == -1)
    {
        convert *= -1;
    }

    if (convert > MAX_INT || convert < MIN_INT)
    {
        return 0;
    }

    return convert;
}