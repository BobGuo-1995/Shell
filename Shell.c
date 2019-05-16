#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// thinking this as an array of pointers and the pointer points to the address of pointers
char *args[20];
//we need another array of characters
char cmd[100];
int  sig;


void parse(){
  int i =0; 
  int j =1;
  args[0]=&cmd[0]; // setting the first array pointer 
   
  while (cmd[i] != '\0'){
    if(cmd[i]==' '){
     cmd[i]='\0';
     args[j]=&cmd[i+1];
     printf("%s\n",args[j]);
     j++;
    }
    else if(cmd[i]=='&'){
      cmd[i]= NULL;
      sig = 2;
    }
    i++;
     
 }
   args[j]=NULL;

}

int main(){
 
  while(1){
    int l=0;
    sig = 0;
    printf("plz enter a command: \n");
    gets(cmd);
    
    //if the user enter a exit command,we exit
    if(strcmp(cmd,"exit")==0){
      break;
    }
    parse(cmd);
    
    int pid=fork();
    //everything that happening in child process
    if (pid ==0){
      execvp(args[0],args);
      printf("Bad command\n");
      exit(1);
    }
    if (sig!=2){
      wait();
    }
