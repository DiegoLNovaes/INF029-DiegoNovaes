
// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Diego Leite Novaes
//  email: pxnovaes@gmail.com
//  Matrícula: 20212160012
//  Semestre: 2°

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include "DiegoNovaes-20212160012-T1.h" // Substitua pelo seu arquivo de header renomeado
#include <stdlib.h>
#include <string.h>
#include <math.h>



/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)
    pode utilizar strlen para pegar o tamanho da string
 */

DataQuebrada quebradata(char data[]);
int validadigito (char digito);
DiasMesesAnos q2(char datainicial[], char datafinal[]);

DataQuebrada q1(char data[]){

    DataQuebrada dataint;
    int verificador=0;

    //printf ("+%s+\t",data);
    dataint = quebradata(data);

    dataint.valido=0;

    if(dataint.iAno>-1)
        verificador++;
    switch(dataint.iMes){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
        {
                if(dataint.iDia<=31 && dataint.iDia>0)
                    verificador++;
                break;
        }
        case 4:
        case 6:
        case 9:
        case 11:
        {
            if(dataint.iDia<=30 && dataint.iDia>0)
                verificador++;
            break;
        }
        case 2:
            if(dataint.iAno%4==0){
                if(dataint.iDia<=29 && dataint.iDia>0){
                    verificador++;
                    if(dataint.iAno%100==0 && dataint.iAno%400!=0)
                        if(dataint.iDia>28)
                            verificador--;
                }
            }
            else{
                if(dataint.iDia<=28)
                    verificador++;
            }
            break;
        default:
            dataint.valido=0;
            break;
    }

    if(verificador == 2)
        dataint.valido=1;


    return dataint;

}

DataQuebrada quebradata(char data[]){

    DataQuebrada dq;
    char dia[3];
    char mes[3];
    char ano[5];
    int i, j , contbarra=0;
    int verificador = 0;

    
    if(validadigito(data[0]) != 1){
        dq.valido = 0;
        return dq;
    }

    for(i=0; data[i]!='\0'; i++){
        if(data[i] == '/')
            contbarra++;
    }
    if(contbarra != 2){
       dq.valido = 0;
        return dq;
    }
    

    for(i=0; data[i]!='/'; i++)
        {
        dia[i] = data[i];
        }
    if(i == 1 || i==2){
        dia[i]= '\0';
        if(i==1 && validadigito(dia[0])==1)
            verificador++;
        else
            dq.valido=0;
        if(i==2 && (validadigito(dia[0])== validadigito(dia[1])==1))
            verificador++;
        else
            dq.valido=0;
        i++;
    }
    else
        dq.valido = 0;


    for(j=0; data[i]!= '/'; i++,j++){
        mes[j]=data[i];
    }
    if (j==1 || j==2){
        mes[j] = '\0';
        if(j==1 && validadigito(mes[0])==1)
            verificador++;
        else
            dq.valido=0;
        if(j==2 &&  validadigito(mes[0])==validadigito(mes[1])==1)
            verificador++;
        else
            dq.valido=0;
        i++;
    }
    else
        dq.valido = 0;

    for(j=0; data[i] != '\0';i++, j++){
        ano[j]= data[i];
    }
    if(j==2 || j==4)
    {
        ano[j] = '\0';
        if(j==2 && validadigito(ano[0])==validadigito(ano[1])==1)
        {
            ano[2] = ano[0];
            ano[3] = ano[1];
            ano[0] = '2';
            ano[1] = '0';
            ano[4] = '\0';
            verificador++;
        }
        else
            dq.valido=0;
        if(j==4 && validadigito(ano[0])==validadigito(ano[1])==validadigito(ano[2])==validadigito(ano[3])==1)
            verificador++;
        else
            dq.valido=0;
    }
    else
        dq.valido = 0;

    if(verificador==3)
    {
        dq.iDia = atoi(dia);
        dq.iMes = atoi(mes);
        dq.iAno = atoi(ano);
        dq.valido = 1;
    }
    else{
        dq.iDia = -1;
        dq.iMes = -1;
        dq.iAno = -1;
    }

    return dq;
}

