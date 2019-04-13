#include <stdio.h>
#include <stdlib.h>

typedef struct Data{
    int numInteger;
    int* numIntPointer;
} myData;

void printData(struct Data data){

   printf( "Data numInteger: %i\n", data.numInteger);
   printf( "Data numIntPointer: %p and the value is %i\n", data.numIntPointer, *data.numIntPointer);

}

void printDataPointer(struct Data *data){

   printf( "Data numInteger: %i\n", data -> numInteger);
   printf( "Data numIntPointer: %p and the value is %i\n", data -> numIntPointer, *data -> numIntPointer);

}

int main(){
    
    myData *dataPointer;
    dataPointer = malloc(sizeof(myData));
    
    dataPointer->numInteger = 2;
    dataPointer -> numIntPointer = malloc(sizeof(int));
    *dataPointer -> numIntPointer = 3;
    
    puts("-----dataPointer-----\n");
    printData(*dataPointer);
    puts("\n");
    puts("-----   dataPointer printed using '->'   -----\n");
    printDataPointer(dataPointer);
    
    
    free(dataPointer);
    return 0;
    
}
