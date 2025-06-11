#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){

    char store[100],data[100];
    int r=0,temp;
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
    data[total+1] = '\0';

    printf("%s\n",data+1);



    for(int i=0;i<r;i++){
        int pos = (int)pow(2,i);
        int sum = 0;
        for(int j=pos;j<=total;j++){
            if(data[j]!='p'){
                temp = pos & j;
                if(temp != 0 && data[j] == '1'){
                    sum++;
                }
            }
        }
        data[pos] = (sum%2) + 48;
    }

    printf("%s\n",data+1);


    return 0;
}

