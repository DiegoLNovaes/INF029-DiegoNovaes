/******************************************************************************

2) Faça uma função recursiva que calcule e retorne o N-ésimo termo da sequência 
Fibonacci. Alguns números desta sequência são: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89...

*******************************************************************************/
#include <stdio.h>
#include <math.h>


int Fibonacci_rec(int enesimo){
    
    if(enesimo == 1)
        return 0;
    if(enesimo == 2)
        return 1;
    else{
        return Fibonacci_rec(enesimo-1) + Fibonacci_rec(enesimo-2);
    }

    
}
int main(){
    
    int termo;
   
    printf("Digite até que termo você gostaria de Ver a sequencia de Fibonacci: ");
    scanf("%d", &termo);
    printf("\n O valor do %d° termo da sequência Fibonacci é: %d", termo, Fibonacci_rec(termo));
    

    return 0;
}