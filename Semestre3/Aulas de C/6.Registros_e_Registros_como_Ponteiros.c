#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[30];
    float nota;
} Aluno;

void preencherAluno(Aluno *a, int id, char nome[], float nota) {
    a->id = id;
    strcpy(a->nome, nome);
    a->nota = nota;
}

void imprimirAluno(Aluno *a) {
    printf("ID: %d, Nome: %s, Nota: %.1f\n", a->id, a->nome, a->nota);
}

int main() {
    // Aluno na stack
    Aluno aluno1;
    preencherAluno(&aluno1, 1, "Maria", 8.5);
    imprimirAluno(&aluno1);
    
    // Aluno na heap (alocação dinâmica)
    Aluno *aluno2 = (Aluno*)malloc(sizeof(Aluno));
    if(aluno2 != NULL) {
        preencherAluno(aluno2, 2, "Pedro", 9.0);
        imprimirAluno(aluno2);
        free(aluno2); // Importante liberar a memória
    }
    
    // Array de alunos
    Aluno turma[3];
    preencherAluno(&turma[0], 3, "Ana", 7.5);
    preencherAluno(&turma[1], 4, "Carlos", 8.0);
    preencherAluno(&turma[2], 5, "Lucia", 9.5);
    
    printf("\nTurma:\n");
    for(int i = 0; i < 3; i++) {
        imprimirAluno(&turma[i]);
    }
    
    return 0;
}