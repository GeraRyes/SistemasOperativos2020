#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
  #include <sys/types.h>
  #include <sys/wait.h>
  #include <signal.h>

void signalHandler(int signum){
    int status;
    wait(&status);
    printf("Mi hijo terminó con status %d", status);
}

void controlC(int signum){
    printf("Terminado");
}

int main(int argc, char **argv){
    signal(17, signalHandler);
    signal(2, controlC);
    unsigned pid=fork();
    if (pid==0){
        sleep(5);
        printf("Proceso hijo\n");
        //execv(argv[1],&argv[1]);
        return 10;
    }else{
        
        sleep(2);
        printf("Proceso padre y mi hijo es %u\n", pid);
        while(1){
            sleep(2);
            printf("trabajando \n");
        }        
    }
    printf("Hola mundo");
    return 0;
}