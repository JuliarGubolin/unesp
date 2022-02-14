#include<stdio.h>
#define max 5

//TAD fila
typedef struct {
    int elementos[max];
    int inicio;
    int final;
    int tam;
}fila_estatica;

//Operações
fila_estatica criar_fila(void);
fila_estatica inserir(fila_estatica q, int x);
fila_estatica remover(fila_estatica q);
void imprimir(fila_estatica q);

//Principal
int main(void){

    //A recebe tudo que está em B
    /*fila_estatica a, b;
    a = b;*/

    return 0;
}
//Implementação
fila_estatica criar_fila(void){
    fila_estatica q_aux;

    q_aux.inicio = 0;
    q_aux.final = 0;
    q_aux.tam = 0;

    return q_aux;
}
fila_estatica inserir(fila_estatica q, int x){
    //Verifica se a fila está cheia
    if(q.tam == max){
        printf("Fila cheia.\n");
    }
    else{
        if(q.tam == 0){
            q.elementos[q.final] = x;
            q.tam++;
        }
        else{
            //Verificação de overflow, volta para p começo
            if(q.final == max-1){
                q.final = 0;
            }
            else{
                q.final++;
            }
            q.elementos[q.final] = x;
            q.tam++;
        }
        //q.tam++;
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



