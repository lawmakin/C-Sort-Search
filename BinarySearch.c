/***********************************************************
 * PROGRAM NAME: BinarySearch.c                            *
 *                                                         *
 * PURPOSE: A program that performs a binary search        *
 *          (O(log n)) on a sorted array of random         *
 *          generated integers.                            *
 *                                                         *
 * AUTHOR: coderlaw                                        *
 * DATE: 14/11/2022                                        *
 **********************************************************/

/* Pre-Processor Directives */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

/* Function Prototypes */
void random_int_list_gen(int *numList, int searchSize);
void print_int_array(int *numList, int searchSize);
int binary_search(int *numList, int searchSize, 
    int numToSearch, int *steps);
int int_compare(const void *val1, const void *val2);
void print_search_result(int result, int numToSearch, 
    int steps);

/* Functions */
void main()
{    
    const int MAX_INPUT = 10;
    char buffer[MAX_INPUT];
    int searchSize, numToSearch;

    printf("Enter in the number of integers you would like "
        "to generate: ");

    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &searchSize);

    int *numList = calloc(searchSize, sizeof(*numList));
    random_int_list_gen(numList, searchSize);

    qsort(numList, searchSize, sizeof(int), int_compare);

    print_int_array(numList, searchSize);

    printf("Enter in the number for which you would like "
        "to search: ");

    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &numToSearch);

    int steps = 0;
    int result = binary_search(numList, searchSize, 
        numToSearch, &steps);

    print_search_result(result, numToSearch, steps);

    free(numList);
}

/* Generate a pseudo-random integer list */
void random_int_list_gen(int *numList, int searchSize)
{   
    srand(time(NULL));
    
    for(int i = 0; i < searchSize; i++) {
        numList[i] = rand() % 100;
    }
}

/* Print out an integer array */
void print_int_array(int *numList, int searchSize)
{
    printf("\n");
    
    for(int i = 0; i < searchSize; i++) {
        printf("%d ", numList[i]);
    }
    
    printf("\n\n");
}

/* Binary search for first instance of integer in array */
int binary_search(int *numList, int searchSize, 
    int numToSearch, int *steps)
{
    int lower_bound = 0, upper_bound = searchSize-1, 
        midpoint = 0, value_midpoint = 0;

    while(lower_bound <= upper_bound) {
        *steps += 1;
        midpoint = (upper_bound + lower_bound)/2;

        value_midpoint = numList[midpoint];

        if(numToSearch == value_midpoint) {
            return midpoint;
        }
        else if(numToSearch < numList[midpoint]) {
            upper_bound = midpoint-1;
        }
        else if(numToSearch > numList[midpoint]) {
            lower_bound = midpoint+1;
        }
    }

    return -1;
}

/* Integer comparison for qsort */
int int_compare(const void *val1, const void *val2)
{
    const int *num1 = (const int*)val1;
    const int *num2 = (const int*)val2;

    /* alternative approach */
    /*if (num1 < num2) return -1;
    if (num1 > num2) return 1;
    return 0;*/

    return (*num1 > *num2) - (*num1 < *num2);
}

void print_search_result(int result, int numToSearch, 
    int steps)
{
    if(result >= 0) {
        printf("Your number to search, %d, was found at "
            "position %d in the list.\n", (numToSearch), 
            result);
    }
    else {
        printf("Your number to search, %d, was not found in"
        " the list.\n", numToSearch);
    }

    printf("\nYour search took %d steps to complete.\n", 
        (steps));
}