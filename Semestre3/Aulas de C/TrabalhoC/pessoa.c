#include "pessoa.h"
#include <stdlib.h>
#include <string.h>

struct pessoa {
    int identificador;
    char nome[41];
    char bairro[31];
    double valor_medio_compras;
};

Pessoa* create_pessoa(int identificador, const char* nome, const char* bairro, double valor_medio_compras) {
    Pessoa* nova_pessoa = (Pessoa*) malloc(sizeof(Pessoa));
    if (nova_pessoa == NULL) {
        return NULL;
    }

    nova_pessoa->identificador = identificador;
    strncpy(nova_pessoa->nome, nome, sizeof(nova_pessoa->nome) - 1);
    nova_pessoa->nome[sizeof(nova_pessoa->nome) - 1] = '\0';

    strncpy(nova_pessoa->bairro, bairro, sizeof(nova_pessoa->bairro) - 1);
    nova_pessoa->bairro[sizeof(nova_pessoa->bairro) - 1] = '\0';

    nova_pessoa->valor_medio_compras = valor_medio_compras;

    return nova_pessoa;
}

int obtem_identificador(const Pessoa* p) {
    if (p == NULL) {
        return -1;
    }
    return p->identificador;
}

const char* obtem_nome(const Pessoa* p) {
    if (p == NULL) {
        return NULL;
    }
    return p->nome;
}

const char* obtem_bairro(const Pessoa* p) {
    if (p == NULL) {
        return NULL;
    }
    return p->bairro;
}

double obtem_media(const Pessoa* p) {
    if (p == NULL) {
        return -1.0;
    }
    return p->valor_medio_compras;
}

void libera_pessoa(Pessoa* p) {
    if (p != NULL) {
        free(p);
    }
}