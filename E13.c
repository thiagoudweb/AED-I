#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int main()
{
    int i, cont_par, cont_impar, y = 0;
    int vetor_geral[15];
    int vetor_impar[5];
    int vetor_par[5];
    // lendo entrada do usuário
    for (i = 0; i < 15; i++)
    {
        scanf("%d", &vetor_geral[i]);
    }

    // impares
    cont_impar = 0;
    for (i = 0; i < 15; i++)
    {
        if (vetor_geral[i] % 2 != 0)
        {
            vetor_impar[y] = vetor_geral[i];
            y++;
            cont_impar++;
            if (cont_impar == 5)
            {
                for (y = 0; y < cont_impar; y++)
                {
                    printf("impar[%d] = %d\n", y, vetor_impar[y]);
                }
                y = 0;
                cont_impar = 0;
            }
        }
    }

    // pares
    cont_par = 0;
    for (i = 0; i < 15; i++)
    {
        if (vetor_geral[i] % 2 == 0)
        {
            vetor_par[y] = vetor_geral[i];
            y++;
            cont_par++;
            if (cont_par == 5)
            {
                for (y = 0; y < cont_par; y++)
                {
                    printf("par[%d] = %d\n", y, vetor_par[y]);
                }
                y = 0;
                cont_par = 0;
            }
        }
    }

    return 0;
}
