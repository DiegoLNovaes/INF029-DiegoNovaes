/******************************************************************************

22) Os números tetranacci iniciam com quatro termos pré-determinados e a partir daí
todos os demais números são obtidos pela soma dos quatro números anteriores. Os
primeiros números tetranacci são: 0, 0, 0, 1, 1, 2, 4, 8, 15, 29, 56, 108, 208...
Faça uma função recursiva que receba um número N e retorne o N-ésimo termo da
sequência de tetranacci.

*******************************************************************************/
#include <stdio.h>
#include <math.h>


int tetranacci_rec(int enesimo){
    
    if(enesimo == 1 || enesimo == 2 || enesimo == 3)
        return 0;
    if(enesimo == 4)
        return 1;
    else{
        return tetranacci_rec(enesimo-1) + tetranacci_rec(enesimo-2) + tetranacci_rec(enesimo-3) + tetranacci_rec(enesimo-4);
    }

    
}
int main(){
    
    int termo;
   
    printf("Digite até que termo você gostaria de Ver a sequencia de Tetranacci: ");
    scanf("%d", &termo);
    printf("\n O valor do %d° termo da sequência Tetranacci é: %d", termo, tetranacci_rec(termo));
    

    return 0;
}