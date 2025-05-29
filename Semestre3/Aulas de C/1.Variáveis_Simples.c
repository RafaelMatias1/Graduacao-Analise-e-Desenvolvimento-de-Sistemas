#include <stdio.h>

int main() {
    // Declaração e inicialização de variáveis
    int idade = 20;
    float altura = 1.75;
    char inicial = 'R';
    double salario = 2500.50;
    
    printf("Idade: %d\n", idade);
    printf("Altura: %.2f\n", altura);
    printf("Inicial: %c\n", inicial);
    printf("Salário: %.2lf\n", salario);
    
    // Modificando valores
    idade++;
    altura += 0.02;
    
    printf("Nova idade: %d\n", idade);
    printf("Nova altura: %.2f\n", altura);
    
    return 0;
}