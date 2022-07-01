/******************************************************************************

18) O superfatorial de um número N é definida pelo produto dos N primeiros fatoriais
de N. Assim, o superfatorial de 4 é
sf(4) = 1! * 2! * 3! * 4! = 288

*******************************************************************************/
#include <stdio.h>

int fatorialrecursivo(int fat){
  
    if( fat==1 || fat==0)
        return 1; 
    else
        return fat * fatorialrecursivo(fat-1);
    
}

int sfatorial=1;

int superfatorial(int fatorial){
    
    
    if(fatorial==1)
        return sfatorial;
    else{
        sfatorial = sfatorial*fatorialrecursivo(fatorial);
        fatorial--;
        superfatorial(fatorial);
    }
}



int main(){
    
    int valor;
   
    
    printf("Digite o número que gostaria de calcular o Fatorial: ");
    scanf("%d", &valor);
    printf("\n\nO superfatorial de %d! é: %d", valor, superfatorial(valor));

    return 0;
}