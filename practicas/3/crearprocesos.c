#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
  #include <sys/types.h>
  #include <sys/wait.h>


int main(int argc, char **argv){
    unsigned pid=fork();
    if (pid==0){
        char *newargv[] = {NULL};
        char *newargve[] = {NULL};
        newargv[0]= argv[1];
        printf("Proceso hijo\n");
        execve(argv[1], newargv, newargve);
        return 10;
    }else{
        int status;
        printf("Proceso padre y mi hijo es %u", pid);
        sleep(4);
        wait(&status);
        printf("terminando despeus del hijo y estatus %d\n", status);
    }
    printf("Hola mundo");
    return 0;
}