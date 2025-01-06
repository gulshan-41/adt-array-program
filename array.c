// Implementing array - abstract data type.

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void welcomeScreen();
void screenCleaner();
void tryAgain(int );

void insertion();
void atBeginning();
void atSpecificIndex();
void atEnd();

void deletion();
void theFirstElement();
void aSpecificIndexValue();

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
    printf("> 4. Sort.");
    printf("> 5. Reverse the array.\n");
    printf("> 6. Min/max values.\n");
    printf("> 7. Exit the program.\n\n");

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
        // case 3:
        //     search();
        //     break;
        // case 4:
        //     sort();
        //     break;
        // case 5:
        //     reverse();
        //     break;
        // case 6:
        //     min_max();
        //     break;
        case 7:
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
    printf("> 4. exit from this section.\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice1);

    switch(choice1) {
        case 1:
            atBeginning();
            printA();
            tryAgain(1);
            break;
        case 2:
            atSpecificIndex();
            printA();
            tryAgain(1);
            break;
        case 3:
            atEnd();
            printA();
            tryAgain(1);
            break;
        case 4:
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
        array[0] = data;
        tail++;
    }
    
}

void atSpecificIndex() {
    int i, idx, data;

    printf("\nindex: ");
    scanf("%d", &idx);
    printf("data: ");
    scanf("%d", &data);

    if(idx > tail) {
        printf("\nWarning: Enter a valid index!");
        printf("\nPress any key to continue...");
        getch();
        insertion();
    } else {
        for(i = tail; i >= idx; i--) {
            array[i + 1] = array[i];
        }
        array[idx] = data;
        tail++;
    }
}

void atEnd() {
    int data;

    printf("\ndata: ");
    scanf("%d", &data);

    array[tail + 1] = data;
    tail++;
}

void deletion() {
    int choice2;

    screenCleaner();

    if(isArrayEmpty()) {
        printf("Alert! Array is empty.\n");
        printf("Press any key to continue...");
        getch();
        welcomeScreen();
    } 
label3:
    screenCleaner();
    printf("-- Deletion.\n\n");
    printf("Options: \n");
    printf("> 1. The first element.\n");
    printf("> 2. A specific index value.\n");
    printf("> 3. The last element.\n");
    printf("> 4. a specific element.\n");
    printf("> 5. exit from this section.\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice2);

    switch(choice2) {
        case 1:
            theFirstElement();
            printA();
            tryAgain(2);
            break;
        case 2:
            aSpecificIndexValue();
            printA();
            tryAgain(2);
            break;
        default:
            printf("\nError! choose from the given options.");
            printf("\nPress any key to continue...");
            getch();
            goto label3;
    }
}

void theFirstElement() {
    int i;

    for(i = 0; i <= tail; i++) {
        array[i] = array[i + 1];
    }
    tail--;
}

void aSpecificIndexValue() {
    int i, di;

    printf("\nindex: ");
    scanf("%d", &di);

    if(di > tail) {
        printf("\nWarning: Enter a valid index!");
        printf("\nPress any key to continue...");
        getch();
        deletion();
    } else {
        for(i = di; i < tail; i++) {
            array[i] = array[i + 1];
        }
        tail--;
    }

    
}

void tryAgain(int choice) {
    char ch;

    printf("\nDo you want to try again [y/N]: ");
    scanf(" %c", &ch);

    switch(ch) {
        case 'y':
        case 'Y':
            if(choice == 1) {
                insertion();
            } else {
                deletion();
            }
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