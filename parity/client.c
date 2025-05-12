#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>
int main(){
    int sd;
    struct sockaddr_in sad,cad;
    char str[50];
    int oneCount = 0;
    sd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    sad.sin_family=AF_INET;
    sad.sin_port=htons(9995);
    sad.sin_addr.s_addr=inet_addr("127.0.0.1");
    connect(sd, (struct sockaddr *)&sad, sizeof(sad));
    printf("Enter a binary string : ");
    scanf("%s",str);
    for(int i=0;str[i]!='\0';i++){
        if(str[i]=='1'){
            oneCount++;
        }
    }
    if(oneCount%2==0){
        strcat(str,"0");
    }
    else{
        strcat(str,"1");
    }
    send(sd, str, sizeof(str),0);
    close(sd);
    return 0;
}