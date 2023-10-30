#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int maior_par(int *lista, int tam)
{
    int guard, i = 0;
    for (i = 0; i < tam; i++)
    {
        if (lista[i] % 2 == 0)
        {
            guard = lista[i];
            break;
        }
    }

    for (i = 0; i < tam; i++)
    {
        if (lista[i] % 2 == 0 && lista[i] > guard)
        {
            guard = lista[i];
        }
    }

    return guard;
}

int main()
{
    int list[] = {34, 30, 9, 35, 15, 6, -5, 32, -1, 0, 10, 18, 38, 15, 42};
    int result;
    int tam = sizeof(list) / sizeof(int);
    result = maior_par(list, tam);
    printf("%d", result);

    return 0;
}