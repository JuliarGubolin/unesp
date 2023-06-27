#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//Atributos do jogador
typedef struct jogador{

    char classe[30];
    char raca[30];
    int level;
	int vida;
	int mana_atual;
	
	int ataque;
	int mana_total;

	int mao_direita;
	int mao_esquerda;
	int armadura;
}player;

//Operações com o jogador
player* criar(void);//Cria um novo jogador 
void defender(player *atacado, player *atacante);//não possui retorno
int atacar(player *atacado, player *atacante, bool magia);//Retorna a nova mana caso tenha usado magia
void imprimir(player *player);//Imprime os dados dos jogadores

//Main
int main(void){
    player *j1, *j2;
    int mana;

    printf("--Criacao de jogadores--\nJogador 1\n");
    j1 = criar();
    printf("Jogador 2\n");
    j2 = criar();
    imprimir(j1);
    imprimir(j2);

    mana = atacar(j1, j2, true);
}
//IMPLEMENTAÇÕES
player* criar(){
    player *aux;
    aux = (player*)malloc(sizeof(player));
    int escudo, arma;
    printf("Qual a raca? "); 
    scanf("%s", aux->raca);
    printf("Qual a classe? "); 
    scanf("%s", aux->classe);
    printf("Qual a qtd de ataque? "); 
    scanf("%d", &aux->ataque);
    printf("Qual a qtd de armadura? "); 
    scanf("%d", &aux->armadura);
    printf("Qual a qtd de vida? "); 
    scanf("%d", &aux->vida);
    printf("Qual a qtd de mana? "); 
    scanf("%d", &aux->mana_total);
    printf("Qual o nivel? "); 
    scanf("%d", &aux->level);
    printf("Possui escudo? <1>sim <2>nao "); 
    scanf("%d", &escudo);
    if(escudo == 1)aux->mao_esquerda = 1;
    else aux->mao_esquerda = 0;
    printf("Possui arma? <1>sim <2>nao ");
    scanf("%d", &arma);
    if(arma == 1) aux->mao_direita = 1;
    else aux->mao_esquerda = 0;
    aux->mana_atual = aux->mana_total;
    return aux;
}
//Comando para contabilizar as perdas após o ataque e se defender
void defender(player *atacado, player *atacante){
    int val;
    //Caso ele tenha um escudo, o dano recebido diminui
    if((atacado->mao_esquerda == 1 && atacante->mao_direita == 1) || (atacado->mao_esquerda == 0 && atacante->mao_direita == 0)){
        atacado->armadura = atacado->armadura -2;
        atacado->vida = atacado->vida -2;
    }
    //Senão, ele recebe o dano total 
    else if(atacado->mao_esquerda == 0 && atacante->mao_direita == 1){
        atacado->armadura = atacado->armadura - 3;
        atacado->vida = atacado->vida - 3;
    }
    else if(atacado->mao_esquerda == 1 && atacante->mao_direita == 0){
        atacado->armadura = atacado->armadura - 1;
        atacado->vida = atacado->vida - 1;
    }
    printf("Jogador atacado esta com %d de armadura e %d de vida!!", atacado->armadura, atacado->vida);
}
//Operação para atacar um personagem
int atacar(player *atacante, player *atacado, bool magia){
    int mana_nova;
    //Caso o ataque exija mana, ela diminui
    if(magia == true){
        mana_nova = atacante->mana_atual-1;
    }
    defender(atacado, atacante);
    return mana_nova;
}
//Mostra os dados do jogador escolhido
void imprimir(player *player){

    printf("---DADOS DO JOGADOR---\n");
    printf("Classe: %s\n", player->classe);
    printf("Raca: %s\n", player->raca);
    printf("Ataque: %d\n",player->ataque);
    printf("Armadura: %d\n", player->armadura);
    printf("Vida: %d\n",player->vida);
    printf("ManaTotal: %d\n", player->mana_total);
    printf("Level: %d\n", player->level);
    printf("Escudo: %d\n", player->mao_esquerda);
}