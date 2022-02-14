#include<stdio.h>
#include<stdlib.h>

//TAD Árvore Binária
typedef struct node{
    int info;
    struct node *esq, *dir;
}ABB;

//Operações
ABB *criar(void);
//ABB *inserir(ABB *r, ABB *novo);
void buscar(ABB *r, int x);
int contagem(ABB *r);
void imprimir(ABB *r);
//Funções para remover
ABB *remover(ABB *r, int x);
ABB *buscarNO(ABB *r, ABB **pai, int x);
//Funções de máximo e mínimo
void min(ABB *r);
void max(ABB *r);
//Inserir iterativo
ABB *inserir_iterativo(ABB *r, ABB *novo);

//Função principal
int main(void){
    int x, cont, opcao=0;
	ABB *R, *novo;
	
	R = criar();
	
	while(opcao != 8){
		printf("-----------------\n");
		printf("1 - Inserir\n");
		printf("2 - Remover\n");
		printf("3 - Imprimir\n");
		printf("4 - Buscar\n");
		printf("5 - Contar nós\n");
        printf("6 - Elemento mínimo\n");
        printf("7 - Elemento máximo\n");
		printf("8 - Sair\n");
		printf("-----------------\n");
		printf("-> ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1 :
                system("clear");
				printf("Digite o valor do novo elemento: ");
				scanf("%d", &x);
				//Criando o nó novo e enviando para inserir
				novo = (ABB*) malloc(sizeof(ABB));
				novo->info = x;
				novo->esq = NULL;
				novo->dir = NULL;
				//Chamando e recebendo o retorno da função inserir
				R = inserir_iterativo(R, novo);
	    	break;
	    	case 2:
                system("clear");
                if(R == NULL){
                    printf("Árvore vazia.\n");
                }else{
	    		    printf("Digite o valor a ser removido: ");
				    scanf("%d", &x);
                    R = remover(R, x);
                }
	    	break;
	    	case 3:
                system("clear");
                if(R == NULL){
                    printf("Árvore vazia.\n");
                }else{
				    imprimir(R);
				    printf("\n");
                }
	    	break;
	    	case 4:
                system("clear");
                if(R == NULL){
                    printf("Árvore vazia.\n");
                }else{
	    		    printf("Digite o valor do elemento a ser buscado: ");
	    		    scanf("%d", &x);
	    		    buscar(R, x);
                }
	    		
	    	break;
	    	case 5:
				cont = contagem(R);
				system("clear");
				printf("A árvore contem %d nos\n", cont);
	    	break;
	    	case 6:
                system("clear");
                min(R);
	    	break;
            case 7:
                system("clear");
                max(R);
	    	break;
            case 8:
                system("clear");
	    		printf("Saindo...\n");
	    	break;
            default:
                system("clear");
	    		printf("Opção inválida. Leia novamente o menu.\n");
	    	break;
		}
	}
    return 0;
}
//Implementações
//Criação da árvore
ABB *criar(void){
    return NULL;
}
//Inserir recursivo
/*ABB *inserir(ABB *r, ABB *novo){
    if(r == NULL){
        system("clear");
        printf("Elemento inserido!\n");
        return novo;
    }else{
        if(novo->info > r->info){
            r->dir = inserir(r->dir, novo);
        }

        if(novo->info < r->info){
            r->esq = inserir(r->esq, novo);
        }

        if(novo->info == r->info){
            system("clear");
            printf("Elemento duplicado!\n");

            return r;
        }
    }

    system("clear");
    printf("Elemento inserido!\n");

    return r;
}*/
//Busca comum
void buscar(ABB *r, int x){
    if(r == NULL){
        system("clear");
        printf("Elemento não encontrado!\n");
    }else{
        if(x == r->info){
            system("clear");
            printf("Elemento %d encontrado!\n", r->info);
        }else{
            if(x > r->info){
                buscar(r->dir, x);
            }else{
                buscar(r->esq, x);
            }
        }
    }
}
//Contagem de nós
int contagem(ABB *r){ //pre-ordem (C-E-D)
    if(r == NULL){
        return 0;
    }else{
        return 1 + contagem(r->esq) + contagem(r->dir);
    }
}
//Imprime a árvore
void imprimir(ABB *r){ //pre-ordem (C-E-D)
    if(r != NULL){
        printf("%d", r->info);
        printf("(");
        imprimir(r->esq);
        imprimir(r->dir);
        printf(")");
    }
}
//Função buscar nó para o remover
ABB *buscarNo(ABB *r, ABB **pai, int x){
    ABB *atual;

    atual = r;
    (*pai) = NULL;

    while(atual != NULL){
        if(atual->info == x){
            return atual;
        }else{
            (*pai) = atual;

            if(x < atual->info){
                atual = atual->esq;
            }else{
                atual = atual->dir;
            }
        }
    }

    return NULL;
}
//Função remover
ABB *remover(ABB *r, int x){
    ABB *no, *pai, *prom, *pai2;

    no = buscarNo(r, &pai, x); //buscar o no a ser removido e seu pai

    if(no == NULL){ //caso o no nao for encontrado
        return r;
    }else{
        if(!no->dir || !no->esq){//se algum dos filhos for nulo (se tem soh um filho)
            if(!no->esq){
                prom = no->dir;
            }else{
                prom = no->esq;
            }
        }else{//se tem dois filhos
            //buscar o no mais a direita da subarvore da esquerda
            pai2 = no;
            prom = no->esq;

            while(prom->dir){
                pai2 = prom;
                prom = prom->dir;
            }

            if(pai2 != no){//se o pai2 nao for o no a ser removido
                pai2->dir = prom->esq;
                prom->esq = no->esq;
            }

            prom->dir = no->dir;
        }

        if(!pai){//se o no for a raiz
            free(no);
            return(prom);
        }

        if(x < pai->info){
            pai->esq = prom;
        }else{
            pai->dir = prom;
        }

        free(no);

        return r;
    }
}
//Respostas questão 2:
//Nó mínimo
void min(ABB *r){
    ABB *aux;
    //Verifica se a árvore está vazia
    if(r == NULL){
        printf("Árvore vazia.\n");
    }
    //Caso não esteja, verifica se só existe a raiz. Em caso afirmativo, ela é
    //O menor elemento.
    else if(r->esq == NULL){
        printf("O menor valor da árvore é: %d.\n", r->info);
    }
    //Caso haja mais de um elemento, o ponteiro aux anda para esquerda até
    //que não seja mais possível e mostra o menor elemento.
    else{
        aux = r->esq;
        while(aux->esq != NULL){
            aux = aux->esq;
        }
        printf("O menor valor da árvore é: %d.\n", aux->info);
    }
}
//Nó máximo
void max(ABB *r){
    ABB *aux;
    //Verifica se a árvore está vazia
    if(r == NULL){
        printf("Árvore vazia.\n");
    }
    //Caso não esteja, verifica se só existe a raiz. Em caso afirmativo, ela é
    //O maior elemento.
    else if(r->dir == NULL){
        printf("O maior valor da árvore é: %d.\n", r->info);
    }
    //Caso haja mais de um elemento, o ponteiro aux anda para direira até
    //que não seja mais possível e mostra o menor elemento.
    else{
        aux = r->dir;
        while(aux->dir != NULL){
            aux = aux->dir;
        }
        printf("O maior valor da árvore é: %d.\n", aux->info);
    }
}
//Resposta questão 3:
//Inserir iterativo
ABB *inserir_iterativo(ABB *r, ABB *novo){ 
    ABB *aux, *aux2;
    aux = r;
    aux2 = NULL;
    //Enquanto existirem nós, o aux percorre verificando se o valor 
    //para o qual ele aponta é menor ou maior que o valor armazenado na info do novo nó
    //e faz o tratamento para cada caso (maior direita e menor esquerda).
    while(aux != NULL){ 
        aux2 = aux;
        if(novo->info < aux->info){
            aux = aux->esq; 
        } 
        else{
            aux = aux->dir; 
        }
    }
    //Se o aux2 for nulo, a árvore estava vazia então o novo nó
    //É a raíz 
    if(aux2 == NULL){
        aux2 = novo;
        r = novo;
    }
    //Caso o valor de novo seja menor que o valor 
    //do nó apontado pelo aux2, ele é inserido na esquerda
    //deste nó. Caso contrário, é inserido na direita.
    else if(novo->info<aux2->info){
        aux2->esq = novo;
    }    
    else{
        aux2->dir = novo;
    }
    return r; 
} 