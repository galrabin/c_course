/*************************************************
*  intStringLisy.c
*  ----------
*  Create new data type called list integers
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

/*********************************
* Problem 2.1
* Copy int array to list array
*********************************/

char *intToStringList(const int *numArray, int arrayLen, char *buffer);

/****************************************
* Problem 2.2
* return pointer to next integerin list.
*****************************************/
char *nextIntString(char *intStringList);

/****************************************
* Problem 2.3
* Performs arithmetics on the int list
*****************************************/
int doOpChain(char *intStrList, char op, char *res_intStr);

/********************************/
/**    FUNCTION DEFINITIONS    **/
/********************************/

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
* Returns next integer pointer in 
* in list.
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

/*****************************************
* Problem 2.3
* Perform arithmetics on given list.
* params:
* intStringList (pointer to int list)
* op (char)
* res_inStr(pointer to result)
* returns 1 if valid anser / 0 if not valid
*******************************************/
// Compile === gcc -Wall -D TEST_2_3 /share/ex_data/ex5/test_ex5.c intString.c intStringList.c -o test_ex5_2_3
// Test === test_ex5_2_3 , compare to = /share/ex_data/ex5/test_ex5_2_3.out

int doOpChain(char *intStrList, char op, char *res_intStr)
{
    char empty[] = {'e'};
    if (op != '+' && op != '-' && op != '*' && op != '/')
    {
        return 0;
    }
    nextIntString(empty);
    char *next = nextIntString(intStrList);
    if (!isIntString(next))
    {
        return 0;
    }
    strcpy(res_intStr, next);
    char *current_int = nextIntString(intStrList);
    while (current_int[0] != (char)0)
    {
        if (current_int[0] != (char)0)
        {
            int result = doOp(res_intStr, current_int, op);
            if (result == 0)
            {
                return 0;
            }
        }
        current_int = nextIntString(intStrList);
    }
    return 1;
}