//
// Created by Omkar Yadav on 9/13/17.
//
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

struct List {
    int data;
    struct List *next;
};

void print_link_list(struct List *head);
void insert_at_link(struct List **location, struct List *priv, int end);
void traverse(struct List *head, int data, struct List **result, struct List **priv);
void search_in_link_list(struct List *head, struct List **result, struct List **priv);

void link_list() {
    int temp;
    struct List *head = NULL, *l_temp1, *l_temp2;
    printf("Program is developed by Omkar Yadav");
    while (1) {
        printf("\nMenu\n1.Display\n2.Insert\nEnter your choice: ");
        scanf("%d", &temp);
        l_temp1 = NULL;
        l_temp2 = NULL;
        switch (temp) {
            case 1:
                print_link_list(head);
                break;
            case 2:
                if (head == NULL) {
                    insert_at_link(&head, NULL, FALSE);
                } else {
                    printf("\nMenu\n1.Insert at head\n2.Insert at anywhere\n3.Insert at end\nEnter your choice: ");
                    scanf("%d", &temp);
                    switch (temp) {
                        case 1:
                            insert_at_link(&head, NULL, FALSE);
                            break;
                        case 2:
                            search_in_link_list(head, &l_temp1, &l_temp2);
                            insert_at_link(&l_temp1, l_temp2, FALSE);
                            break;
                        case 3:
                            l_temp1 = head;
                            while (l_temp1 -> next != NULL) {
                                l_temp1 = l_temp1 -> next;
                            }
                            insert_at_link(&l_temp1, NULL, TRUE);
                    }
                }
                break;
        }
    }
}

void print_link_list(struct List *head) {
    while (head != NULL) {
        printf("Data at %p is %d and next is %p\n", head, head -> data, head -> next);
        head = head -> next;
    }
}

void insert_at_link(struct List **location, struct List *priv, int end) {
    struct List *temp, *temp2 = *location, *temp3;
    temp = (struct List *) malloc(sizeof(struct List));

    printf("Enter data: ");
    scanf("%d", &(temp -> data));
    temp -> next = NULL;

    if (end == TRUE) {
        (*location) -> next = temp;
        return;
    }

    if (*location != NULL) {
        temp -> next = (*location) -> next;
    }

    if (priv == NULL) {
        *location = temp;
    } else {
        priv -> next = temp;
    }
}

void traverse(struct List *head, int data, struct List **result, struct List **priv) {
    *priv = NULL;
    *result = NULL;
    while (head != NULL) {
        if (head -> data == data) {
            *result = head;
            return;
        }
        *priv = head;
        head = head -> next;
    }
}

void search_in_link_list(struct List *head, struct List **result, struct List **priv) {
    int temp;
    printf("Enter the data: ");
    scanf("%d", &temp);
    traverse(head, temp,result, priv);
}
