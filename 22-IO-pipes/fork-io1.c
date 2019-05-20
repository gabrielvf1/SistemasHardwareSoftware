#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>


void funcao_lenta() {
    for (int i = 0; i < 5; i++) {
        printf("Filho %d", i);
        sleep(2);
        printf(" -- Fim Filho %d\n", i);
    }
}

void funcao_lenta_pai() {
    for (int i = 0; i < 10; i++) {
        printf("Pai %d", i);
        sleep(1);
        printf(" -- Fim Pai %d\n", i);
    }
}

int main(int argc, char *argv[]) {
    /* completar aqui */
    char buff[5];
    pid_t f1, f2, f3;
    int fd;
    int status;
    fd = open("./", O_RDWR | __O_TMPFILE , 0777);

    f1 =fork();
    if (f1 == 0){
    	    	dup2( fd , 1 );  
    	funcao_lenta();
 	
    } else{
    	funcao_lenta_pai();
    	wait(&status);
    	lseek(fd,0,SEEK_SET);
    	while(read(fd,&buff,1)){
    		printf("%c",buff[0]);
    	}

    }
    return 0;
}
