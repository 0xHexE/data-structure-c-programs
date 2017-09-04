//
// Created by ok on 9/3/17.
//
#include <stdio.h>
#include <stdlib.h>

#include "set_program.c"
#include "sort_methods.c"
#include "search.c"

int main() {
    int choice;
    printf("Menu"
           "\n1.SET Operations"
           "\n2.Sort"
           "\n3.Search"
           "\n4.Exit"
           "\nEnter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            setProgram();
            break;
        case 2:
            sortMethod();
            break;
        case 3:
            searchProgram();
            break;
        case 4:
            printf("Thank You!");
            exit(0);
        default:
            printf("Enter valid option");
    }
    return 1;
}
