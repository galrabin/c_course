#include <stdio.h>
#include <string.h>
#include "/share/ex_data/ex6/sortedBigIntList.h"
#include "/share/ex_data/ex6/bigInt.h"


/*************************************/
/**     SYMBOLIC  CONSTANTS         **/
/*************************************/
#define MAX_BUFFER 202
#define INC   0
#define DEC   1
#define MAX_INT 2147483647
#define MIN_INT -2147483648
#define SIZE 33

/*********************************
* Chack string if valid int
* params:
* str (pointer)
* returns 1 if valid 0 if not
*********************************/
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
* Change Integer type to String 
* type.
* params:
* str (pointer)
* returns integer type
*********************************/
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



int main(int argc, char const *argv[])
{
    // Check if argument sufficent 
    FILE *file;
    if (argc < 2){
        fprintf(stderr, "Input file not specified.\n");
        return 1;
    }
    else
    {
        // File checking
        if (strcmp(argv[1], "-") == 0){
            file = NULL;
        }
        else{
            file = fopen(argv[1], "r");
            if (!file){
                fprintf(stderr, "Input file %s does not exist, or cannot be opened for reading.\n", argv[1]);
                return 2;
            }
        }
    }

    // Parse arguments
    int list_type = INC;
    int precision = 0;
    for (int i = 2; i < argc; i++) {
        if (strcmp(argv[i],"-r") == 0){
            if (list_type != INC){
                fprintf(stderr,"Flag -r cannot be specified twice.\n");
                return 3;
            }
            list_type = DEC;
        }
        else if (argv[i][0] == '-' && argv[i][1] == 'p')
        {
            if(!isIntString(&argv[i][2])){
                fprintf(stderr,"Invalid precision value %s.\n",&argv[i][2]);
                return 3;
            }
            else if (precision != 0)
            {
                fprintf(stderr,"Flag -p cannot be specified twice.\n");
                return 3;
            }
            else
            {
                precision = stringToInt(&argv[i][2]);
                if (precision < 1 || 99 < precision){
                    fprintf(stderr,"Invalid precision value %s.\n",&argv[i][2]);
                    return 3; 
                }
            }
        } 
        else
        {
            fprintf(stderr,"Invalid flag %s.\n", argv[i]);
            return 3;
        } 
    }

    // Read lines
    BigInt bigInt;
    SortedBigIntList list = newSortedBigIntList(list_type);

    char line[MAX_BUFFER];

    if (file) {
        while (fgets(line, MAX_BUFFER, file)) {
            if (line[strlen(line) - 1] == '\n') {
                line[strlen(line) - 1] = '\0';
            }
            bigInt = newBigInt(line, -1);
            if (bigInt != NULL) {
                addBigIntToSortedList(list, bigInt);
            }
        }
    } else {
        char line[MAX_BUFFER];
        while (fgets(line, MAX_BUFFER, stdin)) {
            if (line[strlen(line) - 1] == '\n') {
                line[strlen(line) - 1] = '\0';
            }
            bigInt = newBigInt(line, -1);
            if (bigInt != NULL) {
                addBigIntToSortedList(list, bigInt);
            }

        }
    }
    if (file) {
        fclose(file);
    }

    printSortedBigIntList(list, precision);
    freeSortedBigIntList(list);
    
    return 0;
}
