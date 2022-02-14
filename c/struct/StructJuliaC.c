#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <sys/time.h>
#define pi 3.14159265359

typedef struct pessoa{
    int idade, filhos;
    float altura;
    bool homem;
    char nome[20];
}p;

//Operações
float media(int a, int b);

int main(void){

    double tempo2, tempo3;
    struct timeval inicio, fim;
	gettimeofday(&inicio, NULL);
    int i=0, j=1;
    float x;
    p pessoas[2];
    strcpy(pessoas[i].nome,"Julia");
    pessoas[i].idade = 19;
    pessoas[i].filhos = 0;
    pessoas[i].homem = false;
    pessoas[i].altura = 1.57;
    i++;

    strcpy(pessoas[i].nome,"Gustavo");
    pessoas[i].idade = sqrt(400);
    pessoas[i].filhos = 0;
    pessoas[i].homem = true;
    pessoas[i].altura = 1.84;

    x = media(pessoas[0].idade, pessoas[1].idade);
    printf("A media das idades e: %.2f\n", x);
    printf("Pessoas usadas para comparação no teste: %s e %s.\n",pessoas[j-1].nome, pessoas[j].nome);
    printf("Soma de pi+1: %f\n", pi+1);
    printf("Aplicação de pi com seno de π/4: %f\n", sin(pi/4));
    if(sin(pi/4) == pi){
        printf("Comparação de sin(pi/4) == pi: True.\n");
    }else{
        printf("Comparação de sin(pi/4) == pi: False.\n");
    }
    gettimeofday(&fim, NULL);
    tempo2 = (fim.tv_sec - inicio.tv_sec) + ((fim.tv_usec - inicio.tv_usec)/1000000.0);
    printf("Tempo: %f\n", tempo2);
    return 0;
}
float media(int a, int b){
    float total;
    total = (float)(a+b)/2;
    return total;
}