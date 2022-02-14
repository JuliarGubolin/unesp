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
  int elementos[40];
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

	for (u = 0; u < g->vertices; u++) {
		cor[u] = VERDE;
	}

	for (u = 0; u < g->vertices; u++) {
		if (cor[u] == VERDE) {
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
/************************/
//Cria uma fila
fila* criar_fila() {
	fila* q = malloc(sizeof(fila));
  	q->head = -1;
  	q->tail = -1;
  	return q;
}
//Função para adicionar elementos na fila. Máximo 40
void inserir(fila* q, int val) {
	if (q->tail == 40 - 1)
    	printf("\nFila cheia. Máximo 40 posições.\n");
  	else{
    	if(q->head == -1){
      		q->head = 0;
		} 
    	q->tail++;
    	q->elementos[q->tail] = val;
  	}
}

//Função remover elementos da fila
int remover(fila* q) {
	int item;
  	if(q->tail == -1){
    	printf("Fila vazia. Não há elementos para remover.\n");
    	item = -1;
  	}else{
    	item = q->elementos[q->head];
    	q->head++;
    	if(q->head > q->tail){
      		q->head = q->tail = -1;
    	}
  	}
  return item;
}
/************************/
void buscaLargura(grafo *g, int vertice_ini){
	fila* q = criar_fila();
	int cor[g->vertices];
	for(int i=0;i<g->vertices;i++){
		cor[i] = VERDE;
	}
	cor[vertice_ini] = VERMELHO;
 	inserir(q, vertice_ini);

  	while(q->tail != -1){
    	int vertice_atual = remover(q);
    	adjacencia* adj = g->adj[vertice_atual].cabeca;
    	while(adj){
     		int vertice_adj = adj->vertice;
      		if(cor[vertice_adj] == VERDE){
        		cor[vertice_adj] = VERMELHO;
        		inserir(q, vertice_adj);
      		}
      		adj = adj->prox;
    	}
  	}
}