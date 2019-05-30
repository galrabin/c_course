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

/********************************/
/**    FUNCTION DECLARATIONS   **/
/********************************/

/*********************************
* Problem 1.1
* Chage Integer type to String 
* type.
*********************************/
int stringToInt(const char *str);

/*********************************
* Problem 1.1
* Chage Integer type to String 
* type.
*********************************/
int isIntString(const char *str);

/********************************/
/**    FUNCTION DEFINITIONS    **/
/********************************/

/*********************************
* Problem 1.1
* Change Integer type to String 
* type.
* params:
* str (pointer)
* returns integer type
*********************************/
// Compile === gcc -Wall -D TEST_1_1 /share/ex_data/ex5/test_ex5.c intString.c -o test_ex5_1_1
// Test === test_ex5_1_1 , compare to = /share/ex_data/ex5/test_ex5_1_1.out
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

/*********************************
* Problem 1.2
* Chack string if valid int
* params:
* str (pointer)
* returns 1 if valid 0 if not
*********************************/
// Compile === gcc -Wall -D TEST_1_2 /share/ex_data/ex5/test_ex5.c intString.c -o test_ex5_1_2
// Test === test_ex5_1_1 , compare to = /share/ex_data/ex5/test_ex5_1_2.out

int isIntString(const char *str)
{
    int size = strlen(str);
    int i = 0;
    while (str[i])
    {
        if (i < size)
        {
            int digit = str[i] - '0';
            if (digit < 48 || digit > 57)
            {
                if (str[i] != '-')
                {
                    return 0;
                }
                else if (i != 0 && str[i + 1] != '0')
                {
                    return 0;
                }
                return 0;
            }
        }
        i++;
    }
    return 1;
}

// int main(int argc, char const *argv[])
// {
//     printf("hello");
//     return 0;
// }
