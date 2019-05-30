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
            int digit = str[i];
            if ((digit < 48 || digit > 57) || (i == 0 && str[i] == '0' && size > 1))
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

/*********************************
* Problem 1.3
* Check string if valid int
* params:
* num (integer)
* str (pointer)
* returns string of num
*********************************/
// Compile === gcc -Wall -D TEST_1_3 /share/ex_data/ex5/test_ex5.c intString.c -o test_ex5_1_3
// Test === test_ex5_1_3 , compare to = /share/ex_data/ex5/test_ex5_1_3.out
char *intToStringRecursion(int num, char *buffer)
{
    if (num < 0)
    {
        buffer[0] = (char)'-';
        num *= -1;
        return intToStringRecursion(num, buffer + 1);
    }
    else if (num > 0)
    {
        buffer = intToStringRecursion(num / 10, buffer++);
        buffer[0] = (char)(num % 10 + '0');
        return buffer + 1;
    }
    return buffer;
}

char *intToString(int num, char *buffer)
{
    char *last_cell;
    if (num == 0)
    {
        buffer[0] = (char)'0';
        buffer[1] = '\0';
        return buffer;
    }
    last_cell = intToStringRecursion(num, buffer);
    last_cell[0] = '\0';
    return buffer;
}

/*********************************
* Problem 1.4
* Computing integer operations recieved as strings
* params:
* intStr1 (pointer)
* intStr2 (pointer)
* op (char)
* returns 1 if valid num or operation 0 if not
*********************************/
// Compile === gcc -Wall -D TEST_1_4 /share/ex_data/ex5/test_ex5.c intString.c -o test_ex5_1_4
// Test === test_ex5_1_4 , compare to = /share/ex_data/ex5/test_ex5_1_4.out
int doOp(char *intStr1, char *intStr2, char op)
{
    if (isIntString(intStr1) || isIntString(intStr2))
    {
        return 0;
    }
    else
    {
        double result = 0;
        double num1 = stringToInt(intStr1);
        double num2 = stringToInt(intStr2);
        switch (op)
        {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        default:
            break;
        }
        if (result > MAX_INT || result < MIN_INT)
        {
            return 0;
        }
        int res = (int)result;
        intToString(res, intStr1);
        return 1;
    }

    return 1;
}

// int main(int argc, char const *argv[])
// {
//     printf("#############################################\n");
//     printf("#############String to integer###############\n");
//     printf("#############################################\n");
//     printf("%s validation suppote to be %d : %d\n", "34987", 1, isIntString("34987"));
//     printf("%s validation suppote to be %d : %d\n", "+34987", 0, isIntString("+34987"));
//     printf("%s validation suppote to be %d : %d\n", "0", 1, isIntString("0"));
//     printf("%s validation suppote to be %d : %d\n", "-0", 0, isIntString("-0"));
//     printf("%s validation suppote to be %d : %d\n", "00", 0, isIntString("00"));
//     printf("%s validation suppote to be %d : %d\n\n", "765\0.", 1, isIntString("765\0."));
// }
