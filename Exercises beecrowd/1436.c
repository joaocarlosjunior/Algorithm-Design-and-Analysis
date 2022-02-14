#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int t,i,j;
    int result;
    int n;
    scanf("%d",&t);
    for(i = 0;i < t;i++){
        scanf("%d",&n);
        int jogadores[n];
        for(j = 0;j < n;j++){
            scanf("%d",&jogadores[j]);
        }
        result = ceil(n/2);
        printf("Case %d: %d\n",i+1,jogadores[result]);
    }
    return 0;
}