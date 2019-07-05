#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<readline/readline.h>
#include<readline/history.h>
#define CLEAR() printf("\033[H\033[J");

int main(){

   char usuario[30];
   char linhacomando[50];
   char nome_diretorio[100];
   
    do{
		             
           getcwd(nome_diretorio, sizeof(nome_diretorio));
           printf("%s~%s~>  ", getenv("USER"),nome_diretorio);
		
           fgets(linhacomando, sizeof(linhacomando), stdin);
           strtok(linhacomando,"\n");
           add_history(linhacomando);
		
    	   if( strcmp(linhacomando,"hello") == 0 ){
	   system("clear");  
	   printf("\nSeja bem vindo a minha SHELL!!!\n\n\n\n");
	   }else if( strcmp(linhacomando,"exit") == 0){
    	        system("clear");  
	        printf("\nENCERRANDO O PROGRAMA!!!\n\n\n");
	   }else if( strstr(linhacomando,"cd") == linhacomando ){
		system("clear");
		chdir("..");
	   }else if( strcmp(linhacomando,"help") == 0){
	        system("clear");  
    	        printf("\n\n -hello- Da saldacao ao usuario.\n -exit- Encerra o programa.\n -cd- Faz alguma coisa.\n -help- Mostra a tela de ajuda.\n\n\n\n");
	   } else{
	        system("clear");
	        printf("Comando invalido, tente outra vez!!!\n\n");
	   }

     }while( strcmp(linhacomando,"exit") != 0 );

}
