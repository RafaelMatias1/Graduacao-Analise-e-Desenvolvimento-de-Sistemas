#include <stdio.h>

void trocarValores(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10, y = 20;
    int *ptr;
    
    // Ponteiro aponta para x
    ptr = &x;
    
    printf("Valor de x: %d\n", x);
    printf("Endereço de x: %p\n", &x);
    printf("Valor do ponteiro: %p\n", ptr);
    printf("Valor apontado pelo ponteiro: %d\n", *ptr);
    
    // Modificando através do ponteiro
    *ptr = 15;
    printf("Novo valor de x: %d\n", x);
    
    // Usando ponteiros para trocar valores
    printf("Antes: x=%d, y=%d\n", x, y);
    trocarValores(&x, &y);
    printf("Depois: x=%d, y=%d\n", x, y);
    
    return 0;
}