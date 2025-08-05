#ifndef LISTA_H
#define LISTA_H

#include "nodo.h"   // Inclui a definição de Nodo
#include "pessoa.h" // Inclui a definição de Pessoa

typedef struct lista Lista;

Lista* cria_lista();

void insere_lista(Lista* lista, Pessoa* pessoa);

Pessoa* busca_lista_por_nome(Lista* lista, const char* nome_busca);

void remove_lista(Lista* lista, const char* nome_remover);

int obtem_tamanho_lista(const Lista* lista);

void libera_lista(Lista* lista);

Pessoa** obtem_todas_pessoas_lista(const Lista* lista, int* quantidade);

#endif 