/******************************************************************************

6) Crie um programa em C, que contenha uma função recursiva que receba dois
inteiros positivos k e n e calcule kn. Utilize apenas multiplicações. O programa principal
deve solicitar ao usuário os valores de k e n e imprimir o resultado da chamada da
função.

*******************************************************************************/
#include <stdio.h>

int exprec(int k , int n){

    if(n == 0)
        return 1;
    else
        return k* exprec(k, n-1);
}

int main()
{
    
    int base, expoente;
    
    printf("Digite o valor da base da exponenciação: ");
    scanf("%d", &base);
    printf("Digite o valor do expoente: ");
    scanf("%d", &expoente);
    
    printf("\n\nO valor de K^n é: %d", exprec(base,expoente));

    return 0;
}