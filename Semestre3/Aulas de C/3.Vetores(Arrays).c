#include <stdio.h>

void imprimirVetor(int arr[], int tamanho) {
    for(int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int somarVetor(int arr[], int tamanho) {
    int soma = 0;
    for(int i = 0; i < tamanho; i++) {
        soma += arr[i];
    }
    return soma;
}

int main() {
    int numeros[5] = {10, 20, 30, 40, 50};
    int tamanho = 5;
    
    printf("Vetor: ");
    imprimirVetor(numeros, tamanho);
    
    printf("Elemento na posição 2: %d\n", numeros[2]);
    
    // Modificando um elemento
    numeros[1] = 25;
    printf("Vetor modificado: ");
    imprimirVetor(numeros, tamanho);
    
    int soma = somarVetor(numeros, tamanho);
    printf("Soma dos elementos: %d\n", soma);
    
    // Vetor de caracteres (string)
    char nome[20] = "Rafael";
    printf("Nome: %s\n", nome);
    
    return 0;
}