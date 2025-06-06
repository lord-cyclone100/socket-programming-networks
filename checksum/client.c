#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>
int main(){
    int sd,cadl,block;
    struct sockaddr_in sad,cad;
    char str[100],check[100]="";
    sd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    sad.sin_family=AF_INET;
    sad.sin_port=htons(9995);
    sad.sin_addr.s_addr=inet_addr("127.0.0.1");
    connect(sd, (struct sockaddr *)&sad, sizeof(sad));
    printf("Enter binary string : ");
    scanf("%s",str);
    printf("Enter the number of blocks ");
    scanf("%d",&block);
    int rem = strlen(str)%block;
    if(rem != 0){
        for(int i=0;i<(block-rem);i++){
            strcat(check,"0");
        }
    }
    strcat(check,str);
    printf("%s",check);
    send(sd, check, sizeof(check),0);
    close(sd);
}