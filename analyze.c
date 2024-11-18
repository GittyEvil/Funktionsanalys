#include "analyze.h"
#include "algorithm.h"

//
// Private
//

//
// Public
//

void generateDataArray(int *arr, int n, case_t c) {
    if(c == best_t) {
    
    } else if(c == worst_t) {
    
    } else {
    
    }
}

void benchmark(const algorithm_t a, const case_t c, result_t *buf, int n)
{
    /*
    här ska varje test/benchmark köras för varje algoritm
    behöver fixa en fylld array för de olika testerna med olika varianter av den
    så det som behövs är nog:
    switch case för varje algoritm följer då parameter a
    funktion för att fylla array, vet ej storlek så behöver förmodligen kunna ha allokering för att göra det dynamiskt
    
    parameter c är för vilken typ av tidstest vi vill ha alltså bästa, sämsta eller det genomsnittliga
    */

    for(int i = 0; i < n;i++) {
        generateDataArray(array,n,c);


        switch(a) {
            case 1:

                break;

            case 2:
            
                break;

            case 3:
            
                break;

            case 4:
            
                break;

            case 5:
            
                break;

            
        }
        
        
    }
}
