#include <stdio.h>

// Busca Linear - O(n)
int buscaLinear(int arr[], int n, int x) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == x) {
            return i;
        }
    }
    return -1;
}

// Busca Binária Iterativa - O(log n)
int buscaBinaria(int arr[], int n, int x) {
    int esquerda = 0, direita = n - 1;
    
    while(esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        
        if(arr[meio] == x) {
            return meio;
        }
        
        if(arr[meio] < x) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
    return -1;
}

// Busca Binária Recursiva - O(log n)
int buscaBinariaRec(int arr[], int esquerda, int direita, int x) {
    if(direita >= esquerda) {
        int meio = esquerda + (direita - esquerda) / 2;
        
        if(arr[meio] == x) {
            return meio;
        }
        
        if(arr[meio] > x) {
            return buscaBinariaRec(arr, esquerda, meio - 1, x);
        }
        
        return buscaBinariaRec(arr, meio + 1, direita, x);
    }
    return -1;
}

// Busca em Lista Encadeada
typedef struct No {
    int dado;
    struct No* proximo;
} No;

No* criarNo(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->proximo = NULL;
    return novo;
}

int buscaLista(No* cabeca, int x) {
    No* atual = cabeca;
    int posicao = 0;
    
    while(atual != NULL) {
        if(atual->dado == x) {
            return posicao;
        }
        atual = atual->proximo;
        posicao++;
    }
    return -1;
}

int main() {
    // Array para buscas
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 67, 78};
    int n = sizeof(arr) / sizeof(arr[0]);
    int buscar = 23;
    
    printf("Array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Busca Linear
    int resultado = buscaLinear(arr, n, buscar);
    if(resultado == -1) {
        printf("Busca Linear: Elemento %d não encontrado\n", buscar);
    } else {
        printf("Busca Linear: Elemento %d encontrado na posição %d\n", buscar, resultado);
    }
    
    // Busca Binária
    resultado = buscaBinaria(arr, n, buscar);
    if(resultado == -1) {
        printf("Busca Binária: Elemento %d não encontrado\n", buscar);
    } else {
        printf("Busca Binária: Elemento %d encontrado na posição %d\n", buscar, resultado);
    }
    
    // Busca Binária Recursiva
    resultado = buscaBinariaRec(arr, 0, n-1, buscar);
    if(resultado == -1) {
        printf("Busca Binária Rec: Elemento %d não encontrado\n", buscar);
    } else {
        printf("Busca Binária Rec: Elemento %d encontrado na posição %d\n", buscar, resultado);
    }
    
    return 0;
}