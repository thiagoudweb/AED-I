#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct Aluno {
    char codigo[31];
    char nome[501];
    int idade;
    int sexo;
    float nota_enem;
};

struct Disciplina {
    char codigo[26];
    char nome[101];
    int num_alunos;
    char **alunos_matriculados; 
};

int comparaNomes(const void *a, const void *b) {
    return strcmp(((struct Aluno *)a)->nome, ((struct Aluno *)b)->nome);
}

int main() {
    int n, cont = 0;
    scanf("%d", &n);

    struct Aluno alunos[n];
    int alunos_masculinos = 0;
    int alunos_femininos = 0;
    float soma_idades = 0.0;
    float soma_idades_enem = 0.0;

    for (int i = 0; i < n; i++) {
        scanf("%s", alunos[i].codigo);
        scanf(" %[^\n]", alunos[i].nome);
        scanf("%d", &alunos[i].idade);
        scanf("%d", &alunos[i].sexo);
        scanf("%f", &alunos[i].nota_enem);

        if (alunos[i].sexo == 0) {
            alunos_femininos++;
        } else {
            alunos_masculinos++;
        }

        soma_idades += alunos[i].idade;
        if (alunos[i].nota_enem > 7.5) {
            soma_idades_enem += alunos[i].idade;
            cont += 1;
        }
    }

    qsort(alunos, n, sizeof(struct Aluno), comparaNomes);

    int m;
    scanf("%d", &m);

    struct Disciplina disciplinas[m];

    for (int i = 0; i < m; i++) {
        scanf("%s", disciplinas[i].codigo);
        scanf(" %[^\n]", disciplinas[i].nome);
        disciplinas[i].num_alunos = 0;
        disciplinas[i].alunos_matriculados = NULL;
    }

    int p;
    scanf("%d", &p);

    for (int i = 0; i < p; i++) {
        char codigo_aluno[31];
        char codigo_disciplina[26];
        scanf("%s %s", codigo_aluno, codigo_disciplina);

        struct Aluno *aluno = NULL;
        struct Disciplina *disciplina = NULL;

        for (int j = 0; j < n; j++) {
            if (strcmp(alunos[j].codigo, codigo_aluno) == 0) {
                aluno = &alunos[j];
                break;
            }
        }

        for (int j = 0; j < m; j++) {
            if (strcmp(disciplinas[j].codigo, codigo_disciplina) == 0) {
                disciplina = &disciplinas[j];
                break;
            }
        }

        if (aluno != NULL && disciplina != NULL) {
            disciplina->num_alunos++;
            disciplina->alunos_matriculados = (char **)realloc(disciplina->alunos_matriculados, disciplina->num_alunos * sizeof(char *));
            disciplina->alunos_matriculados[disciplina->num_alunos - 1] = aluno->nome;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            if (strcmp(disciplinas[i].nome, disciplinas[j].nome) > 0) {
                struct Disciplina temp = disciplinas[i];
                disciplinas[i] = disciplinas[j];
                disciplinas[j] = temp;
            }
        }
    }

    printf("%d\n", alunos_masculinos);
    printf("%d\n", alunos_femininos);
    printf("%.2f\n", soma_idades / n);
    if (soma_idades_enem > 0) {
        printf("%.2f\n", soma_idades_enem / cont);
    } else {
        printf("0.00\n");
    }

    for (int i = 0; i < m; i++) {
        printf("%s\n", disciplinas[i].nome);
        printf("%d\n", disciplinas[i].num_alunos);
        for (int j = 0; j < disciplinas[i].num_alunos; j++) {
            for (int k = j + 1; k < disciplinas[i].num_alunos; k++) {
                if (strcmp(disciplinas[i].alunos_matriculados[j], disciplinas[i].alunos_matriculados[k]) > 0) {
                    char *temp = disciplinas[i].alunos_matriculados[j];
                    disciplinas[i].alunos_matriculados[j] = disciplinas[i].alunos_matriculados[k];
                    disciplinas[i].alunos_matriculados[k] = temp;
                }
            }
        }
        for (int j = 0; j < disciplinas[i].num_alunos; j++) {
            printf("%s\n", disciplinas[i].alunos_matriculados[j]);
        }
    }

    return 0;
}