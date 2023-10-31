#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

typedef struct bd_alunos{
    char codigoDoAluno[50];
    char nomeAlunoCompleto[500];
    int idade;
    int sexo;
    int enem;

} cad_alunos;


int main(){
   
   int num_cad;
   scanf("%d", num_cad);
   getchar();
   cad_alunos *vet_cad = malloc(num_cad*sizeof(cad_alunos));





return 0;

}


