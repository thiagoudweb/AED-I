#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// estrutura estrutura que molda o bloco alocado da heap (criação do elemento da lista)
typedef struct membronode
{
    int val;
    struct membronode *next;

} node;

// estrutura que armazena o primeiro nó da lista
typedef struct lista
{
    node *primeiroElemento;
    node *ultimoElemento;

} cabeca;

// CONSTRUTOR DE BLOCO INICIAL//
// constrói um bloco para guardar o primeiro endereço do nó //

cabeca *criarLista()
{

    cabeca *endInicial = calloc(1, sizeof(cabeca));
    endInicial->primeiroElemento = NULL;
    return endInicial;
}

// CONSTRUTOR DE NÓ //
// constrói umm nó para encaixar na lista //

node *criarEstruturaNode(int val)
{

    node *varTemp = calloc(1, sizeof(node));
    varTemp->next = NULL;
    varTemp->val = val;
    return varTemp;
}

// ADICIONAR ELEMENTO NO INICIO //

void adicionarNoInicio(cabeca *lista, int val)
{

    node *novoNo = criarEstruturaNode(val);

    if (lista->primeiroElemento == NULL)
    {
        lista->primeiroElemento = novoNo;
        lista->ultimoElemento = novoNo;
    }
    else
    {
        node *varTemp = lista->primeiroElemento;
        lista->primeiroElemento = novoNo;
        novoNo->next = varTemp;
    }
}

// ADICIONAR ELEMENTO POR ULTIMO ( MANEIRA OTIMIZADA ) //

void inserirNoFimRapido(cabeca *lista, int val)
{

    node *novoNo = criarEstruturaNode(val);

    if (lista->primeiroElemento == NULL)
    {
        lista->primeiroElemento = novoNo;
        lista->ultimoElemento = novoNo;
    }
    else
    {

        node *varTemp = lista->ultimoElemento;
        varTemp->next = novoNo;
        lista->ultimoElemento = novoNo;
    }
}

// FUNÇÃO PARA IMPRIMIR OS ELEMENTOS DA LISTA //

void imprimirElementos(cabeca *lista)
{

    node *varTemp = lista->primeiroElemento;
    if (varTemp == NULL)
    {
        printf("Você não possui uma lista!\n");
    }
    else
    {
        while (varTemp != NULL)
        {
            printf("%d\n", varTemp->val);
            varTemp = varTemp->next;
        }
    }
}

// FUNÇÃO PARA REMOVER NO FIM //

void removerNode(cabeca *lista, int val)
{

    if (lista->primeiroElemento != NULL)
    {
        node *varPrimeiroNode = lista->primeiroElemento;

        // CASO 1 ( MEU METODO ) : QUANDO A LISTA TEM APENAS UM MEMBRO. LOGO, TEMOS QUE ALTERAR A STRUCT CABEÇA ( HEAD ).
        if (lista->primeiroElemento == lista->ultimoElemento)
        {
            if (varPrimeiroNode->val != val)
            {
                printf("O valor não existe nessa lista\n");
            }
            else
            {
                lista->primeiroElemento = NULL;
                lista->ultimoElemento = NULL;
                free(varPrimeiroNode);
            }
        }

        // REMOVENDO PRIMEIRO ELEMENTO DA LISTA ( A FUNÇAO ACIMA ME GARANTE QUE ESSA LISTA TEM MAIS DE UM ELEMENTO ) //
        else if (varPrimeiroNode->val == val)
        {
            node *backupProxNode = varPrimeiroNode->next;
            lista->primeiroElemento = backupProxNode;
            free(varPrimeiroNode);
        }

        // REMOVENDO DO MEIO DA LISTA

        else
        {
            // VARIAVEIS PARA VERIFICAR O NÓ ANTERIOR E SUCESSOR //
            node *anterior;
            node *poosicaoAtual = lista->primeiroElemento->next;

            while (poosicaoAtual->next != NULL && poosicaoAtual->val != val)
            {
                anterior = poosicaoAtual;
                poosicaoAtual = poosicaoAtual->next;
            }

            if (poosicaoAtual->next == NULL)
            {
                if (poosicaoAtual->val == val)
                {
                    anterior->next = NULL;
                    lista->ultimoElemento = anterior;
                    free(poosicaoAtual);
                }
                else
                {

                    printf("Endereço não encontrado\n");
                }
            }
            else
            {
                anterior->next = poosicaoAtual->next;
                free(poosicaoAtual);
            }
        }
    }

    else
    {
        printf("Você não possui elementos na lista!\n");
    }
}

int main()
{

    cabeca *lista = criarLista();
    inserirNoFimRapido(lista, 1);
    inserirNoFimRapido(lista, 10);
    inserirNoFimRapido(lista, 20);
    inserirNoFimRapido(lista, 30);
    inserirNoFimRapido(lista, 40);
    inserirNoFimRapido(lista, 60);
    imprimirElementos(lista);
    removerNode(lista,60);
    imprimirElementos(lista);

    return 0;
}

// ---------------------------------------------------- //

// FUNÇÕES SEM O MEMBRO "FIM " NA STRUCT DA LISTA

// ADICIONAR ELEMENTO NA CABEÇA //
// inseri o elemento no membro da estrutura de inicio, ou seja, trocando o endereço do antigo primeiro membro. //

// void inserirInicio(cabeca *lista, int val)
// {

//     node *novoNode = criarEstruturaNode(val);

//     if (lista->primeiroElemento == NULL)
//     {
//         lista->primeiroElemento = novoNode;
//     }

//     else
//     {
//         node *varTemp = lista->primeiroElemento;
//         lista->primeiroElemento = novoNode;
//         novoNode->next = varTemp;
//     }
// }

// ADICIONAR ELEMENTO NA CALDA ( ÚLTIMO ELEMENTO ) //
// conecta um novo elemento ao último nó da lista. //

// void inserirFimDaLista(cabeca *lista, int val)
// {

//     node *novoNode = criarEstruturaNode(val);
//     node *varTemp = lista->primeiroElemento;

//     if (lista->primeiroElemento == NULL)
//     {
//         lista->primeiroElemento = novoNode;
//     }

//     else
//     {

//         while (varTemp->next != NULL)
//         {
//             varTemp = varTemp->next;
//         }

//         varTemp->next = novoNode;
//     }
// }