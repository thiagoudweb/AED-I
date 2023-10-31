#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int main()
{

    int num, cont = 0;
    scanf("%d", &num);

    if (num == 0)
    {
        cont = 1;
        return printf("%d", cont);
    }
    else if (num < 0)
    {
        num = -num;
    }
    while (num > 0)
    {
        cont++;
        num = num / 10;
    }

    printf("%d", cont);

    return 0;
}