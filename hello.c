#include <stdio.h>
#include <math.h>
#include <string.h>
int main(){

    char data[100];
    int data1[100],data2[100];
    int dl,r,i=0,j=0,k=0,z,c;
    printf("\n Enter the dataword: "); //taking input in string
    scanf("%s",data);
    dl=strlen(data); //length of the input string
    while(1){ //finding number of parity bits
        if(pow(2,i)>=dl+i+1)
        break;
        i++;
    }
    r=i; //storing number of parity bits into r variable
    printf("\n No of redundant bits: %d \n",r);
    for(i=0;i<dl;i++){ //conversion of string data into integer
        data1[i]=data[i]-48; //data1 array is used to store only integer data
    }
    for(i=0;i<r;i++){ //initialising parity bits' positions with some value (say 999) in data2 array
        z=pow(2,i);
        data2[z]=999; //data2 array is used to store data+parity bits
    }
    for(i=dl+r;i>=1;i--){ //this loop is used to place the data bits and parity bits at fixed positions
        if(data2[i]!=999){
            data2[i]=data1[j]; //if it's not a parity bit, store the data bit in reverse order
            j++;
        }
    }
    for(i=0;i<r;i++){ //outer loop is used to find the values for each parity bit
        z=pow(2,i); //finding position of each parity bit
        c=0; //initializing counter c
        for(j=z;j<=dl+r;j=z+k){ //inner loop is used to add data bits related to each parity bit
            for(k=j;k<z+j;k++){ //this loop is for part by part parity calculation
                if(k<=dl+r){
                    if(data2[k]!=999){ //if k is not a parity bit
                        c=c+data2[k]; //add the value of that position with counter c
                    }
                }
            }
        }
        data2[z]=c%2;//parity bit value
    }
    printf("\n The codeword is: ");
    j=0;
    for(i=dl+r;i>=1;i--){
        printf("%d",data2[i]);
    }
    return 0;
}