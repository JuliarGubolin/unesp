#include<stdio.h>
#include<stdlib.h>
#include "ARN.h"

int main(void){
    int x, cont, opcao = 0;

    ARN *A;
	A = inicializa();
	while(opcao != 4){
		printf("-----------------\n");
		printf("1 - Inserir\n");
		printf("2 - Imprimir\n");
		printf("3 - Buscar\n");
		printf("4 - Sair\n");
		printf("-----------------\n");
		printf("Digite um opcao: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1 :
				printf("Digite o valor do novo elemento: ");
				scanf("%d", &x);
				ARN *novo;
        		novo = criarNo(x);
                A = inserir(A,novo);
				if (A != NULL)//Se a raiz for diferente de vazia, a cor dela sera PRETA
					A->cor = P;
	    	break;
	    	
	    	case 2 :
	    		system("cls");
				imprimir(A);
				printf("\n");
	    	break;
	    	
	    	case 3:
	    		printf("Digite o valor do elemento a ser buscado: ");
	    		scanf("%d", &x);
	    		buscar(A, x);
	    	break;
	    	
	    	case 4 :
	    		printf("\nSaindo...\n");
	    	break;
		}
	}

    return 0;
}