#include <stdio.h>

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort - O(n²)
void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                trocar(&arr[j], &arr[j+1]);
            }
        }
    }
}

// Selection Sort - O(n²)
void selectionSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        int minIdx = i;
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        trocar(&arr[minIdx], &arr[i]);
    }
}

// Insertion Sort - O(n²)
void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int chave = arr[i];
        int j = i - 1;
        
        while(j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = chave;
    }
}

// Quick Sort - O(n log n) médio
int particionar(int arr[], int baixo, int alto) {
    int pivot = arr[alto];
    int i = (baixo - 1);
    
    for(int j = baixo; j <= alto - 1; j++) {
        if(arr[j] < pivot) {
            i++;
            trocar(&arr[i], &arr[j]);
        }
    }
    trocar(&arr[i + 1], &arr[alto]);
    return (i + 1);
}

void quickSort(int arr[], int baixo, int alto) {
    if(baixo < alto) {
        int pi = particionar(arr, baixo, alto);
        quickSort(arr, baixo, pi - 1);
        quickSort(arr, pi + 1, alto);
    }
}

void imprimirArray(int arr[], int tamanho) {
    for(int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int dados1[] = {64, 34, 25, 12, 22, 11, 90};
    int dados2[] = {64, 34, 25, 12, 22, 11, 90};
    int dados3[] = {64, 34, 25, 12, 22, 11, 90};
    int dados4[] = {64, 34, 25, 12, 22, 11, 90};
    int tamanho = 7;
    
    printf("Array original: ");
    imprimirArray(dados1, tamanho);
    
    bubbleSort(dados1, tamanho);
    printf("Bubble Sort: ");
    imprimirArray(dados1, tamanho);
    
    selectionSort(dados2, tamanho);
    printf("Selection Sort: ");
    imprimirArray(dados2, tamanho);
    
    insertionSort(dados3, tamanho);
    printf("Insertion Sort: ");
    imprimirArray(dados3, tamanho);
    
    quickSort(dados4, 0, tamanho-1);
    printf("Quick Sort: ");
    imprimirArray(dados4, tamanho);
    
    return 0;
}