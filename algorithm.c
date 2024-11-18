#include "algorithm.h"
#include <stdio.h>
#include <stdlib.h>

//
// Private
//
//gör den static så den inte kan råkas använda i annan fil
static void parting(int *a, int low, int high) {
    //delar upp array i delar för att sedan slå ihop och då är array sorterad

    //finns det element att sortera
    if (low < high) {
        //pivot = utvalt värde
        int chosenValue = a[high];
        int i = low - 1;
        //kommer varje element från low(0) till high alltså just nu vanlig for loop iterering
        for (int j = low; j < high; j++) {
            //är värdet mindre än utvalda värdet då flyttas den till vänster om väret.
            if (a[j] <= chosenValue) {
                i++;
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        //rättar till det utvalda värdet som flyttades på(den blev osorterad)
        int temp = a[i + 1];
        a[i + 1] = a[high];
        a[high] = temp;

        int partingIndex = i + 1;
        
        //soterar nu om alla tal vänster å sen höger om det utvalda talet
        //vänster del
        parting(a, low, partingIndex - 1);
        //höger del
        parting(a, partingIndex + 1, high);
    }
}

//
// Public
//
void bubble_sort(int *a, int n)
{
	// TODO: bubble sort
    for(int i = 0; i < n - 1;i++) {
        for(int j = 0; j < n - i - 1;j++) {
            if(a[j] > a[j + 1]) {
                int temp;
                temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
            }
        }
    }
}

void insertion_sort(int *a, int n)
{
	// TODO: insertion sort
    
    /*
    sorterings metod som går ut på att dela upp lista i två delar, en sorterad och en icke sorterad.
    ta ett element från icke sorterad och placera in i rätt plats i den sorterade å loopa
    */

    for(int i = 1; i < n;i++) {
        //value kan egentligen vara vilket element som helst
        int value = a[i];
        int j = i - 1;
        //byter ut värdet brevid value
        while(j >=0 && a[j] < value) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = value;
    }
}

void quick_sort(int *a, int n)
{
	// TODO: quick sort
    /*
    splittar upp array i flera mindre arrayer och fortsätter göra så tills den är såppas liten så den automatiskt blir sorterad
    */     
    parting(a,0,n - 1);
}

bool linear_search(const int *a, int n, int v)
{

    //ska söka efter värde v i a finns det så ska den returna positionen? men här är det true/false?
    for(int i = 0; i < n;i++) {
        if(a[i] == v) {
            return true;
        }
    }
	return false; // TODO: linear search
}

bool binary_search(const int *a, int n, int v)
{

    /*
    Kommer ta in värde och kolla mitten först, om den ligger till höger(större än mitten) om mitten eller vänster(mindre än hälften) 
    är väl samma som linear, ska väl egentligen returnera position snarare än true/false om den hittas eller ej
    */
    int mid, left = 0, right = n - 1;

    while (left <= right) {
        mid = left + (right - left) / 2;

        return (a[mid] == v) 
            ? true 
            : (a[mid] < v) 
                ? (left = mid + 1, false) 
                : (right = mid - 1, false);
    }

	return false; // TODO: binary search
}
