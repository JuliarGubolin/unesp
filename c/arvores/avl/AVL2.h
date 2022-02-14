#include<stdio.h>
#include<stdlib.h>

//TAD AVL ---------------------

typedef struct node{
	int info;
	int h; //necessario para calcular o fator de desfatorBamento
	struct node* esq, * dir;
}AVL;

AVL* inicializa(void);
AVL* criarNo(int x);
//Tipos de Rotação
AVL* rotacao_dir(AVL* r);
AVL* rotacao_esq(AVL* r);
AVL* rotacao_dir_esq(AVL* r);
AVL* rotacao_esq_dir(AVL* r);
int max(int a, int b);
int altura(AVL* r);
//Funções para inserção e remoção
AVL *min(AVL *r);
int fatorBalanceamento(AVL *r);
AVL *inserir(AVL *r, AVL *novo);
AVL* removerAVL(AVL* r, int info);

//Implementações ---------------

AVL* inicializa(void) {
	return NULL;
}

AVL* criarNo(int x) {
	AVL* novo;

	novo = (AVL*)malloc(sizeof(AVL));

	novo->dir = NULL;
	novo->esq = NULL;
	novo->info = x;
	novo->h = 0;

	return novo;
}
void imprimir(AVL *r){ //pre-ordem (C-E-D)
    if(r != NULL){
        printf("%d", r->info);
        printf("(");
        imprimir(r->esq);
        imprimir(r->dir);
        printf(")");
    }
}

int max(int a, int b) {
	if (a > b) {
		return a;
	}

	return b;
}
//Calcula a altura 
int altura(AVL* r) {
	if (!r) {
		return -1;
	}

	return r->h;
}

AVL* rotacao_dir(AVL* r) {
	AVL* aux;

	//troca de ponteiros
	aux = r->esq;
	r->esq = aux->dir;
	aux->dir = r;

	//atualizar a altura
	r->h = max(altura(r->dir), altura(r->esq)) + 1;
	aux->h = max(altura(aux->esq), r->h) + 1;

	return aux;
}

AVL* rotacao_esq(AVL* r) {
	AVL* aux;

	//troca de ponteiros
	aux = r->dir;
	r->dir = aux->esq;
	aux->esq = r;

	//atualizar a altura
	r->h = max(altura(r->dir), altura(r->esq)) + 1;
	aux->h = max(altura(aux->dir), r->h) + 1;

	return aux;
}

AVL* rotacao_esq_dir(AVL* r) {
	r->esq = rotacao_esq(r->esq);
	
	return rotacao_dir(r);
}

