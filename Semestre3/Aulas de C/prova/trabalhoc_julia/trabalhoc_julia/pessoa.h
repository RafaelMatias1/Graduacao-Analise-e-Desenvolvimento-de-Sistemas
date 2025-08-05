#ifndef PESSOA_H
#define PESSOA_H

typedef struct pessoa Pessoa;

Pessoa* create_pessoa(int identificador, char* nome, char* bairro, double valor_medio);

int obtem_identificador(Pessoa* pessoa);
char* obtem_nome(Pessoa* pessoa);
char* obtem_bairro(Pessoa* pessoa);
double obtem_media(Pessoa* pessoa);

void libera_pessoa(Pessoa* pessoa);

#endif