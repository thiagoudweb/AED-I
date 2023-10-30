#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

float CalculaMedia(float *notas)
{
    float acumulador = 0, result;
    int i;
    for (i = 0; i < 5; i++)
    {
        acumulador += notas[i];
    }
    return result = acumulador / 5;
}

int main()
{

    float vet_notas[5], result;
    int i, faltas;
    scanf("%d", &faltas);
    for (i = 0; i < 5; i++)
    {
        scanf("%f", &vet_notas[i]);
    }
    result = CalculaMedia(vet_notas);

    if (faltas <= 5 && result >= 7)
    {
        printf("APROVADO");
    }
    else
    {
        printf("REPROVADO");
    }

    return 0;
}
