/*************************************************
*  intStringLisy.c
*  ----------
*  Create new data type called list integers
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

/*********************************
* Problem 2.1
* Copy int array to list array
*********************************/

char *intToStringList(const int *numArray, int arrayLen, char *buffer);

/*********************************
* Problem 2.2
* Copy int array to list array
*********************************/
char *nextIntString(const int *numArray, int arrayLen, char *buffer);

/********************************/
/**    FUNCTION DEFINITIONS    **/
/********************************/

/*********************************
* Problem 2.1
* Change Integer type to String 
* type.
* params:
* numArray (pointer to int array)
* arrayLen (integer)
* buffer (pointer to char array)
* returns integer type
*********************************/
// Compile === gcc -Wall -D TEST_2_1 /share/ex_data/ex5/test_ex5.c intString.c intStringList.c -o test_ex5_1_4
// Test === test_ex5_1_4 , compare to = /share/ex_data/ex5/test_ex5_2_1.out
char *intToStringList(const int *numArray, int arrayLen, char *buffer)
{
    char *buffer_to_return = buffer;
    char *current_buffer = buffer;
    for (int i = 0; i < arrayLen; i++)
    {
        current_buffer = intToString(numArray[i], current_buffer);

        int j = 0;
        while ((int)current_buffer[j] != 0)
        {
            int x = current_buffer[j];
            current_buffer += 1;
        }
        current_buffer += 1;
    }
    current_buffer[1] = '\0';

    return buffer_to_return;
}