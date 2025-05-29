#include <stdio.h>
#include <string.h>

// Definição da estrutura
typedef struct {
    char nome[50];
    int idade;
    float salario;
} Pessoa;

// Funções para "encapsular" operações
void inicializarPessoa(Pessoa *p, char nome[], int idade, float salario) {
    strcpy(p->nome, nome);
    p->idade = idade;
    p->salario = salario;
}

void imprimirPessoa(Pessoa p) {
    printf("Nome: %s\n", p.nome);
    printf("Idade: %d\n", p.idade);
    printf("Salário: %.2f\n", p.salario);
}

void aumentarSalario(Pessoa *p, float percentual) {
    p->salario *= (1 + percentual/100);
}

int main() {
    Pessoa funcionario;
    
    inicializarPessoa(&funcionario, "João", 30, 3000.0);
    
    printf("Dados iniciais:\n");
    imprimirPessoa(funcionario);
    
    aumentarSalario(&funcionario, 10); // 10% de aumento
    
    printf("\nApós aumento:\n");
    imprimirPessoa(funcionario);
    
    return 0;
}