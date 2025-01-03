// Implementing array - abstract data type.

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void welcomeScreen();
void screenCleaner();

void main() {
    welcomeScreen();
}

void welcomeScreen() {

    screenCleaner();
    
    printf("-- Demonstrating array as abstract data type.\n\n");

    printf("Read the options carefully and choose.\n");
    printf("> 1. Insertion.\n");
    printf("> 2. Deletion.\n");
    printf("> 3. Search an element\n");
    printf("> 4. Reverse the array.\n");
    printf("> 5. Min/max values.\n\n");

    printf("*NOTE: Before choosing options like deletion, searching,\n"
           "reverse the array, must insert enough elements.");

}

void screenCleaner() {
    system("cls");
    fflush(stdin);
}