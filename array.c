// Implementing array - abstract data type.

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void welcomeScreen();
void screenCleaner();
void insertion();
void atBeginning();
void printA();
int isArrayFull();

int array[20] = {0};
int counter = 0;

void main() {
    welcomeScreen();
}

void welcomeScreen() {

    int choice;

label1:
    screenCleaner();
    
    printf("-- Demonstrating array as abstract data type.\n\n");

    printf("Read the options carefully and choose.\n");
    printf("> 1. Insertion.\n");
    printf("> 2. Deletion.\n");
    printf("> 3. Search an element\n");
    printf("> 4. Reverse the array.\n");
    printf("> 5. Min/max values.\n");
    printf("> 6. Exit the program.\n\n");

    printf("*NOTE: Before choosing options like deletion, searching,\n"
           "reverse the array, must insert enough elements.\n\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: 
            insertion();
            break;
        case 2: 
            deletion();
            break;
        case 3:
            search();
            break;
        case 4:
            reverse();
            break;
        case 5:
            min_max();
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Error! choose from the given options.\n");
            printf("Press any key to exit...");
            getch();
            goto label1;

    } 

}

void insertion() {

    int flag, choice1;

    screenCleaner();
    flag = isArrayFull();

    if(flag == 1) {
        printf("Alert! Array is full.\n");
        printf("Press any key to continue...");
        getch();
        welcomeScreen();
    } 

    printf("-- Insertion\n\n");
    printf("Options: \n");
    printf("> 1. At the beginning.\n");
    printf("> 2. At a specific index.\n");
    printf("> 3. At the end.\n");
    printf("> 4. In a sorted array.\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice1);

    switch(choice1) {
        case 1:
            atBeginning();
            printA();
            break;
    }
}

void screenCleaner() {
    system("cls");
    fflush(stdin);
}