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
/*
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
            arr[i] = (rand() % n) + 1;
        }
    }
}
*/
static void sortedArray(int* arr, int n) {
    for(int i = 0; i < n;i++) {
            arr[i]= i;
        }
}
static void unsortedArray(int* arr, int n) {
    for(int i = 0; i < n;i++) {
            arr[i] = n - i;
        }
}
static void randArray(int* arr, int n) {
    for(int i = 0; i < n;i++) {
            arr[i] = (rand() % n) + 1;
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

//köra tid i varje sort och search funk för sig
static void benchmarkSortAlg(const algorithm_t a, const case_t c,int* arr, int n) {
    clock_t start, end;
    
    //då insertion och bubble har samma tidskomplexitet kan man hålla bara checka quick sorts krav för cases
    if(c == best_t) {
        sortedArray(arr,n);
    } else if(c == worst_t) {
        unsortedArray(arr,n);
    } else {
        randArray(arr,n);
    }
    
    //för qsort
    if(a == quick_sort_t && c == best_t) {
        randArray(arr,n);
    }
    if(a == quick_sort_t && c == worst_t) {
        sortedArray(arr,n);
    }
    if(a == quick_sort_t && c == average_t) {
        randArray(arr,n);
    }

    //köra funktioner å tid under sen kalla i benchmark
    
}

//samma sak här fast för search
static void benchmarkSearchAlg(const algorithm_t a, const case_t c) {
    clock_t start, end;
    
    //då linear och binary har samma tidskomplexitet isch så har de samma för deras cases var
    if(c == best_t) {
        sortedArray(arr,n);
    } else if(c == worst_t) {
        unsortedArray(arr,n);
    } else {
        sortedArray(arr,n);
    }

    //köra funktioner å tid under sen kalla i benchmark
    
}

//
// Public
//

//skulle kunna dela upp i sort och search funktioner som sedan kallas in, med separat tidmätning oxå(tänker på denna just nu)
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
        int* array = (int*)malloc(size *sizeof(int));
        //generateArray(array,size,c);
        
        start = clock();
        switch(a) {
            case bubble_sort_t:
                //Bubblesort
                if(c == best_t) {
                    sortedArray(array,size);
                }else if(c == worst_t) {
                    unsortedArray(array,size);
                } else {
                    randArray(array,size);
                }
                bubble_sort(array,size);
                //timeInit(bubble_sort(array,size));
                break;

            case insertion_sort_t:
                //insertionSort
                if(c == best_t) {
                    sortedArray(array,size);
                }else if(c == worst_t) {
                    unsortedArray(array,size);
                } else {
                    randArray(array,size);
                }
                insertion_sort(array,size);
                break;

            case quick_sort_t:
                //quick sort
                if(c == best_t) {
                    randArray(array,size);
                }else if(c == worst_t) {
                    sortedArray(array,size);
                } else {
                    randArray(array,size);
                }
                quick_sort(array,size);
                break;

            case linear_search_t:
                //linear
                if(c == best_t) {
                    sortedArray(array,size);
                }else if(c == worst_t) {
                    unsortedArray(array,size);
                } else {
                    sortedArray(array,size);
                }
                linear_search(array,size,rand() % 1000);
                break;

            case binary_search_t:
                //binary
                if(c == best_t) {
                    sortedArray(array,size);
                }else if(c == worst_t) {
                    unsortedArray(array,size);
                } else {
                    sortedArray(array,size);
                }
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
