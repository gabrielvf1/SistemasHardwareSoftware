#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MSGSIZE 16 

void func1() {
    sleep(1);
    printf("print(\"Este e um comando python!\", 1, 2, 4//3, 4/3)\n");
}

void func2() {
    // complete aqui com exec
}


int main() {
    // crie o pipe e redireciona a saída do processo pai para
    // a entrada do filho ;)

    char* msg1 = "hello, world #1"; 
    char* msg2 = "hello, world #2"; 
    char* msg3 = "hello, world #3"; 

    int status;
    int fds[2];
    pipe(fds);
    char inbuf[MSGSIZE];

    pid_t f = fork();



    #ifdef CHAR
    if (f != 0) {
        printf("Char rodando\n");
        close(fds[1]);
        read(fds[0], inbuf, MSGSIZE);
        printf("%s\n",inbuf);
        read(fds[0], inbuf, MSGSIZE);
        printf("%s\n",inbuf);
        read(fds[0], inbuf, MSGSIZE);
        printf("%s\n",inbuf);
        func1();

    } 
    else {
        close(fds[0]);
        write(fds[1], msg1, MSGSIZE); 
        write(fds[1], msg2, MSGSIZE); 
        write(fds[1], msg3, MSGSIZE); 
        func2();

    }
    #endif

    #ifdef INT
    if (f != 0) {
        printf("Int rodando\n");
        int resposta;
        read(fds[0], &resposta, sizeof(int));
        printf("%d\n",resposta);
        func1();

    } 
    else {
        close(fds[0]);
        int envio = 10;
        write(fds[1], &envio, sizeof(int));  
        func2();

    }
    #endif

}