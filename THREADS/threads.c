#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define num_thread 4  //para definir o número de threads


void slow(){
    //função não é obrigatória pro programama funcionar
    //ela está aqui para deixar a execução do programa
    //mais lento, para mostrar o que atá acontecendo
    //pois a execução acontece muito rápido
    int i,j,k;
    int valor = 1000;

    for(i = 0; i < valor; i++)
        for(j = 0; i < valor; j++)
           for(k = 0; k < valor; k++)
                valor = valor;


}


void *funcao(void * arg){
//essa função é importante, pois é ela que executa as threads
    int *pvalor;
    pvalor = arg;

    printf("Thread %i executando...\n",*pvalor);

   slow(); //função pra demorar pra executar o segundo printf que vai melhorar a visualização


   printf("Thread %i finalizada \n", *pvalor);
}

int main(){
    pthread_t threads [num_thread]; //serve para declarar threads
    int i, arg[num_thread];

        for(i = 0; i < num_thread; i++){

            arg[i] =i + 1;
            //agora para criar a thread
            pthread_create(&threads [i], NULL, funcao, (void *)&arg[i]);
        }
    //se deixar assim as threads vão ser executadas, mas não vão terminar, então é preciso criar uma função e outro for
    for(i = 0; i < num_thread; i++){
        pthread_join(threads[i],NULL);


    printf("\n");

    }
}
