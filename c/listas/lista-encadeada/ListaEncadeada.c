#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include"Lista.h"

void limpa_terminal();
int main(void){

    setlocale(LC_ALL, "portuguese");
    lista *L = criar_lista();
    int op, valor, aux=0, p=0;
    //Fazer menu
    while(op != 6){
        printf("-------------\n");
        printf("1 - Inserir\n2 - Remover\n3 - Mostrar\n4 - Recuperar\n5 - Localizar\n6 - Sair\n");
        printf("-------------\n");
        printf("-> ");
        scanf("%d", &op);
        switch (op){
            case 1:
                limpa_terminal();
                printf("Valor para inserir: ");
                scanf("%d", &valor);
                L = inserir(L, valor);
                break;
            case 2: 
                limpa_terminal();
                if(L == NULL){
                    printf("Lista vazia.\n");
                }else{
                    printf("Valor para remover: ");
                    scanf("%d", &valor);
                    L = remover(L, valor);
                }
                break;
            case 3:
                limpa_terminal();
                imprimir(L);
                break;
            case 4:
                limpa_terminal();
                if(L == NULL){
                    printf("Lista vazia.\n");
                }else{
                    printf("Posição para recuperar (Primeira posição = 0): ");
                    scanf("%d", &p);
                    L = recuperar(L, p);
                }
                break;
            case 5:
                limpa_terminal();
                if(L == NULL){
                    printf("Lista vazia.\n");
                }else{
                    printf("Valor para localizar: ");
                    scanf("%d", &valor);
                    aux = localizar(L, valor);
                    printf("Posição do elemento: %d\n", aux);
                }
                break;
            case 6:
                limpa_terminal();
                printf("Saindo...\n");
                break;
            default:
                limpa_terminal();
                printf("Opção inválida. Leia novamente o menu\n");
                break;
        }
    }
    return 0;
}
void limpa_terminal(){
    system("clear");
}