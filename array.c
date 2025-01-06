// Implementing array - abstract data type.

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void welcomeScreen();
void screenCleaner();
void tryAgain();

void insertion();
void atBeginning();

void printA();
int isArrayFull();
int isArrayEmpty();

#define n 20

int array[n] = {0};
int head = 0;
int tail = -1;

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
        // case 2: 
        //     deletion();
        //     break;
        // case 3:
        //     search();
        //     break;
        // case 4:
        //     reverse();
        //     break;
        // case 5:
        //     min_max();
        //     break;
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

int isArrayFull() {
    if(tail >= n - 1) {
        return 1;
    } else {
        return 0;
    }
}

int isArrayEmpty() {
    if(tail == -1) {
        return 1;
    } else {
        return 0;
    }
}

void printA() {
    int i;
    
    for(i = head; i <= tail; i++) {
        printf(" %d |", array[i]);
    }
    printf("\n");
}

void insertion() {

    int choice1;

    screenCleaner();

    if(isArrayFull()) {
        printf("Alert! Array is full.\n");
        printf("Press any key to continue...");
        getch();
        welcomeScreen();
    } 
label2:
    screenCleaner();
    printf("-- Insertion\n\n");
    printf("Options: \n");
    printf("> 1. At the beginning.\n");
    printf("> 2. At a specific index.\n");
    printf("> 3. At the end.\n");
    printf("> 4. In a sorted array.\n");
    printf("> 5. exit from this section.\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice1);

    switch(choice1) {
        case 1:
            atBeginning();
            printA();
            tryAgain();
            break;
        case 5:
            welcomeScreen();
            break;
        default:
            printf("\nError! choose from the given options.");
            printf("\nPress any key to continue...");
            getch();
            goto label2;
    }
}

void atBeginning() {
    int data, i;

    printf("\ndata: ");
    scanf("%d", &data);

    if(isArrayEmpty()) {
        array[0] = data;
        tail++;
    } else {
        for(i = tail; i >= head; i--) {
            array[i + 1] = array[i];
        }
        tail++;
    }
    
}

void tryAgain() {
    char ch;

    printf("\nDo you want to try again [y/N]: ");
    scanf(" %c", &ch);

    switch(ch) {
        case 'y':
        case 'Y':
            insertion();
            break;
        case 'n':
        case 'N':
            welcomeScreen();
            break;
        default:
            printf("\nError: invalid input. \n");
            printf("Press any key to continue... \n");
            getch();
            welcomeScreen();
    }
}

void screenCleaner() {
    system("cls");
    fflush(stdin);
}