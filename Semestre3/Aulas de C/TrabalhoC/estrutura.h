#ifndef ESTRUTURA_H
#define ESTRUTURA_H

#include "pessoa.h"
#include "lista.h"


typedef struct estrutura Estrutura;

Estrutura* cria_estrutura(int tamanho_inicial);

void inserir(Estrutura* estrutura, Pessoa* pessoa);

Pessoa** consultar_por_nome(Estrutura* estrutura, const char* nome_busca, int* quantidade);

Pessoa** consultar_por_faixa(Estrutura* estrutura, int faixa, int* quantidade);

void libera_estrutura(Estrutura* estrutura);

#endif 