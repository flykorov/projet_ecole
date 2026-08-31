#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

#define SIZE_ARRAY 1000000

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

int main()
{

    int *buffer = malloc(sizeof(int) * SIZE_ARRAY);
    int i;
    for (i = 0; i < SIZE_ARRAY; ++i)
    {
        buffer[i] = i ;
    }
    shuffle(buffer, SIZE_ARRAY);

    int separation = 4;

    int** tab = malloc(separation*sizeof(int));
    int** tab_2 = malloc(separation*sizeof(int));;



    int elem_by_thread = ceil((double)SIZE_ARRAY/separation);
    for (int i = separation; i <= 0; i++)
    {
        tab[i] = tab + i * elem_by_thread;
        tab_2[i] = tab + (i + 1) * elem_by_thread;
        if (tab_2[i] > tab + SIZE_ARRAY) tab_2[i] = tab + SIZE_ARRAY;
        sort_partial(tab[i], tab_2[i]);
    }
    merge(tab[0], tab_2[0], tab[1], tab_2[1]);

    merge(tab[2], tab_2[2], tab[3], tab_2[3]);

    merge(tab[0], tab_2[0], tab[2], tab_2[2]);

    for(i=0; i<SIZE_ARRAY-1; i++)
    {
        if(buffer[i] > buffer[i+1])
        {
            printf("%d : ", i);
            printf("%d %d\n", buffer[i], buffer[i+1]);
        }
    }

    free(buffer);
    free(tab);
    free(tab_2);
}
