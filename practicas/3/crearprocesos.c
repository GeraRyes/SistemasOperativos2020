#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
  #include <sys/types.h>
  #include <sys/wait.h>


int main(int argc, char **argv){
    unsigned pid=fork();
    if (pid==0){
        printf("Proceso hijo\n");
        execv(argv[1],&argv[1]);
        return 10;
    }else{
        int status;
        printf("Proceso padre y mi hijo es %u", pid);
        while(1){
            sleep(2);
            printf("trabajando \n");
        }        
        wait(&status);
        printf("terminando despeus del hijo y estatus %d\n", status);
    }
    printf("Hola mundo");
    return 0;
}