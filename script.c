#include <stdio.h>
#include <stdlib.h>


struct dataType{
    
    char name[32]; // se debe poner validación del buffer -> 32 chars para que no haya fallo de segmentación
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
    scanf(" %i", &dato -> age);
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
    
    f = fopen("Data.dat", "w+");
    
    if (f == NULL){
        
        perror("error abriendo");
        exit(-1);
        
    }
    
    // Se guarda de forma binaria la estructura para mas eficiencia en memoria
    // Decoders con Ingeniería inversa para leer el binario si no tengo la estructura en mis conocimientos
    
    int r = fwrite(dato, sizeof(struct dataType), 1, f);
    
    if (r == 0){
        
        perror("error escribiendo");
        exit(-1);
    }

    
    fclose(f);
    
    return 0;
    
}

int readData(void *ap){

   FILE *f;

   f = fopen("Data.dat", "r");
    
    if (f == NULL){
        
        perror("error abriendo");
        exit(-1);
        
    }
   
    struct dataType *datos = ap;
        
    int r = fread(datos, sizeof(struct dataType), 1 , f);
    
     if (r == 0){
        
        perror("error leyendo");
        exit(-1);
    }

    printf("name: %s\n", datos -> name);
    printf("age: %i\n",datos -> age);
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
    
    
    
    //No se recomienda pasar struct como parametro de una funcion porque en algunos compiladores presenta problemas
    
    chargeData(data);
    saveData(data);

    //
    readData(data);
    
    free(data);
    
    
}
