/******************************************************************************

10) Escreva uma função recursiva que determine quantas vezes um dígito K ocorre
em um número natural N. Por exemplo, o dígito 2 ocorre 3 vezes em 762021192.

*******************************************************************************/
#include <stdio.h>

int cont_digitos(int num, int dig){
    
    int resto, cont=0;
    
    if(num/10 == 0){
        if(num%10 == dig)
            return 1;
        else
            return 0;
    }
    resto = num%10;
    num = num/10;
    if(resto == dig)
        return 1 + cont_digitos(num, dig);
    else
        return cont_digitos(num, dig);
    
}


int main()
{
    
    int digito, numero;
    
    printf("Digite um número natural para descobrir quantas um dígito ocorre: ");
    scanf("%d", &numero);
    printf("Digite o digito: ");
    scanf("%d", &digito);
    
    printf("\n\nO dígito %d aparrece %d vez(es) no número", digito, cont_digitos(numero, digito));

    return 0;
}