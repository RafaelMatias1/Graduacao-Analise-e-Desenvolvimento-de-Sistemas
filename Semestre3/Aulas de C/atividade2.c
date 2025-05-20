// 1) Como os tipos primitivos se comportam em operações e representações?

#include <stdio.h>

int main() {
    int a = 5, b = 2;
    float c = 2.5, resultado;
    resultado = a + c;
    printf("Soma (int + float): %f\n", resultado);
    resultado = (float)a / b;
    printf("Divisão com casting (5 / 2): %f\n", resultado);
    int mod = a % b;
    printf("Módulo (5 %% 2): %d\n", mod);
    char ch = 127;  
    ch = ch + 1;  
    printf("Overflow de char (127 + 1): %d\n", ch);
    int num = 1;
    if (*(char *)&num == 1)
        printf("Este sistema é Little-Endian\n");
    else
        printf("Este sistema é Big-Endian\n");

    return 0;
}
