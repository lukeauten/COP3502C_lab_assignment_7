#include <stdio.h>
#include <stdlib.h>

void copyArray(int array1[], int array2[]){
    for(int i = 0; i < 9; i++){
        array1[i] = array2[i];
    }
}

int swap(int array[], int index1, int index2){
    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

int bubbleSort(int array[], int length, int totalSwaps){
    int swaps = 0;
    for(int i = length; i > 0; i--){

        for (int j = length - 1; j > 0; j--){
            if(array[j] < array[j-1]){
                swap(array, j, j-1);
                swaps++;
            }
        }
        printf("%d: %d \n", array[length - i], swaps);
        totalSwaps += swaps;
        swaps = 0;
    }
    return totalSwaps;
}

int selectionSort(int array[], int length, int totalSwaps){
    int minimumIndex, swaps = 0;
    for(int i = 0; i < length; i++){
        minimumIndex = i;
        for(int j = i + 1; j < length; j++){
            if(array[j] < array[minimumIndex]){
                minimumIndex = j;
            }
        }
        if(minimumIndex != i){
            swap(array, minimumIndex, i);
            swaps++;
        }
        printf("%d: %d \n", array[i], swaps);
        totalSwaps += swaps;
        swaps = 0;
    }
    return totalSwaps;
}

void main(){

    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int arrayTemp[9];
    int totalNumSwaps = 0;

    copyArray(arrayTemp, array1);
    printf("array1 bubble sort: \n");
    totalNumSwaps = bubbleSort(arrayTemp, 9, totalNumSwaps);
    printf("%d total swaps \n", totalNumSwaps);
    totalNumSwaps = 0;

    copyArray(arrayTemp, array2);
    printf("array2 bubble sort: \n");
    totalNumSwaps = bubbleSort(arrayTemp, 9, totalNumSwaps);
    printf("%d total swaps \n", totalNumSwaps);
    totalNumSwaps = 0;

    copyArray(arrayTemp, array1);
    printf("array1 selection sort: \n");
    totalNumSwaps = selectionSort(arrayTemp, 9, totalNumSwaps);
    printf("%d total swaps \n", totalNumSwaps);
    totalNumSwaps = 0;

    copyArray(arrayTemp, array2);
    printf("array2 selection sort: \n");
    totalNumSwaps = selectionSort(arrayTemp, 9, totalNumSwaps);
    printf("%d total swaps \n", totalNumSwaps);
    totalNumSwaps = 0;
}