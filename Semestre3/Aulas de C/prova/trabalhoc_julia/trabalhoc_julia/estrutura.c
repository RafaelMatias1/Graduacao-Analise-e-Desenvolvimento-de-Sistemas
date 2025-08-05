#include "estrutura.h"
#include "lista.h"
#include <stdlib.h>
#include <string.h>

struct estrutura {
    Lista** tabela;
    int tamanho;
};

unsigned int hash_string(char* str, int tamanho) {
    unsigned int hash = 5381;
    int c;
    
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }
    
    return hash % tamanho;
}

unsigned int hash_faixa(double valor, int tamanho) {
    if (valor <= 500.0) {
        return 0 % tamanho;
    } else if (valor <= 1000.0) {
        return 1 % tamanho;
    } else {
        return 2 % tamanho;
    }
}

Estrutura* cria_estrutura(int tamanho) {
    Estrutura* estrutura = (Estrutura*)malloc(sizeof(Estrutura));
    if (estrutura == NULL) return NULL;
    
    estrutura->tamanho = tamanho;
    estrutura->tabela = (Lista**)malloc(tamanho * sizeof(Lista*));
    if (estrutura->tabela == NULL) {
        free(estrutura);
        return NULL;
    }
    
    for (int i = 0; i < tamanho; i++) {
        estrutura->tabela[i] = cria_lista();
    }
    
    return estrutura;
}

void inserir(Estrutura* estrutura, Pessoa* pessoa) {
    if (estrutura == NULL || pessoa == NULL) return;
    
    unsigned int indice;
    
    if (estrutura->tamanho == 50) {
        indice = hash_string(obtem_nome(pessoa), estrutura->tamanho);
    } else {
        indice = hash_faixa(obtem_media(pessoa), estrutura->tamanho);
    }
    
    Nodo* nodo = cria_nodo(pessoa);
    if (nodo != NULL) {
        insere_lista(estrutura->tabela[indice], nodo);
    }
}

Pessoa** consultar_por_nome(Estrutura* estrutura, char* nome, int* quantidade) {
    if (estrutura == NULL || nome == NULL || quantidade == NULL) {
        if (quantidade != NULL) *quantidade = 0;
        return NULL;
    }
    
    *quantidade = 0;
    unsigned int indice = hash_string(nome, estrutura->tamanho);
    
    Nodo* atual = obtem_primeiro_nodo(estrutura->tabela[indice]);
    while (atual != NULL) {
        Pessoa* pessoa = obtem_pessoa_nodo(atual);
        if (strcmp(obtem_nome(pessoa), nome) == 0) {
            (*quantidade)++;
        }
        atual = obtem_proximo_nodo(atual);
    }
    
    if (*quantidade == 0) return NULL;
    
    Pessoa** resultado = (Pessoa**)malloc(*quantidade * sizeof(Pessoa*));
    if (resultado == NULL) {
        *quantidade = 0;
        return NULL;
    }
    
    int i = 0;
    atual = obtem_primeiro_nodo(estrutura->tabela[indice]);
    while (atual != NULL && i < *quantidade) {
        Pessoa* pessoa = obtem_pessoa_nodo(atual);
        if (strcmp(obtem_nome(pessoa), nome) == 0) {
            resultado[i] = pessoa;
            i++;
        }
        atual = obtem_proximo_nodo(atual);
    }
    
    return resultado;
}

Pessoa** consultar_por_faixa(Estrutura* estrutura, int faixa, int* quantidade) {
    if (estrutura == NULL || quantidade == NULL || faixa < 1 || faixa > 3) {
        if (quantidade != NULL) *quantidade = 0;
        return NULL;
    }
    
    *quantidade = 0;
    unsigned int indice = faixa - 1;
    
    Nodo* atual = obtem_primeiro_nodo(estrutura->tabela[indice]);
    while (atual != NULL) {
        (*quantidade)++;
        atual = obtem_proximo_nodo(atual);
    }
    
    if (*quantidade == 0) return NULL;
    
    Pessoa** resultado = (Pessoa**)malloc(*quantidade * sizeof(Pessoa*));
    if (resultado == NULL) {
        *quantidade = 0;
        return NULL;
    }
    
    int i = 0;
    atual = obtem_primeiro_nodo(estrutura->tabela[indice]);
    while (atual != NULL && i < *quantidade) {
        resultado[i] = obtem_pessoa_nodo(atual);
        i++;
        atual = obtem_proximo_nodo(atual);
    }
    
    return resultado;
}

void libera_estrutura(Estrutura* estrutura) {
    if (estrutura == NULL) return;
    
    for (int i = 0; i < estrutura->tamanho; i++) {
        if (estrutura->tabela[i] != NULL) {
         
            libera_lista(estrutura->tabela[i]);
        }
    }
    
    free(estrutura->tabela);
    free(estrutura);
}