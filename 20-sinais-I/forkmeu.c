#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

void func1(){
	while (1) {
        printf("loop infinito! meu pid: %d\n", getpid());
        sleep(2);
    }
}

int main() {
    pid_t f1, f2, f3;
    int status;
    int check;

    printf("pai: pid %d ppid %d\n", getpid(), getppid());

    f1 = fork();
    if (f1 == 0) {
        func1();
    }
    sleep(10);
    waitpid(f1,&check,WNOHANG);
    if (WIFSIGNALED(check) == 1){
    	printf("Valor é 1: %s\n",strsignal(check));
    }else{
        printf("Mai que fiinho lento que eu tenho\n");
        kill(f1,2);
    }
    // verifica se o processo filho acabou
    // termine se ele nao tiver finalizado!
    
    return 0;
}