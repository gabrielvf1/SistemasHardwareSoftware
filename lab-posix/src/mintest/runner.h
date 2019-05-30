    #include <sys/types.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <sys/wait.h>
    #include <string.h>

    #define ANSI_COLOR_RED     "\x1b[31m"
    #define ANSI_COLOR_GREEN   "\x1b[32m"
    #define ANSI_COLOR_YELLOW  "\x1b[33m"
    #define ANSI_COLOR_BLUE    "\x1b[34m"
    #define ANSI_COLOR_MAGENTA "\x1b[35m"
    #define ANSI_COLOR_CYAN    "\x1b[36m"
    #define ANSI_COLOR_RESET   "\x1b[0m"

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
                printf("%s:" ANSI_COLOR_GREEN " [PASS]" ANSI_COLOR_RESET "\n",all_tests[i].name);
                pass_count++;

            }else{
                printf("%s:"ANSI_COLOR_RED" [FALHO]"ANSI_COLOR_RESET" \n",all_tests[i].name);
            }
        }
        if(WIFSIGNALED(status) == 1){
            if (WTERMSIG(status) == 14){
                 printf("%s:"ANSI_COLOR_BLUE" [FALHO] TIME OUT"ANSI_COLOR_RESET"\n",all_tests[i].name);
             }else{
            printf("%s:"ANSI_COLOR_RED" [FALHO] %s"ANSI_COLOR_RESET"\n",all_tests[i].name,strsignal(WTERMSIG(status)));
            }
        }

    }
    
    printf("\n\n=====================\n");
    printf("%d/%d tests passed\n", pass_count, size);
    return 0;
}
