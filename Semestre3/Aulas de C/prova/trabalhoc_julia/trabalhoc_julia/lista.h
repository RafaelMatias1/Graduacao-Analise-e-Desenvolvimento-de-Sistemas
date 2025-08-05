#ifndef LISTA_H
#define LISTA_H

#include "nodo.h"

typedef struct lista Lista;

Lista* cria_lista();

void insere_lista(Lista* lista, Nodo* nodo);

Nodo* obtem_primeiro_nodo(Lista* lista);

int lista_vazia(Lista* lista);

void libera_lista(Lista* lista);

#endif