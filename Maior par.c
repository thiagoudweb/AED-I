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
    char list[100];
    int list_num[100], i,tam;
    char *token;
    int menor;
    fgets(list, 100, stdin);

    token = strtok(list, ",");
    while (token != NULL)
    {
        list_num[i++] = atoi(token);
        token = strtok(NULL, ",");
    }
    tam = sizeof(list_num)/sizeof(int);
    menor = maior_par(list_num, tam);

    printf("¨%d", menor);

    return 0;
}
