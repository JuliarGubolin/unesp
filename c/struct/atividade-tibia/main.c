#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	char tipo[30];
	char nome[30];
	int poder;
} arma;

typedef struct
{
	// informacoes basicas
    char nome[30];
	char classe[30];
	int level;
	int vida;

	//skills
	int ataque;
	int defesa;

	//equipamento
	arma *mao_direita; // arma
	arma *mao_esquerda; // escudo
} personagem;

personagem* criar_personagem(arma *esquerda, arma *direita);
arma* criar_arma(void);
int atacar(personagem *agressor, personagem *agredido);// (dano + atk) - (def + escudo)
void imprime(personagem *z);



int main(void)
{
    arma *arma1, *arma2, *escudo1, *escudo2;
    personagem *personagem1, *personagem2;
    printf("Bem vindo! Primeiro, escolha os equipamentos do seu personagem 1: ");
    printf("\n---Criando a primeira arma---\n");
    arma1 = criar_arma();
    printf("\n---Criando o primeiro escudo---\n");
    escudo1 = criar_arma();
    printf("Agora, defina os dados de seu personagem: ");
    criar_personagem(arma1, escudo1);

    system("cls");
    printf("Agora, escreva os equipamentos do personagem 2");
    printf("\n---Criando a segunda arma---\n");
    arma2 = criar_arma();
    printf("\n---Criando o segundo escudo---\n");
    escudo2 = criar_arma();
    printf("Agora, defina os dados de seu personagem: ");
    criar_personagem(arma1, escudo2);
    system("cls");

    printf("Vamos fazer eles brigarem agora!");

    imprime(personagem1);
    imprime(personagem2);

    atacar(personagem1, personagem2);

    imprime(personagem1);
    imprime(personagem2);


	return 0;
}

int atacar(personagem *agressor, personagem *agredido)
{
    int danofinal=0;
    danofinal = (agressor->ataque + agressor->mao_direita->poder) - (agredido->defesa + agressor->mao_esquerda->poder);
    agredido->vida = agredido->vida - danofinal;
}

personagem* criar_personagem(arma *esquerda, arma *direita)
{
    personagem *aux;
    aux = (personagem*) malloc(sizeof(personagem));
    //dados do personagem
    fflush(stdin);
    printf("\nDigite o nome do seu personagem: ");
    scanf("%[^\n]s", aux->nome);

    fflush(stdin);
    printf("Digite a classe do seu personagem: ");
    scanf("%[^\n]s", aux->classe);

    printf("Digite a vida do seu personagem: ");
    scanf("%d", &aux->vida);

    printf("Digite o nivel do seu personagem: ");
    scanf("%d", &aux->level);

    printf("Digite o ataque do seu personagem: ");
    scanf("%d", &aux->ataque);

    printf("Digite a defesa do seu personagem: ");
    scanf("%d", & aux->defesa);

    aux->mao_esquerda = esquerda;
    aux->mao_direita = direita;

    printf("\nPersonagem criado!");
    return aux;

}

arma* criar_arma(void)
{
    arma *aux;
    aux = (arma*) malloc(sizeof(arma));
    //dados da arma
    fflush(stdin);
    printf("Digite o tipo da sua arma: ");
    scanf("%[^\n]s", aux->tipo);
    fflush(stdin);
    printf("Digite o nome da sua arma: ");
    scanf("%[^\n]s", aux->nome);
    printf("Digite o poder da sua arma: ");
    scanf("%d", &aux->poder);
    printf("Arma criada!\n\n");
    return aux;
}

void imprime(personagem *z)
{
    printf("\nStatus do personagem: ");
    printf("\nNome: %s", z->nome);
    printf("\nVida: %d", z->vida);
    printf("\nAtaque: %d", z->ataque);
    printf("\nDefesa: %d", z->defesa);
}
