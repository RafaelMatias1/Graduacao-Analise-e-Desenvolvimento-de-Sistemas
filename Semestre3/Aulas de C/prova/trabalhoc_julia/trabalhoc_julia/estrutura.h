#ifndef ESTRUTURA_H
#define ESTRUTURA_H

#include "pessoa.h"

typedef struct estrutura Estrutura;

Estrutura* cria_estrutura(int tamanho);

void inserir(Estrutura* estrutura, Pessoa* pessoa);

Pessoa** consultar_por_nome(Estrutura* estrutura, char* nome, int* quantidade);

Pessoa** consultar_por_faixa(Estrutura* estrutura, int faixa, int* quantidade);

void libera_estrutura(Estrutura* estrutura);

#endif