#include <stdio.h>

char *intToStringRecursion(int num, char *buffer)
{
    if (num < 0)
    {
        *(buffer) = '-';
        num *= -1;
        return intToStringRecursion(num, buffer + 1);
    }
    else if (num > 0)
    {
        buffer = intToStringRecursion(num / 10, buffer++);
        *(buffer) = num % 10 + '0';
        return buffer + 1;
    }
    return buffer;
}

char *intToString(int num, char *buffer)
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
    char test[32];
    char *p = intToString((1234), test);
    printf("%s", p);
    return 0;
}
