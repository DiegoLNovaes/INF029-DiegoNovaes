/******************************************************************************

8. Dado que a fórmula para conversão de Fahrenheit para Celsius é 
C = 5/9 (F – 32), leu um 
valor de temperatura em Fahrenheit e exibi-lo em Celsius

*******************************************************************************/
#include <stdio.h>

int main()
{
    float Fahrenheit, Celsius;
    
    printf("Conversor de temperatura, de Fahrenheit para Celsius.\nDigite o valor da temperatura em Fahrenheit.");
    scanf("%f", &Fahrenheit);
    Celsius = (5*(Fahrenheit-32)/9); 
    /*Se você colocar 5/9 na expressão o c entenderá que é
    uma divisão de números inteiros e retornará zero, Use 5.0/9.0 ou mude a
    ordem*/ 
    printf("%0.1f Fahrenheit equivale a %0.1f Celsius.",Fahrenheit, Celsius);

    return 0;
}

