/*************************************************
*  intString.c
*  ----------
*  Perform operation of converting integer to  
*  string and vice versa, also perform operations.
*************************************************/
#include <string.h>
#include <stdio.h>

#define MAX_INT 2147483647
#define MIN_INT -2147483648
#define SIZE 33

/********************************/
/**    FUNCTION DECLARATIONS   **/
/********************************/

/*********************************
* Problem 1.1
* Change String type to integer 
* type.
*********************************/
int stringToInt(const char *str);

/*********************************
* Problem 1.2
* Chage Integer type to String 
* type.
*********************************/
int isIntString(const char *str);

/*********************************
* Problem 1.3
* Change Integer type to String 
* type.
*********************************/
char *intToString(int num, char *buffer);
char *intToStringRecursion(int num, char *buffer);

/*********************************
* Problem 1.4
* Perform arithmetics on integer
* string.
*********************************/
int doOp(char *intStr1, const char *intStr2, char op);

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
    int sign = 1;
    double degree = 0.1;

    int size = strlen(str);

    if (!isIntString(str))
    {
        return 0;
    }

    if (str[0] == 45)
    {
        i = 1;
        sign = -1;
    }

    for (; i < size; i++)
    {
        if (degree == 0.1 && str[i] == '0')
        {
            continue;
        }
        degree *= 10;
    }

    if (sign == -1)
    {
        i = 1;
    }
    else
    {
        i = 0;
    }

    double result = 0;
    for (; i < size; i++)
    {
        if (result == 0 && str[i] == '0')
        {
            continue;
        }
        result += degree * ((int)str[i] - 48);
        degree /= 10;
    }

    if (sign == -1)
    {
        result *= -1;
    }

    if (result > MAX_INT || result < MIN_INT)
    {
        return 0;
    }

    return (int)result;
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
    for (int i = 0; i < size; i++)
    {
        int ascii = str[i];
        if (ascii == 45 && i == 0)
        {
            int next_ascii = str[i + 1];
            if (next_ascii == 48)
            {
                return 0;
            }
            continue;
        }
        if (ascii <= 57 && 48 <= ascii)
        {
            if (ascii == 48 && i == 0)
            {
                int next_ascii = str[i + 1];
                if (next_ascii <= 57 && 48 <= next_ascii)
                {
                    return 0;
                }
            }
            continue;
        }
        return 0;
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
        buffer[1] = (char)0;
        return buffer;
    }
    last_cell = intToStringRecursion(num, buffer);
    last_cell[0] = (char)0;
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
int doOp(char *intStr1, const char *intStr2, char op)
{
    if (!(isIntString(intStr1)) || !(isIntString(intStr2)))
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
        case '/':
            if (num2 == 0)
            {
                return 0;
            }
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

/********************************************
* Problem 2.1
* move integers array to char array to create
* integer list as defined in the mission.
* params:
* numArray (pointer to int array)
* arrayLen (integer)
* buffer (pointer to char array)
* returns pointer to list
**********************************************/
// Compile === gcc -Wall -D TEST_2_1 /share/ex_data/ex5/test_ex5.c intString.c intStringList.c -o test_ex5_2_1
// Test === test_ex5_1_4 , compare to = /share/ex_data/ex5/test_ex5_2_1.out
char *intToStringList(const int *numArray, int arrayLen, char *buffer)
{
    char *buffer_to_return = buffer;
    char *current_buffer = buffer;
    if (arrayLen == 0)
    {
        buffer[0] = (char)0;
        buffer[1] = (char)0;
    }
    for (int i = 0; i < arrayLen; i++)
    {
        current_buffer = intToString(numArray[i], current_buffer);

        int j = 0;
        while ((int)current_buffer[j] != 0)
        {
            current_buffer += 1;
        }
        current_buffer += 1;
    }
    current_buffer[0] = (char)0;

    return buffer_to_return;
}

/*********************************
* Problem 2.2
* Change Integer type to String
* type.
* params:
* intStringList (pointer to int list)
* returns pointer to next integer
*********************************/
// Compile === gcc -Wall -D TEST_2_2 /share/ex_data/ex5/test_ex5.c intString.c intStringList.c -o test_ex5_2_2
// Test === test_ex5_2_2 , compare to = /share/ex_data/ex5/test_ex5_2_2.out
char *nextIntString(char *intStringList)
{
    static char *last_list;
    static char *last_int;
    if (last_list != intStringList)
    {
        last_list = intStringList;
        last_int = intStringList;
        return last_int;
    }
    else
    {
        if (last_int[0] == (char)0)
        {
            return last_int;
        }
        int j = 0;
        while (last_int[j] != (char)0)
        {
            j++;
        }
        last_int += j + 1;
        return last_int;
    }

    return last_list;
}



// int main(int argc, char const *argv[])
// {
//     int a[] = {12, 13, 14};
//     int arrayLen = 3;
//     char b[SIZE];
//     char *c = intToStringList(a, arrayLen, b);
//     char *d = nextIntString(c);
//     printf("%c", d[0]);
//     printf("%c\n", d[1]);

//     char *e = nextIntString(c);
//     printf("%c", e[0]);
//     printf("%c\n", e[1]);

//     char *f = nextIntString(c);
//     printf("%c", f[0]);
//     printf("%c\n", f[1]);

//     char *h = nextIntString(c);
//     printf("%d", h[0]);
//     printf("%d\n", h[0]);

//     char result[33];
//     int x = doOpChain(c, 'd', result);
//     printf("%d\n",x);
//     printf("%s", result);
//     return 0;
// }
