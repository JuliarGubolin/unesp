//Inserção das bibliotecas
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
//Estrutura para a arma e escudo
typedef struct {
	char tipo[30];
	char nome[30];
	int poder;
} arma;
//Estrutura para a criação do personagem
typedef struct {
	//Informações básicas
	char nome[30];
	char classe[30];
	int level;
	int vida;
	
	//Skills
	int ataque;
	int defesa;
	
	//Equipamento
	arma *mao_direita; // arma
	arma *mao_esquerda; // escudo
} personagem;

//Declaração das funções
personagem* criar_personagem(arma *direita, arma *esquerda);
arma* criar_arma(void);
int batalha(personagem *agressor, personagem *agredido);// Dano_recebido: (dano + atk) - (def + escudo)
void imprimir(personagem *p);
void limpa_terminal();

//Função Principal
int main(void){
	//Função para utilização dos acentos em português
    setlocale(LC_ALL,"portuguese");
    //Declaração de algumas variáveis que serão utilizadas
    personagem *j1, *j2;
    arma *left, *right;
    int dano, op, cont=0, chose;
    //Menu para inicio do jogo
    do{
        printf("---------------\n");
        printf("1 - Crie dois jogadores\n2 - Batalhe!\n3 - Imprima os dados dos personagens\n4 - Sair\n");
        printf("---------------\n");
        printf("-> ");
        scanf("%d", &op);
        switch(op){
            //Opção 1: cria dois personagens para jogar
            case 1:
                //Verificação: caso os personagens já tenham sido criados
                limpa_terminal();
                if(cont >= 1){
                    printf("Já existem personagem criados!\n");
                    break;
                }
                limpa_terminal();
                printf("Criação de ESCUDO jogador 1.\n");
                left = criar_arma();
                limpa_terminal();
                printf("Criação de ARMA jogador 1.\n");
                right = criar_arma();
                limpa_terminal();
                printf("Criação de PERSONAGEM jogador 1.\n");
                j1 = criar_personagem(right, left);
                limpa_terminal();
                printf("Criação jogador 1 concluída!\n");
                printf("Criação de ESCUDO jogador 2.\n");
                left = criar_arma();
                limpa_terminal();
                printf("Criação de ARMA jogador 2.\n");
                right = criar_arma();
                limpa_terminal();
                printf("Criação de PERSONAGEM jogador 2.\n");
                j2 = criar_personagem(right, left);
                printf("\nCriação jogador 2 concluída!\n");
                cont++;
                break;
            //Opção 2: inicia a batalha
            case 2:
                limpa_terminal();
                //Verificação caso os personagens não tenham sido criados
                if(cont == 0){
                    printf("Crie os personagens antes de iniciar!\n");
                }
                else{
                    printf("Qual o jogador agressor? <1>J1 - %s <2>J2 - %s: ", j1->nome, j2->nome);
                    scanf("%d", &chose);
                    if(chose == 1){
                        dano = batalha(j1, j2);
                        //Verificação: caso o jogador agredido morra, o programa é encerrado para criação de novos
                        //personagens jogáveis
                        if(dano >= j2->vida){
                            printf("\nJogador agredido MORTO!! Jogador agressor vence!\n");
                            return 0;
                        }
                        else{
                            printf("\nPersonagem agredido recebeu %d de dano!!\n", dano);
                        }
                    }
                    else if(chose == 2){
                        dano = batalha(j2, j1);
                        if(dano >= j1->vida){
                            printf("\nJogador agredido MORTO!! Jogador agressor vence!\n");
                            return 0;
                        }
                        else{
                            printf("\nPersonagem agredido recebeu %d de dano!!\n", dano);
                        }
                    }
                    else{
                        limpa_terminal();
                        printf("Opção Inválida.\n");
                    }
                }
                break;
            //Opção 3: Mostra os dados dos personagens criados
            case 3:
                limpa_terminal();
                //Verificação caso os personagens não tenham sido criados
                if(cont == 0){
                    printf("Crie os personagens para mostrar seus dados!\n");
                }
                else{
                    imprimir(j1);
                    imprimir(j2);
                }
                break;
            //Opção 4: Fecha o programa
            case 4:
                limpa_terminal();
                printf("Programa encerrado.\n");
                break;
            //Verificação: caso 'op' não seja um valor válido
            default:
                limpa_terminal();
                printf("Opção Inválida. Leia novamente o menu.\n");
                break;
        }
    }while(op != 4);
	return 0;
}
//Imprime todos os dados do personagem. Não possui retorno.
void imprimir(personagem *p){
    printf("Nome: %s\n" ,p->nome);
    printf("Classe: %s\n", p->classe);
    printf("Level: %d\n" ,p->level);
    printf("Vida: %d\n", p->vida);
    printf("Ataque: %d\n" ,p->ataque);
    printf("Defesa: %d\n", p->defesa);
    printf("--ARMA--\n");
    printf("Nome: %s\n" ,p->mao_direita->nome);
    printf("Tipo: %s\n", p->mao_direita->tipo);
    printf("Poder: %d\n" ,p->mao_direita->poder);
    printf("--ESCUDO--\n");
    printf("Nome: %s\n" ,p->mao_esquerda->nome);
    printf("Tipo: %s\n", p->mao_esquerda->tipo);
    printf("Poder: %d\n" ,p->mao_esquerda->poder);
}
//Receba os dados inerentes a arma ou escudo. Retorna o item criado.
arma* criar_arma(void){
    arma *aux;
    aux = (arma*)malloc(sizeof(arma));
    printf("Tipo: ");
    scanf("%s", aux->tipo);
    printf("Nome: ");
    scanf("%s", aux->nome);
    printf("Poder: ");
    scanf("%d", &aux->poder);
    return aux;
}
//Criação de personagem. Recebe a arma e o escudo e retorna o personagem criado.
personagem* criar_personagem(arma *direita, arma *esquerda){
    personagem *aux;
    aux = (personagem*)malloc(sizeof(personagem));
    printf("Nome: ");
    scanf("%s", aux->nome);
    printf("\nClasse: ");
    scanf("%s", aux->classe);
    printf("\nLevel: ");
    scanf("%d", &aux->level);
    printf("\nVida: ");
    scanf("%d", &aux->vida);
    printf("\nAtaque: ");
    scanf("%d", &aux->ataque);
    printf("\nDefesa: ");
    scanf("%d", &aux->defesa);
    aux->mao_direita = direita;
    aux->mao_esquerda = esquerda;
 
    return aux;
}
//Inicia a batalha entre os dois jogadores criados. Retorna o dano recebido pelo agredido
int batalha(personagem *agressor, personagem *agredido){

    //Mostra os dados dos personagem no início da batalha
    printf("---INÍCIO DA BATALHA---\n");
    printf("--> Dados do agressor\n");
    printf("Level: %d\n" ,agressor->level);
    printf("Vida: %d\n", agressor->vida);
    printf("Ataque: %d\n" ,agressor->ataque);
    printf("Defesa: %d\n", agressor->defesa);
    printf("--> Dados do agredido\n");
    printf("Level: %d\n" ,agredido->level);
    printf("Vida: %d\n", agredido->vida);
    printf("Ataque: %d\n" ,agredido->ataque);
    printf("Defesa: %d\n", agredido->defesa);
    //Computa o dano recebido pelo personagem agredido
    int dano_recebido = (agressor->mao_direita->poder + agressor->ataque) - (agredido->defesa + agredido->mao_esquerda->poder);
    //Caso o dano tenha sido 0 ou menor que isso, ele recebe 0 para que o agredido não receba vida
    if(dano_recebido <=0){
        dano_recebido = 0;
    }
    agredido->vida = (agredido->vida) - (dano_recebido);
    //Caso o dano tenha sido maior ou igual a vida do agredido, é declarado vitória ao agressor
    if(agredido->vida <= 0){
        dano_recebido = agredido->vida;
    }
    //Mostra os dados dos personagem no fim da batalha
    printf("---RESULTADO DA BATALHA---\n");
    printf("--> STATUS agressor\n");
    printf("Level: %d\n" ,agressor->level);
    printf("Vida: %d\n", agressor->vida);
    printf("Ataque: %d\n" ,agressor->ataque);
    printf("Defesa: %d\n", agressor->defesa);
    printf("--> STATUS agredido\n");
    printf("Level: %d\n" ,agredido->level);
    printf("Vida: %d\n", agredido->vida);
    printf("Ataque: %d\n" ,agredido->ataque);
    printf("Defesa: %d\n", agredido->defesa);

    return (dano_recebido);
}
//Função que limpa o cmd
void limpa_terminal(){
    system("clear");
}