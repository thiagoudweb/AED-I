#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct banco_usuario
{
    int idade;
    char nome[50];
    char sexo;
    char estado_civil;
    int amigos;
    int fotos_perfil;
} bd_usuario;

void formatar_string(char *str)
{
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int numero_cad, i;
    scanf("%d", &numero_cad);
    getchar();
    bd_usuario *cadastro = malloc(numero_cad * sizeof(bd_usuario));
    
    for (i = 0; i < numero_cad; i++)
    {
        scanf("%d", &cadastro[i].idade);
        getchar();
        fgets(cadastro[i].nome, sizeof(cadastro[i].nome), stdin);
        formatar_string(cadastro[i].nome);
        scanf("%c", &cadastro[i].sexo);
        getchar();
        scanf("%c", &cadastro[i].estado_civil);
        getchar();
        scanf("%d", &cadastro[i].amigos);
        getchar();
        scanf("%d", &cadastro[i].fotos_perfil);
        getchar();
    }

    for (i = 0; i < numero_cad; i++)
    {
        printf("Idade: %d\n", cadastro[i].idade);
        printf("Nome: %s\n", cadastro[i].nome);
        printf("Sexo: %c\n", cadastro[i].sexo);
        printf("Estado Civil: %c\n", cadastro[i].estado_civil);
        printf("Numero de amigos: %d\n", cadastro[i].amigos);
        printf("Numero de fotos: %d\n\n", cadastro[i].fotos_perfil);
    }

    free(cadastro);

    return 0;
}
