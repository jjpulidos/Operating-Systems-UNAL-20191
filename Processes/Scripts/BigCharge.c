#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int foo(){
    int x;
    for(int i = 0; i< 2e09;i++){
        x = x+ sin(i);
    }
}


int main(){

        pid_t p;
        p = fork();
    if (p<0){
        perror("Fork Error\n");
        exit(-1);
    }
    if(!p){
        foo();
    }else{
        foo();
    }


return 0;
}

