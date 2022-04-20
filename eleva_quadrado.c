#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NTHREADS 2
#define array[10000]

typedef struct{
    int pos_i, pos_f;
} t_Args;

void *ElevaQuadrado(void *arg){
    t_Args *args = (t_Args *) arg;
    
    for(int i = args->pos_i; i < args->pos_f; i++){
        int temp = array[i];
        array[i] = temp*temp;
    }

    pthread_exit(NULL);
}

int main(){
    pthread_t tid_sistema[NTHREADS];
    int inicio = 0, meio = 5000, fim = 10000;
    for (int s=0; s<10000;s++){
        array[s] = s;
    }
    t_Args *arg;

    for(int thread = 0; thread < NTHREADS; thread++){
        arg = malloc(sizeof(t_Args));
        if (arg == NULL) {
            printf("--ERRO: malloc()\n"); exit(-1);
        }
        for(int k=0; k<f; k++){
            arg->vetor[k] = array[k];
        }
        if (thread == 0){
            arg->pos_i = inicio;
            arg->pos_f = meio;
        }
        else{
            arg->pos_i = meio;
            arg->pos_f = fim;
        }

        if (pthread_create(&tid_sistema[thread], NULL, ElevaQuadrado, (void*) arg)) {
            printf("--ERRO: pthread_create()\n"); exit(-1);
        }
        pthread_join(thread,NULL)
    }

    pthread_exit(NULL);

    for (int j=0; j < f; j++){
        if (array[j]!=j*j){
            printf("False")
        }
        if (array[j]==f*f){
            printf("True")
        }
    }
}
