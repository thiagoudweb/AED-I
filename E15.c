#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int main()
{

    int matriz[3][3];
    int menor_numero, delta, soma_sem_diagonal = 0, cont_posi = 0;
    float media = 0;
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
                media += matriz[i][j];
                cont_posi++;
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
    // diagonal
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (i != j)
            {
                soma_sem_diagonal += matriz[i][j];
            }
        }
    }

    media = media / cont_posi;
    if (menor_numero % 2 == 0)
    {
        delta = 1;
    }
    else
    {
        delta = 0;
    }

    printf("%.2f %d %d %d", media, menor_numero, delta, soma_sem_diagonal);

    return 0;
}
