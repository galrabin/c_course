#include <stdio.h>
#include <string.h>
#include "/share/ex_data/ex6/bigInt.h"
#include "/share/ex_data/ex6/virtualHeap.h"

/*** Problem 1.1:
 * compute the exponent corresponding to a given int given as a string
 * Parameters:
 * 1. intStr - receive number in string object.
 * 
 * returns: 
 * return exponent in scientific representation if number is construct from digits
 * otherwise return -1 (if zero returns 0)
 *  ***/

// cat /share/ex_data/ex6/test_ex6_1_1.out
int computeExponent(const char* intStr){
    int pointer = 0;
    char exp = 0;

    if (intStr[0] == (char)0) return -1;
    while (intStr[pointer])
    {
        char cur_char = intStr[pointer];
        if ('0' <= cur_char && cur_char <= '9'){
            if (exp == 0 && cur_char == '0'){
                pointer++;
                continue;
            }else
            {
                exp++;
                pointer++;
            }
        } else
        {
            return -1;
        }
    }
    if (exp == 0) return 0;
    return exp - 1;
}


/*** Problem 1.2: compute the length of the full mantissa corresponding to a given int given as a string 
 * Parameters:
 * 1. intStr - receive number in string object.
 * 
 * returns: 
 * return mantisa length in scientific representation if number is construct from digits
 * otherwise return -1 (if zero returns 0)
 * ***/
// cat /share/ex_data/ex6/test_ex6_1_2.out
int fullMantissaLength(const char* intStr){
    char exp = computeExponent(intStr);
    if (exp == -1) return - 1;

    int pointer = 0;
    while (intStr[pointer] == '0'){
        pointer++;
    }

    char man_len = 0;
    int len = strlen(intStr);
    for (int i = pointer; i < len; i++)
    {
        if (intStr[i] == '0'){
            int new_pointer = i+1;
            char to_break = 0;
            while (intStr[new_pointer] == '0' || intStr[new_pointer] == (char)0){
                if (new_pointer == len){
                    to_break = 1;
                }
                new_pointer++;
                
            }
            if (to_break == 1) break;
            else man_len++;
        }else
        {
            man_len++;
        }
        
    }
    if (man_len == 0){
        return 1;
    }
    return man_len;
}

/*** Problem 1.3: copy mantissa digits from an int (given as string) into a given buffer
 * Parameters:
 * 1. intStr - receive number in string object.
 * 2. mantisa - pointer to save mantisa.
 * 3. numDigits - round down number.
 * 
 * returns: 
 * return 1 if valid intStr number else return 0***/
// cat /share/ex_data/ex6/test_ex6_1_3.out
int copyMantissa(const char* intStr, char* mantissaBuff, int numDigits){
    // if numDigits is negative
    if (numDigits <= 0) return -1;

    // if intStr has non digit in it 
    char exp = computeExponent(intStr);
    if (exp == -1) return -1;
    
    
    // check if there is loss in precision
    int precision = 1;
    char mantisa_len = fullMantissaLength(intStr);
    if (numDigits < mantisa_len){
        precision = 0;
    };
    
    // Go to the start of a number 
    int i = 0;
    while (intStr[i] == '0')
    {
        i++;
    }

    if (i == strlen(intStr)){
        mantissaBuff[0] = '0';
        mantissaBuff[1] = (char)0;
        return 1;
    }

    int j = 0;
    while (j < numDigits && j < mantisa_len)
    {
        if (intStr[i] == '0'){
            int checker = i + 1;
            int to_continue = 1;
            while (checker < strlen(intStr))
            {
                if ('0' < intStr[checker] && intStr[checker] <= '9'){
                   int is_too_big = checker - i + j;
                   if (is_too_big > numDigits){
                       to_continue = 0;
                   } else
                   {
                       to_continue = 1;
                   }
                }
                checker++;
            }
            if (to_continue == 0) break;
            else{
                mantissaBuff[j] = '0';
                i++;
                j++;
            } 
        }
        if ('0' < intStr[i] && intStr[i] <= '9'){
            mantissaBuff[j] = intStr[i];
            i++;
            j++;
        }
        
        
    }
    
    mantissaBuff[j] = (char)0;
    return precision;
}


/*** Problem 1.4:
 * Create new structure of bigInt as defined
 * Parameters:
 * 1. intStr - receive number in string object.
 * 2. numDigits - num of digits in mantissa.
 * 
 * returns: 
 * return NULL if intStr isnt valid otherwise eturn bigInt structure
 *  ***/
