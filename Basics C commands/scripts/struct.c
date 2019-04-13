#include <stdio.h>
#include <stdlib.h>

struct Data{
    int numInteger;
    double numDouble;
};

void printData(struct Data data){

   printf( "Data numInteger: %i\n", data.numInteger);
   printf( "Data numDouble: %lf\n", data.numDouble);

}

void printDataPointer(struct Data *data){

   printf( "Data numInteger: %i\n", data -> numInteger);
   printf( "Data numDouble: %lf\n", data -> numDouble);

}

int main(){
    
    struct Data data1;
    struct Data data2;
    
    data1.numInteger = 34;
    data1.numDouble = 2.45;
    
    data2.numInteger = 10;
    data2.numDouble = 3.14;
    
    puts("-----data1-----\n");
    printData(data1);
    puts("\n");
    puts("-----data2-----\n");
    printData(data2);
    puts("\n");
    struct Data *dataPointer;
    dataPointer = &data1;
    puts("-----dataPointer-----\n");
    printData(*dataPointer);
    
    puts("\n");
    *dataPointer = data2;
    puts("-----   dataPointer printed using '->'   -----\n");
    printDataPointer(dataPointer);
    
    return 0;
    
}

