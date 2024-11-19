#include "analyze.h"
#include "algorithm.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define sizing 100

//
// Private
//


//genererar heltal för array på olika sätt
static void generateArray(int *arr, int n, case_t c) {
    if(c == best_t) {
        for(int i = 0; i < n;i++) {
            
        }
    } else if(c == worst_t) {
        for(int i = 0; i < n;i++) {
            
        }
    } else {
    
    }
}

int scanfnPrint(int value) {
    printf("välj ett value: ");
    scanf("%d",&value);
    return value;
}

//för att minska upprepningar gällande tidmätning
void timeInit( void (*funct)()) {
    //clock_t start,end;
    struct timespec *start;
    struct timespec *end;
    
    //ska ta tid från innan funktion körs tills den är klar sen returnera ut in i *buf
    //time start
    clock_gettime(CLOCK_MONOTONIC,&start);
    
    funct():
    
    //time end;
    clock_gettime(CLOCK_MONOTONIC,&end);
    
    //return time;
    return end.tv_nsec - start.tv_nsec;
}

//
// Public
//


void benchmark(const algorithm_t a, const case_t c, result_t *buf, int n)
{
    /*
    här ska varje test/benchmark köras för varje algoritm
    behöver fixa en fylld array för de olika testerna med olika varianter av den
    så det som behövs är nog:
    switch case för varje algoritm följer då parameter a
    funktion för att fylla array, vet ej storlek så behöver förmodligen kunna ha allokering för att göra det dynamiskt

    kunna printa ut informationen efter varje körning är också något som behövs implementeras, alltså tidskvantor
    
    parameter c är för vilken typ av tidstest vi vill ha alltså bästa, sämsta eller det genomsnittliga
    */

    //behöver allokera upp plats för array och size
    int size = sizing;
    int* array = (int*) malloc(size *sizeof(int));
    int value = 0;
    generateArray(array,size,c);
    
    for(int i = 0; i < n;i++) {
        switch(a) {
            case bubble_sort_t:
                //Bubblesort
                //bubble_sort(array,size);
                timeInit(bubble_sort(array,size));
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
                value = scanfnPrint(value);
                linear_search(array,size,value);
                break;

            case binary_search_t:
                //binary
                value = scanfnPrint(value);
                binary_search(array,size,value);
                break;
        }
    }
}
