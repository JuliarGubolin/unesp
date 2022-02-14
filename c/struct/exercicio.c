/*Faça um programa que, utilizando registros, leia o nome e a data de nascimento (dia, mês e ano) de 10
pessoas. O programa deve calcular e mostrar a idade de cada pessoa, bem como o nome da pessoa mais
velha*/
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#define max 5
#define m 8
#define ano_atual 2019
//Considerando mês 08/2019
int main (){
	setlocale(LC_ALL, "portuguese");
	
	typedef struct dados{
		char nome[45];
		int dia, mes, ano, ano_id;
	}Tdados;
	
	Tdados dad[max];
	int menor_dia=0, menor_mes=0, menor_ano=0, indice, i;
	
	for(i=0;i<max;i++){
		
		printf("Dados\n");
		setbuf(stdin, NULL);
		printf("Digite seu nome:\n");
		scanf("%[^\n]s", &dad[i].nome);
		setbuf(stdin, NULL);
		printf("DATA DE NASCIMENTO\n");
		printf("Dia:\n");
		scanf("%d", &dad[i].dia);
		printf("Mês:\n");
		scanf("%d", &dad[i].mes);
		printf("Ano:\n");
		scanf("%d", &dad[i].ano);
		
		//pessoa mais velha
		if(i==0){
			menor_ano = dad[i].ano;
			menor_mes = dad[i].mes;
			menor_dia = dad[i].dia;
		}
		if(dad[i].ano<menor_ano){
			menor_ano = dad[i].ano;
				if(dad[i].mes<menor_mes){
					menor_mes = dad[i].mes;
						if(dad[i].dia<menor_dia){
							menor_dia = dad[i].dia;
						}
				}
				indice=i;
		}
		//Calcular idade
		dad[i].ano_id = ano_atual - dad[i].ano;
		if(dad[i].mes>m)
		dad[i].ano_id = dad[i].ano_id - 1;
		
	}
	//Mostrar idades
	printf("NOMES E IDADES:\n");
	for(i=0;i<max;i++){
		printf("Nome: %s, tem %d anos em 2019\n", dad[i].nome, dad[i].ano_id);
	}
	printf("A pessoa mais velha é: %s\n", dad[indice].nome);
	return 0;	
}
