#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int mdc_recursao(int num1, int num2) {
    if (num2== 0) {
        return num1; 
    } else {
        return mdc_recursao(num2, num1 % num2); 
    }
}

int main() {
    int num1,num2,resultado;
    scanf("%d", &num1);
    scanf("%d", &num2);
    resultado = mdc_recursao(num1,num2);
    printf("%d", resultado);
    
    return 0;
}