#ifndef NODO_H
#define NODO_H

#include "pessoa.h" 

typedef struct nodo Nodo;

Nodo* cria_nodo(Pessoa* pessoa);

Pessoa* obtem_pessoa_nodo(const Nodo* nodo);

Nodo* obtem_proximo_nodo(const Nodo* nodo);

void define_proximo_nodo(Nodo* nodo, Nodo* proximo);

void libera_nodo(Nodo* nodo);

#endif 