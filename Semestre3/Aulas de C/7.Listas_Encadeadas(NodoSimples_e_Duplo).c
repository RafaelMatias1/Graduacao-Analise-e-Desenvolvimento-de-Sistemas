#include <stdio.h>
#include <stdlib.h>

// Lista Simples
typedef struct NoSimples {
    int dado;
    struct NoSimples *proximo;
} NoSimples;

// Lista Dupla
typedef struct NoDuplo {
    int dado;
    struct NoDuplo *proximo;
    struct NoDuplo *anterior;
} NoDuplo;

// Funções para Lista Simples
NoSimples* inserirInicio(NoSimples *cabeca, int valor) {
    NoSimples *novo = (NoSimples*)malloc(sizeof(NoSimples));
    novo->dado = valor;
    novo->proximo = cabeca;
    return novo;
}

void imprimirListaSimples(NoSimples *cabeca) {
    NoSimples *atual = cabeca;
    while(atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

// Funções para Lista Dupla
NoDuplo* inserirInicioD(NoDuplo *cabeca, int valor) {
    NoDuplo *novo = (NoDuplo*)malloc(sizeof(NoDuplo));
    novo->dado = valor;
    novo->proximo = cabeca;
    novo->anterior = NULL;
    
    if(cabeca != NULL) {
        cabeca->anterior = novo;
    }
    return novo;
}

void imprimirListaDupla(NoDuplo *cabeca) {
    printf("Frente: ");
    NoDuplo *atual = cabeca;
    while(atual != NULL) {
        printf("%d <-> ", atual->dado);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

int main() {
    // Lista Simples
    NoSimples *listaS = NULL;
    listaS = inserirInicio(listaS, 10);
    listaS = inserirInicio(listaS, 20);
    listaS = inserirInicio(listaS, 30);
    
    printf("Lista Simples:\n");
    imprimirListaSimples(listaS);
    
    // Lista Dupla
    NoDuplo *listaD = NULL;
    listaD = inserirInicioD(listaD, 100);
    listaD = inserirInicioD(listaD, 200);
    listaD = inserirInicioD(listaD, 300);
    
    printf("\nLista Dupla:\n");
    imprimirListaDupla(listaD);
    
    return 0;
}