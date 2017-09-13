//
// Created by Omkar Yadav on 9/13/17.
//
#include <stdio.h>
#include <stdlib.h>

struct List {
    int data;
    struct List *next;
};

void insert(struct List **head, struct List *location);
void delete_from_list(struct List **head, struct List **location);
void search_in_list(struct List *head, int data, struct List **result, struct List **priv);
void update_in_list(struct List *head, int data);
void traverse(struct List *head, struct List *location, struct List **result, int printData);

void link_list() {
    int temp, temp2;
    struct List *head = NULL, *temp_list = NULL, *temp2_list = NULL;

    printf("Program developed by Omkar Yadav");

    while (1) {
        printf("\nMenu\n1.Insert\n2.Delete\n3.Search\n4.Update\n5.Display\nEnter your choice: ");
        scanf("%d", &temp);
        temp_list = NULL;
        temp2_list = NULL;
        switch (temp) {
            case 1:
                if (head == NULL) {
                    insert(&head, NULL);
                } else {
                    printf("\nMenu\n1.Insert at head\n2.Insert at any location\n3.Insert at end\nEnter your choice: ");
                    scanf("%d", &temp);
                    switch (temp) {
                        case 1:
                            insert(&head, head);
                            break;
                        case 2:
                            printf("Enter data to search: ");
                            scanf("%d", &temp);
                            search_in_list(head, temp, &temp_list, NULL);
                            if (temp_list == NULL) {
                                printf("Data not found");
                                break;
                            }
                            insert(&head, temp_list);
                            break;
                        case 3:
                            insert(&head, NULL);
                            break;
                    }
                }
                break;
            case 2:
                printf("Enter data to search: ");
                scanf("%d", &temp);
                temp2_list = NULL;
                search_in_list(head, temp, &temp_list, &temp2_list);
                if (temp_list == NULL) {
                    printf("Data not found");
                    break;
                }
                delete_from_list(&head, &temp2_list);
                break;
            case 3:
                printf("Enter data to search: ");
                scanf("%d", &temp);
                search_in_list(head, temp, &temp_list, NULL);
                if (temp_list == NULL) {
                    printf("Data not found");
                    break;
                }
                printf("Data found at %p and data is %d", temp_list, temp_list -> data);
                break;
            case 4:
                printf("Enter data to search: ");
                scanf("%d", &temp);
                search_in_list(head, temp, &temp_list, NULL);
                if (temp_list == NULL) {
                    printf("Data not found");
                    break;
                }
                printf("Enter data to update: ");
                scanf("%d", &temp2);
                update_in_list(temp_list, temp2);
                break;
            case 5:
                traverse(head, NULL, &temp_list, 1);
                break;
        }
    }
}

void insert(struct List **head, struct List *location) {
    struct List *temp, *temp2;
    int temp_data;

    temp = (struct List *) malloc(sizeof(struct List));

    if (temp == NULL) {
        return;
    }

    printf("Enter the data: ");
    scanf("%d", &temp_data);
    temp -> data = temp_data;
    temp -> next = NULL;

    if (*head == NULL) {
        *head = temp;
        return;
    }

    if (location == NULL) {
        traverse(*head, NULL, &temp2, 0);
        temp2 -> next = temp;
    } else if (location == *head) {
        printf("\n%p - %p\n", location, head);
        temp2 = *head;
        *head = temp;
        (*head) -> next = temp2;
    } else {
        temp2 = location -> next;
        temp -> next = temp2;
        location = temp;
    }

}

void delete_from_list(struct List **head, struct List **location) {
    struct List *temp = NULL;
    if (*location == NULL) {
        temp = (*head) -> next;
        temp -> next = (*head) -> next;
        *head = temp;
    }
    if ((*location) -> next != NULL) {
        temp = (*location) -> next -> next;
    }
    free((*location) -> next);
    (*location) -> next = temp;
}

void search_in_list(struct List *head, int data, struct List **result, struct List **priv) {
    struct List *temp = head, *temp2;

    while (temp -> data != data) {
        if (priv != NULL)
            temp2 = temp;
        if (temp -> next == NULL) {
            *result = NULL;
            return;
        }
        temp = temp -> next;
    }
    if (priv != NULL)
        *priv = temp2;
    *result = temp;
}

void update_in_list(struct List *head, int data) {
    ;
}

void traverse(struct List *head, struct List *location, struct List **result, int printData) {
    struct List *temp = head, *temp2;
    while (temp != location) {
        if (printData == 1)
            printf("data at %p is %d and next is %p\n", temp, temp -> data, temp -> next);
        temp2 = temp;
        temp = temp -> next;
    }
    if (location == NULL) {
        *result = temp2;
    } else {
        *result = temp;
    }
}
