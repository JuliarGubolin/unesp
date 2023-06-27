#include<stdio.h>
#include<stdlib.h>
#define max 5
//Resposta questão 1
//TAD fila
typedef struct {
    int elementos[max];
    int inicio;
    int final;
    int key[max];
    int tam;
}fila_estatica;

//Operações
fila_estatica criar_fila(void);
fila_estatica inserir(fila_estatica q, int x, int p);
fila_estatica remover(fila_estatica q);
void imprimir(fila_estatica q);
void limpa_terminal(void);

//Principal
int main(void){

    int op, value, priority;
    fila_estatica f;
    f = criar_fila();
    do{
        printf("\n---MENU---\n1 - Inserir\n2 - Remover\n3 - Mostrar Fila\n4 - Sair\n-> ");
        scanf("%d", &op);
        switch(op){
          case 1:
              limpa_terminal();
              printf("---INSERIR---\n");
              printf("Valor: ");
              scanf("%d", &value);
              printf("Prioridade (Quanto menor, mais a frente na fila): ");
              scanf("%d", &priority);
              f = inserir(f, value, priority);
          break;
          case 2:
            limpa_terminal();
            printf("---RECUPERAR---\n");
            f = remover(f);
          break;
          case 3:
            limpa_terminal();
            printf("---IMPRIMIR---\n");
            imprimir(f);
          break;
          case 4:
            limpa_terminal();
            printf("Encerrado.\n");
          break;
          default: 
            limpa_terminal();
            printf("Escolha inválida.\n");
          break;
        }
    }while(op != 4);
    return 0;
}
//Implementação
void limpa_terminal(void){
    system("clear");
}
fila_estatica criar_fila(void){
    fila_estatica q_aux;

    q_aux.inicio = 0;
    q_aux.final = 0;
    q_aux.tam = 0;

    return q_aux;
}
fila_estatica inserir(fila_estatica q, int x, int p){
    int aux=0, i, j, k=0;
    //Verifica se a fila está cheia
    if(q.tam == max){
        printf("Fila cheia.\n");
    }
    //Verifica se é o primeiro elemento a ser inserido
    if(q.tam == 0){
        q.elementos[q.final] = x;
        q.key[q.final] = p;
        q.tam++;
    }
    //Verificação de overflow
    else if(q.final == max-1){
        q.final = 0;
    }
    //Caso exista espaço livre no vetor
    else{
        /*Percorre o vetor do final para o início, verifica se o valor de q.key[i] é maior que o valor de prioridade P
        e se ainda existe espaço no vetor para analisar. Caso exista e o valor do vetor que salva as prioridades seja maior que 
        p, o elemento sucessor recebe o anterior, até a posição ser liberada.
        */
        int i = q.tam-1;
        while(i>=0 && q.key[i] >= p){
            q.elementos[i+1] = q.elementos[i];
            i--;
        }
        //Quando a posição que ele deve ser inserido é encontrada, ele salva o valor e a prioridade.
        q.elementos[i+1] = x;
        q.key[i+1] = p;
        q.tam++;
        q.final++;
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
    printf("Removido.\n");
    return q;
}
void imprimir(fila_estatica q){
	int i, j;
	if(q.tam == 0){
		printf("Fila vazia!\n");
	}else{
		i = q.inicio;
		j = 0;
		
		printf("\nFila: ");
		while(j < q.tam){
			printf("|%d| -  ", q.elementos[i]);
			
			if(i+1 == max){
				i = 0;
			}else{
				i++;
			}
			
			j++;
		}
		printf("NULL\n");
	}
}
/*Resposta questão 2
2) Quais são as complexidades em notação Big O das duas funções?
Resposta: 
Função inserir: T(max) = O(max), considerando a fila de prioridade
Função remover: T(max) = O(0)
*/




