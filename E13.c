#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int main()
{
    int i, cont_par = 0, cont_impar = 0;
    int vetor_geral[15];
    int vetor_impar[5];
    int vetor_par[5];

    // lendo entrada do usuário
    for (i = 0; i < 15; i++)
    {
        scanf("%d", &vetor_geral[i]);
    }
    // impar
    for (i = 0; i < 15; i++)
    {
        if (vetor_geral[i] % 2 != 0)
        {
            vetor_impar[cont_impar] = vetor_geral[i];
            cont_impar++;
            if (cont_impar == 5)
            {
                for (int y = 0; y < 5; y++)
                {
                    printf("impar[%d] = %d\n", y, vetor_impar[y]);
                }
                cont_impar = 0;
            }
        }
        // par
        else
        {
            vetor_par[cont_par] = vetor_geral[i];
            cont_par++;
            if (cont_par == 5)
            {
                for (int y = 0; y < 5; y++)
                {
                    printf("par[%d] = %d\n", y, vetor_par[y]);
                }
                cont_par = 0;
            }
        }
    }
    // vetor rsto
    for (int y = 0; y < cont_impar; y++)
    {
        printf("impar[%d] = %d\n", y, vetor_impar[y]);
    }

    for (int y = 0; y < cont_par; y++)
    {
        printf("par[%d] = %d\n", y, vetor_par[y]);
    }

    return 0;
}
