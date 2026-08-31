// TD 5 
// Victor Bouvier d'Acher
// Classe 42
// exo 2

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define SIZE_FIFO 8
#define NB_PROD 25
#define NB_CONSO 25

pthread_mutex_t mutex;
pthread_cond_t cond_sup;
pthread_cond_t cond_ajo;

// Structure Fifo communication entre consommateurs et producteurs
struct fifo {
    int tab[SIZE_FIFO]; // Tableau d'éléments stockés
    int ptr_lecteur;    // Index de la prochaine case à lire
    int ptr_ecrivain;   // Index de la prochaine case à écrire
    int nb_elem;        // Nombre d'éléments présents dans la fifo
} fifo;

// Fonction d'initialisation de la fifo
void init_fifo(struct fifo* f) {
    f->ptr_lecteur = 0;
    f->ptr_ecrivain = 0;
    f->nb_elem = 0;
}

// Fonction permettant d'insérer une valeur dans la fifo
void put(struct fifo* f, int a) {
    f->tab[f->ptr_ecrivain] = a;
    f->ptr_ecrivain++;
    if(f->ptr_ecrivain % SIZE_FIFO == 0)
        f->ptr_ecrivain = 0;
    f->nb_elem++;
}

// Fonction permettant de récupérer une valeur depuis la fifo
int get(struct fifo* f) {
    int r = f->tab[f->ptr_lecteur++];
    if(f->ptr_lecteur % SIZE_FIFO == 0)
        f->ptr_lecteur = 0;
    f->nb_elem--;
    return r;
}


// Fonction de production
void* prod(void* arg) {
    long id = (long)arg;
    for(;;) {
        int a = rand() % 100;
        pthread_mutex_lock(&mutex);
        while(fifo.nb_elem == SIZE_FIFO)
        {
            pthread_cond_wait(&cond_sup, &mutex);
            printf("une case est libéré\n");
        }
        put(&fifo, a);
        printf("producteur n°%ld crée valeur : %d\n", id, a);
        pthread_cond_signal(&cond_ajo);
        pthread_mutex_unlock(&mutex);
        usleep(10000);
    }

}

// Fonction de consommation
void* conso(void* arg) {
    long id = (long)arg;
    for(;;) {
        pthread_mutex_lock(&mutex);
        while(fifo.nb_elem == 0)
        {
            pthread_cond_wait(&cond_ajo, &mutex);
            printf("une case est ajouté\n");
        }
        printf("consomateur n°%ld lu valeur : %d\n", id, get(&fifo));
        pthread_cond_signal(&cond_sup);
        pthread_mutex_unlock(&mutex);
        usleep(10000);
    }
}

// Fonction principale
int main() {
    srand(time(NULL));
    init_fifo(&fifo);
    pthread_t consomateur[NB_CONSO];
    pthread_t producteur[NB_PROD];

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond_sup, NULL);
    pthread_cond_init(&cond_ajo, NULL);


    for(long i=0; i<NB_PROD; i++)
        pthread_create(&producteur[i], NULL, prod, (void*)i);
    
    for(long i=0; i<NB_CONSO; i++)
        pthread_create(&consomateur[i], NULL, conso, (void*)i);
    
    sleep(5);

}
