#include <stdio.h>

int main();
int stringToInt(const char *str);

int stringToInt(const char *str)
{
    const char *back_up = &str[0];
    int size = 0;
    int location = 0;
    int symbol = 1;
    char curChar = str[0];

    // Determine sign of the number
    if (curChar == '-')
    {
        symbol = 0;
    }
    else if (curChar == '0')
    {
        return 0;
    }

    // Checking number size
    location++;
    curChar = str[location];
    while (curChar != '\0')
    {
        location++;
        curChar = str[location];
        switch (curChar)
        {
        case '-':
            return 0;
            break;
        default:
            break;
        }
    }
    size = location;
    if (!symbol)
    {
        size--;
        curChar = back_up[1];
        location = 1;
    }
    else
    {
        curChar = back_up[0];
        location = 0;
    }

    // convert to int
    int degree = 1;
    for (int i = 1; i < size; i++)
    {
        degree *= 10;
    }

    int converted = 0;
    while (curChar != '\0')
    {
        switch (curChar)
        {
        case '0':
            converted += 0;
            break;
        case '1':
            converted += degree * 1;
            break;
        case '2':
            converted += degree * 2;
            break;
        case '3':
            converted += degree * 3;
            break;
        case '4':
            converted += degree * 4;
            break;
        case '5':
            converted += degree * 5;
            break;
        case '6':
            converted += degree * 6;
            break;
        case '7':
            converted += degree * 7;
            break;
        case '8':
            converted += degree * 8;
            break;
        case '9':
            converted += degree * 9;
            break;
        default:
            return 0;
            break;
        }
        location++;
        curChar = back_up[location];
        degree /= 10;
    }

    if (symbol)
    {
        converted *= -1;
    }

    return converted;
}

int main()
{
    char s[] = "34";
    printf("Converted : %d", stringToInt(s));
    return 0;
}