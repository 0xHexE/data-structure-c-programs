#include <stdio.h>
#include <stdlib.h>

void unionArray(int *, int , int *, int , int *);
void intersectArray(int *, int , int *, int , int *);
void subtractArray(int *, int ,  int *, int , int *);

void fillArray(int *, int , int );
void printArraySet(int *array, int sizeOfArray);
void getArraySet(int *, int, char *);

void setProgram() {
    int array1[5], array2[5], resultArray[10], choice;
    while (1) {
        getArraySet(array1, 5, "Array 1");
        getArraySet(array2, 5, "Array 2");
        printf("Menu\n"
               "\t\t1.Union All\n"
               "\t\t2.Intersect\n"
               "\t\t3.Subtraction\n"
               "\t\t4.Exit\n"
               "\t\tEnter Your Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                unionArray(array1, 5, array2, 5, resultArray);
                printArraySet(resultArray, 10);
                break;
            case 2:
                intersectArray(array1, 5, array2, 5, resultArray);
                printArraySet(resultArray, 10);
                break;
            case 3:
                printf("\n\t\t1.A-B"
                       "\n\t\t2.B-A\nSelect Your choice: ");
                scanf("%d", &choice);
                switch (choice) {
                    case 1:
                        subtractArray(array1, 5, array2, 5, resultArray);
                        printArraySet(resultArray, 10);
                        break;
                    case 2:
                        subtractArray(array2, 5, array1, 5, resultArray);
                        printArraySet(resultArray, 10);
                        break;
                    default:
                        printf("Invalid choice");
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice");
        }
    }
}

/*
 * It get array
 */
void getArraySet(int *array, int number, char *string) {
    int i;
    for (i = 0; i < number; i++) {
        printf("Enter %s at %d: ", string, i);
        scanf("%d", &array[i]);
    }
}

void printArraySet(int *array, int sizeOfArray) {
    for (int i = 0; i < sizeOfArray; ++i) {
        if (i == 0)
            printf("{");
        printf(" %d,", array[i]);
        if (i == sizeOfArray - 1)
            printf("\b}\n");
    }
}

/*
 * This function join to integer array.
 */
void unionArray(int *array1, int array1Size, int *array2, int array2Size, int *resultArray) {
    int i, j, temp;
    for (i = 0; i < array1Size; i++) {
        resultArray[i] = array1[i];
    }
    temp = array1Size;
    for (i = 0; i < array2Size; i++) {
        for (j = 0; j < array1Size; j++) {
            if (array2[i] == array1[j]) {
                break;
            }
        }
        if (j == 5) {
            resultArray[temp++] = array2[i];
        }
    }
    fillArray(resultArray, temp, array1Size + array2Size);
}

/*
 * This function intersect two array
 */
void intersectArray(int *array1, int array1Size, int *array2, int array2Size, int *resultArray) {
    int i, j, temp = 0;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (array1[i] == array2[j]) {
                resultArray[temp++] = array1[i];
                break;
            }
        }
    }
    fillArray(resultArray, temp, array1Size + array2Size);
}

void subtractArray(int *array1, int array1Size,  int *array2, int array2Size, int *resultArray) {
    int i, j, temp = 0;
    for (i = 0; i < array1Size; i++) {
        for (j = 0; j < array2Size; j++) {
            if (array1[i] == array2[j]) {
                break;
            }
        }
        if (j == 5) {
            resultArray[temp++] = array1[i];
        }
    }
    fillArray(resultArray, temp, 10);
}

/*
 * It fills the array rest with 0
 */
void fillArray(int *resultArray, int start, int end) {
    int i;
    for (i = start; i < end; i++) {
        resultArray[i] = 0;
    }
}
