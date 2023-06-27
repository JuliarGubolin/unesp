#pragma once
#include<stdio.h>
#include<stdlib.h>

#define max 5
#define VERDE 0
#define VERMELHO 1
#define CINZA 2

typedef struct adj {
	int vertice; //o vertice onde a aresta chega
	int peso; //o peso da aresta
	struct adj* prox; //o proximo da lista
}adjacencia;

typedef struct vert {
	//Outros dados vao aqui
	adjacencia* cabeca; //cabeca para a lista de adjacencia
}vertice;

typedef struct gr {
	int vertices; //numero de vertices
	int arestas; //numero de arestas
	vertice* adj; //vetor de vertices
}grafo;

typedef struct Fila{
  int elementos[20];
  int head;
  int tail;
}fila;

fila* criar_fila();
void inserir(fila* q, int);
int remover(fila* q);

grafo* criaGrafo(int v);
adjacencia* criaAdj(int v, int peso);
int criaAresta(grafo *g, int vi, int vf, int peso);
void imprime(grafo* g);
void buscaProfundidade(grafo* g);
void visita(grafo* g, int u, int* cor);
void buscaLargura(grafo *g, int vertice_ini);

grafo* criaGrafo(int v) {
	int i;
	grafo* g;

	g = (grafo*)malloc(sizeof(grafo));
	g->vertices = v;
	g->arestas = 0;
	g->adj = (vertice*)malloc(v*sizeof(vertice));

	for (i = 0; i < v; i++) {
		g->adj[i].cabeca = NULL;
	}

	return g;
}

adjacencia* criaAdj(int v, int peso) {
	adjacencia* adj;

	adj = (adjacencia*)malloc(sizeof(adjacencia));
	adj->vertice = v;
	adj->peso = peso;
	adj->prox = NULL;

	return adj;
}

int criaAresta(grafo* g, int vi, int vf, int peso) {
	adjacencia* novo;

	if (!g) {
		return 0;
	}

	if (vf < 0 || vf >= g->vertices) {
		return 0;
	}

	if (vi < 0 || vi >= g->vertices) {
		return 0;
	}

	novo = criaAdj(vf, peso);
	novo->prox = g->adj[vi].cabeca;
	g->adj[vi].cabeca = novo;
	g->arestas++;

	return 1;
}

void imprime(grafo* g) {
	int i;
	adjacencia* aux;

	printf("Vertices: %d, Arestas: %d. \n",g->vertices, g->arestas);

	for (i = 0; i < g->vertices; i++) {
		printf("u%d: ", i);
		
		aux = g->adj[i].cabeca;

		while (aux) {
			printf("u%d(%d) ", aux->vertice, aux->peso);
			aux = aux->prox;
		}

		printf("\n");
	}
}

void buscaProfundidade(grafo* g) {
	int cor[g->vertices];
	int u;

	for(u = 0; u < g->vertices; u++){
		cor[u] = VERDE;
	}

	for (u = 0; u < g->vertices; u++){
		if(cor[u] == VERDE){
			visita(g, u, cor);
		}
	}
}

void visita(grafo* g, int u, int* cor) {
	adjacencia* v;

	cor[u] = VERMELHO;

	v = g->adj[u].cabeca;

	while (v) {
		if (cor[v->vertice] == VERDE) {
			visita(g, v->vertice, cor);
		}

		v = v->prox;
	}

	cor[u] = CINZA;
}
//Funções para manipulação da fila usada na busca em largura
/************************/
//Cria uma fila
fila* criar_fila() {
	//Os ponteiros head e tail recebem o valor da primeira posição e da última posição 
	//do vetor que representa a fila, respectivamente.
	fila* q = malloc(sizeof(fila));
	//Neste caso, são inicializados com -1, já que quando são criados não 
	//apontam para nenhuma posição.
  	q->head = -1;
  	q->tail = -1;
  	return q;
}
//Função para adicionar elementos na fila. Máximo 40
void inserir(fila* q, int val){
	//Verifica se a fila estava vazia, se sim, o ponteiro para o início da fila
	//recebe o endereço da primeira posição do vetor (0).
    if(q->head == -1){
      	q->head = 0;
	} 
	//O ponteiro que guarda a última posição do vetor aumenta, para a posição
	//em que deve ser inserido o novo elemento.
    q->tail++;
    q->elementos[q->tail] = val;
}
//Função remover elementos da fila. Retorna o item removido.
int remover(fila* q) {
	int item;
	//O item da primeira posição (a que será removida) passa a ser desconsiderado,
	//já que o ponteiro que representa a posição dele é movido para a próxima.
    item = q->elementos[q->head];
    q->head++;
    if(q->head > q->tail){
      	q->head = q->tail = -1;
    }
	return item;
}
/************************/
//Função para busca em largura
void buscaLargura(grafo *g, int vertice_ini){
	//Criação da fila.
	fila* q = criar_fila();
	//Criação do vetor que representa as cores dos vértices.
	int cor[g->vertices];
	//Como nenhuma posição foi visitada ainda, todas serão verdes.
	for(int i=0;i<g->vertices;i++){
		cor[i] = VERDE;
	}
	cor[vertice_ini] = VERMELHO;
 	inserir(q, vertice_ini);
	//Enquando existir elementos na fila:
  	while(q->tail != -1){
		//Iremos remover o elemento que está na fila.
    	int vertice_atual = remover(q);
		printf("Vértice: %d\n", vertice_atual);
		//adj recebe o adjacente do vértice atual.
    	adjacencia* adj = g->adj[vertice_atual].cabeca;
		//Enquanto for verdade:
    	while(adj){
			//Tornaremos todos os vértices não explorados (verdes) em explorados (vermelhos).
     		int vertice_adj = adj->vertice;
      		if(cor[vertice_adj] == VERDE){
        		cor[vertice_adj] = VERMELHO;
				//inserimos o novo elemento na lista.
        		inserir(q, vertice_adj);
      		}
      		adj = adj->prox;
    	}
  	}
}