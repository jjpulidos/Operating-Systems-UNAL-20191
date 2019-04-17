#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

long double piCalc(_Bool odd){
    
    long double piDecimals = 0;
    
    if(odd){
        
        for(double i = 1.0; i< 1e11; i+=4){
             piDecimals += (long double) (4.0/i);
        }

        
    }else{
        
        for(double i = 3; i< 1e11; i+=4){
             piDecimals -= (long double)(4.0/i);
        }
    }
    
    return piDecimals;
}


int main(){

        pid_t p;
        p = fork();
    
    if (p<0){
        perror("Fork Error\n");
        exit(-1);
    }
    
    long double piChild= 0;
    long double piFather= 0;
    long double piTotal = 0;
    
    if(!p){
        piChild = piCalc(1);
         FILE *f;
    
         f = fopen("Data/pi.dat", "w+");
    
        if (f == NULL){

            perror("opening file error");
            exit(-1);

        }
    
        int r = fwrite(&piChild, sizeof(piChild), 1, f);

        if (r == 0){

            perror("writing file error");
            exit(-1);
        }


        fclose(f);
    }else{
        
        piFather = piCalc(0);
        int status;
        wait(&status);
        FILE *fd = fopen("Data/pi.dat", "a+");
        long double pi_file;
        fread(&pi_file,sizeof(pi_file),1,fd);
        //printf("%Lf\n",piPadre);
        //printf("%Lf\n'",pi_file);
        piTotal += piFather+ pi_file;
        
        int Digs = DECIMAL_DIG;
        printf("%.*Le\n", Digs, piTotal);
        
    }
    


    return 0;
}

