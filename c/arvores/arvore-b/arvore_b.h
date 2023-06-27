//Este arquivo .h contém as funções para árvore B e manipulação de arquivos.
//Declaração das bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
//Define uma ordem fixa para a paginação da árvore.
#define ORDEM 2
//Define um nome fixo para o arquivo de dados.
#define namefile "_arquivo.dat"

int cont = -1, count = 0;
//Struct com os dados que as referências bibliográficas devem conter
typedef struct
{
  char nome[50], DOI[50], sobrenome[20];
  char titulo[50], local[30], edit[20];
  int ano, ed;
  int rank;
} Registro;

typedef struct Pagina_str *Apontador;
typedef struct Pagina_str
{
  int n;
  int pageNum;
  int num;
  Registro r[2*ORDEM];
  Apontador p[2*ORDEM+1];
} Pagina;

struct Node{
	Registro info;
	struct Node *prox;
}; 
typedef struct Node node;

//Declaração das funções 
//##########################################################
void Antecessor(Apontador Ap, int Ind, Apontador ApPai, int *Diminuiu);
void Busca(Registro Reg, Apontador Ap);
void buscainFile(Registro Reg, Apontador pagina);
int file_exists(const char *filename);
void Insere(Registro Reg, Apontador *Ap);
void InsereNaPagina(Apontador Ap, Registro Reg, Apontador ApDir);
void Ins(Registro Reg, Apontador Ap, int *Cresceu, Registro *RegRetorno, Apontador *ApRetorno);
int Imprime2(Apontador p, int Nivel, int aux, int n);
void InsertPosFile(Registro Reg, Apontador *Ap);
node *busca(Registro info, node *LISTA);
void InsPosFile(Registro Reg, Apontador Ap, int *Cresceu, Registro *RegRetorno, Apontador *ApRetorno);
void Retira(char doi[], Apontador *Ap);
void Ret(char doi[], Apontador *Ap, int *Diminuiu);
void Reconstitui(Apontador ApPag, Apontador ApPai, int PosPai, int *Diminuiu);
void saveAux(Apontador p, int Nivel);
void salvar(Apontador pagina, Registro Reg[]);
void recuperarReg(Apontador *arv, node *LISTA);void insereInicio(Registro info, node *LISTA);
void execut(Registro info, node *LISTA);
void alterarReg(char doi[], Apontador *Ap, int *Diminuiu);
void alterarReg2(char doi[], Apontador *Ap);
//############################################################
typedef Apontador TipoDicionario;
void Inicializa(TipoDicionario *Dicionario)
{
  *Dicionario = NULL;
}

