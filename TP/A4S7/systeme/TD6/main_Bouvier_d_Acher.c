#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
#include "time.c"

#define SIZE_ARRAY 100000000

struct context
{
    int * ptr_start;
    int * ptr_end;
    int index_demarrage;
    int nb_thread;
};

pthread_t* tid;



int cmp (const void * a, const void * b)
{
   return (*(int*)a - *(int*)b);
}

void sort_partial(int* start, int* end)
{
    qsort(start, end - start, sizeof(int), cmp);
}

void merge(int *s1, int *e1, int* s2, int* e2)
{
    int *start = s1;

    if (s2 == e2) return;

    assert((e1 - s1) > 0);
    assert((e2 - s2) > 0);

    int size = (e2 - s1);
    int *out = malloc(sizeof(int) * size);
    int *tmpbuf = out;

    while (!(s1 >= e1 || s2 >= e2))
    {
        if (*s1 > *s2)
        {
            *out = *s2;
            ++s2;
        }
        else
        {
            *out = *s1;
            ++s1;
        }
        ++out;
    }

    while(s2 < e2)
    {
        *out = *s2;
        ++out;
        ++s2;
    }

    while(s1 < e1)
    {
        *out = *s1;
        ++out;
        ++s1;
    }

    memcpy(start, tmpbuf, size * sizeof(int));
    free(tmpbuf);
}

void* qsort_thread(void* arg)
{
    struct context *ctx = arg;
    int nombre_iteration = ceil(log2(ctx->nb_thread));
    // Max partiel
    sort_partial(ctx->ptr_start, ctx->ptr_end);

    int it;
    for (it = 0; it < nombre_iteration; ++it)
    {
        if (ctx->index_demarrage % (2 << it) == 0)
        {
            int thread_waited = ctx->index_demarrage + (1 << it);
            if (thread_waited >= ctx->nb_thread) return ctx;

            // Attente du thread
            struct context *ctx_merge;
            assert(pthread_join(tid[thread_waited], (void**)&ctx_merge) == 0);


            // Fusion des threads voisin
            
            merge(ctx->ptr_start, ctx->ptr_end, ctx_merge->ptr_start, ctx_merge->ptr_end);

            if(ctx->ptr_start > ctx_merge->ptr_start) ctx->ptr_start = ctx_merge->ptr_start;
            if(ctx->ptr_end < ctx_merge->ptr_end) ctx->ptr_end = ctx_merge->ptr_end;

            free(ctx_merge);
        }
        else
        {
            return ctx;
        }
    }
    return ctx;
}

void tri(int* tab, size_t nb_elem, int nb_thread)
{
    int elem_by_thread = ceil((double)SIZE_ARRAY/nb_thread);
    tid = malloc(nb_thread * sizeof(pthread_t));
    // Création des threads
    int i;
    for (i = nb_thread - 1; i >= 0; --i)
    {
        struct context *ctx = malloc(sizeof(struct context));

        // printf("%d\n", i);
        ctx->ptr_start = tab + i * elem_by_thread;
        ctx->ptr_end = tab + (i + 1) * elem_by_thread;
        if (ctx->ptr_end > tab + nb_elem) ctx->ptr_end = tab + nb_elem;
        ctx->index_demarrage = i;
        ctx->nb_thread = nb_thread;
        // printf("s = %d, e = %d\n",  i * elem_by_thread, (i + 1) * elem_by_thread);
        assert(pthread_create(&tid[i], NULL, qsort_thread, ctx) == 0);
    }
    struct context *ctx;
    assert(pthread_join(tid[0], (void**)&ctx) == 0);
    free(ctx);
    free(tid);
    // return tab;
}

void shuffle(int * b, int size)
{
    srand(time(NULL));
    int i;
    for (i = 0; i < size/2; ++i)
    {
        int first = rand() % size;
        int second = rand() % size;
        int tmp = b[first];
        b[first] = b[second];
        b[second] = tmp;
    }
}


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage : %s nb_thread\n", argv[0]);
        exit(-1);
    }
    int nb_thread = atoi(argv[1]);
    int *buffer = malloc(sizeof(int) * SIZE_ARRAY);
    int i;
    for (i = 0; i < SIZE_ARRAY; ++i)
    {
        buffer[i] = i;
    }
    shuffle(buffer, SIZE_ARRAY);

    // for(i=0; i<SIZE_ARRAY-1; i++)
    // {
    //     if(buffer[i] > buffer[i+1])
    //     {
    //         printf("%d : ", i);
    //         printf("%d %d\n", buffer[i], buffer[i+1]);
    //     }
    // }
    // for(i=0; i<SIZE_ARRAY; i++)
    // {
    //     printf("%d\n", buffer[i]);
    // }

    double startTime, endTime;
    startTime = getRealTime();

    tri(buffer, SIZE_ARRAY, nb_thread);

    endTime = getRealTime();
    for(i=0; i<SIZE_ARRAY-1; i++)
    {
        if(buffer[i] > buffer[i+1])
        {
            printf("%d : ", i);
            printf("%d %d\n", buffer[i], buffer[i+1]);
        }
        // else
        // {
        //     printf("%d\n", buffer[i]);
        // }
    }
    // printf("Max : %d\n", m);

    free(buffer);
    fprintf(stderr, "Real time used = %lf\n", (endTime - startTime));
    return 0;
}
