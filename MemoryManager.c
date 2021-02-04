#include <stdio.h>
#include <stdlib.h>

/**
 * Compares two numbers and returns a positive integer, 0 or 
 * a negative integer if the first number is greater than, equal to
 * or less than the second number.
 * Assumes the numbers are of the type int.
 * Used when invoking the quicksort function.  
 */
int compare (const void * a, const void * b)
{
   return (*(int*)a - *(int*)b);
}


/**
 * Takes in an array of integers and the number of elements in the array 
 * as arguments.
 * Then it will sort and return the median of the sorted array. 
 * To keep things simple, it always returns
 * the element at index arr_size/2 even though the 
 * array size is even.
 */
int return_median(int *arr, int size)
{
   qsort(arr, size, sizeof(int), compare);
   return arr[size/2];
}


/**
 * Takes in a random number and maps it to the
 * range [100000 - 120000)
 */
int get_iteration_count(int rand)
{
    return (rand % 20000) + 100000;     
}

/**
 * Takes in a random number and maps it to the 
 * range [1000 - 1500)
 */
int get_arr_size(int rand)
{
    return (rand % 500) + 1000;
}

int get_running_count(){
    int k=0;                   
    //Here i declare and initialize my iteration counter
    int y = get_iteration_count(rand()); 
    // Get the number of itterations store it in y
    printf("[MemoryManager] Number of Iterations: %d\n", y); 
    // print y
    for (int i = 0; i<y; i++){   
        //for loop to itterate y times
        int size = get_arr_size(rand()); 
        // Generate an array size and 
        //map it to range [100000 -120000) using the provided utility function
        int* array = malloc(size*sizeof(int)); 
        // Allocate memory for the arary on the heap
            for (int j = 0; j < size; j++){
            array[j] = rand();
            // populate the array with random numbers
            }
        int median = return_median(array, size);
        // get median of array
        if (median%13 == 0){
           k++;
           // check if median is divisable by 13
           // if it is increment out itteration counter
        }
        free(array);
        // free allocated memory after each round
    }
    return k;
    // return total number of medians that were divisable by 13
}

