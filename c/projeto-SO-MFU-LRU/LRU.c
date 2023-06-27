//Declaracao de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

//Struct da página
typedef struct Pagina{
	char endereco[9];//Endereco da pagina
	struct Pagina *prox;//Ligando ela com a proxima por lista encadeada
}Pagina;

//Variaveis globais
char *arq, linha[20], end_temp[9];
int tamPag, tamMem, numPags, operacoes=0, lidas=0, escritas=0, acessada=0, pag_n_encontrada=0, sobreposta=0, pags_usadas=0;
float falha=0;
FILE *file;
//Ponteiros indicando a primeira e a última página da lista encadeada
Pagina *primeira, *ultima;

void nova_pag(char valor[9]){//Criar nova pagina
	Pagina *atual = (Pagina*)malloc(sizeof(Pagina));
	strcpy(atual->endereco, valor);//Coloca o endereco na pag atual
	atual->prox = NULL;//Coloca a prox pag como NULL
	
	if(pags_usadas == 0){//Caso nao tenha pagina ainda
	  	primeira = atual;//a primeira e a ultima vira a atual
		ultima =  primeira;
	}
	else {//Senao
		ultima->prox = atual;//Prox da ultima vira a atual
		ultima = atual;//Ultima vira atual
	}
	if(pags_usadas < numPags)//Enquanto as paginas usadas sao menores que o numero de paginas definido por tamMem/tamPag
		pags_usadas++;//Acrescentamos em pags_usadas
	
	escritas++;//Pag foi escrita
}

//Método LRU
void LRU(char valor[9]){
	nova_pag(valor);//Criar nova pagina
	if(pags_usadas == numPags)//Caso o numero de pags usadas seja igual ao que temos no sistema
	  primeira =  primeira->prox;//A pag em desuso por mais tempo sera removida da memoria
}

bool encontrar(char valor[9]){//Encontrando a pag
	Pagina *tmp = primeira, *prev = NULL;//Comecamos do inicio da lista encadeada
	while(tmp != NULL){//Percorre a lista
		if(strcmp(tmp->endereco, valor)==0){//Caso o endereco seja igual ao valor
				if(prev != NULL){//Caso seja da segunda pagina em diante
					if(tmp->prox != NULL)//Caso NAO seja a ultima pagina
						prev->prox = tmp->prox;							
				}
				else {//Caso prev seja igual a null, temos a primeira apontando para a proxima(encontrada na primeira)
				  primeira =  primeira->prox;
				}
        		//Organizando as paginas para colocar a mais usada em ultimo da lista, pois quando acabar a memoria, a primeira que ira ser retirada
				ultima->prox = tmp;
				ultima = tmp;
				tmp->prox = NULL;

			return true;//Foi encontrada, retorna verdadeiro
		}
    //Passa para a proxima pagina
		prev = tmp;	
		tmp = tmp->prox;
	}
	return false;//Caso termine o while e ela nao foi encontrada, retorna falso
}

//Substituindo pagina
void substituir_pag(char valor[9]){
  	LRU(valor);//Substitui chamando o LRU e informando o valor
	sobreposta++;//Mostra que foi sobreposta
}

//Escrevendo o endereco
void escrever_end(char valor[9]){
	if(pags_usadas < numPags){//Se ter espaco, criar nova pag
		nova_pag(end_temp);
	}
	else{//Se nao tiver espaco
		falha++;//Ocorre a falha
		substituir_pag(end_temp);//Troca da pag que permaneceu em desuso por mais tempo
	}
}

//Limpar a memoria
void limpa_memoria(){//Limpar a memoria
	Pagina *tmp = primeira;//Colocamos a primeira em temp
	while(tmp != NULL){//Enquanto temp for diferente de NULL
		tmp = tmp->prox;//Ate acabar as paginas
		free(tmp);
	}
	fclose(file);//Fecha o arquivo
}

int main(){
	arq = "operacoes.log";
	tamPag = 64;//Varia normalmente de 2 a 64
	tamMem = 8192;//Varia normalmente de 128 a 16384

	numPags = tamMem/tamPag;//Saber o numero de paginas disponiveis no sistema
		
	if(strlen(arq) > 0){//Se o tamanho do arquivo é maior que 0
		file = fopen(arq, "r");//Abre o arquivo em modo leitura
		while(fgets(linha, 20, file) != NULL){//Enquanto a linha for diferente de null
			operacoes++;//Soma 1 na operacao
			strncpy(end_temp, linha, 8);//Copia o endereco para end_temp
			end_temp[8] = '\0';//Adiciona um \0 no endereco
			if(linha[9] == 'W' || linha[9] == 'w'){//Se a operacao eh escrita
				escrever_end(end_temp);//Escreve o endereco na memoria
			}
			else if(linha[9] == 'R' || linha[9] == 'r'){//Se a operacao eh leitura				
				if(encontrar(end_temp)){//Se foi encontrado o endereco na memoria, acrescentamos 
				 acessada++;	
				}
				else{//Senao 
					pag_n_encontrada++;//Acrescenta 1 na pagina n_encontrada (paginas que sao R e nao foram achadas na memoria)
					escrever_end(end_temp);//Escrever o endereco na memoria
				}
				lidas++;//Pagina foi lida
			}
			else{//Senao ter W ou R na frente do endereco
				printf("ERRO: Os dados do arquivo de entrada estao em formato incorreto.");
				return 0;	
			}	
		}
	}
	else{//Caso o arquivo esteja vazio
		printf("ERRO: Arquivo de entrada invalido.");
		return 0;
	}
	
	printf("\nExecutando o simulador...\n");
	printf("Tamanho da memoria: %dKB\n", tamMem);
	printf("Tamanho das paginas: %dKB\n", tamPag);
	printf("Tecnica de reposicao: LRU\n");
	printf("Numero de paginas: %d\n", numPags);
	printf("Operacoes no arquivo de entrada: %d\n", operacoes);
	printf("Operacoes de leitura: %d\n", lidas);
	printf("Operacoes de escrita: %d\n", escritas);
	printf("Paginas acessadas(hit): %d\n", acessada);
	printf("Paginas de leitura nao encontradas(misses): %d\n", pag_n_encontrada);
	printf("Numero de paginas sobrepostas(writebacks): %d\n", sobreposta);
	printf("Taxa de falhas de pagina(page fault): %f%% \n", falha/escritas*100);
	
	limpa_memoria();
		
	return 0;
}