int validadigito (char digito){

    switch(digito)
    {
        case '0':
            return 1;
            break;
        case '1':
           return 1;
            break;
        case '2':
           return 1;
            break;
        case '3':
            return 1;
            break;
        case '4':
            return 1;
            break;
        case '5':
            return 1;
            break;
        case '6':
            return 1;
            break;
        case '7':
           return 1;
            break;
        case '8':
            return 1;
            break;
        case '9':
            return 1;
            break;
        default:
            return 0;
    }
}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal.
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
*/

DiasMesesAnos q2(char datainicial[], char datafinal[])
{

    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;
    DataQuebrada dataIntInicial, dataIntFinal;
    int difano, difmes, difdia;
    int num_d_m;

    dataIntInicial = q1(datainicial);
    dataIntFinal = q1(datafinal);

    if (dataIntInicial.valido == 0){
      dma.retorno = 2;
      return dma;
    }else if (dataIntFinal.valido == 0){
      dma.retorno = 3;
      return dma;
    }

    difano = dataIntFinal.iAno - dataIntInicial.iAno;
    difmes = dataIntFinal.iMes - dataIntInicial.iMes;
    difdia = dataIntFinal.iDia - dataIntInicial.iDia;

    if( (difano > 0) || ((difano == 0) && (difmes > 0)) || ((difano == 0) && (difmes == 0) && (difdia>=0))){
        dma.retorno = 1;
        if(difmes>=0){
            if(difdia>=0){
                dma.qtdAnos = difano;
                dma.qtdMeses = difmes;
                dma.qtdDias = difdia;
               // printf("\n %d ano(s), %d mes(es) e %d dia(s)\n", dma.qtdAnos,dma.qtdMeses,dma.qtdDias);
            }
            else{
                dma.qtdAnos = difano;
                dma.qtdMeses = difmes-1;
                num_d_m = (n_dia_mes(dataIntInicial.iMes, dataIntFinal.iAno));
                dma.qtdDias = (num_d_m - dataIntInicial.iDia) + dataIntFinal.iDia;
                if (num_d_m == dataIntInicial.iDia){
                    dma.qtdDias = 0;
                    dma.qtdMeses++;
                }
               // printf("\n %d ano(s), %d mes(es) e %d dia(s)\n", dma.qtdAnos,dma.qtdMeses,dma.qtdDias);
            }
        }
        if(difmes<0){
            if(difdia>=0){
                dma.qtdAnos = difano-1;
                dma.qtdMeses = 12+difmes;
                dma.qtdDias = difdia;
               // printf("\n %d ano(s), %d mes(es) e %d dia(s)\n", dma.qtdAnos,dma.qtdMeses,dma.qtdDias);
            }
            else{
                dma.qtdAnos = difano-1;
                dma.qtdMeses = 11+difmes;
                num_d_m = (n_dia_mes(dataIntInicial.iMes, dataIntFinal.iAno));
                dma.qtdDias = (num_d_m - dataIntInicial.iDia) + dataIntFinal.iDia;
                if (num_d_m == dataIntInicial.iDia){
                    dma.qtdDias = 0;
                    dma.qtdMeses++;
                }
                //printf("\n %d ano(s), %d mes(es) e %d dia(s)\n", dma.qtdAnos,dma.qtdMeses,dma.qtdDias);
            }
        }
    }
    else{
        dma.retorno = 4;
        return dma;
    }

    return dma;
}

int n_dia_mes( int mes, int ano){



    int num_dia_do_mes;

    switch(mes){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
        {
            num_dia_do_mes = 31;
            return num_dia_do_mes;
            break;
        }
        case 4:
        case 6:
        case 9:
        case 11:
        {
            num_dia_do_mes = 30;
            return num_dia_do_mes;
            break;
        }
        case 2:
            if(ano%4==0){
                if(ano%100==0 && ano%400!=0){
                    num_dia_do_mes = 28;
                    return num_dia_do_mes;
                }
                else{
                    num_dia_do_mes = 29;
                    return num_dia_do_mes;
                }
            }
            else{
                num_dia_do_mes = 28;
                return num_dia_do_mes;
            }
            break;

        default:
            break;
    }


}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
   int q3(char *texto, char c, int isCaseSensitive)
{
    int qtdOcorrencias = 0;
    int i ;
    int l_ascii;
    char c_C;

    if(c >=65 && c<=90)
        l_ascii = (c+32);
    else if(c>=97 && c<=122)
                l_ascii = (c-32);
    c_C = l_ascii;

    if(isCaseSensitive==1){
        for(i=0 ; i<=250 ; i++){
            if (texto[i] != '\0'){
                //printf("%c", texto[i]);
                if (texto[i] == c)
                    qtdOcorrencias++;
            }
            else
                i=250;
        }
    }
    else{
        for(i=0 ; i<=250 ; i++){
            if (texto[i] != '\0'){
                //printf("%c", texto[i]);
                if (texto[i] == c || texto[i] == c_C)
                    qtdOcorrencias++;
            }
            else
                i=250;
        }
    }
    return qtdOcorrencias;
}


