#include "lista.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h> // Mantenha este include para printf

struct lista {
    Nodo* inicio;
    int tamanho;
};

Lista* cria_lista() {
    Lista* nova_lista = (Lista*) malloc(sizeof(Lista));
    if (nova_lista == NULL) {
        return NULL;
    }
    nova_lista->inicio = NULL;
    nova_lista->tamanho = 0;
    // Debug: Confirma que a lista foi criada
    // printf("[DEBUG - cria_lista] Lista criada. Endereco: %p\n", (void*)nova_lista);
    return nova_lista;
}

void insere_lista(Lista* lista, Pessoa* pessoa) {
    if (lista == NULL || pessoa == NULL) {
        // Debug: Erro de entrada
        // printf("[DEBUG - insere_lista] Erro: Lista ou Pessoa NULL. Lista: %p, Pessoa: %p\n", (void*)lista, (void*)pessoa);
        return;
    }
    Nodo* novo_nodo = cria_nodo(pessoa);
    if (novo_nodo == NULL) {
        // Debug: Falha na criação do nodo
        // printf("[DEBUG - insere_lista] Erro: Falha ao criar nodo para pessoa '%s'.\n", obtem_nome(pessoa));
        return;
    }

    define_proximo_nodo(novo_nodo, lista->inicio);
    lista->inicio = novo_nodo;
    lista->tamanho++;
    // Debug: Mostra a pessoa inserida e o novo tamanho da lista
    // printf("[DEBUG - insere_lista] Pessoa '%s' inserida em lista (Addr: %p). Novo tamanho: %d.\n", obtem_nome(pessoa), (void*)lista, lista->tamanho);
}

Pessoa* busca_lista_por_nome(Lista* lista, const char* nome_busca) {
    if (lista == NULL || nome_busca == NULL) {
        return NULL;
    }
    Nodo* atual = lista->inicio;
    while (atual != NULL) {
        Pessoa* p = obtem_pessoa_nodo(atual);
        if (p != NULL && strcmp(obtem_nome(p), nome_busca) == 0) {
            return p;
        }
        atual = obtem_proximo_nodo(atual);
    }
    return NULL;
}

void remove_lista(Lista* lista, const char* nome_remover) {
    if (lista == NULL || nome_remover == NULL || lista->inicio == NULL) {
        return;
    }

    Nodo* atual = lista->inicio;
    Nodo* anterior = NULL;

    while (atual != NULL) {
        Pessoa* p = obtem_pessoa_nodo(atual);
        if (p != NULL && strcmp(obtem_nome(p), nome_remover) == 0) {
            if (anterior == NULL) {
                lista->inicio = obtem_proximo_nodo(atual);
            } else {
                define_proximo_nodo(anterior, obtem_proximo_nodo(atual));
            }
            libera_nodo(atual);
            lista->tamanho--;
            return;
        }
        anterior = atual;
        atual = obtem_proximo_nodo(atual);
    }
}

int obtem_tamanho_lista(const Lista* lista) {
    if (lista == NULL) {
        return 0;
    }
    // Debug: Retorna o tamanho da lista
    // printf("[DEBUG - obtem_tamanho_lista] Lista (Addr: %p) tamanho: %d.\n", (void*)lista, lista->tamanho);
    return lista->tamanho;
}

void libera_lista(Lista* lista) {
    if (lista == NULL) {
        return;
    }
    Nodo* atual = lista->inicio;
    while (atual != NULL) {
        Nodo* proximo = obtem_proximo_nodo(atual);
        libera_nodo(atual);
        atual = proximo;
    }
    free(lista);
    // Debug: Confirma a liberação da lista
    // printf("[DEBUG - libera_lista] Lista (Addr: %p) liberada.\n", (void*)lista);
}

Pessoa** obtem_todas_pessoas_lista(const Lista* lista, int* quantidade) {
    if (lista == NULL || quantidade == NULL) {
        *quantidade = 0;
        return NULL;
    }

    *quantidade = lista->tamanho;
    // Debug: Mostra o tamanho que será retornado
    // printf("[DEBUG - obtem_todas_pessoas_lista] Lista (Addr: %p) - Tamanho a retornar: %d.\n", (void*)lista, *quantidade);

    if (lista->tamanho == 0) {
        return NULL;
    }

    Pessoa** pessoas_array = (Pessoa**) malloc(sizeof(Pessoa*) * lista->tamanho);
    if (pessoas_array == NULL) {
        *quantidade = 0;
        // Debug: Falha na alocação do array de retorno
        // printf("[DEBUG - obtem_todas_pessoas_lista] Erro: Falha na alocação do array de pessoas.\n");
        return NULL;
    }

    Nodo* atual = lista->inicio;
    int i = 0;
    while (atual != NULL && i < lista->tamanho) {
        pessoas_array[i] = obtem_pessoa_nodo(atual);
        atual = obtem_proximo_nodo(atual);
        i++;
    }
    return pessoas_array;
}