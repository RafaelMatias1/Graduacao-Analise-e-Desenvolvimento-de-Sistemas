#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLIENTES 50
#define MAX_ACOES 30
#define MAX_DESFAZER 5

typedef struct {
    int id;
    char descricao[50];
    char duracao[6]; // Formato 99h99
} Acao;

typedef struct {
    char nome[30];
    int idade;
    Acao acoes[MAX_ACOES];
    int total_acoes;
} Cliente;

typedef struct {
    Cliente fila[MAX_CLIENTES];
    int inicio, fim;
} FilaClientes;

void inicializarFila(FilaClientes *fila) {
    fila->inicio = 0;
    fila->fim = 0;
}

int filaVazia(FilaClientes *fila) {
    return fila->inicio == fila->fim;
}

int filaCheia(FilaClientes *fila) {
    return fila->fim == MAX_CLIENTES;
}

void adicionarCliente(FilaClientes *fila, Cliente cliente) {
    if (!filaCheia(fila)) {
        fila->fila[fila->fim++] = cliente;
    } else {
        printf("Fila cheia!\n");
    }
}

Cliente removerCliente(FilaClientes *fila) {
    Cliente c;
    if (!filaVazia(fila)) {
        c = fila->fila[fila->inicio++];
    } else {
        printf("Fila vazia!\n");
    }
    return c;
}

void adicionarAcao(Cliente *cliente, Acao acao) {
    if (cliente->total_acoes < MAX_ACOES) {
        cliente->acoes[cliente->total_acoes++] = acao;
    } else {
        printf("Limite de ações atingido!\n");
    }
}

void desfazerAcao(Cliente *cliente) {
    if (cliente->total_acoes > 0) {
        cliente->total_acoes--;
    } else {
        printf("Nenhuma ação para desfazer!\n");
    }
}

void exibirCliente(Cliente cliente) {
    printf("Nome: %s, Idade: %d\n", cliente.nome, cliente.idade);
    printf("Ações:\n");
    for (int i = 0; i < cliente.total_acoes; i++) {
        printf("  ID: %d, Descrição: %s, Duração: %s\n", cliente.acoes[i].id, cliente.acoes[i].descricao, cliente.acoes[i].duracao);
    }
}

int main() {
    FilaClientes fila;
    inicializarFila(&fila);
    
    Cliente cliente1 = {"João", 25, {}, 0};
    Acao acao1 = {1, "Comprar Ações", "02h30"};
    Acao acao2 = {2, "Vender Ações", "01h45"};
    
    adicionarAcao(&cliente1, acao1);
    adicionarAcao(&cliente1, acao2);
    adicionarCliente(&fila, cliente1);
    
    Cliente atendido = removerCliente(&fila);
    exibirCliente(atendido);
    
    printf("\nDesfazendo última ação:\n");
    desfazerAcao(&atendido);
    exibirCliente(atendido);
    
    return 0;
}
