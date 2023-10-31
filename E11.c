#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int maior_par(int *lista, int tam)
{
    int guard = -1;
    for (int i = 0; i < tam; i++)
    {
        if (lista[i] % 2 == 0 && (guard == -1 || lista[i] > guard))
        {
            guard = lista[i];
        }
    }

    return guard;
}

int main()
{
    int list[15], i;
    for (i = 0; i < 15; i++)
    {
        scanf("%d", &list[i]);
    }

    int tam = sizeof(list) / sizeof(int);
    int result = maior_par(list, tam);

    if (result != -1)
    {
        printf("%d", result);
    }
    else
    {
        return 0;
    }

    return 0;
}
