
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    float *vetor;
    int inicio;
    int fim;
    float soma;
 } salva;

void *minha_thread(void *arg) {
    printf("Hello thread!\n");
    return NULL;
}
 void *tar_print    (void *arg){
    salva *a = (salva *) arg;
    for(int i = a->inicio; i< a->fim ; i++){
        a->soma += a->vetor[i];
    }
    return NULL;
 }



int main() {
    //pthread_t tid;
    
    //int *vi = malloc(4 * sizeof(int));
    pthread_t *tids = malloc(4 * sizeof(pthread_t));
    salva *teste = malloc(2 * sizeof(salva));
    int in;
    scanf("%d", &in);

    float *vec = malloc(in * sizeof(float));
    float soma_total = 0;
    for (int i = 0 ; i < in; i ++){
        vec[i] = (float) i / (i+1);
    }


    int n_threads = 2;
    for (int i = 1 ; i <= n_threads; i++){
        teste[i].vetor = vec;
        teste[i].soma = 0;
        teste[i].inicio = (in/n_threads)*(i - 1);
        teste[i].fim = (in * i - (in/n_threads)*i) - 1;
        int error = pthread_create(&tids[i], NULL, tar_print, &teste[i]);

    }

    for (int i = 0 ; i < n_threads; i++){
        pthread_join(tids[i], NULL);
        soma_total += teste[i].soma;
        //printf("%f\n",teste[i].soma);
    }

    printf("%f\n", soma_total);
   
    free(tids);
    free(teste);

    
    return 0;
}