// cat /share/ex_data/ex6/test_ex6_1_4.out
BigInt newBigInt(const char* intStr, int numDigits){
    // check if it is a number
    int is_num;
    if (intStr[0] == '+' || intStr[0] == '-'){
        is_num = computeExponent(&(intStr[1]));
    }else
    {
        is_num = computeExponent(intStr);
    }
    if (is_num == -1) return NULL;
    
    
    // create big int object
    BigInt created = ourMalloc(sizeof(BigInt_st));
    if (!created){
        return NULL;
    } 

    // Checking sign
    if (intStr[0] == '+' || ('0' <= intStr[0] && intStr[0] <= '9')){
        created->sign = '+';
        if (intStr[0] == '+'){
            intStr = &(intStr[1]);
        }
    } else if (intStr[0] == '-')
    {
        created->sign = '-';
        intStr = &(intStr[1]);
    } else
    {
        ourFree(created);
        return NULL;
    }

    // create mantissa
    if (numDigits <= 0 || numDigits > fullMantissaLength(intStr)){
        numDigits = fullMantissaLength(intStr);
    }
    created->mantissa = ourMalloc(sizeof(char) * numDigits + 1);
    if (!created->mantissa){
        ourFree(created);
        return NULL;
    } 

    copyMantissa(intStr,created->mantissa,numDigits);
    if (created->mantissa[0] == '0')
    {
        created->sign = '+';
    }
    

    // add exponent
    created->exp = is_num;

    return created;
}


/*** Problem 1.5:
 * Free pointer in heap that holds given bigInt structure
 * Parameters:
 * 1. bigInt - bigInt structure.
 *  ***/
// cat /share/ex_data/ex6/test_ex6_1_5.out
void freeBigInt(BigInt bigInt){
    ourFree(bigInt->mantissa);
    ourFree(bigInt);
}

/*** Problem 1.6:
 * print a given BigInt object in the following format: <sign><mantissa>e<exp>
 * Parameters:
 * 1. bigInt - bigInt structure.
 * 2. precition - precision of the number.
 *  ***/
// cat /share/ex_data/ex6/test_ex6_1_6.out
void printBigInt(BigInt bigInt, int precision){
    if (precision <= 0){
        precision = strlen(bigInt->mantissa);
    }
    printf("%c",bigInt->sign);
    int len_mantisa = strlen(bigInt->mantissa);
    for (int i = 0; i < precision; i++)
    {
        if (i == 1){
            printf(".");
        }
        if (i < len_mantisa){
           printf("%c",bigInt->mantissa[i]);
        } else
        {
            printf("0");
        }
        
    }   

    printf("e%d",bigInt->exp);
}

/*** Problem 1.7:
 * compare the values of two BigInt objects
 * Parameters:
 * 1. BigInt1 - bigInt1 structure.
 * 2. BigInt2 - bigInt2 structure.
 * 
 * Returns:
 * return 1 if BigInt1 bigger, -1 if BigInt2 is bigger, 0 both equal.
 *  ***/
// cat /share/ex_data/ex6/test_ex6_1_7.out
int compareBigInt(BigInt bigInt1, BigInt bigInt2){
    if (bigInt1->sign == '-' && bigInt2->sign == '+') return -1;
    if (bigInt1->sign == '+' && bigInt2->sign == '-') return 1;
    else
    {
        if (bigInt1->sign == '-'){
            if (bigInt1->exp < bigInt2->exp) return 1;
            else if (bigInt1->exp > bigInt2->exp) return -1;
            else
            {
                int i = 0;
                while(bigInt1->mantissa[i] || bigInt2->mantissa[i]){
                    if (bigInt1->mantissa[i] < bigInt2->mantissa[i]) return 1;
                    if (bigInt1->mantissa[i] > bigInt2->mantissa[i]) return -1;
                    if (bigInt1->mantissa[i] && !(bigInt2->mantissa[i])) return -1;
                    if (!(bigInt1->mantissa[i]) && bigInt2->mantissa[i]) return 1;
                    i++;
                }
            }
            return 0; 
        }else{
            if (bigInt1->exp > bigInt2->exp) return 1;
            else if (bigInt1->exp < bigInt2->exp) return -1;
            else
            {
                int i = 0;
                while(bigInt1->mantissa[i] || bigInt2->mantissa[i]){
                    if (bigInt1->mantissa[i] > bigInt2->mantissa[i]) return 1;
                    if (bigInt1->mantissa[i] < bigInt2->mantissa[i]) return -1;
                    if (bigInt1->mantissa[i] && !(bigInt2->mantissa[i])) return 1;
                    if (!(bigInt1->mantissa[i]) && bigInt2->mantissa[i]) return -1;
                    i++;
                }
                return 0;   
            }
        }   
    }  
}