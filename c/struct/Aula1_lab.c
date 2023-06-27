//Ponteiros para estruturas e TAD
#include<stdio.h>
#include<stdlib.h>
//Não precisa do nome "Aluno"
//TAD aluno
typedef struct Aluno{
    char nome[20];//20 bites
    int nota;//4 bites
}aluno;

//Operações
aluno* cadastro(void);
void imprime(aluno *p);

//Ponteiro: armazena um link para outra variável
int main(void){
    /*aluno *p;
    aluno x;
    //Salva o endereço de memória da struct (aluno)
    p = &x;
    //Devemos usar -> e não '.'
    p->nota = 10;*/
    aluno *aluno1, *aluno2;
    printf("Digite as informações do aluno 1\n");
    aluno1 = cadastro();
    aluno2 = cadastro();

    printf("\nAluno 1: \n");
    imprime(aluno1);
    printf("\nAluno 2: \n");
    imprime(aluno2);

    return 0;
}

//Implementação das operações
aluno* cadastro(void){
    aluno *aux;
    //Declara uma variável sem dar um NOME 
    aux = /*para que ele saiba o tipo*/(aluno*)malloc(/*tamanho*/sizeof(aluno));
    printf("Digite o nome do aluno: ");
    scanf("%s", aux->nome);
    printf("Digite a nota do aluno: ");
    scanf("%d", &aux->nota);
    return aux;
}
void imprime(aluno *p){
    printf("Nome: %s\n" ,p->nome);
    printf("Nota: %d\n", p->nota);
}
