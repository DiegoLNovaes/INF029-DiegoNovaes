// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo contém exemplos de testes das questões do trabalho.
//  o aluno pode incrementar os testes

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 19/08/2016 - 12/12/2018

// #################################################

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


//renomeie o arquivo do include abaixo para PrimeiroUltimoNomeMATRICULA.h
#include "DiegoNovaes-20212160012-T1.h"


void testQ1();
void testQ2();
void testQ3();
void testQ4();
void testQ5();
void testQ6();

int main()
{

  testQ1();
  //testQ2();
  //testQ3();
  //testQ4();
  //testQ5();
  //testQ6();

    return 0;
}

void testQ1()
{

    DataQuebrada data_Int;
    char str[11];

    strcpy(str, "//2016");
    data_Int = q1(str);
    printf("%d\n", data_Int.valido == 0);
    strcpy(str, "29/2/15");
    data_Int = q1(str);
    printf("%d\n", data_Int.valido == 0);
    strcpy(str, "2/2016");
    data_Int = q1(str);
    printf("%d\n", data_Int.valido == 0);
    strcpy(str, "x2/2/2015");
    data_Int = q1(str);
    printf("%d\n", data_Int.valido == 0);
    strcpy(str, "1//20");
    data_Int = q1(str);
    printf("%d\n", data_Int.valido == 0);
    strcpy(str, "29/02/2012");
    data_Int = q1(str);
    printf("%d\n", data_Int.valido == 1);
    strcpy(str, "9/13/2014");
    data_Int = q1(str);
    printf("%d\n", data_Int.valido == 0);
    strcpy(str, "45/4/2014");
    data_Int = q1(str);
    printf("%d\n", data_Int.valido == 0);
    strcpy(str, "/9/2014");
    data_Int = q1(str);
    printf("%d\n", data_Int.valido == 0);
    strcpy(str, "29/02/1900");
    data_Int = q1(str);
    printf("%d\n", data_Int.valido == 0);
    strcpy(str, "29/02/24");
    data_Int = q1(str);
    printf("%d\n", data_Int.valido == 1);
    strcpy(str, "28/02/17");
    data_Int = q1(str);
    printf("%d\n", data_Int.valido == 1);
    strcpy(str, "1/R/2016");
    data_Int = q1(str);
    printf("%d\n", data_Int.valido == 0);

}

void testQ2()
{
    char datainicial[11], datafinal[11];
    int qtdDias, qtdMeses, qtdAnos;
    DiasMesesAnos dma;

    //teste 1
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial, "01/06/2015");
    strcpy(datafinal, "01/06/2016");
    dma = q2(datainicial, datafinal);
    printf("%d\n", dma.retorno == 1);
    printf("%d\n", dma.qtdDias == 0);
    printf("%d\n", dma.qtdMeses == 0);
    printf("%d\n", dma.qtdAnos == 1);
    printf("\n");

    //teste 2 - retornos
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial, "01/30/2015");
    strcpy(datafinal, "01/06/2016");
    dma = q2(datainicial, datafinal);
    printf("%d\n", dma.retorno == 2);

    strcpy(datainicial, "01/3/2015");
    strcpy(datafinal, "40/06/2016");
    dma = q2(datainicial, datafinal);
    printf("%d\n", dma.retorno == 3);

    strcpy(datainicial, "01/06/2016");
    strcpy(datafinal, "01/06/2015");
    dma = q2(datainicial, datafinal);
    printf("%d\n", dma.retorno == 4);
    printf("\n");
  
    //teste 3
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial, "06/06/2017");
    strcpy(datafinal, "07/07/2017");
    dma = q2(datainicial, datafinal);
    printf("%d\n", dma.retorno == 1);
    printf("%d\n", dma.qtdDias == 1);
    printf("%d\n", dma.qtdMeses == 1);
    printf("%d\n", dma.qtdAnos == 0);
    printf("\n");
  
  //teste 4
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial,"06/06/2017");
    strcpy(datafinal,"05/07/2018");
    dma = q2(datainicial, datafinal);
    printf("%d\n",dma.retorno == 1);
    printf("%d\n",dma.qtdDias == 29);
    printf("%d\n",dma.qtdMeses == 0);
    printf("%d\n",dma.qtdAnos == 1);
    printf("\n");
  
  //teste 5
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial,"26/07/2017");
    strcpy(datafinal,"25/08/2017");
    dma = q2(datainicial, datafinal);
    printf("%d\n",dma.retorno == 1);
    printf("%d\n",dma.qtdDias == 30);
    printf("%d\n",dma.qtdMeses == 0);
    printf("%d\n",dma.qtdAnos == 0);
    printf("\n");
  
    //teste 6
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial,"26/06/2017");
    strcpy(datafinal,"26/07/2017");
    dma = q2(datainicial, datafinal);
    printf("%d\n",dma.retorno == 1);
    printf("%d\n",dma.qtdDias == 0);
    printf("%d\n",dma.qtdMeses == 1);
    printf("%d\n",dma.qtdAnos == 0);
    printf("\n");
 
    //teste 8
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial,"27/02/2016");
    strcpy(datafinal,"03/03/2017");
    dma = q2(datainicial, datafinal);
    printf("%d\n",dma.retorno == 1);
    printf("%d\n",dma.qtdDias == 4);
    printf("%d\n",dma.qtdMeses == 0);
    printf("%d\n",dma.qtdAnos == 1);
    printf("\n");

    //teste 9
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial,"27/02/2015");
    strcpy(datafinal,"03/03/2016");
    dma = q2(datainicial, datafinal);
    printf("%d\n",dma.retorno == 1);
    printf("%d\n",dma.qtdDias == 5);
    printf("%d\n",dma.qtdMeses == 0);
    printf("%d\n",dma.qtdAnos == 1);
    printf("\n");

    //teste 10
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial,"28/01/2016");
    strcpy(datafinal,"29/02/2016");
    dma = q2(datainicial, datafinal);
    printf("%d\n",dma.retorno == 1);
    printf("%d\n",dma.qtdDias == 1);
    printf("%d\n",dma.qtdMeses == 1);
    printf("%d\n",dma.qtdAnos == 0);
    printf("\n");
}