void inicia(node *LISTA)
{
	LISTA->prox = NULL;
}
void alterarReg (char doi[], Apontador *Ap, int *Diminuiu)
{
  int Ind, j;
  Apontador WITH;
  Registro reg;
  WITH = *Ap;
  Ind = 1;
  if (WITH == NULL)
  {
    printf("DOI não encontrado.\n");
    *Diminuiu = 0;
    return;
  }
  while (Ind < WITH->n && strcmp(doi,WITH->r[Ind - 1].DOI) >0 )
    Ind++;
  if (strcmp(doi,WITH->r[Ind - 1].DOI) == 0)
  {
    printf("Sobrenome: ");
          setbuf(stdin, NULL);
          scanf("%[^\n]s", reg.sobrenome);
          setbuf(stdin, NULL);
          printf("Nome: ");
          setbuf(stdin, NULL);
          scanf("%[^\n]s", reg.nome);
          setbuf(stdin, NULL);
          printf("Título da obra: ");
          setbuf(stdin, NULL);
          scanf("%[^\n]s", reg.titulo);
          printf("Local de publicação: ");
          setbuf(stdin, NULL);
          scanf("%[^\n]s", reg.local);
          setbuf(stdin, NULL);
          printf("Editora: ");
          setbuf(stdin, NULL);
          scanf("%[^\n]s", reg.edit);
          printf("Edição: ");
          setbuf(stdin, NULL);
          scanf("%d", &reg.ed);
          setbuf(stdin, NULL);
          printf("Ano de publicação: ");
          scanf("%d", &reg.ano); 
    if (WITH->p[Ind - 1] == NULL) {
      strcpy(WITH->r[Ind - 1].sobrenome, reg.sobrenome);
      strcpy(WITH->r[Ind - 1].nome,reg.nome);
      strcpy(WITH->r[Ind - 1].titulo, reg.titulo);
      strcpy(WITH->r[Ind - 1].edit, reg.edit);
      strcpy(WITH->r[Ind - 1].local, reg.local);
      WITH->r[Ind - 1].ano = reg.ano;
      WITH->r[Ind - 1].ed = reg.ed;
      WITH->r[Ind - 1].rank = reg.rank;
      return;
    }
    Antecessor(*Ap, Ind, WITH->p[Ind - 1], Diminuiu);
    if (*Diminuiu)
      Reconstitui(WITH->p[Ind - 1], *Ap, Ind - 1, Diminuiu);
    return;
  }
  if (strcmp(doi,WITH->r[Ind - 1].DOI) > 0)
    Ind++;
  alterarReg(doi,&WITH->p[Ind - 1], Diminuiu);
  if (*Diminuiu)
    Reconstitui(WITH->p[Ind - 1], *Ap, Ind - 1, Diminuiu);
}
void alterarReg2(char doi[], Apontador *Ap)
{
  int Diminuiu;
  Apontador Aux;

  alterarReg(doi, Ap, &Diminuiu);
  if (Diminuiu && (*Ap)->n == 0) { 
    Aux = *Ap;
    *Ap = Aux->p[0];
    free(Aux);
    
  }
  
}
//---------------------------
void Antecessor(Apontador Ap, int Ind, Apontador ApPai, int *Diminuiu)
{
  if (ApPai->p[ApPai->n] != NULL)
  {
    Antecessor(Ap, Ind, ApPai->p[ApPai->n], Diminuiu);
    if (*Diminuiu)
      Reconstitui(ApPai->p[ApPai->n], ApPai, ApPai->n, Diminuiu);
    return;
  }
  Ap->r[Ind - 1] = ApPai->r[ApPai->n - 1];
  ApPai->n--;
  *Diminuiu = ApPai->n < ORDEM;
}  /* Antecessor */

void Busca(Registro Reg, Apontador Ap)
{
  int i;

  if (Ap == NULL) 
  {
	printf("DOI não encontrado: %s.\n",Reg.DOI);
	return;  
  }
  i = 1;
  while (i < Ap->n && (strcmp(Reg.DOI, Ap->r[i - 1].DOI)) > 0)
    i++;
  if (strcmp(Reg.DOI, Ap->r[i-1].DOI) == 0)
  {
    printf("DOI: %s \n", Reg.DOI);
    buscainFile(Ap->r[i-1],Ap);
    return;
  }
  if ((strcmp(Reg.DOI, Ap->r[i - 1].DOI)) < 0)
    Busca(Reg, Ap->p[i-1]);
  else
    Busca(Reg, Ap->p[i]);
}
void buscainFile(Registro Reg, Apontador pagina)
{
	Registro reg[2*ORDEM];
	int i;
	FILE *arq = fopen(namefile,"rb");
	if (arq == NULL)
	exit(1);
	fseek(arq, pagina->pageNum*(2*ORDEM*sizeof(Registro)), SEEK_SET);
	fread(reg, (2*ORDEM*sizeof(Registro)),1,arq);
	fclose(arq);
	for(i = 0; i < 2*ORDEM; i++){
		if (strcmp(Reg.DOI, reg[i].DOI) == 0)
    /*123: Gubolin, Julia. Boa tarde. 12. ed. Rio Preto: Joji, 2001.*/
    printf("%s: %s, %s. %s. %d. ed. %s: %s, %d.\n\n",reg[i].DOI, reg[i].sobrenome, reg[i].nome, reg[i].titulo, reg[i].ed, reg[i].local, reg[i].edit, reg[i].ano);
			}
	}

int file_exists(const char *filename)
{
  FILE *arquivo;

  if((arquivo = fopen(filename, "rb")))
  {
    fclose(arquivo);
    return 1;
  }
  return 0;
}

