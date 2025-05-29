#include <stdio.h>

// Passagem por valor
int quadrado(int num) {
    return num * num;
}

// Passagem por referência
void incrementar(int *num) {
    (*num)++;
}

// Função com vetor
double media(int arr[], int tamanho) {
    int soma = 0;
    for(int i = 0; i < tamanho; i++) {
        soma += arr[i];
    }
    return (double)soma / tamanho;
}

// Função recursiva
int fatorial(int n) {
    if(n <= 1) return 1;
    return n * fatorial(n - 1);
}

int main() {
    int numero = 5;
    
    printf("Número: %d\n", numero);
    printf("Quadrado: %d\n", quadrado(numero));
    printf("Número após quadrado: %d\n", numero); // Não muda
    
    incrementar(&numero);
    printf("Número após incrementar: %d\n", numero); // Muda
    
    int notas[] = {8, 7, 9, 6, 10};
    printf("Média: %.2f\n", media(notas, 5));
    
    printf("Fatorial de 5: %d\n", fatorial(5));
    
    return 0;
}