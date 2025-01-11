// Implementing array - abstract data type.

#include <stdio.h>      // for: input & output.
#include <conio.h>      // for: getch();
#include <stdlib.h>     // for: exit(), system();

void welcomeScreen();       // Introduction page & choice screen.
void screenCleaner();       // Clear the console screen & input buffer.
void tryAgain(int );        // Try again choice

// Insertion choice screen & function.
void insertion();
void atBeginning();
void atSpecificIndex();
void atEnd();

// Deletion choice screen & function.
void deletion();
void theFirstElement();
void aSpecificIndexValue();
void lastElement();
void specificElement();

// Search function.
void search();

// Sort function (- quick sort algorithm).
void sort();
void quickSort(int , int );
int partition(int , int );

// Reverse function.
void reverse();

// Returns min & max values.
void min_max();


// Print array element (- linear fashion);
void printA();

// Checker function.
int isArrayFull();
int isArrayEmpty();

// Defining fixed size array.
#define n 20

// Globally declaring array and pointers,
// reducing the number of parameters +acessibility accross functions.
int array[n] = {0};
int head = 0;
int tail = -1;

// C-program main function.
void main() {
    welcomeScreen();
}

// Welcome screen.
void welcomeScreen() {
    int choice;

label1:
    screenCleaner();
    
    printf("-- Demonstrating array as abstract data type.\n\n");

    printf("Read the options carefully and choose.\n");
    printf("> 1. Insertion.\n");
    printf("> 2. Deletion.\n");
    printf("> 3. Search an element\n");
    printf("> 4. Sort.\n");
    printf("> 5. Reverse the array.\n");
    printf("> 6. Min/max values.\n");
    printf("> 7. Exit the program.\n\n");

    printf("*NOTE: Before choosing options like deletion, searching,\n"
           "reverse the array, must insert enough elements.\n\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Calls functions as per user input.
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
            sort();
            break;
        case 5:
            reverse();
            break;
        case 6:
            min_max();
            break;
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

// Checker functions.
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

// Display resultant array.
void printA() {
    int i;
    
    printf("\nArray: |");
    for(i = head; i <= tail; i++) {
        printf(" %d |", array[i]);
    }
    printf("\n");
}

// Insertion function, including specific operations.
void insertion() {
    screenCleaner();

    int choice1;

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

// Deletion function, including specific operations.
void deletion() {
    screenCleaner();

    int choice2;

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
    printf("> 4. A specific element.\n");
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
        case 3:
            lastElement();
            printA();
            tryAgain(2);
            break;
        case 4:
            specificElement();
            printA();
            tryAgain(2);
            break;
        case 5:
            welcomeScreen();
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
        for(i = di; i <= tail; i++) {
            array[i] = array[i + 1];
        }
        tail--;
    }
}

void lastElement() {

    array[tail] = 0;
    tail--;
}

void specificElement() {
    int i, j, element, flag = 0;

    printf("\nelement: ");
    scanf("%d", &element);

    for(i = 0; i <= tail; i++) {
        if(array[i] == element) {
            flag++;
            break;
        }
    }

    if(flag == 1) {
        for(j = i; j <= tail; j++) {
            array[j] = array[j + 1];
        }
        tail--;
    } else {
        printf("\nWarning: Element not found!");
        printf("\nPress any key to continue...");
        getch();
        deletion();
    }
}

// Search specific element, returns it's index value.
void search() {
    int i, target, flag = 0;

    if(isArrayEmpty()) {
        printf("Alert! Array is empty.\n");
        printf("Press any key to continue...");
        getch();
        welcomeScreen();
    }

    screenCleaner();
    printA();

    printf("\nelement: ");
    scanf("%d", &target);

    for(i = 0; i <= tail; i++) {
        if(array[i] == target) {
            flag++;
            break;
        }
    }

    if(flag == 1) {
        printf("\nat index[%d]: %d", i, array[i]);
    } else {
        printf("\nelement not found!");
    }

    printf("\nPress any key to continue...");
    getch();
    welcomeScreen();
}

// Sort the array in ascending order & displays the result, before & after.
void sort() {
    screenCleaner();

    if(isArrayEmpty()) {
        printf("Alert! Array is empty.\n");
        printf("Press any key to continue...");
        getch();
        welcomeScreen();
    }

    printA();

    quickSort(head, tail);

    printA();

    printf("\nPress any key to continue...");
    getch();
    welcomeScreen();
}

void quickSort(int low, int high) {
    int pi; 

    if(low < high) {
        pi = partition(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

int partition(int low, int high) {
    int pivot, i, j, temp;

    pivot = array[high];
    i = (low - 1);

    for(j = low; j < high; j++) {
        if(array[j] <= pivot) {
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;

    return(i + 1);
}

// Reverse the array & displays the result, before & after.
void reverse() {
    screenCleaner();

    int left, right, temp = 0;

    left = head;
    right = tail;

    if(isArrayEmpty()) {
        printf("Alert! Array is empty.\n");
        printf("Press any key to continue...");
        getch();
        welcomeScreen();
    }

    printA();

    while(left < right) {
        temp = array[left];
        array[left] = array[right];
        array[right] = temp;

        left++;
        right--;
    }

    printA();

    printf("\nPress any key to continue...");
    getch();
    welcomeScreen();
}

// Returns the smallest & greatest number.
void min_max() {
    screenCleaner();

    int i, min, max;

    if(isArrayEmpty()) {
        printf("Alert! Array is empty.\n");
        printf("Press any key to continue...");
        getch();
        welcomeScreen();
    }

    printA();

    min = array[0];

    for(i = 1; i <= tail; i++) {
        if(array[i] < min) {
            min = array[i];
        }
    }
    printf("\nmin: %d", min);

    max = array[0];

    for(i = 1; i <= tail; i++) {
        if(array[i] > max) {
            max = array[i];
        }
    }
    printf("\nmax: %d", max);

    printf("\nPress any key to continue...");
    getch();
    welcomeScreen();
}


// Try again program.
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
    system("cls");      // Clears the console.
    fflush(stdin);      // Clears the input buffer.
}