//No mesmo programa, atribua para a primeira variável 120 e para a segunda variável 280.
// Imprima as variáveis da mesma forma de antes.

#include <stdio.h>

int main() {
    char var1, var2;
    var1 = 1;
    var2 = 54;
    printf("var1 como inteiro: %d | var1 como acaractere: %c\n", var1, var1);
    printf("var2 como inteiro: %d | var2 como caractere: %c\n\n", var2, var2);

    var1 = 65; 
    var2 = 98;  
    printf("var1 como inteiro: %d | var1 como caractere: %c\n", var1, var1);
    printf("var2 como inteiro: %d | var2 como caractere: %c\n\n", var2, var2);

    var1 = 120; 
    var2 = 280;

    printf("var1 como inteiro: %d | var1 como caractere: %c\n", var1, var1);
    printf("var2 como inteiro: %d | var2 como caractere: %c\n", var2, var2);

    return 0;
}
