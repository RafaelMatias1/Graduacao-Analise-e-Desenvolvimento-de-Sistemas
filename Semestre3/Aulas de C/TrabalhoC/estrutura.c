#include "estrutura.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h> // Mantenha este include para printf

struct estrutura {
    Lista** baldes;
    int tamanho;
    Pessoa** pessoas_originais;
    int num_pessoas_originais;
    int capacidade_pessoas_originais;
};

static unsigned int hash_nome(const char* nome, int tamanho_tabela) {
    unsigned int hash_val = 0;
    while (*nome != '\0') {
        hash_val = (hash_val << 5) + *nome++;
    }
    return hash_val % tamanho_tabela;
}

static unsigned int hash_faixa(int faixa, int tamanho_tabela) {
    // Debug: Verifica se o mapeamento da faixa para o índice está correto
    // printf("[DEBUG - hash_faixa] Faixa: %d, Tamanho Tabela: %d -> Indice: %u\n", faixa, tamanho_tabela, (unsigned int)(faixa - 1));
    if (faixa >= 1 && faixa <= tamanho_tabela) {
        return (unsigned int)(faixa - 1);
    }
    return 0;
}

static void adicionar_pessoa_original(Estrutura* estrutura, Pessoa* p) {
    if (estrutura->pessoas_originais == NULL) {
        estrutura->capacidade_pessoas_originais = 10;
        estrutura->pessoas_originais = (Pessoa**) malloc(sizeof(Pessoa*) * estrutura->capacidade_pessoas_originais);
        if (estrutura->pessoas_originais == NULL) {
            return;
        }
        estrutura->num_pessoas_originais = 0;
    }

    if (estrutura->num_pessoas_originais >= estrutura->capacidade_pessoas_originais) {
        estrutura->capacidade_pessoas_originais *= 2;
        Pessoa** temp = (Pessoa**) realloc(estrutura->pessoas_originais, sizeof(Pessoa*) * estrutura->capacidade_pessoas_originais);
        if (temp == NULL) {
            return;
        }
        estrutura->pessoas_originais = temp;
    }
    estrutura->pessoas_originais[estrutura->num_pessoas_originais++] = p;
}

Estrutura* cria_estrutura(int tamanho_inicial) {
    Estrutura* nova_estrutura = (Estrutura*) malloc(sizeof(Estrutura));
    if (nova_estrutura == NULL) {
        return NULL;
    }
    nova_estrutura->tamanho = tamanho_inicial;
    nova_estrutura->baldes = (Lista**) calloc(tamanho_inicial, sizeof(Lista*));
    if (nova_estrutura->baldes == NULL) {
        free(nova_estrutura);
        return NULL;
    }

    for (int i = 0; i < tamanho_inicial; i++) {
        nova_estrutura->baldes[i] = cria_lista();
        if (nova_estrutura->baldes[i] == NULL) {
            for (int j = 0; j < i; j++) {
                libera_lista(nova_estrutura->baldes[j]);
            }
            free(nova_estrutura->baldes);
            free(nova_estrutura);
            return NULL;
        }
    }
    
    nova_estrutura->pessoas_originais = NULL;
    nova_estrutura->num_pessoas_originais = 0;
    nova_estrutura->capacidade_pessoas_originais = 0;
    // Debug: Confirma a criação das estruturas
    // printf("[DEBUG - cria_estrutura] Estrutura de tamanho %d criada.\n", tamanho_inicial);
    return nova_estrutura;
}

void inserir(Estrutura* estrutura, Pessoa* pessoa) {
    if (estrutura == NULL || pessoa == NULL) {
        return;
    }

    if (estrutura->tamanho == 50) { // Assume que esta é a estrutura para nomes
        unsigned int indice = hash_nome(obtem_nome(pessoa), estrutura->tamanho);
        if (estrutura->baldes[indice] != NULL) {
            insere_lista(estrutura->baldes[indice], pessoa);
            // Debug: Acompanha a inserção na estrutura de nomes
            // printf("[DEBUG - inserir] Nome: '%s' (ID: %d) inserido na estrutura_nome (indice %u).\n", obtem_nome(pessoa), obtem_identificador(pessoa), indice);
        }
        adicionar_pessoa_original(estrutura, pessoa);
    } else if (estrutura->tamanho == 3) { // Assume que esta é a estrutura para faixas
        double valor = obtem_media(pessoa);
        int faixa;
        if (valor <= 500.0) {
            faixa = 1;
        } else if (valor > 500.0 && valor <= 1000.0) {
            faixa = 2;
        } else { // valor > 1000.0
            faixa = 3;
        }
        unsigned int indice = hash_faixa(faixa, estrutura->tamanho);
        if (estrutura->baldes[indice] != NULL) {
            insere_lista(estrutura->baldes[indice], pessoa);
            // Debug: Acompanha a inserção na estrutura de valores
            // printf("[DEBUG - inserir] Pessoa '%s' (Valor: %.2f) inserida na Faixa %d (Indice: %u).\n", obtem_nome(pessoa), valor, faixa, indice);
        } else {
            // Debug: Alerta se um balde for NULL, o que não deveria acontecer após calloc e cria_lista
            // printf("[DEBUG - inserir] ERRO: Balde de faixa %d (indice %u) é NULL para pessoa '%s'.\n", faixa, indice, obtem_nome(pessoa));
        }
    } else {
        fprintf(stderr, "Erro: Tamanho de estrutura inesperado para insercao (%d).\n", estrutura->tamanho);
    }
}

