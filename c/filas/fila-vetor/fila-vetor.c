#include<stdio.h>

#define MAX 5

//TAD fila ----------
typedef struct{
	int elementos[MAX];
	int inicio;
	int fim;
	int tam;
	int alocado[MAX];
} fila;

//operacoes
fila cria_fila(void);
fila inserir(fila q, int x);
fila organizar(fila q);
fila remover(fila q);
void imprimir(fila q);

//main -----------
int main(void){
	fila q;
	int x;
	int opcao = 0;
	
	q = cria_fila();
	
	while(opcao != 4){
		printf("-----------------\n");
		printf("\n1 - Inserir\n");
		printf("2 - Imprimir a lista\n");
		printf("3 - Remover\n");
		printf("4 - Sair\n");
		printf("-----------------\n");
		printf("Digite uma opcao: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1 :
	    		printf("Digite o elemento: ");
	    		scanf("%d", &x);
	    		
	    		q = inserir(q, x);
	    	break;
	    	
	    	case 2 :
				system("cls");
				imprimir(q);
	    	break;
	    	
	    	case 3 :
	    		q = remover(q);
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
	system("cls");//limpar tela
	int k, j, aux, i, z, y;
	fila novo;
	if( q.fim+1  == q.inicio || (q.fim+1)%MAX == q.inicio ){ //verifica o overflow
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
		}
		
	}
	novo = cria_fila();
	novo.inicio=0;
	novo.fim=q.tam-1;
	novo.tam=q.tam;

		z = q.inicio;
		y = 0;
		
		while(y < q.tam){
			novo.elementos[y] = q.elementos[z];

			if(z+1 == MAX)
				z = 0;

			else
				z++;
			
			y++;
		}

			for (k = 1; k < novo.tam; k++) {
        		for (j = 0; j <  novo.tam - 1; j++) {
            		if (novo.elementos[j] > novo.elementos[j + 1]) {
                		aux = novo.elementos[j];
                		novo.elementos[j] = novo.elementos[j + 1];
                		novo.elementos[j + 1] = aux;
            		}
        		}
    		}
	return novo;
}

fila remover(fila q){
	system("cls");//limpar tela
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
	}
	printf("\nElemento removido!\n");
	return q;
}

void imprimir(fila q){
	system("cls");//limpar tela
	int i, j;
	
	if(q.tam == 0){
		printf("\nFila vazia!\n");
	}else{
		i = q.inicio;
		j = 0;
		
		printf("\n");
		while(j < q.tam){
			printf("%d ", q.elementos[i]);
			
			if(i+1 == MAX){
				i = 0;
			}else{
				i++;
			}
			
			j++;
		}
		printf("\n");
	}
}
