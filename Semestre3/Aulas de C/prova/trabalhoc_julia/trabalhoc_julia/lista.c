#include "lista.h"
#include <stdlib.h>

struct lista {
    Nodo* primeiro;
};

Lista* cria_lista() {
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    if (lista == NULL) return NULL;
    
    lista->primeiro = NULL;
    
    return lista;
}

void insere_lista(Lista* lista, Nodo* nodo) {
    if (lista == NULL || nodo == NULL) return;
    
    define_proximo_nodo(nodo, lista->primeiro);
    lista->primeiro = nodo;
}

Nodo* obtem_primeiro_nodo(Lista* lista) {
    if (lista == NULL) return NULL;
    return lista->primeiro;
}

int lista_vazia(Lista* lista) {
    if (lista == NULL) return 1;
    return (lista->primeiro == NULL);
}

void libera_lista(Lista* lista) {
    if (lista == NULL) return;
    
    Nodo* atual = lista->primeiro;
    while (atual != NULL) {
        Nodo* temp = atual;
        atual = obtem_proximo_nodo(atual);
        libera_nodo(temp);
    }
    
    free(lista);
}