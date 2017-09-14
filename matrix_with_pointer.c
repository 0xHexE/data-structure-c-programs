//
// Created by Omkar Yadav on 9/14/17.
//

#include <stdio.h>
#include <stdlib.h>

// ALIAS mat = matrix
// ALIAS sz = size

void get_matrix(int **, int , int );
void put_matrix(int *, int , int );
void add_matrix(int *, int, int, int *, int, int);
void transpose(int *, int , int);
void mult_matrix(int *, int , int , int *, int , int );
int getFromArray(int *matrix1, int i, int j, int sz);

void matrix_with_pointer() {
    int *matrix1, *matrix2, temp, matrix_1_row, matrix_1_col, matrix_2_row, matrix_2_col, *result;
    printf("Developed by Omkar Yadav IT-1@83\n");
    while(1) {
        printf("\nMenu\n1.Get Matrix\n2.Print Matrix\n3.Add Matrix\n4.Multiply matrix\n5.Transpose\nEnter your choice: ");
        scanf("%d", &temp);
        switch(temp) {
            case 1:
                printf("\nMatrix 1:\n");
                printf("Enter row and column: ");
                scanf("%d%d", &matrix_1_row, &matrix_1_col);
                get_matrix(&matrix1, matrix_1_row, matrix_1_col);
                printf("\nMatrix 2: \n");
                printf("Enter row and column: ");
                scanf("%d%d", &matrix_2_row, &matrix_2_col);
                get_matrix(&matrix2, matrix_2_row, matrix_2_col);
                break;
            case 2:
                printf("\nMatrix 1:\n");
                put_matrix(matrix1, matrix_1_row, matrix_1_col);
                printf("\nMatrix 2:\n");
                put_matrix(matrix2, matrix_2_row, matrix_2_col);
                break;
            case 3:
                add_matrix(matrix1, matrix_1_row, matrix_1_col, matrix2, matrix_2_row, matrix_2_col);
                break;
            case 4:
                mult_matrix(matrix1, matrix_1_row, matrix_1_col, matrix2, matrix_2_row, matrix_2_col);
                break;
            case 5:
                transpose(matrix1, matrix_1_row, matrix_1_col);
                transpose(matrix2, matrix_2_row, matrix_2_col);
        }
    }
}

void get_matrix(int **mat, int matRow, int matCol) {
    int i, j;
    *mat = (int *) malloc(sizeof(int) * matRow * matCol);
    for (i = 0; i < matRow; i++) {
        for (j = 0; j < matCol; j++) {
            printf("Enter number at %d %d: ", i, j);
            scanf("%d", (*mat) + i * matCol + j);
            //printf("%d", *(mat + i * matCol + j));
        }
    }
}

void put_matrix(int *mat, int matRow, int matCol) {
    int i, j;
    printf("\n");
    for (i = 0; i < matRow; i++) {
        printf("[");
        for (j = 0; j < matCol; j++) {
            printf("\t%d", *(mat + (i * matCol + j)));
        }
        printf("]\n");
    }
}

void add_matrix(int *matrix1, int matrix_1_row, int matrix_1_col, int *matrix2, int matrix_2_row, int matrix_2_col) {
    int i ,j, result_mat[matrix_1_row][matrix_1_col];
    if (!(matrix_1_row == matrix_2_row && matrix_2_col == matrix_2_col)) {
        printf("Array size must be same\n");
        return;
    }
    for (i = 0; i < matrix_1_row; i++) {
        for (j = 0; j < matrix_1_col; j++) {
            result_mat[i][j] = *(matrix1 + (i * matrix_1_col + j)) + *(matrix2 + (i * matrix_2_col + j));
        }
    }
    put_matrix(result_mat, i, j);
}

void mult_matrix(int *matrix1, int matrix_1_row, int matrix_1_col, int *matrix2, int matrix_2_row, int matrix_2_col) {
    int i, j, k, result_matrix[matrix_1_row][matrix_2_col], temp = 0;
    for (i = 0; i < matrix_1_row; i++) {
        for (j = 0; j < matrix_1_col; j++) {
            for (k = 0; k < matrix_2_row; k++) {
                temp = temp + getFromArray(matrix1, i, k, matrix_1_col) * getFromArray(matrix2, k, j, matrix_2_col);
            }
            result_matrix[i][j] = temp;
            temp = 0;
        }
    }
    put_matrix(result_matrix, i, j);
}

int getFromArray(int *matrix1, int i, int j, int sz) {
    return *(matrix1 + i  * sz + j);
}

void transpose(int *matrix1, int matrix_1_row, int matrix_1_col) {
    int i, j, temp, result_matrix[matrix_1_col][matrix_1_row];
    for (i = 0; i < matrix_1_row; i++) {
        for (j = 0; j < matrix_1_col; j++) {
            result_matrix[j][i] = *(matrix1 + i * matrix_1_col + j);
        }
    }
    put_matrix(result_matrix, matrix_1_col, matrix_1_row);
}
