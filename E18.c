#include <stdio.h>
#include <math.h>
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
void formtando_string (){



}


int main()
{
    // setlocale(LC_ALL, "Portuguese");
    
    // int i;
    
    // cliente *cad_cliente = malloc(i + sizeof(cliente));
    // for (i = 0; i <100; i++)
    // {
    //     /* code */
    // }
    int i;

    i = sizeof(cliente);
    printf("%d", i);
    



    return 0;
}
