// 2) Faça um programa que tenha duas variáveis do tipo char. Atribua valores inteiros a ela, tais como 1, 54, 65, 98.
// A cada atribuição, imprima a variável com printf, ora indicando a variável como inteira (%d), ora indicando como caractere(%c).


#include <stdio.h>

int main() {
    char var1, var2;
    var1 = 1;
    var2 = 54;
    printf("var1 como inteiro: %d | var1 como caractere: %c\n", var1, var1);
    printf("var2 como inteiro: %d | var2 como caractere: %c\n\n", var2, var2);

    var1 = 65;
    var2 = 98; 
    printf("var1 como inteiro: %d | var1 como caractere: %c\n", var1, var1);
    printf("var2 como inteiro: %d | var2 como caractere: %c\n", var2, var2);

    return 0;
}
