#include <stdio.h>
#include <stdlib.h>


struct dataType{
    
    char name[32]; // 1st Consideration
    short age;
    float height;
    float weight;
    
};

int chargeData(void* ap){
    
    struct dataType *dato;
    dato = ap;
    
    printf("name:");
    scanf(" %s", dato -> name);
    printf("age:");
    scanf(" %hi", &dato -> age);
    printf("height:");
    scanf(" %f", &dato -> height);
    printf("weight:");
    scanf(" %f", &dato -> weight);

    
    return 0;
}


int saveData(void *ap){
    
    struct dataType *dato;
    dato = ap;
    
    FILE *f;
    
    f = fopen("binary-files/Data.dat", "w+");
    
    if (f == NULL){
        
        perror("opening file error");
        exit(-1);
        
    }
    
    // 2nd and 3rd Considerations
    
    int r = fwrite(dato, sizeof(struct dataType), 1, f);
    
    if (r == 0){
        
        perror("writing file error");
        exit(-1);
    }

    
    fclose(f);
    
    return 0;
    
}

int readData(void *ap){

   FILE *f;

   f = fopen("binary-files/Data.dat", "r");
    
    if (f == NULL){
        
        perror("Open File Error");
        exit(-1);
        
    }
   
    struct dataType *datos = ap;
        
    int r = fread(datos, sizeof(struct dataType), 1 , f);
    
     if (r == 0){
        
        perror("reading file error");
        exit(-1);
    }

    printf("name: %s\n", datos -> name);
    printf("age: %hi\n",datos -> age);
    printf("height: %f\n",datos-> height);
    printf("weight: %f\n",datos-> weight);
    
    fclose(f);
    return 0;
    
}

struct dataType *data;

int main(){
    
    data = malloc(sizeof(struct dataType));
    
    if (data == NULL){
        
        perror("There is a Error in malloc sentence, or there is a problem with virtual memory assignment manager");
        exit(-1);
    
    }
    
    
    
    //4th Consideration
    
    // Uncomment this code block if you want put the data and save in a bin file
    
    
    chargeData(data);
    saveData(data);
    
    
    
     // Uncomment the next line if you want read the struct data form a bin file
    readData(data);
    
    free(data);
    
    
}