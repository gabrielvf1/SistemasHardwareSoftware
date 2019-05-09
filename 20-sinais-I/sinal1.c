#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
int contagem = 0;
struct sigaction s;

void sig_handler(int num) {
    printf("Chamou Ctrl+C\n");
    contagem +=1;
    if (contagem == 3){
        printf("Apertou crtl c 3 vezes\n");
        exit(0);
    }
    s.sa_handler = SIG_DFL;
    sigaction(SIGINT, &s, NULL);



}

int main() {
    s.sa_handler = sig_handler;
    sigemptyset(&s.sa_mask);
    sigaction(SIGINT, &s, NULL);

    printf("Meu pid: %d\n", getpid());

    while(1) {
        sleep(1);
    }

    return 0;
}