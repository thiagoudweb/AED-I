#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// struct para guardar os livros
typedef struct prat_livros
{
    char lib_livros[100];
} array_livros;

// remover o \0 no final da string na struct
void remover_final(array_livros *remover_barran)
{
    int taman_len;
    taman_len = strlen(remover_barran->lib_livros);
    if (taman_len > 0 && remover_barran->lib_livros[taman_len - 1] == '\n')
    {
        remover_barran->lib_livros[taman_len - 1] = '\0';
    }
}

// remover o \0 no final da string
void remover_final_usuario(char *usuario_livro)
{
    int taman_len;
    taman_len = strlen(usuario_livro);
    if (taman_len > 0 && usuario_livro[taman_len - 1] == '\n')
    {
        usuario_livro[taman_len - 1] = '\0';
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int n, i, bool_comp;
    scanf("%d", &n);
    getchar();
    char nome_usuario[100];
    array_livros *guard_livros = malloc(n * sizeof(array_livros));

    for (i = 0; i < n; i++)
    {
        fgets(guard_livros[i].lib_livros, sizeof(guard_livros[i].lib_livros), stdin);
        remover_final(&guard_livros[i]);
    }

    fgets(nome_usuario, 100, stdin);
    remover_final_usuario(nome_usuario);

    bool_comp = 1;

    for (i = 0; i < n; i++)
    {
        bool_comp = strcmp(nome_usuario, guard_livros[i].lib_livros);
        if (bool_comp == 0)
        {
            bool_comp = 0;
            break;
        }
    }
    if (bool_comp == 0)
    {
        printf("Sim");
    }
    else
    {
        printf("Não");
    }
}