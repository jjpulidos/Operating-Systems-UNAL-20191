#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main(){

        pid_t p;
        p = fork();
    if (p<0){
        perror("Fork Error\n");
        exit(-1);
    }
    if(!p){
        printf("I'm a child process\n");
    }else{
        printf("I'm a father process\n");
    }


return 0;
}

