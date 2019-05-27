    #include <sys/types.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <sys/wait.h>
    #include <string.h>

int main() {
    int status;
    int size = sizeof(all_tests)/sizeof(test_data);
    printf("Running %d tests:\n", size);
    printf("=====================\n\n");
    int pass_count = 0;
    int pidF [size];
    for (int i = 0; i < size; i++) {
        if ((pidF[i] = fork()) == 0){
            alarm(3);
            if (all_tests[i].function() >= 0) {

                exit(1);
            }
            else {
                exit(0);
            }

        }
    }
    for (int i = 0; i < size; i++) {
        pid_t atual = waitpid(pidF[i],&status,0);
        if (WIFEXITED(status)){
            if(WEXITSTATUS(status)){
                printf("[PASS] %s Teste bem Sucedido\n",all_tests[i].name);
                pass_count++;

            }else{
                printf("[FALHO] %s Teste Falhou \n",all_tests[i].name);
            }
        }
        if(WIFSIGNALED(status) == 1){
            printf("[FALHO] %s %s\n",all_tests[i].name,strsignal(WTERMSIG(status)));
        }

    }
    
    printf("\n\n=====================\n");
    printf("%d/%d tests passed\n", pass_count, size);
    return 0;
}
