#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// banco de dados disciplinas
typedef struct bd_disciplinas
{
    char codDisciplina[25];
    char nomeDisciplina[100];

} cad_disciplinas;

// banco de dados alunos
typedef struct bd_alunos
{
    char codigoDoAluno[50];
    char nomeAlunoCompleto[500];
    int idade;
    int sexo;
    int enem;

} cad_alunos;

// banco de dados matriculas
typedef struct bd_matriculas
{
    cad_alunos aluno;
    cad_disciplinas disciplina;

} cad_matriculas;

int main()
{
    int numCad, numDis, numMat;
    scanf("%d", &numCad);
    getchar();
    scanf("%d", &numDis);
    getchar();
    cad_alunos *vet_cad = malloc(numCad * sizeof(cad_alunos));
    cad_disciplinas *vet_dis = malloc(numDis * sizeof(cad_disciplinas));

    // leitura dos dados dos alunos
    for (int i = 0; i < numCad; i++) {
        fgets(vet_cad[i].codigoDoAluno, 50, stdin);
        fgets(vet_cad[i].nomeAlunoCompleto, 500, stdin);
        scanf("%d", &vet_cad[i].idade);
        scanf("%d", &vet_cad[i].sexo);
        scanf("%d", &vet_cad[i].enem);
        getchar();
    }

    // leitura dos dados das disciplinas
    for (int i = 0; i < numDis; i++) {
        fgets(vet_dis[i].codDisciplina, 25, stdin);
        fgets(vet_dis[i].nomeDisciplina, 100, stdin);
        getchar();
    }

    // leitura das matriculas
    scanf("%d", &numMat);
    getchar();
    cad_matriculas *vet_mat = malloc(numMat * sizeof(cad_matriculas));
    
    for (int i = 0; i < numMat; i++) {
        char codAluno[50], codDisciplina[25];
        fgets(codAluno, 50, stdin);
        fgets(codDisciplina, 25, stdin);
        
        // busca o aluno e a disciplina correspondentes
        for (int j = 0; j < numCad; j++) {
            if (strcmp(vet_cad[j].codigoDoAluno, codAluno) == 0) {
                vet_mat[i].aluno = vet_cad[j];
                break;
            }
        }
        
        for (int j = 0; j < numDis; j++) {
            if (strcmp(vet_dis[j].codDisciplina, codDisciplina) == 0) {
                vet_mat[i].disciplina = vet_dis[j];
                break;
            }
        }
        
        getchar();
    }

    // TODO: implementar a lógica para gerar o relatório

    free(vet_cad);
    free(vet_dis);
    free(vet_mat);

    return 0;
}

