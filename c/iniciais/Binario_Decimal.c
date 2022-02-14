#include <stdlib.h>
#include <stdio.h>

float conversao(int v){
    int cont=0,d=0;
    int A[4];
    float aux;
    aux=v;

    for(int i=0;i<5;i++){
        d=1;
        for(int y=i+1;y<5;y++){
            d=d*10;
        }

        if(v<d)
            A[i]=0;
        
        if(v>=d){
            A[i]=1;
            v=v-d;
        }
            
        printf("\nA[i] %d = %d\n",i,A[i]);
    }

    //for(int i=0;i<5;i++){
        //printf("\n I %d -> A[%d]\n",i,A[i]);
         //if(cont==0 && A[i] != 0){
            // cont = 5-i;
             //break;
        // }
                  
    //}
    printf("\n O numero tem %d digitos\n",cont);

    aux=0;
    for(int y=4;y>-1;y--){

            aux=(A[y] + aux)/2;

        printf("\n I %d -> A[%d]= %.5f\n",y,A[y], aux);
    }
    
    return aux;
}


int main(void){
    int vb=0;
    float vd=0;

    printf("\nDigite o valor em binario:\n");
    scanf("%d",&vb);

    vd=conversao(vb);

    printf("\n(. %d) na base 2 ---> (%.5f) na base 10.\n",vb,vd);

    return 0;
}