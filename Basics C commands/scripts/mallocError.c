#include <stdio.h>
#include <stdlib.h>

int main(){
    
    char *a;
    a = (char*) malloc(10);
    if (a==NULL){
        perror("There is a Error in malloc sentence, or there is a problem with virtual memory assignment manager");
        exit(-1);
    }else{
        *a = 'H';
        printf("'a' char value: %c, 'a' memory address %p\n",*a,a);
        free(a);
    
    }
    
    return 0;
    
}
