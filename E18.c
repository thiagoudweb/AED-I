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
    int i, senha_cad, status, senha_veri, bool_senha;
    cliente cad_cliente[100];
    for (i = 0; i < 100; i++)
    {
        fgets(cad_cliente[i].cliente, sizeof(cad_cliente[i].cliente), stdin);
        formatando_string(cad_cliente + i);
        // verificando saida do usuario
        if (strcasecmp(cad_cliente[i].cliente, "SAIR") == 0)
        {
            break;
        }
        scanf("%d", &cad_cliente[i].senhaAcesso);
        getchar();
        scanf("%s", &cad_cliente[i].situacao);
        getchar();
    }

    while (1)
    {
        i = 0;
        bool_senha = 0;
        scanf("%d", &senha_veri);

        if (senha_veri == -1)
        {
            break;
        }
        else
        {

            for (i = 0; i < 100; i++)
            {
                if (senha_veri == cad_cliente[i].senhaAcesso && cad_cliente->situacao == 'P')
                {
                    printf("%s, Seja bem vindo(a)\n", cad_cliente[i].cliente);
                    bool_senha = 1;
                }
                else if (senha_veri == cad_cliente[i].senhaAcesso && cad_cliente->situacao != 'P')
                {
                    printf("Não está esquecendo de algo, %s ? Procure a recepção!\n", cad_cliente[i].cliente);
                    bool_senha = 1;
                }

                else if (bool_senha == 0)
                {
                    printf("Seja bem-vindo(a)! Procure a recepção!\n");
                }
            }
        }
    }

    return 0;
}