void InsereNaPagina(Apontador Ap, Registro Reg, Apontador ApDir)
{
	
  int k;
  int NaoAchouPosicao;

  k = Ap->n;
  NaoAchouPosicao = k > 0;
  while (NaoAchouPosicao)
  {
    if (strcmp(Reg.DOI, Ap->r[k - 1].DOI) >=0)
    {
      NaoAchouPosicao = 0;
      break;
    }
    
    Ap->r[k] = Ap->r[k - 1];
    
    Ap->p[k + 1] = Ap->p[k];
    
    k--;
    if (k < 1)
      NaoAchouPosicao = 0;
  }
  Ap->r[k] = Reg;
  Ap->p[k + 1] = ApDir;
  Ap->n++;
}  

void Ins(Registro Reg, Apontador Ap, int *Cresceu, Registro *RegRetorno, Apontador *ApRetorno)
{
  Apontador ApTemp;
  Registro Aux;
  int i, j;

  if (Ap == NULL) 
  {
    *Cresceu = 1;
    *RegRetorno = Reg;
    *ApRetorno = NULL;
    return;
  }
  i = 1;
  while (i < Ap->n && (strcmp(Reg.DOI,Ap->r[i - 1].DOI)>0))
    i++;
  if (strcmp(Reg.DOI,Ap->r[i - 1].DOI) == 0)
  {
    printf("DOI já existente.\n");
    *Cresceu = 0;
    return;
  }
  if (strcmp(Reg.DOI,Ap->r[i - 1].DOI)<0)
    Ins(Reg, Ap->p[i-1], Cresceu, RegRetorno, ApRetorno);
  else
    Ins(Reg, Ap->p[i], Cresceu, RegRetorno, ApRetorno);
  if (!*Cresceu)
    return;
  if (Ap->n < 2*ORDEM)
  {  /* Verificando se a pagina tem espaco */
    InsereNaPagina(Ap, *RegRetorno, *ApRetorno);
    *Cresceu = 0;
    return;
  }
  /* Split: Pagina tem que ser dividida */
  ApTemp = (Apontador) malloc(sizeof(Pagina));
  ApTemp->n = 0;
  ApTemp->p[0] = NULL;
  cont++;
  ApTemp->pageNum = cont;
  
  if (i <= ORDEM + 1)
  {
    InsereNaPagina(ApTemp, Ap->r[2*ORDEM - 1], Ap->p[2*ORDEM]);
    Ap->n--;    
    InsereNaPagina(Ap, *RegRetorno, *ApRetorno);
  }
  else{
    InsereNaPagina(ApTemp, *RegRetorno, *ApRetorno);
    }
  for (j = ORDEM + 2; j <= 2*ORDEM; j++)
    InsereNaPagina(ApTemp, Ap->r[j - 1], Ap->p[j]);
    
  
  Ap->n = ORDEM;
  ApTemp->p[0] = Ap->p[ORDEM + 1];
  *RegRetorno = Ap->r[ORDEM];
  *ApRetorno = ApTemp;
 for (j = ORDEM; j < Ap->n+2; j++){
    strcpy(Aux.DOI, "Referencia_Auxiliar");
    Aux.rank = 0;
    Ap->r[j] = Aux;
		}
}  /*Ins*/

void Insere(Registro Reg, Apontador *Ap)
{
  int Cresceu;
  Registro RegRetorno;
  Apontador ApRetorno;
  Apontador ApTemp;

  Ins(Reg, *Ap, &Cresceu, &RegRetorno, &ApRetorno);
  if (Cresceu) { /* Se arvore cresce na altura pela raiz */
    ApTemp = (Apontador) malloc(sizeof(Pagina));
    ApTemp->n = 1;
    ApTemp->r[0] = RegRetorno;
    ApTemp->p[1] = ApRetorno;
    cont++;
    ApTemp->pageNum = cont;
    ApTemp->p[0] = *Ap;
    *Ap = ApTemp;
    //save in file
  }
  saveAux(*Ap, 2*ORDEM);
}  /*Insercao*/

int Imprime2(Apontador p, int Nivel, int aux, int n)
{
  int i;
  if (p == NULL)
    return 0;
  if(Nivel == aux){
	  n++;
	printf("No: %d - ",p->pageNum);
  for (i = 0; i < p->n; i++){
	  if (p->p[i] !=NULL)
    printf("Apontador: %d - ", p->p[i]->pageNum);
    else
    printf("Apontador: null - ");
    printf("DOI: %s.\n", p->r[i].DOI);
   }
   printf("\n");
   return n;
 }else{
	aux++; 
	 for (i = 0; i <= p->n; i++)
	 Imprime2(p->p[i], Nivel, aux, n);
	 }
	return 0;   
     
}

