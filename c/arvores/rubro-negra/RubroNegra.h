#include<stdio.h>
#include<stdlib.h>

//TAD Rubro Neavora ---------------------

typedef struct node{
	int info;
	int cor;
	struct node* esq, * dir, *pai;
}RB;

RB* inicializa_no(void);
RB* criarNo(int x);
RB *inserir(RB *r, RB *novo);
RB *rotacao_dir(RB *r);
RB *rotacao_esq(RB *r);
int cor_do_node(RB *r);
void trocar_cor(RB *r);

//Implementações ---------------

RB* inicializa_no(void) {
	return NULL;
}

RB* criarNo(int x) {
	RB* novo;

	novo = (RB*)malloc(sizeof(RB));

	novo->dir = NULL;
	novo->esq = NULL;
	novo->info = x;
	novo->pai = NULL;
	novo->cor = 1;//0 - preto, 1 - vermelho

	return novo;
}
void imprimir(RB *r){ 
    if(r != NULL){
        printf("%d", r->info);
        printf("(");
        imprimir(r->esq);
        imprimir(r->dir);
        printf(")");
    }
}
//Função para retornar a cor do nó recebido;
int cor_do_node(RB *r){
	if(r == NULL){
		return 0;
	}else{
		return r->cor;
	}
}
//Rotações usadas também na árvore AVL
RB* rotacao_dir(RB* r) {
	RB* aux;

	aux = r->esq;
	r->esq = aux->dir;
	aux->dir = r;

    //A única mudança em relação a rotação na árvore binária é a troca da cor do nó
	aux->cor = r->cor;
    r->cor = 1;

	return aux;
}
RB* rotacao_esq(RB* r) {
	RB* aux;

	aux = r->dir;
	r->dir = aux->esq;
	aux->esq = r;

    //A única mudança em relação a rotação na árvore binária é a troca da cor do nó
	aux->cor = r->cor;
    r->cor = 1;

	return aux;
}
//Função que recebe um nó e troca a cor de seus filhos e a sua própria
void trocar_cor(RB* r){
    //Troca a cor do nó recebido
    r->cor = !r->cor;
    //Troca a cor dos seus filhos (se for vermelho (1) se torna preto (0) e vice versa)
    if(r->esq != NULL)
        r->esq->cor = !r->esq->cor;
    
    if(r->dir != NULL)
        r->dir->cor = !r->dir->cor;
    
}
//Função de inserção com balanceamento
RB *inserir(RB *r, RB *novo){
    if(r == NULL){
        printf("Elemento inserido!\n");
        return novo;
    }
    else{
        if(novo->info > r->info){
            r->dir = inserir(r->dir, novo);
            novo->pai = r;
        }
        if(novo->info < r->info){
            r->esq = inserir(r->esq, novo);
            novo->pai = r;
        }
        if(novo->info == r->info){
            printf("Elemento duplicado!\n");
            return r;
        }
        //Até aqui, temos uma inserção recursiva comum em uma árvore binária
        //A partir daqui, vamos analisar a cor dos nós para determinar a rotação ou a troca
        //de cor.
        if(cor_do_node(r->dir) == 1 && cor_do_node(r->esq) == 0){
            r = rotacao_esq(r);
        }
        if(cor_do_node(r->esq) == 1 && cor_do_node(r->esq->esq) == 1){
            r = rotacao_dir(r);
        }
        if(cor_do_node(r->esq) == 1 && cor_do_node(r->dir) == 1){
            trocar_cor(r);
        }
        return r;
    }
}


