//
// Created by Omkar Yadav on 9/18/17.
//

#include <stdio.h>
#include <stdlib.h>

struct CircularLinkList {
    int coefficient, exponent;
    struct CircularLinkList *next;
};

void get_polynomial(struct CircularLinkList **polynomial);
void put_polynomial(struct CircularLinkList *polynomial);
void merge_polynomial(struct CircularLinkList *polynomial, int length);
void swapNumber(int *number1, int *number2);
void add_polynomial(struct CircularLinkList *first, struct CircularLinkList *second, struct CircularLinkList *result);

void main() {
    int choice;
    struct CircularLinkList *first = NULL, *second = NULL, *result = NULL;
    printf("Developed by Omkar Yadav");
    while (1) {
        printf("\nMenu"
                       "\n1.Get Polynomials"
                       "\n2.Display Polynomials"
                       "\n3.Add Polynomials"
                       "\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                get_polynomial(&first);
                get_polynomial(&second);
                break;
            case 2:
                put_polynomial(first);
                put_polynomial(second);
                break;
            case 3:
                add_polynomial(first, second, result);
                put_polynomial(result);
        }
    }
}

void get_polynomial(struct CircularLinkList **polynomial) {
    int number_of_elements, i;
    struct CircularLinkList *temp = NULL;
    *polynomial = NULL;
    printf("Enter number of entries");
    scanf("%d", &number_of_elements);
    for (i = 0; i < number_of_elements; ++i) {
        if (i != 0) {
            temp -> next = (struct CircularLinkList *) malloc(sizeof(struct CircularLinkList));
            temp = temp -> next;
        } else {
            temp = (struct CircularLinkList *) malloc(sizeof(struct CircularLinkList));
        }
        if (i == 0) {
            temp -> next = temp;
            *polynomial = temp;
        } else {
            temp -> next = *polynomial;
        }
        printf("Enter coefficient, exponent: ");
        scanf("%d%d", &(temp -> coefficient), &(temp -> exponent));
    }
    merge_polynomial(*polynomial, i);
}

void put_polynomial(struct CircularLinkList *polynomial) {
    struct CircularLinkList *head = polynomial;
    if (head != NULL) {
        do {
            if ((polynomial -> exponent ) == 0)
                printf("%d", (polynomial -> coefficient));
            else if ((polynomial -> exponent ) == 1)
                printf("%d+x", (polynomial -> coefficient));
            else
                printf("%d+x^%d", (polynomial -> coefficient), (polynomial -> exponent));
            polynomial = polynomial -> next;
            if (polynomial != head)
                printf(" + ");
            else
                printf("\n");
        } while (polynomial != head);
    }
}

void merge_polynomial(struct CircularLinkList *polynomial, int length) {
    struct CircularLinkList *head = polynomial, *temp = NULL, *previous = polynomial;
    if (head != NULL) {
        do {
            temp = polynomial -> next;
            do {
                if (polynomial -> exponent == temp -> exponent) {
                    polynomial -> coefficient += temp -> coefficient;
                    previous -> next = temp -> next;
                } else {
                    previous = temp;
                }
                temp = temp -> next;
            } while (temp != polynomial);
            polynomial = polynomial -> next;
        } while (polynomial != head);
    }
}

void add_polynomial(
        struct CircularLinkList *first,
        struct CircularLinkList *second,
        struct CircularLinkList *result
) {
    ;
}