void InsertPosFile(Registro Reg, Apontador *Ap)
{
  int Cresceu;
  Registro RegRetorno;
  Apontador ApRetorno;
  Apontador ApTemp;

  InsPosFile(Reg, *Ap, &Cresceu, &RegRetorno, &ApRetorno);
  if (Cresceu) { /* Se arvore cresce na altura pela raiz */
    ApTemp = (Apontador) malloc(sizeof(Pagina));
    ApTemp->n = 1;
    ApTemp->r[0] = RegRetorno;
    ApTemp->p[1] = ApRetorno;
    cont++;
    ApTemp->pageNum = cont;
    ApTemp->p[0] = *Ap;
    *Ap = ApTemp;
  }
}

void InsPosFile(Registro Reg, Apontador Ap, int *Cresceu, Registro *RegRetorno, Apontador *ApRetorno)
{
  Apontador ApTemp;
  Registro Aux;
  int i, j;

  if (Ap == NULL) //
  {
    *Cresceu = 1;
    *RegRetorno = Reg;
    *ApRetorno = NULL;
    return;
  }
  i = 1;
  while (i < Ap->n && (strcmp(Reg.DOI, Ap->r[i - 1].DOI)) > 0)
    i++;
  if ((strcmp(Reg.DOI, Ap->r[i - 1].DOI)) == 0)
  {
    printf("DOI já existente\n");
    *Cresceu = 0;
    return;
  }
  if ((strcmp(Reg.DOI, Ap->r[i - 1].DOI)) > 0)
    InsPosFile(Reg, Ap->p[i-1], Cresceu, RegRetorno, ApRetorno);
  else
    InsPosFile(Reg, Ap->p[i], Cresceu, RegRetorno, ApRetorno);
  if (!*Cresceu)
    return;
  if (Ap->n < 2*ORDEM)
  {  /* Verificando se a pagina tem espaco */
    InsereNaPagina(Ap, *RegRetorno, *ApRetorno);
    *Cresceu = 0;
    return;
  }
  /* Split: Pagina tem que ser dividida */
  ApTemp = (Apontador) malloc(sizeof(Pagina));
  ApTemp->n = 0;
  ApTemp->p[0] = NULL;
  cont++;
  ApTemp->pageNum = cont;
  
  if (i <= ORDEM + 1)
  {
    InsereNaPagina(ApTemp, Ap->r[2*ORDEM - 1], Ap->p[2*ORDEM]);
    Ap->n--;    
    InsereNaPagina(Ap, *RegRetorno, *ApRetorno);
  }
  else{
    InsereNaPagina(ApTemp, *RegRetorno, *ApRetorno);
    }
  for (j = ORDEM + 2; j <= 2*ORDEM; j++)
    InsereNaPagina(ApTemp, Ap->r[j - 1], Ap->p[j]);
    
  
  Ap->n = ORDEM;
  ApTemp->p[0] = Ap->p[ORDEM + 1];
  *RegRetorno = Ap->r[ORDEM];
  *ApRetorno = ApTemp;
 for (j = ORDEM; j < Ap->n+2; j++){
    Aux.rank = 0;
    Ap->r[j] = Aux;
	}
} 

void Pesquisa(Registro *x, Apontador Ap)
{
  int i;

  if (Ap == NULL)
  {
    printf("Erro: Registro nao existe\n");
    return;
  }
  i = 1;
  while (i < Ap->n && strcmp(x->DOI,  Ap->r[i - 1].DOI)>0)
    i++;
  if (strcmp(x->DOI,  Ap->r[i - 1].DOI) == 0)
  {
    *x = Ap->r[i - 1];
    return;
  }
  if (strcmp(x->DOI,  Ap->r[i - 1].DOI)<0)
    Pesquisa(x, Ap->p[i - 1]);
  else
    Pesquisa(x, Ap->p[i]);
} /* Pesquisa */

