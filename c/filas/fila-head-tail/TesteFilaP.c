#include<stdio.h>
#define max 5

//TAD fila
typedef struct {
    int elementos[max];
    int inicio;
    int fim;
    int key[max];
    int tam;
}fila_estatica;

//Operações
fila_estatica criar_fila(void);
fila_estatica inserir(fila_estatica q, int x, int p);
fila_estatica remover(fila_estatica q);
void imprimir(fila_estatica q);

//Principal
int main(void){

    int op, value, priority;
    fila_estatica f;
    f = criar_fila();
    do{
        printf("Programa FILA\n1 - Inserir\n2 - Remover\n3 - Mostrar Fila\n4 - Sair\n-> ");
        scanf("%d", &op);
        switch(op){
          case 1:
              printf("Valor: ");
              scanf("%d", &value);
              printf("Prioridade (Quanto maior, mais a frente na fila): ");
              scanf("%d", &priority);
              f = inserir(f, value, priority);
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
fila_estatica criar_fila(void){
    fila_estatica q_aux;

    q_aux.inicio = 0;
    q_aux.fim = 0;
    q_aux.tam = 0;

    return q_aux;
}
fila_estatica inserir(fila_estatica q, int x, int p){
    //Verifica se a fila está cheia
    int aux, i;
    if(q.tam == max){
        printf("Fila cheia.\n");
    }
    else{
        if(q.tam == 0){
            q.elementos[q.fim] = x;
            q.key[q.fim] = p;
            q.tam++;
            printf("Tam: %d\n", q.tam);
            printf("Elem e p: %d e %d\n", q.elementos[q.fim], q.key[q.fim]);
        }
        else{
            //Verificação de overflow, volta para o começo
            if(q.fim == max-1){
                q.fim = 0;
            }
            else{
                q.fim++;
            }
            q.elementos[q.fim] = x;
            q.key[q.fim] = p;
            q.tam++;
            printf("Tam1: %d\n", q.tam);
            printf("p0 e p1: %d e %d\n", q.key[i], q.key[i+1]);
            for(i=0;i<q.tam;i++){
              for(int j=0;j<q.tam-1-i;j++){
			            if(q.key[j]<q.key[j+1]){
				          aux = q.elementos[j];
				          q.elementos[j] = q.elementos[j+1];
				          q.elementos[j+1] = aux;
                }
			    }
		    }
        }
    }
    return q;
}
fila_estatica remover(fila_estatica q){
    if(q.tam == 0){
        printf("Fila vazia.\n");
    }
    else{//Remoção
        if(q.tam == 1){
            //Inserimos no lugar deste valor e ele deixa de existir
            q.tam = 0;
        }
        else{
            if(q.inicio == max-1){
                q.inicio = 0;
            }
            else{
                q.inicio++;
            }
        }
        q.tam--;
    }
    return q;
}
void imprimir(fila_estatica q){
	int i, j;
	if(q.tam == 0){
		printf("\nFila vazia!\n");
	}else{
		i = q.inicio;
		j = 0;
		
		printf("\n");
		while(j < q.tam){
			printf("%d ", q.elementos[i]);
			
			if(i+1 == max){
				i = 0;
			}else{
				i++;
			}
			
			j++;
		}
		printf("\n");
	}
}



