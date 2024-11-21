#define _POSIX_C_SOURCE 199309L
#include "analyze.h"
#include "algorithm.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


#define sizing 512

//
// Private
//


//genererar heltal för array på olika sätt
static void generateArray(int *arr, int n, case_t c) {
    if(c == best_t) {
        for(int i = 0; i < n;i++) {
            arr[i]= i;
        }
    } else if(c == worst_t) {
        for(int i = 0; i < n;i++) {
            arr[i] = n - i;
        }
    } else {
        for(int i = 0; i < n;i++) {
            arr[i] = rand() % 1000;
        }
    }
}
/*
//för att minska upprepningar gällande tidmätning
int timeInit( void (*funct)(int *, int, void*), int *a,int n void arg*) {
    //clock_t start,end;
    struct timespec *start;
    struct timespec *end;
    
    //ska ta tid från innan funktion körs tills den är klar sen returnera ut in i *buf
    //time start
    clock_gettime(CLOCK_MONOTONIC,&start);
    
    funct(a,n,arg);
    
    //time end;
    clock_gettime(CLOCK_MONOTONIC,&end);
    
    //return time;
    return (end->tv_nsec - start->tv_nsec);
}
*/
//
// Public
//


void benchmark(const algorithm_t a, const case_t c, result_t *buf, int n)
{
    /*
    här ska varje test/benchmark köras för varje algoritm
    behöver fixa en fylld array för de olika testerna med olika varianter av den
    så det som behövs är nog:
    switch case för varje algoritljer då parameter a
    funktion för att fylla array, vet ej storlek så behöver förmodligen kunna ha allokering för att göra det dynamiskt

    kunna printa ut informationen efter varje körning är också något som behövs implementeras, alltså tidskvantor
    
    parameter c är för vilken typ av tidstest vi vill ha alltså bästa, sämsta eller det genomsnittliga
    */

    //behöver allokera upp plats för array och size

    for(int i = 0; i < n;i++) {
        clock_t start, end;
        
        int size = sizing * (1 << i);
        int* array = malloc(size *sizeof(int));
        generateArray(array,size,c);
        
        start = clock();
        switch(a) {
            case bubble_sort_t:
                //Bubblesort
                bubble_sort(array,size);
                //timeInit(bubble_sort(array,size));
                break;

            case insertion_sort_t:
                //insertionSort
                insertion_sort(array,size);
                break;

            case quick_sort_t:
                //quick sort
                quick_sort(array,size);
                break;

            case linear_search_t:
                //linear
                linear_search(array,size,rand() % 1000);
                break;

            case binary_search_t:
                //binary
                binary_search(array,size,rand() % 1000);
                break;
        }
        end = clock();
        //detta laddar in resultaten in i ui filens result array
        buf[i].size = size;
        buf[i].time = ((double)(end - start)) / CLOCKS_PER_SEC;
        
        //buf[i].time = (end.tv_nsec - start.tv_nsec);
        //printf("%lf",((end.tv_nsec - start.tv_nsec)/(double)1E9));
        //printf("%lf",((double)(end - start)) / CLOCKS_PER_SEC);

        //frigör det som allokerats
        free(array);
    }
}
