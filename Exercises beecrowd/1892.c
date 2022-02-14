#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char al[15];
}ALUNO;

long long merge(ALUNO *arr,ALUNO *temp,int l,int m,int r){
 int i,j,k;
 long long c;
 
    for(i = l;i <= m;i++){
        strcpy(temp[i].al,arr[i].al);
    }
    for(j = m + 1;j <= r;j++){
        strcpy(temp[r + m +1-j].al,arr[j].al);
    }

    i = l;
    j = r;
    c = 0; 
 
    for(k = l;k <= r;k++){
        if(strcmp(temp[i].al,temp[j].al) <= 0){
            strcpy(arr[k].al,temp[i].al);
            i = i + 1;
        }else{
            strcpy(arr[k].al,temp[j].al);
            j = j - 1;
            c = c + (m - i + 1);
        }
    }
    return c;
}

long long mergeSort(ALUNO *arr,ALUNO *temp, int l,int r){
    int mid;
    if(l >= r){
        return 0;
    }else{
        mid = (l + r)/2;
        return mergeSort(arr,temp,l, mid) + mergeSort(arr,temp, mid + 1, r) + merge(arr,temp, l, mid, r);
    } 
}

int main(){  
	int n, i;
    ALUNO *aluno;
	ALUNO *aux;
    while (scanf("%d", &n) != EOF){
        i = 0;
        aluno = (ALUNO *)malloc(n*sizeof(ALUNO));
        aux = (ALUNO *)malloc(n*sizeof(ALUNO));
		while(n--){
            scanf("%s", aluno[i++].al);
        }
		printf("%lld\n",mergeSort(aluno,aux, 0, i - 1));
        free(aluno);
        free(aux);
	}
	return 0;
}