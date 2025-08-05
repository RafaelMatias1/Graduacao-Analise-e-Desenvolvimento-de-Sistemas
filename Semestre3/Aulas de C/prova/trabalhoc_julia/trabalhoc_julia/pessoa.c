#include "pessoa.h"
#include <stdlib.h>
#include <string.h>

struct pessoa {
    int identificador;
    char* nome;
    char* bairro;
    double valor_medio;
};

Pessoa* create_pessoa(int identificador, char* nome, char* bairro, double valor_medio) {
    Pessoa* p = (Pessoa*)malloc(sizeof(Pessoa));
    if (p == NULL) return NULL;
    
    p->identificador = identificador;
    
    p->nome = (char*)malloc((strlen(nome) + 1) * sizeof(char));
    if (p->nome == NULL) {
        free(p);
        return NULL;
    }
    strcpy(p->nome, nome);
    
    p->bairro = (char*)malloc((strlen(bairro) + 1) * sizeof(char));
    if (p->bairro == NULL) {
        free(p->nome);
        free(p);
        return NULL;
    }
    strcpy(p->bairro, bairro);
    
    p->valor_medio = valor_medio;
    
    return p;
}

int obtem_identificador(Pessoa* pessoa) {
    if (pessoa == NULL) return -1;
    return pessoa->identificador;
}

char* obtem_nome(Pessoa* pessoa) {
    if (pessoa == NULL) return NULL;
    return pessoa->nome;
}

char* obtem_bairro(Pessoa* pessoa) {
    if (pessoa == NULL) return NULL;
    return pessoa->bairro;
}

double obtem_media(Pessoa* pessoa) {
    if (pessoa == NULL) return -1.0;
    return pessoa->valor_medio;
}

void libera_pessoa(Pessoa* pessoa) {
    if (pessoa != NULL) {
        free(pessoa->nome);
        free(pessoa->bairro);
        free(pessoa);
    }
}