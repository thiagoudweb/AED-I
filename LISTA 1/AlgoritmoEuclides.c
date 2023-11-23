#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>

int algoeclides(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return algoeclides(b, a % b);
}

int main()
{
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        int result = algoeclides(a, b);

        printf("MDC(%d,%d) = %d\n", a, b, result);
    }

    return 0;
}