#include <stdio.h>
#include <stdlib.h>

int main(){
    int t,i,cont = 0;
    int populacaoA,populacaoB;
    float g1,g2;
    scanf("%d",&t);
    for(i = 0;i < t;i++){
        cont = 0;
        scanf("%d %d %f %f",&populacaoA,&populacaoB,&g1,&g2);
        while(populacaoA <= populacaoB &&cont <101){
            populacaoA = populacaoA + (populacaoA * (g1 / 100));
            populacaoB = populacaoB + (populacaoB * (g2 / 100));
            cont++;
        }
            if(cont < 100){
                printf("%d anos.\n",cont);
            }else{
                printf("Mais de 1 seculo.\n");
            }
    }
 return 0;
}