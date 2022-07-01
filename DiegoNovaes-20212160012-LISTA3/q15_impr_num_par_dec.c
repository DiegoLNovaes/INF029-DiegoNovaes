/******************************************************************************

15) Faça uma função recursiva que receba um número inteiro positivo par N e imprima
todos os números pares de 0 até N em ordem decrescente.

*******************************************************************************/
#include <stdio.h>

void imprime_num_rec(int cont, int numero){
    
    
    
    if(cont == numero){
        printf("| %d |", numero);
        numero--;
    }
    else{
        printf("| %d ", numero);
        numero = numero -2;
        imprime_num_rec(cont, numero);
    }
}

int main(){
    
    int num, soma1=0;
    
    do{
    printf("Digite um número N par para imprimirmos a sequência dos pares de N até 0: ");
    scanf("%d", &num);
    if(num%2!=0)
        printf("%d é impar digite um número par.\n", num);
    } while ((num%2)!=0);
    
    imprime_num_rec(soma1, num);

    return 0;
}