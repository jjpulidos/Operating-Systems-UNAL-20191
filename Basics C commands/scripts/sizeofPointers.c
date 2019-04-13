#include <stdio.h>

int main(){
    
    char *a;
    int *b;
    float *c;
    short *d;
    double *e;
    long *f;
    long long *g;
    
    printf("char* size: %li bytes\n", sizeof(a));
    printf("int* size: %li bytes\n", sizeof(b));
    printf("float* size: %li bytes\n", sizeof(c));
    printf("short* size: %li bytes\n", sizeof(d));
    printf("double* size: %li bytes\n", sizeof(e));
    printf("long* size: %li bytes\n", sizeof(f));
    printf("long long* size: %li bytes\n", sizeof(g));
    
    return 0;
    
}

