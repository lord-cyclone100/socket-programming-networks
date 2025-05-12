#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>
int main(){
    int sd,cd,cadl,oneCount=0;
    struct sockaddr_in sad,cad;
    char str[50],newstr[50];
    sd=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    sad.sin_family=AF_INET;
    sad.sin_port=htons(9995);
    sad.sin_addr.s_addr=inet_addr("127.0.0.1");
    bind(sd, (struct sockaddr *)&sad, sizeof(sad));
    listen(sd,10);
    cadl=sizeof(cad);
    cd=accept(sd, (struct sockaddr *)&cad, &cadl);
    recv(cd,str,sizeof(str),0);
    for(int i=0;i<strlen(str)-1;i++){
        newstr[i]=str[i];
    }
    for(int i=0;newstr[i]!='\0';i++){
        if(newstr[i]=='1'){
            oneCount++;
        }
    }
    if(oneCount%2==0){
        strcat(newstr,"0");
    }
    else{
        strcat(newstr,"1");
    }
    if(strcmp(str,newstr)==0){
        printf("No error detected");
    }
    else{
        printf("Error detected");
    }
    close(cd);
    close(sd);
    return 0;
}