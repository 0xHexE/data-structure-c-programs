//
// Created by Omkar Yadav on 9/18/17.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILEPATH "temp/data.txt"

struct StudentData {
    int roll_number;
    char name[50];
};

void modify_record(struct StudentData students[]);
void display_records(struct StudentData students[]);
void load_records(struct StudentData student_db[], FILE **file_pointer);
void add_record(struct StudentData student_db[], FILE **file_pointer);
void remove_record(struct StudentData student_db[]);
int search_record(struct StudentData student_db[]);
void write_to_file(struct StudentData student_db[], FILE *file_pointer);
struct StudentData get_data();

int current_record = 0;

void file_operation() {
    FILE *file_pointer;
    struct StudentData student_data[100];
    int choice;
    load_records(student_data, &file_pointer);
    printf("Program is developed by Omkar Yadav");
    while (1) {
        printf("\nMenu\n1.Display students\n2.Add student\n3.Search student\n4.Modify student\n5.Remove student\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                display_records(student_data);
                break;
            case 2:
                add_record(student_data, &file_pointer);
                break;
            case 3:
                choice = search_record(student_data);
                if (choice == -1)
                    printf("Data not found");
                else
                    printf("Roll number: %d, name: %s", student_data[choice].roll_number, student_data[choice].name);
                break;
            case 4:
                modify_record(student_data);
                write_to_file(student_data, file_pointer);
                break;
            case 5:
                remove_record(student_data);
                write_to_file(student_data, file_pointer);
                break;
            default:
                printf("Invalid choice");
        }
        if (file_pointer != NULL) {
            fclose(file_pointer);
            file_pointer = NULL;
        }
    }
}

void display_records(struct StudentData students[]) {
    int i;
    printf("%4s %s\n", "No.", "Name");
    for (i = 0; i < current_record; ++i) {
        printf("%4d %s\n", students[i].roll_number, students[i].name);
    }
}

void add_record(struct StudentData student_db[], FILE **file_pointer) {
    struct StudentData student;
    printf("Enter Roll number: ");
    scanf("%d", &student.roll_number);
    printf("Enter Name: ");
    scanf("%49s", student.name);
    *file_pointer = fopen(FILEPATH, "a");
    fprintf(*file_pointer, "%d,%s\n", student.roll_number, student.name);
    student_db[current_record++] = student;
}

void load_records(struct StudentData student_db[], FILE **file_pointer) {
    char line[256];
    if ((*file_pointer = fopen(FILEPATH, "r")) == NULL)
        return;
    while (fgets(line, sizeof(line), *file_pointer)) {
        char *token = strtok(line, ",");
        student_db[current_record].roll_number = atoi(token);
        strcpy(student_db[current_record++].name, strtok(NULL, "\n"));
    }
}

void remove_record(struct StudentData student_db[]) {
    int data = search_record(student_db), i;
    if (data == -1)
        printf("Data not found");
    for (i = data; i < current_record; ++i) {
        student_db[i] = student_db[i + 1];
    }
    current_record--;
}

void write_to_file(struct StudentData student_db[], FILE *file_pointer) {
    int i;
    file_pointer = fopen(FILEPATH, "w");
    for (i = 0; i < current_record; ++i) {
        fprintf(file_pointer, "%d,%s\n", student_db[i].roll_number, student_db[i].name);
    }
    fclose(file_pointer);
}

int search_record(struct StudentData student_db[]) {
    int i, roll_number;
    printf("Enter roll number to find: ");
    scanf("%d", &roll_number);
    for (i = 0; i < current_record; ++i) {
        if (student_db[i].roll_number == roll_number)
            return i;
    }
    return -1;
}

void modify_record(struct StudentData students[]) {
    int record_data = search_record(students);
    if (record_data == -1) {
        printf("Data not found");
        return;
    }
    else
        students[record_data] = get_data();
}

struct StudentData get_data() {
    struct StudentData student;
    printf("Enter Roll number: ");
    scanf("%d", &student.roll_number);
    printf("Enter Name: ");
    scanf("%49s", student.name);
    return student;
}
