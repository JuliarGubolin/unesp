#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
typedef struct elemento
{
	int val;
	struct elemento *prox;
	
}element;

typedef struct pilha
{
	int tam;
	element *inicio;
	
}pil;

pil *create()
{
	pil* f=(pil*)malloc(sizeof(pil));
	f->tam=0;
	f->inicio=NULL;
}

void inserir_pilha(int val, pil *f)
{
	element* novo = (element*) malloc(sizeof(element));
	novo->val=val;
	novo->prox = f->inicio;
	f->inicio = novo;
	f->tam++;
}

void remover_pilha(pil *f)
{
	if(f->tam==0)
		printf("NAo ha elementos para remover.\n");
	else
	{
		element *temp;
		temp = f->inicio;
		printf("Numero %d removido com sucesso!!!",temp->val);
		f->inicio = f->inicio->prox;
		temp->prox = NULL;
		free(temp);
		f->tam--;
	}
}

void mostrar_pilha(pil *f)
{
	element *atual = f->inicio;
	if(f->tam == 0)
		printf("Fila vazia !!!");
	else
	{
		printf("Fila: ");
		while(atual != NULL)
		{
			printf("%d,", atual->val);
			atual = atual->prox;
		}
	}
}
void menu()
{
	printf("\n--MENU PILHA--\n\n1.Inserir\n2.Remover\n3.Mostrar pilha\n4.Tamanho da pilha\n5.Sair\n-> ");
}
int main ()
{
	setlocale(LC_ALL,"portuguese");
	pil *f=create();
	int op, exp;
	do{
		menu();
		scanf("%d", &op);
		
		switch (op)
		{
			
			case 1 :
			printf("Numero: ");
			scanf("%d", &exp);
			inserir_pilha(exp, f);
			break;
			
			case 2 :
			remover_pilha(f);	
			break;
			
			case 3: mostrar_pilha(f);
			break;
			
			case 4 :
			printf("O tamanho da fila �: %d\n", f->tam);
			break;
			
			case 5 :
			return 0;
			break;
	
			
			default:printf("Leia novamente o menu.\n");	
		}
	}while(op!=5);
}
