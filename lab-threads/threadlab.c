#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <pthread.h>


#define bufferSize 1

struct inputs{
    char *arg1;
    char *arg2;
    int tamanho_total;
    int porcentagem;
    int size;
    int total_lido;
 } ;

void *copy (void *_arg){
    struct inputs *dados = _arg;
    printf("%s\n", dados->arg2);
    int nread;
    char *buffer[bufferSize];
    int arq_org = open(dados->arg1,O_RDONLY);
    int arq_destino = open(dados->arg2,O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    while((nread = read(arq_org,buffer,bufferSize)) > 0){
        dados->total_lido+=1;
        dados->porcentagem = (dados->total_lido*100)/dados->tamanho_total;
        printf("%d%%\n",dados->porcentagem );
        write(arq_destino,buffer,nread);
       }
    exit(1);
    
 }

 
int main(int argc, char* argv[])
{
    int a = 0;

    pthread_t tid;

    struct inputs input;

    //Pegando Tamanho
    struct stat st;
    stat(argv[1], &st);
    int size = st.st_size;


    //Salvando no struct
    input.arg1 = argv[1];
    //printf("%s\n", input.arg1);
    input.arg2 = argv[2];
    input.tamanho_total = size;
    input.porcentagem = 0;
    input.total_lido = 0;

    int error = pthread_create(&tid, NULL, copy, &input);
 
    pthread_join(tid, NULL);
    exit(1);
}