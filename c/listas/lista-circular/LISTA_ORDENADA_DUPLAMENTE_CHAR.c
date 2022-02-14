#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#define max 50

//strcmp
//-1 indicando que o parâmetro 1 é menor que o parâmetro 2;
//0 indicando que os parâmetros são iguais;
//1 caso o primeiro seja maior que o segundo parâmetro.

typedef struct elemento//Pra criar o elemento é a caixinha, valor dele e pra quem ele aponta.
{
	char nome[max];
	struct elemento *prox;
	struct elemento *ant;
}element;

typedef struct Lista//Pra criar a fila, é o tamanho dela e os elemento de inicio.
{
	int tam;
	element *inicio, *final;
}lista;

lista *create()//criação  da lista, inicio é NULL e o tamanho é zero, retorna l.
{
	lista* l=(lista*)malloc(sizeof(lista));
	l->tam=0;
	l->inicio=NULL;
	
	return l;
}

void inserir_lista(lista *l)//Preciso da lista.
{
	char nome[max];
	printf("Nome: ");//Pedir o nome.
	scanf("%s", nome);
	element* novo = (element*) malloc(sizeof(element));//Pra inserir, cria uma nova caixinha com o valor e o prox dela apontando pra NULL.
	strcpy(novo->nome,nome);
	novo->prox=NULL;
	novo->ant=NULL;
	
	element *atual = l->inicio;//IMPORTANTE, o atual recebe o de inicio e o anterior NULL.
    element *anterior = NULL;
    
	if(l->inicio==NULL)//Se não tem elemento na lista, ele vai pro primeiro.
		l->inicio = l->final = novo;
	else//Se já tem elemento na lista.
	{
		while (atual != NULL && strcmp(atual->nome,nome)<0)//Vai procurar enquanto for diferente do NULL e enquanto o valor das caixinhas forem menores que o valor.
		{
	        anterior = atual;
	        atual = atual->prox;
    	}
	    if(atual != NULL)//Se for inserir no começo ou no meio
		{
			if (anterior == NULL)//Inserir no começo
			{
	            novo->prox = l->inicio;
	            novo->ant = NULL;
	            l->inicio = novo;
       		}
       		else//Se o anterior for diferente de NULL, então vai inserir no meio.
       		{
	            anterior->prox = novo;
	            novo->ant=anterior;
	            novo->prox = atual;
	            atual->ant= novo;
       		}
	    }
		else//Se o atual é NULL, vai inserir no final
		{
			anterior->prox = novo;
			novo->ant=anterior;
			l->final = novo;
		}
	}
	l->tam++;
	
}

void remover_lista(lista *l)//Remover da lista, precisa só da lista.
{
	char op[max];
	if(l->tam==0)//Se o tamanho da lista é zero, não tem como remover.
		printf("Não há elementos para remover.\n");
	else//Se o tamanho é diferente de zero.
	{
		printf("Qual nome deseja remover?: ");
		scanf("%s", op);
			element *atual = l->inicio;//IMPORTANTE, o atual recebe o de inicio e o anterior NULL.
			element *anterior = NULL;
			
			while (atual != NULL && strcmp(atual->nome,op)!=0)//Enquanto o atual for diferente de NULL(final) e o atual for diferente da opção escolhida pra remover.
			{
	        	anterior = atual;
	        	atual = atual->prox;
    		}
	    	if(atual != NULL)//Se o atual for diferente de null, ele está na lista pra se remover.
			{
				if (anterior == NULL)//Se o anterior é NULL, vai remover o primeiro elemento.
				{
	            	l->inicio=atual->prox;
	            	atual->ant=NULL;
	            	free(atual);
       			}
       			else//Se o anterior não for NULL, vai remover o elemento do meio ou fim.
				{
					if(atual->prox==NULL)//Se o proximo depois do atual for NULL, vai remover o ultimo.
					{
						anterior->prox = NULL;
						free(atual);
					}
					else//Se o proximo for diferente de NULL, vai remover do meio.
					{
						anterior->prox = atual->prox;
	            		atual->prox->ant=anterior;
	            		free(atual);
					}
					
            	}
            	l->tam--;//Só posso abaixar o tamanho se ele estiver na lista.
	    	}
			else//Se o atual chegou no null e os numeros forem diferentes do escolhido.
			{
				printf("Este nome não existe.\n");
			}
	}
}

void mostrar_lista(lista *l)//Pra mostrar lista preciso só da lista;
{
	element *atual = l->inicio;//Atual vai receber inicio.
	if(l->tam == 0)//Se o tamanho for 0, lista vazia.
		printf("lista vazia !!!");
	else//Se o tamanho for diferente de zero.
	{
		printf("lista: ");
		while(atual != NULL)//Enquanto o atual não chegar no NULL, printa o valor do atual e atual recebe o atual proximo.
		{
			printf("%s,", atual->nome);
			atual = atual->prox;
		}
	}
}
void menu()//Menu padrão.
{
	printf("\n--MENU lista--\n\n1.Inserir\n2.Remover\n3.Mostrar lista\n4.Tamanho da lista\n5.Sair\n-> ");
}
int main ()
{
	setlocale(LC_ALL,"portuguese");
	lista *l=create();//Criar a lista.
	int op;
	do{
		menu();
		scanf("%d", &op);//Escolha do menu.
		
		switch (op)
		{
			
			case 1 :
				
			inserir_lista(l);//Insere.
			break;
			
			case 2 :
			remover_lista(l);//Remove.
			break;
			
			case 3: 
			mostrar_lista(l);//Mostra.
			break;
			
			case 4 :
			printf("O tamanho da lista é: %d\n", l->tam);//Tamanho.
			break;
			
			case 5 :
			return 0;//Sai do programa.
			break;
	
			
			default:printf("Leia novamente o menu.\n");
		}
	}while(op!=5);
}
