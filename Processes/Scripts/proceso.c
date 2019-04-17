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
        printf("hola soy hijo\n");
    }else{
        printf("hola soy padre\n");
    }


return 0;
}

