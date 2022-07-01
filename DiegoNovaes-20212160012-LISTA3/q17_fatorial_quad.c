/******************************************************************************

17) O fatorial quádruplo de um número N é dado por (2n)!/n!
Faça uma função recursiva que receba um número inteiro positivo N e retorne o
fatorial quádruplo desse número.

*******************************************************************************/
#include <stdio.h>

int fatorial4recursivo(int fat, int duplofat){
  
    if( (fat+1) == duplofat)
        return fat+1; 
    else
        return duplofat * fatorial4recursivo(fat, duplofat-1);
    
}

int main(){
    
    int valor;
    
    printf("Digite o número que gostaria de calcular o Fatorial quadruplo: ");
    scanf("%d", &valor);
    printf("\n\nO fatorial quadruplo de %d é: %d", valor, fatorial4recursivo(valor, 2*valor));

    return 0;
}