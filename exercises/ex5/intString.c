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
    double degree = 1;
    for (int i = 1; i < size; i++)
    {
        degree *= 10;
    }

    double converted = 0;
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
        degree /= 10.0;
    }

    if (!symbol)
    {
        converted *= -1;
    }

    if (converted > 2147483647 || converted < -2147483648)
    {
        return 0;
    }

    int to = (int)converted;

    return to;
}

int isIntString(const char *str)
{
    int location = 0;
    char curChar = str[location];
    while (curChar != '\0')
    {
        switch (curChar)
        {
        case '-':
            if (location != 0)
            {
                return 0;
            }
        case '0':
            if (location != 0)
            {
                return 0;
            }
        case '1':
            break;
        case '2':
            break;
        case '3':
            break;
        case '4':
            break;
        case '5':
            break;
        case '6':
            break;
        case '7':
            break;
        case '8':
            break;
        case '9':
            break;
        default:
            return 0;
            break;
        }
        location++;
        curChar = str[location];
    }
    return 1;
}

char *intToStringRecursion(int num, char *buffer)
{
    if (num < 0)
    {
        buffer[0]= '-';
        num *= -1;
        return intToStringRecursion(num, buffer + 1);
    }
    else if (num > 0)
    {
        buffer = intToStringRecursion(num / 10, buffer++);
        buffer[0] = num % 10 + '0';
        return buffer + 1;
    }
    return buffer;
}

char *intToString(int num, char **buffer)
{
    char *last_cell;
    if (num == 0)
    {
        buffer[0] = '0';
        buffer[1] = '\0';
        return buffer;
    }
    last_cell = intToStringRecursion(num, buffer);
    last_cell[0] = '\0';
    return buffer;
}

int main()
{
    printf("#############################################\n");
    printf("#############String to integer###############\n");
    printf("#############################################\n");
    printf("Converted %s : %d\n", "34987", stringToInt("34987"));
    printf("Converted %s : %d\n", "0", stringToInt("0"));
    printf("Converted %s : %d\n", "-2147483648", stringToInt("-2147483648"));
    printf("C onverted %s : %d\n", "2147483648", stringToInt("2147483648"));
    printf("Converted %s : %d\n", "--3", stringToInt("--3"));
    printf("Converted %s : %d\n", ".765", stringToInt(".765"));
    printf("Converted %s : %d\n\n", "765\0.", stringToInt("765\0."));

    printf("#############################################\n");
    printf("#############String to integer###############\n");
    printf("#############################################\n");
    printf("%s validation suppote to be %d : %d\n", "34987", 1, isIntString("34987"));
    printf("%s validation suppote to be %d : %d\n", "+34987", 0, isIntString("+34987"));
    printf("%s validation suppote to be %d : %d\n", "0", 1, isIntString("0"));
    printf("%s validation suppote to be %d : %d\n", "-0", 0, isIntString("-0"));
    printf("%s validation suppote to be %d : %d\n", "00", 0, isIntString("00"));
    printf("%s validation suppote to be %d : %d\n\n", "765\0.", 1, isIntString("765\0."));

    printf("#############################################\n");
    printf("#############Integer to String###############\n");
    printf("#############################################\n");
    char test[33];
    printf("Integer entered %d, string recieved: %s\n",1234,intToString(1234,&test));
    printf("Integer entered %d, string recieved: %s\n",-1234,intToString(-1234,&test));
    printf("Integer entered %d, string recieved: %s\n",10000,intToString(10000,&test));
    printf("Integer entered %d, string recieved: %s\n\n",0,intToString(0,&test));
    

    
    return 0;
}