#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>

typedef struct cadastroCliente
{
    char cliente[50];
    int senhaAcesso;
    char situacao;
} Cliente;

int main()
{
    setlocale(LC_ALL, "Portuguese");

    return 0;
}

