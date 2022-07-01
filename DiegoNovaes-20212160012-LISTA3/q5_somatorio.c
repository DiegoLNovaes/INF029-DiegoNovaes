/******************************************************************************
5) Crie uma função recursiva que receba um número inteiro positivo N e calcule o 
somatório dos números de 1 a N

*******************************************************************************/

#include <stdio.h>

int somatorio();

int main()
{
    
    int num;
    
    printf("Digite o valor um valor N para somarmos de 1 a N: ");
    scanf("%d", &num);
    printf("O somatório é: %d",somatorio(num));
    
    return 0;
}

int somatorio(int numero){
    
    if(numero == 0)
        return 0;
    else
        return numero + somatorio(numero-1);
    
}

