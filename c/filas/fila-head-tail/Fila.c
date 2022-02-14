#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
typedef struct fila
{
	int elem;
	struct fila *prox;
	
}fil;

typedef struct es
{
	int n_elem;
	fil *cabeca;
	fil *cauda;
	
}es_d;

void criar_fila(es_d *l)
{
	l = malloc(sizeof(es_d));
	l->n_elem = 0;
	l->cabeca = l->cauda = NULL;
}
void num_elem(es_d *l)
{
	int cont=0;
	if(l->cabeca == NULL)
	{
		printf("Fila vazia!\n\n");
		printf("A");
	}
	
	fil *aux;
	
	while(aux->prox!=NULL)
	{
		cont++;
		aux = aux->prox;
		printf("A");
	}
	
	printf("%d elementos.\n\n", cont);
	
}
void inserir_final(es_d *l, int dado)
{
	fil *novo;
	printf("A");
	novo = malloc(sizeof(fil));
	novo->elem = dado;
	l->n_elem++;
	l->cauda->prox = novo;
	l->cauda = novo;
	novo->prox = NULL;
	
}
void imprimir(es_d *l)
{
	fil *y;
	while(y)
	{
		printf("%d - ", y->elem);
		y = y->prox;
	}
}
void inserir_ordenada(es_d *l, int dado)
{
	fil *p, *aux, *novo;
	printf("A");
	if(l->cabeca == NULL)
	{
		printf("A");
		inserir_final(l, dado);
			printf("A");
	}
	else
	{
		printf("A");
		novo = (fil *)malloc(sizeof(fil));
		while(p!=NULL)
		{
			if(dado>p->elem/*4*/)
			{
				p = aux->prox;
				p->prox = novo;
				novo = p->prox->prox;
				l->n_elem++;
				imprimir(l);
			}
			else
			{
				printf("Ainda nao pensei.\n\n");
				imprimir(l);
			}
			p = p->prox;
		}	
	}
		printf("A");
}
void remove_inicio(es_d *l)
{
	fil *p;
	l->cabeca = p->prox;
	free(p);
	l->n_elem--;
	
}
int main ()
{
	setlocale(LC_ALL,"portuguese");
	es_d *w;
	int num;
	criar_fila(w);
	int op;
	do{
		printf("1.Inserir\n2.Remover primeiro\n3.Imprimir\n4.Número de elementos\n5.Sair\n-> ");
		scanf("%d", &op);
		
		if(op==1)
		{
			printf("Elemento: ");
			scanf("%d", &num);
			inserir_final(w, num);
		}
		else if(op==2)
		{
			remove_inicio(w);
		}
		else if(op==3)
		{
			imprimir(w);
		}
		else if(op==4)
		{
			num_elem(w);
		}
		else if(op==5)
		{
			return 0;
		}
		else
		{
			printf("Opção inválida.\n\n");
		}
	}while(op!=5);
}
