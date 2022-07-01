/******************************************************************************

3) Faça uma função recursiva que permita inverter um número inteiro N. Ex: 123 - 321


*******************************************************************************/
#include <stdio.h>
#include <math.h>

int inverte_num();
int qtd_digitos();

int main()
{
    int num, numero_invertido;
    
    printf("Digite um número: ");
    scanf("%d", &num);
    
    numero_invertido = inverte_num(num);
    printf("\nO inverso do numero acima é: %d", numero_invertido);

    return 0;
}



int inverte_num(int numero){
    
    int potencia;
    int resto;
    
    potencia = qtd_digitos(numero);
    
    if(numero/10 == 0)
        return numero%10;
    else{
        resto= numero%10;
        numero= numero/10;
        potencia--;
        return resto * pow(10, potencia) + inverte_num(numero);
    }
    
}


int qtd_digitos(int digi){

    int cont=1;
    
    while(digi>10){
        digi = digi/10;
        cont++;
    }
    
    return cont;
}