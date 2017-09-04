//
// Created by ok on 9/4/17.
//
#include <stdio.h>

int binarySearch(int *array, int arraySize, int searchElement);
int linearSearch(int *array, int arraySize, int searchElement);

void getArray(int *, int, char *);

void searchProgram() {
    int temp, array[5];
    getArray(array, 5, "Array");
    printf("Menu\n"
           "1.Linear search\n"
           "2.Binary search\n"
           "3.Exit\n"
           "Enter your choice: ");
    scanf("%d", &temp);
    switch (temp) {
        case 1:
            printf("Enter the number to search: ");
            scanf("%d", &temp);
            temp = linearSearch(array, 5, temp);
            if (temp == -1)
                printf("Number not found");
            else
                printf("Number found at %d", temp);
            break;
        case 2:
            printf("Enter the number to search: ");
            scanf("%d", &temp);
            temp = binarySearch(array, 5, temp);
            if (temp == -1)
                printf("Number not found");
            else
                printf("Number found at %d", temp);
            break;
        default:
            printf("Invalid choice");
    }
}

int binarySearch(int *array, int arraySize, int searchElement) {
    int low = 0, high = arraySize, mid = (low + high) / 2;
    while (1) {
        if (low >= high) {
            return -1;
        }
        if (array[mid] == searchElement)
            return mid;
        if (array[mid] < searchElement) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
        mid = (low + high) / 2;
    }
}

int linearSearch(int *array, int arraySize, int searchElement) {
    int i;
    for (i = 0; i < arraySize; ++i) {
        if (array[i] == searchElement) {
            return i;
        }
    }
    return -1;
}

void getArray(int *array, int number, char *string) {
    int i;
    for (i = 0; i < number; i++) {
        printf("Enter %s at %d: ", string, i);
        scanf("%d", &array[i]);
    }
}
