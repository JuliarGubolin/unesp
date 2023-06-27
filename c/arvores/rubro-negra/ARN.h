#include<stdio.h>
#include<stdlib.h>

//TAD ARN ---------------------

typedef struct node {
	int info;
	int cor; //necessario para calcular o fator de desbalanceamento
	struct node* esq, * dir;
}ARN;

#define V 1
#define P 0

ARN* inicializa(void);
ARN* criarNo(int x);
int cor(ARN* A);
void trocar(ARN* A);
ARN *inserir(ARN* r, ARN* novo);//Exercicio 1
ARN* rotacao_dir(ARN* r);
ARN* rotacao_esq(ARN* r);

//Implementacoes ---------------

int cor(ARN* A){//Operação para verificar a cor do nó
    if(A == NULL)//Se o nó for vazio, retorna a cor PRETA
        return P;

    return A->cor;//Senão retorna a cor do próprio nó
}

void trocar(ARN* A){//Operação para trocar a cor do nó e de suas arvóres
    A->cor = !A->cor;//Se a cor for PRETA ela se torna VERMELHA, e se for VERMELHA ela se torna PRETA
    
    if(A->esq != NULL)//Se tiver um nó do lado esquerdo, esse nó tem sua cor trocada
        A->esq->cor = !A->esq->cor;
    
    if(A->dir != NULL)//Se tiver um nó do lado direito, esse nó tem sua cor trocada
        A->dir->cor = !A->dir->cor;
    
}

ARN* inicializa(void) {
	return NULL;
}

ARN* criarNo(int x) {
	ARN* novo;

	novo = (ARN*)malloc(sizeof(ARN));

	novo->dir = NULL;
	novo->esq = NULL;
	novo->info = x;
	novo->cor = V;//Todo novo nó recebe a cor VERMELHA

	return novo;
}

ARN* rotacao_dir(ARN* r) {//Mesma coisa que a rotação direita da arvore AVL, so que invez de atualizar a altura, ela atualiza a cor
	ARN* aux;

	//troca de ponteiros
	aux = r->esq;
	r->esq = aux->dir;
	aux->dir = r;

	//atualizar a cor do nó
	aux->cor = r->cor;//O nó auxiliar recebe a cor do nó atual
    r->cor = V;//O nó recebe a cor VERMELHA

	return aux;
}

ARN* rotacao_esq(ARN* r) {//Mesma coisa que a rotação esquerda da arvore AVL, so que invez de atualizar a altura, ela atualiza a cor
	ARN* aux;

	//troca de ponteiros
	aux = r->dir;
	r->dir = aux->esq;
	aux->esq = r;

	//atualizar a cor do nó
	aux->cor = r->cor;//O nó auxiliar recebe a cor do nó atual
    r->cor = V;//O nó recebe a cor VERMELHA

	return aux;
}

ARN *inserir(ARN *r, ARN *novo){
    if(r == NULL){
        system("cls");
        printf("Elemento inserido!\n");
        return novo;
    }
    else{
        //Na subarvore da direta
        if(novo->info > r->info){
            r->dir = inserir(r->dir, novo);
        }
        //Na subarvore da esquerda
        if(novo->info < r->info){
            r->esq = inserir(r->esq, novo);
        }

        if(novo->info == r->info){//Se o elemento for igual a um que ja estava na arvore
            system("cls");
            printf("Elemento duplicado!\n");

            return r;
        }

        if(cor(r->dir) == V && cor(r->esq) == P)//Se a arvore da direta do nó for VERMELHA e a da esquerda for PRETA, se faz uma rotação a esquerda
            r = rotacao_esq(r);
        
        if(cor(r->esq) == V && cor(r->esq->esq) == V)//Se a arvore da esquerda do nó for VERMELHA e a arvore esquerda desse nó a esquerda for VERMELHA, se faz uma rotação a direita
            r = rotacao_dir(r);

        if(cor(r->esq) == V && cor(r->dir) == V)//Se a arvore da direta do nó for VERMELHA e a da esquerda for VERMELHA, se faz uma troca de cor somente
            trocar(r);

        system("cls");
        printf("Elemento inserido!\n");
        return r;
    }
}

void imprimir(ARN *r){ //pre-ordem (C-E-D)
    if(r != NULL){
        printf("%d", r->info);
        printf("(");
        imprimir(r->esq);
        imprimir(r->dir);
        printf(")");
    }
}


void buscar(ARN *r, int x){
    if(r == NULL){
        system("cls");
        printf("Elemento nao encontrado!\n");
    }else{
        if(x == r->info){
            system("cls");
            printf("Elemento %d encontrado!Sua cor :", r->info);
            if (cor(r)==V)
                printf(" Vermelha.\n");
            if (cor(r)==P)
                printf(" Preta.\n");
            
        }else{
            if(x > r->info){
                buscar(r->dir, x);
            }else{
                buscar(r->esq, x);
            }
        }
    }
}