void Reconstitui(Apontador ApPag, Apontador ApPai, int PosPai, int *Diminuiu)
{
  Apontador Aux;
  int DispAux, j;

  if (PosPai < ApPai->n) {  /* Aux = Pagina a direita de ApPag */
    Aux = ApPai->p[PosPai + 1];
    DispAux = (Aux->n - ORDEM + 1) / 2;
    ApPag->r[ApPag->n] = ApPai->r[PosPai];
    ApPag->p[ApPag->n + 1] = Aux->p[0];
    ApPag->n++;
    if (DispAux > 0) {  /* Existe folga: transfere de Aux para ApPag */
      for (j = 1; j < DispAux; j++)
        InsereNaPagina(ApPag, Aux->r[j - 1], Aux->p[j]);
      ApPai->r[PosPai] = Aux->r[DispAux - 1];
      Aux->n -= DispAux;
      for (j = 0; j < Aux->n; j++)
        Aux->r[j] = Aux->r[j + DispAux];
      for (j = 0; j <= Aux->n; j++)
        Aux->p[j] = Aux->p[j + DispAux];
      *Diminuiu = 0;
    }
    else
    { /* Fusao: intercala Aux em ApPag e libera Aux */
      for (j = 1; j <= ORDEM; j++)
        InsereNaPagina(ApPag, Aux->r[j - 1], Aux->p[j]);
      free(Aux);
      for (j = PosPai + 1; j < ApPai->n; j++)
      {   /* Preenche vazio em ApPai */
        ApPai->r[j - 1] = ApPai->r[j];
        ApPai->p[j] = ApPai->p[j + 1];
      }
      ApPai->n--;
      if (ApPai->n >= ORDEM)
        *Diminuiu = 0;
    }
  }
  else
  { /* Aux = Pagina a esquerda de ApPag */
    Aux = ApPai->p[PosPai - 1];
    DispAux = (Aux->n - ORDEM + 1) / 2;
    for (j = ApPag->n; j >= 1; j--)
      ApPag->r[j] = ApPag->r[j - 1];
    ApPag->r[0] = ApPai->r[PosPai - 1];
    for (j = ApPag->n; j >= 0; j--)
      ApPag->p[j + 1] = ApPag->p[j];
    ApPag->n++;
    if (DispAux > 0) {  /* Existe folga: transfere de Aux para ApPag */
      for (j = 1; j < DispAux; j++)
        InsereNaPagina(ApPag, Aux->r[Aux->n - j], Aux->p[Aux->n - j + 1]);
      ApPag->p[0] = Aux->p[Aux->n - DispAux + 1];
      ApPai->r[PosPai - 1] = Aux->r[Aux->n - DispAux];
      Aux->n -= DispAux;
      *Diminuiu = 0;
    }
    else
    {  /* Fusao: intercala ApPag em Aux e libera ApPag */
      for (j = 1; j <= ORDEM; j++)
        InsereNaPagina(Aux, ApPag->r[j - 1], ApPag->p[j]);
      free(ApPag);
      ApPai->n--;
      if (ApPai->n >= ORDEM)
        *Diminuiu = 0;
    }
  }
} 
void Ret(char doi[], Apontador *Ap, int *Diminuiu)
{
  int Ind, j;
  Apontador WITH;
  Registro Reg;

  if (*Ap == NULL)
  {
    printf("DOI não encontrado.\n");
    *Diminuiu = 0;
    return;
  }
  WITH = *Ap;
  Ind = 1;
  while (Ind < WITH->n && strcmp(doi,WITH->r[Ind - 1].DOI) >0 )
    Ind++;
  if (strcmp(doi,WITH->r[Ind - 1].DOI) == 0)
  {
    strcpy(Reg.DOI, "Referencia_Auxiliar");
    Reg.rank = 0;
    WITH->r[Ind -1] = Reg;
    if (WITH->p[Ind - 1] == NULL) { 
      WITH->n--;
      *Diminuiu = WITH->n < ORDEM;
      for (j = Ind; j <= WITH->n; j++)
      {
        WITH->r[j - 1] = WITH->r[j];
        WITH->p[j] = WITH->p[j + 1];
      }
      return;
    }
    Antecessor(*Ap, Ind, WITH->p[Ind - 1], Diminuiu);
    if (*Diminuiu)
      Reconstitui(WITH->p[Ind - 1], *Ap, Ind - 1, Diminuiu);
    return;
  }
  if (strcmp(doi,WITH->r[Ind - 1].DOI) > 0)
    Ind++;
  Ret(doi, &WITH->p[Ind - 1], Diminuiu);
  if (*Diminuiu)
    Reconstitui(WITH->p[Ind - 1], *Ap, Ind - 1, Diminuiu);
}  
void Retira(char doi[], Apontador *Ap)
{
  int Diminuiu;
  Apontador Aux;

  Ret(doi, Ap, &Diminuiu);
  if (Diminuiu && (*Ap)->n == 0) { 
    Aux = *Ap;
    *Ap = Aux->p[0];
    free(Aux);
    
  }
  
}
void recuperarReg(Apontador *arv, node *LISTA)
{

    FILE* arq;
    Registro Reg[2*ORDEM];
    node *tmp;
    int i=0,j=0, tam;
        arq = fopen(namefile,"rb");
        if (arq == NULL)
            exit(1);
       fseek(arq, 0, SEEK_END);
       tam = ftell(arq);
       rewind(arq);
       fclose(arq);
       arq = fopen(namefile,"rb");
        if (arq == NULL)
            exit(1);
        while (j*(2*ORDEM*sizeof(Registro)) < tam){
			fseek(arq, j*(2*ORDEM*sizeof(Registro)), SEEK_SET);
			fread(Reg, 2*ORDEM*sizeof(Registro),1,arq);
			
        for(i = 0; i < 2*ORDEM; i++){
           if (strcmp(Reg[i].DOI,"Referencia_Auxiliar")!=0)
           execut(Reg[i], LISTA);
        }
    j++;
    }
    fclose(arq);
    tmp = LISTA->prox;
    while( tmp != NULL){
		InsertPosFile(tmp->info, arv);
		tmp = tmp->prox;
	}
	free(tmp);
	free(LISTA);
    }

