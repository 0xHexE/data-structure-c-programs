//
// Created by ok on 9/3/17.
//
#include <stdio.h>
#include <stdlib.h>

#include "set_program.c"
#include "sort_methods.c"
#include "search_program.c"
#include "single_link_list.c"
#include "matrix_with_pointer.c"
#include "string_operation_without_lib.c"
#include "structure.c"

int main() {
    int choice;
    printf("Menu"
           "\n1.SET Operations"
           "\n2.Sort"
           "\n3.Search"
           "\n4.Link List"
           "\n5.Matrix"
           "\n6.String"
           "\n7.Structure"
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
            link_list();
            break;
        case 5:
            matrix_with_pointer();
            break;
        case 6:
            string_operation_without_lib();
            break;
        case 7:
            structure();
            break;
        default:
            printf("Thank You!");
            exit(0);
    }
    return 1;
}
