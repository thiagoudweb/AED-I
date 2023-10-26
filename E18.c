#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

typedef struct cadastroCliente
{
    char cliente[50];
    int senhaAcesso;
    char situacao;
} Cliente;

int main()
{
    int x = 0, y = 1;
    int escolha, senhaverif;
    Cliente cad[100];
    while (x < 100)
    {
        printf("Escolha uma opção\n");
        printf("[1]: CADASTRAR CLIENTE\n");
        printf("[2]: SAIR\n");
        scanf("%d", &escolha);

        if (escolha == 2)
        {
            break;
        }
        else
        {    
            printf("Cliente:\n");
            scanf("%s", cad[x].cliente);
            fflush(stdin);        
            printf("Senha:\n");
            scanf("%d", &cad[x].senhaAcesso);
            printf("Situacao:\n");
            gets(cad[x].situacao);           
            x++;
        }
    }

    while (y == 1)
    {
        printf("Digite a senha de acesso:\n");
        scanf("%d", &senhaverif);
        if (senhaverif == -1)
        {
            return 0;
        }
        else
        {
            int achou = 0;
            for (int i = 0; i < x; i++)
            {
                if (senhaverif == cad[i].senhaAcesso)
                {
                    achou = 1;
                    if (cad[i].situacao == 'P')
                    {
                        printf("%s, seja Bem vindo(a)\n", cad[i].cliente);
                        break;
                    }
                    else if (cad[i].situacao != 'P')
                    {
                        printf("Não está esquecendo de algo, %s? Procure a recepção!\n", cad[i].cliente);
                        break;
                    }
                }
            }
            if (achou == 0)
            {
                printf("Seja bem-vindo(a)! Procure a recepcaoo!");
            }
        }
    }

    return 0;
}

// O sistema de acesso à academia Corpo Tangente Derivada está obsoleto e tem sido motivo de insatisfação.
// Acredite se quiser, os clientes dependem de uma antiga caderneta, a qual contém o nome, a senha e a situação
// da mensalidade. Duda, a dona fitness da academia, decidiu aderir à evolução tecnológica, ela deseja que você
// crie, urgentemente, uma catraca digital, que seja capaz de receber os dados citados acima para cada cliente e,
// logo após, ao receber uma senha, liberar o acesso ou não.

// // // Formato de entrada

// // // Para cada cliente a ser cadastrado, o programa receberá uma estrutura com os campos:

// // // Nome: string com no máximo 50 caracteres.
// // // Senha de acesso: inteiro.
// // // Situação da mensalidade: caractere correspondente a 'P' quando estiver paga, ou 'F', quando estiver devendo.
// // // O programa deverá receber essas entradas até que o nome dado seja “SAIR” ou o limite de 100 clientes seja atingido.

// // // Após encerrado o cadastro, serão recebidas inúmeras senhas, até que o valor lido seja -1.

// // // Formato de saída

// // // Automaticamente, ao receber uma senha de acesso, o programa deverá:

// // // Caso haja uma senha cadastrada correspondente e a situação da mensalidade seja “P”, imprimir o nome do cliente,
// // acompanhado de uma mensagem de boas-vindas. Ex.: “Maria Foco Total, seja bem-vindo(a)!”

// // // Caso haja uma senha cadastrada correspondente, mas a situação da mensalidade seja diferente de “P”, imprimir o
// // nome do cliente, acompanhado de uma mensagem o direcionando à recepção. Ex.: “Não está esquecendo de algo,
// // Joãozinho Fitness? Procure a recepção!”

// // // Caso não haja uma senha cadastrada, imprimir uma mensagem de boas-vidas que o direcione à recepção. Ex.:
// //  “Seja bem-vindo(a)! Procure a recepção!”