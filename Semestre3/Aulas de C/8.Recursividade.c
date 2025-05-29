#include <stdio.h>

// Fatorial
int fatorial(int n) {
    if(n <= 1) return 1;
    return n * fatorial(n - 1);
}

// Fibonacci
int fibonacci(int n) {
    if(n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Soma dos elementos de um vetor
int somaRecursiva(int arr[], int tamanho) {
    if(tamanho <= 0) return 0;
    return arr[tamanho - 1] + somaRecursiva(arr, tamanho - 1);
}

// Torre de Hanoi
void hanoi(int n, char origem, char destino, char auxiliar) {
    if(n == 1) {
        printf("Mover disco 1 de %c para %c\n", origem, destino);
        return;
    }
    hanoi(n-1, origem, auxiliar, destino);
    printf("Mover disco %d de %c para %c\n", n, origem, destino);
    hanoi(n-1, auxiliar, destino, origem);
}

// Busca binária recursiva
int buscaBinaria(int arr[], int inicio, int fim, int valor) {
    if(inicio > fim) return -1;
    
    int meio = (inicio + fim) / 2;
    
    if(arr[meio] == valor) return meio;
    else if(arr[meio] > valor) return buscaBinaria(arr, inicio, meio-1, valor);
    else return buscaBinaria(arr, meio+1, fim, valor);
}

int main() {
    printf("Fatorial de 5: %d\n", fatorial(5));
    printf("Fibonacci de 6: %d\n", fibonacci(6));
    
    int numeros[] = {1, 2, 3, 4, 5};
    printf("Soma recursiva: %d\n", somaRecursiva(numeros, 5));
    
    printf("\nTorre de Hanoi (3 discos):\n");
    hanoi(3, 'A', 'C', 'B');
    
    int ordenado[] = {1, 3, 5, 7, 9, 11, 13};
    int posicao = buscaBinaria(ordenado, 0, 6, 7);
    printf("\nBusca binária por 7: posição %d\n", posicao);
    
    return 0;
}