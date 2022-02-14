#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include"ListaCircularOrdenada.h"

void limpa_terminal();
int main(void){

    setlocale(LC_ALL, "portuguese");
    p *C = criar_ponteiros();
    int op, valor, aux=0, p=0;
    //Fazer menu
    while(op != 4){
        printf("----LISTA CIRCULAR----\n");
        printf("1 - Inserir\n2 - Remover\n3 - Imprimir e verificar a circularidade\n4 - Sair\n");
        printf("----------------------\n");
        printf("-> ");
        scanf("%d", &op);
        switch (op){
            case 1:
                limpa_terminal();
                printf("--INSERIR--\n");
                printf("Valor para inserir: ");
                scanf("%d", &valor);
                inserir(C, valor);
                break;
            case 2: 
                limpa_terminal();
                if(C->ini == NULL){
                    printf("Lista vazia.\n");
                }
                else{
                    printf("--REMOVER--\n");
                    printf("Valor para remover: ");
                    scanf("%d", &valor);
                    remover(C, valor);
                }
                break;
            case 3:
                limpa_terminal();
                if(C->ini != NULL){
                    imprimir(C);
                    printf("C->fim->info: %d\n",C->fim->info);
                    printf("C->ini->info: %d\n",C->ini->info);
                    printf("C->fim->prox->info (Início): %d\n",C->fim->prox->info);
                    printf("C->ini->ant->info (Fim): %d\n",C->ini->ant->info);
                }else{
                    printf("Lista Circular vazia.\n");
                }
                break;
            case 4:
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