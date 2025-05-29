#include <stdio.h>
#include <time.h>

// O(1) - Constante
int acessoVetor(int arr[], int indice) {
    return arr[indice];
}

// O(n) - Linear
int buscaLinear(int arr[], int tamanho, int valor) {
    for(int i = 0; i < tamanho; i++) {
        if(arr[i] == valor) return i;
    }
    return -1;
}

// O(log n) - Logarítmica
int buscaBinariaIt(int arr[], int tamanho, int valor) {
    int inicio = 0, fim = tamanho - 1;
    
    while(inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if(arr[meio] == valor) return meio;
        else if(arr[meio] < valor) inicio = meio + 1;
        else fim = meio - 1;
    }
    return -1;
}

// O(n²) - Quadrática
void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void imprimirVetor(int arr[], int tamanho) {
    for(int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int dados[] = {64, 34, 25, 12, 22, 11, 90};
    int tamanho = 7;
    
    printf("Array original: ");
    imprimirVetor(dados, tamanho);
    
    // O(1) - acesso direto
    printf("Elemento na posição 3: %d\n", acessoVetor(dados, 3));
    
    // O(n) - busca linear
    int pos = buscaLinear(dados, tamanho, 22);
    printf("Busca linear por 22: posição %d\n", pos);
    
    // O(n²) - ordenação
    bubbleSort(dados, tamanho);
    printf("Array ordenado: ");
    imprimirVetor(dados, tamanho);
    
    // O(log n) - busca binária
    pos = buscaBinariaIt(dados, tamanho, 22);
    printf("Busca binária por 22: posição %d\n", pos);
    
    return 0;
}