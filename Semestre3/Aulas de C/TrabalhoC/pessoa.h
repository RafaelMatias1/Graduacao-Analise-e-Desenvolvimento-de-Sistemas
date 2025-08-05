#ifndef PESSOA_H
#define PESSOA_H

typedef struct pessoa Pessoa;

Pessoa* create_pessoa(int identificador, const char* nome, const char* bairro, double valor_medio_compras);

int obtem_identificador(const Pessoa* p);

const char* obtem_nome(const Pessoa* p);

const char* obtem_bairro(const Pessoa* p);

double obtem_media(const Pessoa* p);

void libera_pessoa(Pessoa* p);

#endif 