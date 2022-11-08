/**********************************************************
 * PROGRAM NAME: LinearSearch.c                           *
 *                                                        *
 * PURPOSE: A program that performs a linear search (O(N))*
 *          on an array of random generated integers.     *
 *                                                        *
 * AUTHOR: coderlaw                                       *
 * DATE: 08/11/2022                                       *
 *********************************************************/

/* Pre-Processor Directives */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

/* Function Prototypes */
void random_int_list_gen(int *numList, int searchSize);
void print_int_array(int *numList, int searchSize);
void linear_search(int *numList, int searchSize, 
    int numToSearch);

/* Functions */
void main(){
    
    const int MAX_INPUT = 10;
    char buffer[MAX_INPUT];
    int searchSize, numToSearch;

    printf("Enter in the number of integers you would like "
        "to generate: ");

    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &searchSize);

    int *numList = calloc(searchSize, sizeof(*numList));
    random_int_list_gen(numList, searchSize);

    print_int_array(numList, searchSize);

    printf("Enter in the number for which you would like "
        "to search: ");

    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &numToSearch);

    linear_search(numList, searchSize, numToSearch);

    free(numList);
}

/* Generate a pseudo-random integer list */
void random_int_list_gen(int *numList, int searchSize){
    
    srand(time(NULL));
    
    for(int i = 0; i < searchSize; i++){
        numList[i] = rand() % 100;
    }
}

/* Print out an integer array */
void print_int_array(int *numList, int searchSize){

    printf("\n");
    for(int i = 0; i < searchSize; i++){
        printf("%d ", numList[i]);
    }
    printf("\n\n");
}

/* Linear search for first instance of integer in array */
void linear_search(int *numList, int searchSize, 
    int numToSearch){

    bool found = false;

    for(int i = 0; i < searchSize; i++){
        if(numList[i] == numToSearch){
            found = true;
            printf("\nYour number, %d, was found in the "
                "list at position %d.\n", numToSearch, i+1);
            break;
        }
    }
    
    if(!found){
        printf("Your number, %d, was not found in the list."
        "\n", numToSearch);
    }
}