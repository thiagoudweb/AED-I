#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int main()
{

    int matriz[3][3];
    int tamanho = sizeof(matriz) / sizeof(matriz[0]);
    int soma, menor_numero;
    int i = 0, j = 0;
    // preenchendo a matriz
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }
    // somando positivos
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (matriz[i][j] > 0)
            {
                soma +=matriz[i][j];
            }
        }
    }
    // pegando o menor numero
    menor_numero = matriz[0][0];
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
        if (matriz[i][j] < menor_numero)
        {
            menor_numero = matriz[i][j];
        }

        }
    }

    return 0;
}
