#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void formatar_string(char *formString)
{
    int len;
    len = strlen(formString);
    if (len > 0 && formString[len - 1] == '\n')
    {
        formString[len - 1] = '\0';
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    float precos[] = {5.50, 6.0, 7.50, 1.99, 4.00, 6.70, 1.20, 2.80, 5.30, 5.00, 3.00, 2.00, 3.50, 0.80, 1.00,
                      0.80, 5.40, 1.90, 5.00, 10.00, 0.50, 0.50, 5.00, 4.50, 1.99, 2.90, 0.30};
    int sn = sizeof(precos) / sizeof(float);
    char vetEscolhaChar[500];
    float somador = 0;
    int itebsEscolhaInt[sn], totalMedia = 0, valorDoado;
    char *token;
    int i = 0;
    // limiter usuário //
    fgets(vetEscolhaChar, 500, stdin);
    formatar_string(vetEscolhaChar);
    scanf("%d", &valorDoado);
    getchar();
    // limita o usuário
    token = strtok(vetEscolhaChar, ",");
    while (i < sn)
    {
        itebsEscolhaInt[i] = atoi(token);
        token = strtok(NULL, ",");
        i++;
    }
    for (i = 0; i < sn; i++)
    {
        somador += itebsEscolhaInt[i] * precos[i];
    }

    totalMedia = valorDoado / somador;
    printf("O valor da cesta básica ficou em: %.2f\n", somador);
    printf("%d cestas básicas podem ser compradas com o valor doado\n", totalMedia);

    return 0;
}
