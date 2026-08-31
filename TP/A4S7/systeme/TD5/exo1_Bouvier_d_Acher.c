// TD 5 
// Victor Bouvier d'Acher
// Classe 42
// exo 1

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define NB_THREADS 50
int var=0;
pthread_mutex_t mutex;

void* thread(void* arg) {
    //pthread_detach(pthread_self());
    long i = (long)arg;
    sleep(1);
    printf("Bonjour, j'ai reçu %ld\n", i);
    long * tmp = malloc(sizeof(long));
    pthread_mutex_lock(&mutex);
    var += i;
    pthread_mutex_unlock(&mutex);
    *tmp = i*10;
    pthread_exit((void*)tmp);
}

int main() {
    long i;
    pthread_t pid[NB_THREADS];
    pthread_mutex_init(&mutex, NULL);
    for (i = 0; i < NB_THREADS; i++) {
        pthread_create(&pid[i], NULL, thread, (void*)i);
    }
    for (i = 0; i < NB_THREADS; i++) {
        long* a;
        pthread_join(pid[i], (void**)&a);
        printf("Le thread %ld s'est terminé en renvoyant %ld\n", i, *a);
    	free(a);
    }
    printf("variable global = %d\n", var);
    printf("Fin du thread principal\n");
    return EXIT_SUCCESS;
}
