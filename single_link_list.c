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

void print_node(struct List *location);
void print_link_list(struct List *head);
void insert_at_link(struct List **location, struct List *priv, int end);
void traverse(struct List *head, int data, struct List **result, struct List **priv);
void search_in_link_list(struct List *head, struct List **result, struct List **priv);
void update_node(struct List *node);
void delete_node(struct List **current, struct List *priv);
void reverse_list(struct List **head);

void link_list() {
    int temp;
    struct List *head = NULL, *l_temp1, *l_temp2;
    printf("Program is developed by Omkar Yadav");
    while (1) {
        printf("\nMenu\n1.Display\n2.Insert\n3.Search\n4.Update\n5.Delete\n6.Reverse\nEnter your choice: ");
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
            case 3:
                search_in_link_list(head, &l_temp1, &l_temp2);
                if (&l_temp1 != NULL)
                    print_node(l_temp1);
                else
                    printf("Data not found");
                break;
            case 4:
                search_in_link_list(head, &l_temp1, &l_temp2);
                update_node(l_temp1);
                break;
            case 5:
                search_in_link_list(head, &l_temp1, &l_temp2);
                delete_node(&l_temp1, l_temp2);
                break;
            case 6:
                reverse_list(&head);
                print_link_list(head);
        }
    }
}

void print_link_list(struct List *head) {
    while (head != NULL) {
        print_node(head);
        head = head -> next;
    }
}

void print_node(struct List *location) {
    printf("Data at %p is %d and next is %p\n", location, location -> data, location -> next);
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
        temp -> next = *location;
        *location = temp;
    } else {
        temp -> next = priv -> next;
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

void update_node(struct List *node) {
    int temp;
    printf("Enter the data: ");
    scanf("%d", &temp);
    node -> data = temp;
}

void delete_node(struct List **current, struct List *priv) {
    struct List *temp = *current;

    if (priv != NULL) {
        priv -> next = (*current) -> next;
    }
    else {
        *current = (*current) -> next;
    }

    free(temp);
    temp = NULL;
}

void reverse_list(struct List **head) {
    struct List *previous_node = NULL, *current_node = *head, *next_node;
    while (current_node != NULL) {
        next_node = current_node -> next;
        current_node -> next = previous_node;
        previous_node = current_node;
        current_node = next_node;
    }
    *head = previous_node;
}
