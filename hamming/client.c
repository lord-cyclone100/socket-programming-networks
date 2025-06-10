#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){

    char store[100],data[100];
    int r=0;
    printf("Enter the data : ");
    scanf("%s",store);

    int m = strlen(store);

    while(1){
        int res = (int)pow(2,r);
        if(res >= (m+r+1)){
            break;
        }
        r++;
    }

    // printf("%d",r);
    int total = m+r;
    int j = 0;

    for(int i=total;i>=1;i--){
        if((i & (i - 1)) == 0){
            data[i] = 'p';
        }
        else{
            data[i] = store[j++];
        }
    }

    printf("%s",data);
    return 0;
}

