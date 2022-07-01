/******************************************************************************

1) Faça uma função recursiva que calcule e retorne o fatorial de um número inteiro N.

*******************************************************************************/
#include <stdio.h>

int fatorialrecursivo(int fat){
  
    if( fat==1 || fat==0)
        return 1; 
    else
        return fat * fatorialrecursivo(fat-1);
    
}

int main(){
    
    int valor;
    
    printf("Digite o número que gostaria de calcular o Fatorial: ");
    scanf("%d", &valor);
    printf("\n\nO fatorial de %d! é: %d", valor, fatorialrecursivo(valor));

    return 0;
}
