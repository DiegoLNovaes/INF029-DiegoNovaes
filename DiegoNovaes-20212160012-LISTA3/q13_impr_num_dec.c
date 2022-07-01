/******************************************************************************

13) Faça uma função recursiva que receba um número inteiro positivo N e imprima
todos os números naturais de 0 até N em ordem decrescente.

*******************************************************************************/
#include <stdio.h>

void imprime_num_rec(int cont, int numero){
    
    
    
    if(cont == numero){
        printf("| %d |", numero);
        numero--;
    }
    else{
        printf("| %d ", numero);
        numero--;
        imprime_num_rec(cont, numero);
    }
}

int main(){
    
    int num, soma1=0;
    
    printf("Digite um número N para imprimirmos a sequência de O até N em ordem decrscente: ");
    scanf("%d", &num);
    imprime_num_rec(soma1, num);

    return 0;
}