void saveAux(Apontador p, int Nivel)
{
  int i,j;

  if (p == NULL)
    return;
  for (i = 0; i < p->n; i++)
    salvar(p, p->r);
  for (j = 0; j <= p->n; j++)
    saveAux(p->p[j], Nivel + 1);
}
//Função para escrever no arquivo "_arquivo.dat" o registro adicionado.
void salvar(Apontador pagina, Registro Reg[])
{
    //Declara um ponteiro para arquivo chamado "arq".
    FILE* arq;
    //Se o arquivo não existir inicialmente, ele é criado. 
    if (!file_exists(namefile)){
        arq = fopen(namefile,"wb");
        //Caso, no momento de criar o arquivo, ocorra algum erro, o programa é encerrado.
        if (arq == NULL)
            exit(1);
        //Caso contrário, é colocado um ponteiro na posição onde
        //deve ser inserido o novo registro.
        fseek(arq, pagina->pageNum*(2*ORDEM*sizeof(Registro)), SEEK_SET);
        fwrite(Reg,(2*ORDEM*sizeof(Registro)),1,arq);
        //O arquivo é fechado.
        fclose(arq);
    }
    //Caso o arquivo já exista, apenas ocorre a escrita do registro.
    else{
        arq = fopen(namefile,"r+b");
        if (arq == NULL)
            exit(1);
        fseek(arq, pagina->pageNum*(2*ORDEM*sizeof(Registro)), SEEK_SET);
        fwrite(Reg, (2*ORDEM*sizeof(Registro)),1,arq);
        fclose(arq);
        }
    }

//############################### //Estrutura 2 lista encadeada
void insereInicio(Registro info, node *LISTA)
{
	node *novo=(node *) malloc(sizeof(node));
	node *tmp = busca(info, LISTA);
	if(LISTA->prox == NULL){
		novo->info = info;
		novo->prox = LISTA->prox;
		LISTA->prox = novo;
	}else{	
	novo->prox = tmp->prox;
	novo->info = info;
	tmp->prox = novo;
}
}

node *busca(Registro info, node *LISTA)
{
		node *atual,*antNode;
		atual = LISTA->prox;
		antNode = LISTA;
		while(atual != NULL && info.rank > atual->info.rank){
			antNode = atual;
			atual = atual->prox;
		}
		return antNode;
	}
void execut(Registro info, node *LISTA)
{
	insereInicio(info, LISTA);		
}
