#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int maior_par(int lista[], int n)
{
    int verinum, i;

    for (i = 0; i < n; i++)
    {
        if (lista[i] % 2 == 0)
        {
            verinum = lista[i];
            break;
        }
    }
    for (i = 0; i < n; i++)
    {
        if (lista[i] % 2 == 0 && lista[i] > verinum)
        {
            verinum = lista[i];
        }
    }

    return verinum;
}

void formatar_string(char *str)
{
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
    }
}

int main()
{
    char vet_str[100];
    int vet_int[100];
    char *caract; 
    int i = 0, cont = 0, result;
    fgets(vet_str, 100, stdin);
    formatar_string(vet_str);
    caract = strtok(vet_str, ",");
    while (caract != NULL)
    {
        vet_int[i] = atoi(caract);
        caract = strtok(NULL, ",");
        cont++;
       
    }
    result = maior_par(vet_int, cont);
    printf("%d", result);

    return 0;
}


// 34\030\0 9, 35, 15, 6, -5, 32, -1, 0, 10, 18, 38, 15, 42 > string