Pessoa** consultar_por_nome(Estrutura* estrutura, const char* nome_busca, int* quantidade) {
    if (estrutura == NULL || nome_busca == NULL || quantidade == NULL || estrutura->tamanho != 50) {
        *quantidade = 0;
        return NULL;
    }

    unsigned int indice = hash_nome(nome_busca, estrutura->tamanho);
    // Debug: Mostra qual balde está sendo consultado para nomes
    // printf("[DEBUG - consultar_por_nome] Buscando por '%s' no índice %u.\n", nome_busca, indice);

    if (estrutura->baldes[indice] == NULL) {
        *quantidade = 0;
        // printf("[DEBUG - consultar_por_nome] Balde %u é NULL.\n", indice);
        return NULL;
    }

    Pessoa* p_encontrada = busca_lista_por_nome(estrutura->baldes[indice], nome_busca);

    if (p_encontrada != NULL) {
        *quantidade = 1;
        Pessoa** resultado = (Pessoa**) malloc(sizeof(Pessoa*));
        if (resultado == NULL) {
            *quantidade = 0;
            return NULL;
        }
        resultado[0] = p_encontrada;
        // printf("[DEBUG - consultar_por_nome] '%s' ENCONTRADA. ID: %d\n", obtem_nome(p_encontrada), obtem_identificador(p_encontrada));
        return resultado;
    } else {
        *quantidade = 0;
        // printf("[DEBUG - consultar_por_nome] '%s' NAO ENCONTRADA.\n", nome_busca);
        return NULL;
    }
}

Pessoa** consultar_por_faixa(Estrutura* estrutura, int faixa, int* quantidade) {
    if (estrutura == NULL || quantidade == NULL || estrutura->tamanho != 3 || faixa < 1 || faixa > 3) {
        *quantidade = 0;
        // Debug: Validação de entrada para consulta por faixa
        // printf("[DEBUG - consultar_por_faixa] Erro: Entrada inválida. Faixa: %d, Tamanho Estrutura: %d.\n", faixa, (estrutura != NULL ? estrutura->tamanho : -1));
        return NULL;
    }

    unsigned int indice = hash_faixa(faixa, estrutura->tamanho);
    // Debug: Qual índice de balde estamos consultando para a faixa
    // printf("[DEBUG - consultar_por_faixa] Consultando Faixa %d (Indice Balde: %u).\n", faixa, indice);

    if (estrutura->baldes[indice] == NULL) {
        *quantidade = 0;
        // Debug: Balde de faixa NULL
        // printf("[DEBUG - consultar_por_faixa] ERRO: Balde de faixa %d (indice %u) é NULL.\n", faixa, indice);
        return NULL;
    }

    Pessoa** resultado_faixa = obtem_todas_pessoas_lista(estrutura->baldes[indice], quantidade);
    // Debug: Resultado final da consulta por faixa
    // printf("[DEBUG - consultar_por_faixa] Faixa %d (Indice %u) retornou QUANTIDADE: %d pessoas.\n", faixa, indice, *quantidade);
    return resultado_faixa;
}

void libera_estrutura(Estrutura* estrutura) {
    if (estrutura == NULL) {
        return;
    }

    if (estrutura->baldes != NULL) {
        for (int i = 0; i < estrutura->tamanho; i++) {
            if (estrutura->baldes[i] != NULL) {
                libera_lista(estrutura->baldes[i]);
            }
        }
        free(estrutura->baldes);
    }

    if (estrutura->pessoas_originais != NULL && estrutura->tamanho == 50) {
        // Debug: Quantidade de pessoas originais sendo liberadas
        // printf("[DEBUG - libera_estrutura] Liberando %d pessoas originais da estrutura de nomes.\n", estrutura->num_pessoas_originais);
        for (int i = 0; i < estrutura->num_pessoas_originais; i++) {
            libera_pessoa(estrutura->pessoas_originais[i]);
        }
        free(estrutura->pessoas_originais);
    }
    
    free(estrutura);
    // Debug: Confirma a liberação da estrutura
    // printf("[DEBUG - libera_estrutura] Estrutura liberada. Tamanho: %d.\n", estrutura->tamanho);
}