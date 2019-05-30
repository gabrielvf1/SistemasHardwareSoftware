#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>


#define bufferSize 1

typedef struct{
    char *arg1;
    char *arg2;
    int tamanho_total;
    int porcentagem;
 } inputs;
 
int main(int argc, char* argv[])
{
    int nread;
    char *buffer[bufferSize];
    int a = 0;

    inputs *inputs = malloc(sizeof(inputs));

    int arq_org = open(argv[1],O_RDONLY);
    int arq_destino = open(argv[2],O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

    //Pegando Tamanho
    struct stat st;
    stat(argv[1], &st);
    int size = st.st_size;

    //Salvando no struct
    inputs->arg1 = argv[1];
    inputs->arg2 = argv[2];
    inputs->tamanho_total = size;
    inputs->porcentagem = 0;

    while((nread = read(arq_org,buffer,bufferSize)) > 0){
        a+=1;
        inputs->porcentagem = (a*100)/size;
        printf("%d%%\n",inputs->porcentagem );
        write(arq_destino,buffer,nread);
       }
 
    exit(1);
}