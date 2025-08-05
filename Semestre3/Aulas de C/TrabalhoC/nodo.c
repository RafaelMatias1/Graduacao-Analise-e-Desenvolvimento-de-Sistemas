#include "nodo.h"
#include <stdlib.h> 

struct nodo {
    Pessoa* pessoa;
    Nodo* proximo;
};

Nodo* cria_nodo(Pessoa* pessoa) {
    Nodo* novo_nodo = (Nodo*) malloc(sizeof(Nodo));
    if (novo_nodo == NULL) {
        return NULL;
    }
    novo_nodo->pessoa = pessoa;
    novo_nodo->proximo = NULL;
    return novo_nodo;
}

Pessoa* obtem_pessoa_nodo(const Nodo* nodo) {
    if (nodo == NULL) {
        return NULL;
    }
    return nodo->pessoa;
}

Nodo* obtem_proximo_nodo(const Nodo* nodo) {
    if (nodo == NULL) {
        return NULL;
    }
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