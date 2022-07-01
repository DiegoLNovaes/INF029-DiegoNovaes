/******************************************************************************

16) A função fatorial duplo é definida como o produto de todos os números naturais
ímpares de 1 até algum número natural ímpar N.
Assim, o fatorial duplo de 5 é
5!! = 1 * 3 * 5 = 15
Faça uma função recursiva que receba um número inteiro positivo impar N e retorne o
fatorial duplo desse número.

*******************************************************************************/
#include <stdio.h>

int fatduplorec(int numero){
    
    if(numero == 1)
        return 1;
    else
        return (numero * fatduplorec(numero-2));
}

int main()
{
    
    int num;
    
    do{
    printf("Digite um número impar para calcularmos os seu fatorial duplo: ");
    scanf("%d", &num);
    if(num%2==0)
        printf("%d é par digite um número impar.\n", num);
    } while ((num%2)==0);
    
   printf("\nO valor de %d!! é: %d", num ,fatduplorec(num));

    return 0;
}