void testQ3()
{
    char str[250];
  
    strcpy(str, "Renato Lima Novais");
    printf("%d\n", q3(str, 'a', 0) == 3);
    printf("%d\n", q3(str, 'b', 0) == 0);
    printf("%d\n", q3(str, 'l', 1) == 0);
    printf("%d\n", q3(str, 'l', 0) == 1);
    printf("%d\n", q3(str, 'L', 0) == 1);

    printf("\n");
  
    strcpy(str,"Letícia, signifiCa fEliCIdADE");
    printf("%d\n",q3(str, 'c', 0) == 3);
    printf("%d\n",q3(str, 'C', 0) == 3);
    printf("%d\n",q3(str, 'c', 1) == 1);
    printf("%d\n",q3(str, 'C', 1) == 2);
    printf("%d\n",q3(str, 'R', 0) == 0);
    printf("%d\n",q3(str, 'e', 0) == 3);
    printf("%d\n",q3(str, 'E', 1) == 2);
    printf("%d\n",q3(str, 'S', 1) == 0);
}

void testQ4()
{
    char strTexto[250];
    char strBusca[50];
    int posicoes[30];
    int i;

    for (i = 0; i < 30; i++)
    {
        posicoes[i] = -1;
    }
    strcpy(strTexto, "Laboratorio de programacao: para ratos de programação");
    strcpy(strBusca, "rato");
    printf("%d\n", q4(strTexto, strBusca, posicoes) == 2);
    printf("%d\n", posicoes[0] == 5);
    printf("%d\n", posicoes[1] == 8);
    printf("%d\n", posicoes[2] == 34);
    printf("%d\n", posicoes[3] == 37);

    for (i = 0; i < 30; i++)
    {
        posicoes[i] = -1;
    }
    strcpy(strTexto, "Ola, o mundo e muito grande. Tem muitas pessoas, e muitos problemas");
    strcpy(strBusca, "mui");
    printf("%d\n", q4(strTexto, strBusca, posicoes) == 3);
    printf("%d\n", posicoes[0] == 16);
    printf("%d\n", posicoes[1] == 18);
    printf("%d\n", posicoes[2] == 34);
    printf("%d\n", posicoes[3] == 36);
    printf("%d\n", posicoes[4] == 52);
    printf("%d\n", posicoes[5] == 54);

  for (i = 0; i<30; i++){
        posicoes[i] = -1;
    }
    strcpy(strTexto,"Programar e legal?");
    strcpy(strBusca,"sim");
    printf("%d\n",q4(strTexto, strBusca, posicoes) == 0);

    for (i = 0; i<30; i++){
        posicoes[i] = -1;
    }
    strcpy(strTexto,"maraaaavilha, meu prograaaama funcionou");
    strcpy(strBusca,"aa");
    printf("%d\n",q4(strTexto, strBusca, posicoes) == 4);
    printf("%d\n",posicoes[0]==4);
    printf("%d\n",posicoes[1]==5);
    printf("%d\n",posicoes[2]==6);
    printf("%d\n",posicoes[3]==7);
    printf("%d\n",posicoes[4]==24);
    printf("%d\n",posicoes[5]==25);
    printf("%d\n",posicoes[6]==26);
    printf("%d\n",posicoes[7]==27);
}

void testQ5()
{
    printf("%d\n",q5(345) == 543);
    printf("%d\n",q5(78) == 87);
    printf("%d\n",q5(3) == 3);
    printf("%d\n",q5(5430) == 345);
    printf("%d\n",q5(1000) == 1);
    printf("%d\n",q5(0) == 0);
    printf("%d\n",q5(707) == 707);
    printf("%d\n",q5(80) == 8);
    printf("%d\n",q5(8) == 8);
    printf("%d\n",q5(1234) == 4321);
    printf("%d\n", q5(3005689) == 9865003);
    printf("%d\n", q5(10) == 1);
    printf("%d\n", q5(100) == 1);
    printf("%d\n", q5(2340010) == 100432);
    printf("%d\n", q5(200) == 2);
}

void testQ6()
{
    printf("%d\n",q6(34567368, 3) == 2);
    printf("%d\n",q6(34567368, 4576) == 0);
    printf("%d\n",q6(3539343, 3) == 4);
    printf("%d\n",q6(3539343, 39) == 1);
    printf("%d\n",q6(5444, 44) == 1);
    printf("%d\n",q6(54444, 44) == 2);
    printf("%d\n",q6(1234562354, 23) == 2);
    printf("%d\n",q6(1234, 13) == 0);
    printf("%d\n",q6(544444, 4) == 5);
    printf("%d\n",q6(1234562354, 32) == 0);

}

