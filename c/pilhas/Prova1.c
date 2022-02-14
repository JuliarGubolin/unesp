//A função empty, tanto da fila quanto da pilha retornam true se
//a pilha e/ou fila for vazia e false se a pilha e/ou fila possuir elementos.
fila* inverte_fila(fila *Q, pilha *S){
    int aux;
    if(empty(Q) != true){
        while(empty(Q) != false){
            aux = remove(Q);
            S = push(S,aux);
        }
    }
    else{
        printf("Fila vazia.\n");
    }
    if(empty(S) != true){
        while(empty(S) != false){
            aux = pop(S);
            Q = insert(Q,aux);
        }
    }else{
        printf("Pilha vazia.\n");
    }
    return Q;
}