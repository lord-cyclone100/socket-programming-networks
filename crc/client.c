#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>
int main(){
    int sd,choice;
    struct sockaddr_in sad,cad;
    char str[50],div[50], newStr[50];
    sd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    sad.sin_family=AF_INET;
    sad.sin_port=htons(9995);
    sad.sin_addr.s_addr=inet_addr("127.0.0.1");
    connect(sd, (struct sockaddr *)&sad, sizeof(sad));
    printf("Enter a binary string : ");
    scanf("%s",str);

    printf("Enter divisor : ");
    scanf("%s",div);

    for(int i=0;i<strlen(str);i++){     //copying contents of str to newStr for future use
        newStr[i]=str[i];
    }

    for(int i=0;i<(strlen(div))-1;i++){
        strcat(str,"0");
    }

    for(int i=0;i<=strlen(str)-strlen(div);i++){
        if(str[i]=='1'){
            for(int j=0;j<strlen(div);j++){
                str[i+j]=((div[j]-'0' ^ str[i+j]-'0'))+'0';
            }
        }
    }

    for(int i=0;i<strlen(newStr)-1;i++){
        str[i]=newStr[i];
    }

    printf("Do you want error (1 for yes and 0 for no) : ");
    scanf("%d",&choice);

    printf("%s",str);

    send(sd, str, sizeof(str),0);
    send(sd, div, sizeof(div),0);
    send(sd, &choice, sizeof(int),0);
    close(sd);
    return 0;
}