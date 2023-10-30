#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>
// Registro clientes //
typedef struct cadastroCliente
{
    char cliente[100];
    int senhaAcesso;
    char situacao;
} cliente;

// Removendo '\n' da string //
void formatando_string(cliente *nome_cliente)
{
    int len;
    len = strlen(nome_cliente->cliente);
    if (len > 0 && nome_cliente->cliente[len - 1] == '\n')
    {
        nome_cliente->cliente[len - 1] = '\0';
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int i;
    for (i = 0; i < 100; i++)
    {
        cliente *cad_cliente = malloc(i * sizeof(cliente));
        fgets(cad_cliente[i].cliente, sizeof(cad_cliente[i].cliente), stdin);
        formatando_string(cad_cliente + i);
    }

    return 0;
}
