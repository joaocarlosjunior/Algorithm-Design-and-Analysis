#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    double valor;
    double peso;
    double divVP;//divisão de valor pelo peso
    double frac;//Fracionária
}ITEM;

void merge(ITEM *vetor, int inicio, int meio, int fim){
    int i = inicio;
    int j = meio + 1;
    int k = 0;
    int size = fim - inicio + 1;
    ITEM *aux = (ITEM *)malloc(size * sizeof(vetor[0]));

    while(i <= meio && j <= fim){
        if(vetor[i].divVP < vetor[j].divVP){
            aux[k++] = vetor[i++];
        }else{
            aux[k++] = vetor[j++];
        }
    }
        
    while(i <= meio){
        aux[k++] = vetor[i++];
    }

    while(j <= fim){
        aux[k++] = vetor[j++];
    }
    k = 0;
    for(i = inicio;i <= fim; i++){
        vetor[i] = aux[k++];
    }
}

void mergeSort(ITEM *vetor, int inicio, int fim){
    if (inicio < fim){
        int meio = (fim + inicio) / 2;
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio + 1, fim);
        merge(vetor, inicio, meio, fim);
    }
}

double knapsack(ITEM *queijo,int n,double capac){
    int i,base;
    double pesoAtual = 0;//peso atual da "mochila"
    double parteFrac;
    double blocoTotal = 0;
    // Laço de repetição para todos os queijo
    for(i = 0; i < n; i++){
        //Se adicionar o queijo e não estourar a capacidade, adicione-o completamente.
        if(queijo[i].valor + pesoAtual < capac){
            pesoAtual = pesoAtual + queijo[i].valor;
            blocoTotal = blocoTotal + queijo[i].peso;
            queijo[i].frac = 1;
        }
        else{
            //Se não podemos adicionar o queijo atual, adicione a parte fracionária.
            queijo[i].frac = (capac - pesoAtual)/queijo[i].valor;
            blocoTotal = blocoTotal + (queijo[i].peso * queijo[i].frac);
            pesoAtual = queijo[i].frac * queijo[i].valor;
            break;
        }
    }
    return blocoTotal;
}
 
int main() {
    int qLoja,orcJoao;
    int i;
    
        scanf("%d",&qLoja);    
        scanf("%d",&orcJoao);  
    
        ITEM *queijo = (ITEM *)malloc(qLoja*sizeof(ITEM));
        
        for(i = 0;i < qLoja;i++){
            scanf("%lf",&queijo[i].peso);
        }
        
        for(i = 0;i < qLoja;i++){
            scanf("%lf",&queijo[i].valor);
        }
        
        for(i = 0;i < qLoja;i++){
            queijo[i].divVP = queijo[i].valor / queijo[i].peso;
        }
        mergeSort(queijo, 0, qLoja - 1);//Ordenar de acordo com valor especifico
        double blocoTotal = knapsack(queijo,qLoja,orcJoao);
        int base = (-1 + sqrt(1 + (8 * blocoTotal))) / 2;
        printf("%d\n",base);
        free(queijo);
    
   return 0;
}