#include<stdio.h>
#include<stdlib.h>
#define MAX 5
//Resposta questão 1
//TAD fila
typedef struct {
    int elementos[MAX];
    int inicio;
    int fim;
    int tam;
}fila;

//Operações
fila criar_fila(void);
fila inserir(fila q, int x);
fila remover(fila q);
void imprimir(fila q);

//Principal
int main(void){

    int op, value, prioridade;
    fila f;
    f = criar_fila();
    do{
        printf("Programa FILA\n1 - Inserir\n2 - Remover\n3 - Mostrar Fila\n4 - Sair\n-> ");
        scanf("%d", &op);
        switch(op){
          case 1:
            printf("Valor: ");
            scanf("%d", &value);
            f = inserir(f, value);
          break;
          case 2:
            f = remover(f);
          break;
          case 3:
            imprimir(f);
          break;
          case 4:
            printf("Encerrado.\n");
          break;
          default: 
            printf("Escolha inválida.\n");
          break;
        }
    }while(op != 4);
    return 0;
}
//Implementação
fila criar_fila(void){
    fila q_aux;

    q_aux.inicio = 0;
    q_aux.fim = 0;
    q_aux.tam = 0;

    return q_aux;
}
//Código PROFESSOR
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
//Código feito ANTERIORMENTE
/*fila inserir(fila q, int x){
    //Verifica se a fila está cheia
    int j, troca, i, t=0, ini;
	if(q.fim+1==q.inicio||(q.fim+1)%MAX == q.inicio){ //verifica o overflow
		printf("Fila cheia!\n");
	}
    else{
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
    //Cria uma fila auxiliar, que irá receber todos os valores da fila original
    fila aux;
	aux = criar_fila();
	aux.inicio = 0;
	aux.fim = q.tam-1;
	aux.tam = q.tam;
	ini = q.inicio;
	t = 0;
    //Copia os valores da fila original para a auxiliar, respeitando
    //onde ela inicia (q.inicio) e onde ela termina (q.fim).
	while(t<q.tam){
		aux.elementos[t] = q.elementos[ini];
		if(ini+1 == MAX)
			ini = 0;
		else
			ini++;
		t++;
	}
    //Bubble Sort para ordenar os valores do vetor auxiliar de forma crescente
	for(i=1;i<aux.tam;i++){
        for(j=0;j<aux.tam-1;j++){
            if(aux.elementos[j]>aux.elementos[j+1]){
                troca = aux.elementos[j];
                aux.elementos[j] = aux.elementos[j+1];
                aux.elementos[j+1] = troca;
            }
        }
    }
    //Retorna a nova fila para a Main
	return aux;
}*/
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
/*Resposta questão 2
2) Quais são as complexidades em notação Big O das duas funções?
Resposta: 
Função inserir com prioridade: T(MAX) = O((q.tam)^2).
Função inserir com prioridade (professor): T(MAX) = O(1).
Função remover: T(MAX) = O(1).*/
void imprimir(fila q){
	int i, j;
	if(q.tam == 0){
		printf("\nFila vazia!\n");
	}else{
		i = q.inicio;
		j = 0;
		
		printf("\nFila: ");
		while(j < q.tam){
			printf("|%d| -  ", q.elementos[i]);
			
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