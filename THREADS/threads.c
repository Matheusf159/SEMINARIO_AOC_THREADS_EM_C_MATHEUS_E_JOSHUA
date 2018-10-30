#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define num_thread 4  //para definir o n�mero de threads


void slow(){
    //fun��o n�o � obrigat�ria pro programama funcionar
    //ela est� aqui para deixar a execu��o do programa
    //mais lento, para mostrar o que at� acontecendo
    //pois a execu��o acontece muito r�pido
    int i,j,k;
    int valor = 1000;

    for(i = 0; i < valor; i++)
        for(j = 0; i < valor; j++)
           for(k = 0; k < valor; k++)
                valor = valor;


}


void *funcao(void * arg){
//essa fun��o � importante, pois � ela que executa as threads
    int *pvalor;
    pvalor = arg;

    printf("Thread %i executando...\n",*pvalor);

   slow(); //fun��o pra demorar pra executar o segundo printf que vai melhorar a visualiza��o


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
    //se deixar assim as threads v�o ser executadas, mas n�o v�o terminar, ent�o � preciso criar uma fun��o e outro for
    for(i = 0; i < num_thread; i++){
        pthread_join(threads[i],NULL);


    printf("\n");

    }
}
