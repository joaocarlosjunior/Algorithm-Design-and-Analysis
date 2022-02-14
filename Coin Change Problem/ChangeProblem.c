#include <stdio.h>
#include <stdlib.h>
// função que recebe um vetor com as moedas disponíveis MOEDAS, o valor de troco VALOR,
// e  o número de moedas disponíveis TAM
// essa função deve retornar o número mínimo de moedas,
// de acordo com a solução com Programação Dinamica.
void numeroMinimo(int *moedas,int valor,int tam){
    int i,j;
    int valores[tam+1][valor+1];
    int valorMin;
    //Caso base
    //Quando valor do troco = 0
       for(i = 0; i < tam + 1;i++){
            valores[i][0] = 0;
        }
        //Iterando no loop externo para possíveis valores do troco entre 1 a TAM+1
        //Uma vez que nossa solução final para o troco pode depender de qualquer um desses valores
        for(i = 1; i < tam + 1;i++){
            // O loop interno denota o índice da matriz de moedas.
            for(j = 0;j < valor+1;j++){ 
                if (moedas[i-1] > j){
                    valores[i][j] = valores[i-1][j];
                }else{
                    valorMin = 1 + valores[i][j - moedas[i-1]];
                    valores[i][j]=valorMin;
                }
            }
        }
    printf("%d",valores[tam][valor]);
}
int main(){
    int moedas[] = {1,2,4,5};
    int tam = (int)(sizeof(moedas) / sizeof(moedas[0]));
    int valor;
    printf("Digite o valor do troco:");
    scanf("%d",&valor);
    numeroMinimo(moedas,valor,tam);
    return 0;
}