/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;
 */
int q4(char *strTexto, char *strBusca, int *posicoes)
{
    int qtdOcorrencias = 0;
    int i, aux_i, j, cont=0, c=0;
    int tam_strBusca;

    tam_strBusca = strlen(strBusca);
    //printf("%d\n", tam_strBusca);

    for(i=0; i<=250; i++){
        if(strTexto[i] != '\0'){
            if(strTexto[i] == strBusca[0]){
                aux_i = i;
                cont = 0;
                for(j=0; j<tam_strBusca;j++){
                    if(strTexto[aux_i] == strBusca[j]){
                        cont++;
                        if(cont == tam_strBusca){
                            qtdOcorrencias++;
                            posicoes[c] = (i+1);
                            c++;
                            posicoes[c] = (i+tam_strBusca);
                            c++;
                            i = i + cont-1;
                        }
                        aux_i++;
                    }
                }
            }
        }
        else
            i=250;
    }

    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int numero){

    int numero_invertido;
    int resto, resultado, divisor = 10;
    int i , cont_casas_decimais = 0;
    int num_aux;
    int expoente;

    num_aux = numero;

    do {
        resultado = num_aux/divisor;
        num_aux = resultado;
        cont_casas_decimais++;
    }while (resultado>=10);

    if(resultado==0 && cont_casas_decimais==1)
        expoente = 0;
    else
        expoente = cont_casas_decimais;

    numero_invertido = 0;
    for(i=0; i<cont_casas_decimais; i++){
        resultado = numero/divisor;
        resto = numero%divisor;
        numero_invertido += resto*(pow(10,expoente));
        expoente--;
        numero = resultado;
    }

    numero_invertido += resultado;

    return numero_invertido;

}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias=0;
    int num_aux, num_aux_busca;
    int resultado, resto;
    int cont_casas_decimais=1 , cont_casas_decimais_busca=1;
    int numerobasevet[12];
    int numerobuscavet[12];
    int i=0 , j , aux_i, cont;

    for(i=0; i<12; i++){
        numerobasevet[i]=-1;
        numerobuscavet[i]= -1;
    }

    num_aux_busca = numerobusca;
    i=0;
    do {
        resultado = num_aux_busca/10;
        resto = num_aux_busca%10;
        numerobuscavet[i] = resto;
        i++;
        num_aux_busca = resultado;
        cont_casas_decimais_busca++;
        if(numerobusca<10)
            cont_casas_decimais_busca = 1;
    }while (resultado>=10);
    numerobuscavet[i] = resultado;
/*
    for(i=0 ; i<cont_casas_decimais_busca; i++){
        printf("%d\t", numerobuscavet[i]);
    }
    printf("\n");
*/
    num_aux = numerobase;
    i=0;
    do {
        resultado = num_aux/10;
        resto = num_aux%10;
        numerobasevet[i] = resto;
        i++;
        num_aux = resultado;
        cont_casas_decimais++;
    }while (resultado>=10);
    numerobasevet[i] = resultado;
/*
    for(i=0 ; i<cont_casas_decimais; i++){
        printf("%d\t", numerobasevet[i]);
    }

    printf("\n");
*/
    for(i=0 ;  i<=cont_casas_decimais; i++){
        if(numerobuscavet[0] == numerobasevet[i]){
            aux_i = i;
            cont = 0;
            for(j=0; j<cont_casas_decimais_busca; j++){
                    if(numerobuscavet[j] == numerobasevet[aux_i]){
                        cont++;
                        if(cont == cont_casas_decimais_busca){
                            qtdOcorrencias++;
                            i = i + cont-1;
                        }
                    aux_i++;
                    }
            }
        }
    }

    return qtdOcorrencias;
}