AVL* rotacao_dir_esq(AVL* r) {
	r->dir = rotacao_dir(r->dir);

	return rotacao_esq(r);
}
/*Função auxiliar para a inserção e a remoção. Retorna o valor do 
fator de balanceamento. Seu cálculo é feito subtraindo a altura do nó do lado esquerdo
do nó indicado por r pela altura do nó do lado direito.*/
int fatorBalanceamento(AVL *r){ 
    if(r == NULL){ 
        return 0; 
	}
    return altura(r->esq) - altura(r->dir); 
}
//Função inserir
AVL *inserir(AVL *r, AVL *novo){
    /*Verifica se R aponta para null. Em caso afirmativo, o elemento foi inserido com sucesso 
    e podemos retornar a árvore para a função principal. Esta condição se torna também a condição de parada
    para a recursão mais a baixo.*/
    if(r == NULL){
        printf("Elemento inserido!\n");
        return novo;
    }
    else{
        /*Caso o valor presente no novo nó for maior que o valor presente em R,
        iremos inserir o valor na subárvore da direita. Além disso, iremos verificar se
        houve desbalanceamento da árvore. Se a diferença das alturas dos nós for maior que dois, 
        devemos rotacionar a árvore para a esquerda e depois para a direita. Caso a diferença das
        alturas for menor que -2, temos uma árvore "pendendo" para a direita, portanto devemos rotacioná-la 
        para a esquerda.*/
        if(novo->info > r->info){
            r->dir = inserir(r->dir, novo);
            if(fatorBalanceamento(r) >=2){
                r = rotacao_esq_dir(r);
			}
            if(fatorBalanceamento(r) <=-2){
                r = rotacao_esq(r);
			}		
        }
        /*Caso o valor presente no novo nó for menor que o valor presente em R,
        iremos inserir o valor na subárvore da esquerda. Além disso, iremos verificar se
        houve desbalanceamento da árvore. Se a diferença das alturas dos nós for maior que dois, 
        temos uma árvore "pendendo" para a esquerda, portanto devemos rotacioná-la 
        para a direita. Caso a diferença das alturas for menor que -2, devemos rotacionar a árvore 
        para a direita e depois para a esquerda. */
        if(novo->info < r->info){
            r->esq = inserir(r->esq, novo);
                if(fatorBalanceamento(r) >=2){
                    r = rotacao_dir(r);
				}
                if (fatorBalanceamento(r) <=-2){
                    r = rotacao_dir_esq(r);
				}	
        }
        /*Como a árvore não aceita valores iguais, quando um valor já
        inserido é enviado para ser incluído novamente, ele não é inserido e a função
        retorna a árvore para a função principal.*/
        if(novo->info == r->info){
            printf("Elemento duplicado!\n");
            return r;
        }
    }
    //Por fim, recalculamos a altura da árvore com a nova inserção e ela é retornada para a função principal
    r->h = max(altura(r->esq), altura(r->dir)) + 1;
    return r;
}
//Remoção árvore AVL
/*A remoção deve levar em conta que o nó removido pode causar
um desbalanceamento na árvore, o qual deve ser corrigido utilizando as rotações.*/
//A função min retorna o menor valor e é utilizada na função remover
AVL* min(AVL *r){

    AVL *aux1,*aux2;
    aux1 = r;
    aux2 = r->esq;
    while(aux2 != NULL){
        aux1 = aux2;
        aux2 = aux2->esq;
    }
    return aux1;
}
//Função remover
AVL *removerAVL(AVL* r, int info){

    //Variáveis auxiliares
    AVL *old, *temp;
    //Verificação: caso a raiz seja nula o valor buscado não pode ser encontrado
    if(r == NULL){
        printf("Valor nao encontrado.\n");
        return r;
    }else{
        /*Caso a informação a ser removida for menor que o valor da raíz, 
        chamamos a função remover novamente, mas dessa vez para a parte esquerda da árvore.*/
        if(info < r->info){
            r->esq = removerAVL(r->esq, info);
        }
        /*Caso a informação a ser removida for maior que o valor da raíz, 
        chamamos a função remover novamente, mas dessa vez para a parte direita da árvore.*/
        else if(info > r->info){
            r->dir = removerAVL(r->dir, info);
        }
        /*Caso a informação a ser removida for igual ao valor da raíz, 
        analisaremos os seguntes casos:*/
        else{
            //1 - Possui um ou nenhum filho
            //Em algum momento da execução do código, iremos entrar neste caso para que o valor seja removido (free (old))
            if((r->esq == NULL) || (r->dir == NULL)){
                old = r;
                if(r->esq != NULL){
                    r = r->esq;
                }else{
                    r = r->dir;
                }
                free(old);
            //2 - Possui dois filhos. A função min retorna o menor valor na parte direita da árvore
            }else{
                temp = min(r->dir);
                r->info = temp->info;
                r->dir = removerAVL(r->dir, temp->info);
            }
        }
    }
    //Verificação: se a raíz for nula não são necessárias rotações para balanceamento
    if(r == NULL){
        return r;
    }
    //Calculo da altura da árvore AVL
    r->h = 1 + max(altura(r->esq), altura(r->dir));
    //A variável fator recebe o fator de balanceamento que irá definir a rotação necessária
    int fator  = fatorBalanceamento(r);
    //Caso 1: rotação simples a direita
    if(fator > 1 && fatorBalanceamento(r->esq) >= 0){
        r = rotacao_dir(r);
    }
    //Caso 2: rotação dupla esquerda direita
    if(fator > 1 && fatorBalanceamento(r->esq) < 0){
        r  = rotacao_esq_dir(r);
    }
    //Caso 3: rotação simples a esquerda
    if(fator < -1 && fatorBalanceamento(r->dir) <= 0){
        r = rotacao_esq(r);
    }
    //Caso 4: rotação simples a direita
    if(fator < -1 && fatorBalanceamento(r->dir) > 0){
        r = rotacao_dir_esq(r);
    }
    //Por fim, retornamos a raíz para a função principal
    return r;
}

