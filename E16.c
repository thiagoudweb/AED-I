#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct livro
{
    char nome[100];

} livro;

int main()
{
    int x;   
    scanf("%d", &x);
    livro *busca_livro = malloc(x*sizeof(livro));

    busca_livro 






    return 0;
}

// faça um programa que receba n nomes de livros, depois receba mais um nome e diga se ele já foi citado anteriormente

// Formato de entrada

// um inteiro n seguido de n nomes de livro mais um nome de livro no final

//      3

//      O pequeno príncipe

//      O Código Da Vince

//      Calculo II

//      O pequeno príncipe

// Formato de saída

// Sim ou Não se o livro estiver na lista

//      Sim