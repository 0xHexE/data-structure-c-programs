//
// Created by Omkar Yadav on 9/3/17.
//
#include <stdio.h>

void select_sort (int *array, int arraySize);
void bubble_sort(int *array, int arraySize);
void insertionSort(int *array, int arraySize);
void quickSort(int *array, int arraySize, int low, int high);
int quickSortPart(int *array, int low, int high);

// Optional Deps
void swap_number(int *number1, int *number2);
void getArraySort(int *array, int number, char *string);
void printArraySort(int *array, int sizeOfArray);

void sortMethod () {
    int choice, array[5];
    getArraySort(array, 5, "Array");
    printf("Menu"
           "\n1.Bubble sort"
           "\n2.Selection sort"
           "\n3.Quick sort"
           "\n4.Insertion sort"
           "\n5.Exit"
           "\n\t\tEnter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            bubble_sort(array, 5);
            printArraySort(array, 5);
            break;
        case 2:
            select_sort(array, 5);
            printArraySort(array, 5);
            break;
        case 3:
            quickSort(array, 5, 0, 5);
            printArraySort(array, 5);
            break;
        case 4:
            insertionSort(array, 5);
            printArraySort(array, 5);
            break;
        case 5:
            return;
        default:
            printf("Invalid choice");
    }
}

void select_sort (int *array, int arraySize) {
    int i, j;
    for (i = 0; i < arraySize; ++i) {
        for (j = i + 1; j < arraySize; ++j) {
            if (array[i] > array[j]) {
                swap_number(&array[i], &array[j]);
            }
        }
    }
}

void bubble_sort(int *array, int arraySize) {
    int i, j;
    for (i = 0; i < arraySize - 1; ++i) {
        for (j = 0; j < arraySize - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                swap_number(&array[j], &array[j + 1]);
            }
        }
    }
}

void insertionSort(int *array, int arraySize) {
    int i, j, temp;
    for (i = 0; i < arraySize; ++i) {
        temp = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > temp) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = temp;
    }
}

void quickSort(int *array, int arraySize, int low, int high) {
    int piot;
    if (low < high) {
        piot = quickSortPart(array, low, high);
        quickSort(array, arraySize, low, piot - 1);
        quickSort(array, arraySize, piot + 1, high);
    }
}

int quickSortPart(int *array, int low, int high) {
    int pivot = array[high], i, j;
    i = (low - 1);  // Index of smaller element
    for (j = low; j <= high- 1; j++) {
        if (array[j] <= pivot) {
            i++;
            swap_number(&array[i], &array[j]);
        }
    }
    swap_number(&array[i + 1], &array[high]);
    return (i + 1);
}

void swap_number(int *number1, int *number2) {
    int temp;
    temp = *number1;
    *number1 = *number2;
    *number2 = temp;
}

/*
 * It get array
 */
void getArraySort(int *array, int number, char *string) {
    int i;
    for (i = 0; i < number; i++) {
        printf("Enter %s at %d: ", string, i);
        scanf("%d", &array[i]);
    }
}

void printArraySort(int *array, int sizeOfArray) {
    for (int i = 0; i < sizeOfArray; ++i) {
        printf("\n%d", array[i]);
    }
}
