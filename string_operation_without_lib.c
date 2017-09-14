//
// Created by Omkar Yadav 9/14/17.
//

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int string_length(char []);
int palindrome(char *string);
void reverse(char *input, char *output);
int string_cmp(char string1[], char string2[]);
void string_sub(char string[], int start, int end, char out_string[]);
void string_concat(char string1[], char string2[], char out_string[]);
int string_length(char string[]);
void string_cpy(char string[], char out[]);

void string_operation_without_lib() {
    int choice, start, end;
    char string1[40], string2[40], result[100];
    printf("Devloped by Omkar Yadav");
    while (1) {
        printf("\nMenu\n1.Palindrome\n2.String Compare\n3.String Copy\n4.String Reverce\n5.Substring\n6.Concat\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter String: ");
                scanf("%s", string1);
                if (palidrome(string1) == TRUE) {
                    printf("String is paledrome\n");
                } else {
                    printf("String is not paledrome\n");
                }
                break;
            case 2:
                printf("Enter string 1: ");
                scanf("%s", string1);
                printf("Enter string 2: ");
                scanf("%s", string2);
                if (string_cmp(string1, string2) == 0) {
                    printf("String are equal");
                } else {
                    printf("String are not equal");
                }
                break;
            case 3:
                printf("Enter the string: ");
                scanf("%s", string1);
                string_cpy(string1, result);
                printf("output string %s", result);
                break;
            case 4:
                printf("Enter the string: ");
                scanf("%s", string1);
                reverce(string1, result);
                printf("Reverce String %s", result);
                break;
            case 5:
                printf("Enter the string:");
                scanf("%s", string1);
                printf("Enter start, end: ");
                scanf("%d%d", &start, &end);
                string_sub(string1, start, end, result);
                printf("Substring %s", result);
                break;
            case 6:
                printf("Enter two string: ");
                scanf("%s%s", string1, string2);
                string_concat(string1, string2, result);
                printf("Concat string is %s", result);
                break;
            case 7:
                printf("Enter string: ");
                scanf("%s", string1);
                printf("%d", string_length(string1));
                //Sub
                //con
        }
    }
}

int palidrome(char string[]) {
    char out_string[50];
    reverce(string, out_string);
    return string_cmp(out_string, string) == 0 ? TRUE : FALSE;
}

void reverce(char input[], char output[]) {
    int length = string_length(input), i, j = length - 1;
    for (i = 0; i < length; i++) {
        output[i] = input[--j];
    }
    output[i] = '\0';
}

int string_cmp(char string1[], char string2[]) {
    int i, j;
    for (i = 0, j = 0; i < string_length(string1) || j < string_length(string2); i++, j++) {
        if (string1[i] != string2[j]) {
            return -1;
        }
    }
    if (i == j) {
        return 0;
    } else if (i < j) {
        return j;
    } else {
        return -i;
    }
}

void string_sub(char string[], int start, int end, char out_string[]) {
    int i;
    for (i = start; i <= start + end; i++) {
        out_string[i - start] = string[i];
    }
    out_string[i] = '\0';
}

void string_concat(char string1[], char string2[], char out_string[]) {
    int i, string_1_length = string_length(string1), string_2_length = string_length(string2);
    string_cpy(string1, out_string);
    for(i = string_length (string1) - 1; i < string_2_length + string_1_length; i++) {
        out_string[i] = string2[i - string_1_length + 1];
    }
    out_string[i] = '\0';
}

void string_cpy(char string[], char out[]) {
    int i, length = string_length(string);
    for (i = 0; i < length; i++ ) {
        out[i] = string[i];
    }
    out[i] = '\0';
}

int string_length(char string[]) {
    int i = 0;
    char ch;
    do {
        ch = string[i++];
    } while(ch != '\0');
    return i;
}

