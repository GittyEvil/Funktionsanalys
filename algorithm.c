#include "algorithm.h"
#include <stdio.h>
#include <stdlib.h>

//
// Private
//

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
        int value = a[i];
        int j = i - 1;

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
    //använda sig utav qsort?
    for(int i = 0; i < n;i++) {
        qsort(*a,n,sizeof(int),a[i] - a[i + 1]);
    }        
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

    //Kommer ta in värde och kolla mitten först, om den ligger till höger(större än mitten) om mitten eller vänster(mindre än hälften)
    int mid, left = 0, right = n - 1;

    while(low <= high) {
        if(arr[mid] == v) {
            return true;
        } else if(a[mid] < v) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
	return false; // TODO: binary search
}
