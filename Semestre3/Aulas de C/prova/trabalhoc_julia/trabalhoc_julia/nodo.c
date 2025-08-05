#include "nodo.h"
#include <stdlib.h>

struct nodo {
    Pessoa* pessoa;
    Nodo* proximo;
};

Nodo* cria_nodo(Pessoa* pessoa) {
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    if (nodo == NULL) return NULL;
    
    nodo->pessoa = pessoa;
    nodo->proximo = NULL;
    
    return nodo;
}

Pessoa* obtem_pessoa_nodo(Nodo* nodo) {
    if (nodo == NULL) return NULL;
    return nodo->pessoa;
}

Nodo* obtem_proximo_nodo(Nodo* nodo) {
    if (nodo == NULL) return NULL;
    return nodo->proximo;
}

void define_proximo_nodo(Nodo* nodo, Nodo* proximo) {
    if (nodo != NULL) {
        nodo->proximo = proximo;
    }
}

void libera_nodo(Nodo* nodo) {
    if (nodo != NULL) {
        free(nodo);
    }
}