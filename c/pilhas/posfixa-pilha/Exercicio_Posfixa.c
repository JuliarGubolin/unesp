#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<string.h>
typedef struct elemento{
	int val;
	struct elemento *prox;
	
}element;
typedef struct pilha{
	int tam;
	element *inicio;
	
}pil;
pil *create(){
	pil* f=(pil*)malloc(sizeof(pil));
	f->tam=0;
	f->inicio=NULL;
  	return f;
}
void push(pil *f, int val){
	element* novo = (element*) malloc(sizeof(element));
	novo->val=val;
	novo->prox = f->inicio;
	f->inicio = novo;
	f->tam++;
}
void pop(pil *f){
	if(f->tam==0)
		printf("NAo ha elementos para remover.\n");
	else
	{
		element *temp;
		temp = f->inicio;
		f->inicio = f->inicio->prox;
		temp->prox = NULL;
		free(temp);
		f->tam--;
	}
}
char stacktop(pil *f){
  char top;
	element *atual = f->inicio;
	if(f->tam == 0)
		printf("Fila vazia !!!");
	else
    top = f->inicio->val;
  return top;
}
bool empty(pil *f){
    if(f->tam != 0){
        return false;
    }
    else{
        return true;
    }
}
void mostrar_pilha(pil *f){
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
int main(){
	char topo, conta[15];
	int i=0;
	int aux=0, aux2=0, aux3=0, aux4=0;
  	char *p;
	
	printf("\nNotacao pos-fixa: ");
	scanf("%s",conta);
  	pil *s = create();
  	
	for(i=0;i<strlen(conta);i++){
		if(conta[i]=='+'){
     		aux = stacktop(s);
     		pop(s);
     		aux2 = stacktop(s);
     		pop(s);
     		aux3 = aux + aux2;
     		push(s, aux3);
     		aux = 0;
     		aux2 = 0;
     		aux3 = 0;
		}
		else if(conta[i]=='*'){
     		aux = stacktop(s);
     		pop(s);
     		aux2 = stacktop(s);
     		pop(s);
     		aux3 = aux * aux2;
     		push(s, aux3);
     		aux = 0;
     		aux2 = 0;
     		aux3 = 0;
		}
		else{
			topo = conta[i];
      		p = &topo;
      		int r = atoi(p);
      		push(s, r);
		}
	}
	int resultado = stacktop(s);
	pop(s);	
	printf("\nO resultado da conta eh %d\n", resultado);
	return 0;
}
