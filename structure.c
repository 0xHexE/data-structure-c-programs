//
// Created by Omkar Yadav on 9/14/17.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ALIAS current_rec = Current Record
// ALIAS rn = roll_number

struct Student {
    int roll_number;
    char name[30];
    float marks;
};

void display_struct(struct Student data[]);
void insert_struct(struct Student data[], int record);
int search_struct(struct Student data[], int roll_number);
void delete_struct(struct Student data[], int index);
void display_data(char *name, int rn, float marks);

int current_rec = 0;

void structure() {
    struct Student data[100];
    int choice, i;
    printf("Devloped by Omkar Yadav");
    while (1) {
        printf("\nMenu\n1.Insert\n2.Display\n3.Search\n4.Update\n5.Delete\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter how much records you want insert: ");
                scanf("%d", &choice);
                for (i = 0; i < choice; i++ )
                    insert_struct(data, current_rec);
                break;
            case 2:
                display_struct(data);
                break;
            case 3:
                printf("Enter roll number to search: ");
                scanf("%d", &choice);
                choice = search_struct(data, choice);
                if (choice == -1)
                    printf("Data not found");
                else {
                    printf("Data found at %d\n", choice);
                    display_data(data[choice].name, data[choice].roll_number, data[choice].marks);
                }
                break;
            case 4:
                printf("Enter roll number to update: ");
                scanf("%d", &choice);
                choice = search_struct(data, choice);
                if (choice == -1)
                    printf("Data not found");
                else
                    insert_struct(data, choice);
                break;
            case 5:
                printf("Enter roll number to delete: ");
                scanf("%d", &choice);
                choice = search_struct(data, choice);
                if (choice == -1)
                    printf("Data not found");
                else
                    delete_struct(data, choice);
                break;
        }
    }
}

void display_struct(struct Student data[]) {
    int i;
    printf("\n%-30s%-10s%-10s\n", "Name", "Roll No", "Marks");
    for (i = 0; i < current_rec; i++) {
        display_data(data[i].name, data[i].roll_number, data[i].marks);
    }
}

void display_data(char *name, int rn, float marks) {
    printf("%-30s%-10d%-10.2f\n", name, rn, marks);
}

void insert_struct(struct Student data[], int record) {
    char name[100];
    int roll;
    float marks;
    printf("Enter name, roll number, marks: ");
    scanf("%s%d%f", name, &roll, &marks);
    if (search_struct(data, roll) != -1 && current_rec == record) {
        printf("Data is already exist\n");
        return;
    } else {
        strcpy(data[record].name, name);
        data[record].roll_number = roll;
        data[record].marks = marks;
    }
    if (record == current_rec) {
        current_rec++;
    }
}

int search_struct(struct Student data[], int roll_number) {
    int i;
    for (i = 0; i < current_rec; i++) {
        if ( data[i].roll_number == roll_number ) {
            return i;
        }
    }
    return -1;
}

void delete_struct(struct Student data[], int index) {
    int i;
    for (i = index; i < current_rec; i++)
        data[i] = data[i+1];
    data[i].name[0] = '\0';
    data[i].marks = 0;
    data[i].roll_number = -1;
    current_rec--;
}
