#include<stdio.h>

#define MAX 5

//TAD fila ----------
typedef struct{
	int elementos[MAX];
	int inicio;
	int fim;
	int tam;
} fila;

//operacoes
fila cria_fila(void);
fila inserir(fila q, int x);
fila remover(fila q);
void imprimir(fila q);

//main -----------
int main(void){
	fila q;
	int x;
	int opcao = 0;
	
	q = cria_fila();
	
	while(opcao != 4){
		printf("\n1 - Inserir\n");
		printf("2 - Remover\n");
		printf("3 - Imprimir a lista\n");
		printf("4 - Sair\n");
		printf("Digite uma opcao: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1 :
	    		printf("Digite o elemento: ");
	    		scanf("%d", &x);
	    		
	    		q = inserir(q, x);
	    	break;
	    	
	    	case 2 :
	    		q = remover(q);
	    	break;
	    	
	    	case 3 :
	    		imprimir(q);
	    	break;
	    	
	    	case 4 :
	    		printf("\nSaindo...\n");
	    	break;
		}
	}
	
	return 0;
}

//implementacao ----------
fila cria_fila(void){
	fila q_aux;
	
	q_aux.inicio = 0;
	q_aux.fim = 0;
	q_aux.tam = 0;
	
	return q_aux;
}


fila inserir(fila q, int x){
	int i, aux;
	
	if( q.tam == MAX ){ //verifica o overflow
		printf("\nFila cheia!\n");
	}else{
		if(q.tam == 0){ //caso a lista estiver vazia
			q.elementos[q.fim] = x;
			q.tam++;
		}else{
			if (q.fim == MAX-1){ //se o fim estiver na ultima posicao do vetor
				q.fim = 0;
			}else{
				q.fim++;
			}
			
			q.elementos[q.fim] = x;
			q.tam++;
			
			//insere com prioridade
			i = q.fim;
			while( i != q.inicio ){
				if(i == 0){ //tratamento para se o fim estiver na posicao 0
					if(q.elementos[i] < q.elementos[MAX-1]){
						//troca
						aux = q.elementos[i];
						q.elementos[i] = q.elementos[MAX-1];
						q.elementos[MAX-1] = aux;
					}
					
					i = MAX-1;
				}else{
					if(q.elementos[i] < q.elementos[i-1]){
						//troca
						aux = q.elementos[i];
						q.elementos[i] = q.elementos[i-1];
						q.elementos[i-1] = aux;
					}
					
					i--;
				}
			}
		}
	}
	
	
	return q;
}
fila remover(fila q){
	if(q.tam == 0){
		printf("\nFila vazia!\n");
	}else{
		if(q.tam == 1){ //1 elemento na fila
			q.tam = 0;
		}else{ //remocao normal
			if(q.inicio == MAX-1){
				q.inicio = 0;
			}else{
				q.inicio++;
			}
			
			q.tam--;
		}
		printf("Elemento excluido!\n");
	}
	return q;
}
void imprimir(fila q){
	int i, j;
	if(q.tam == 0){
		printf("\nFila vazia!\n");
	}else{
		i = q.inicio;
		j = 0;
		
		printf("\n");
		while(j < q.tam){
			printf("| %d ", q.elementos[i]);
			
			if(i+1 == MAX){
				i = 0;
			}else{
				i++;
			}
			
			j++;
		}
		printf("|\n");
	}
}