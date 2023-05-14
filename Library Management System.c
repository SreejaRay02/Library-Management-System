#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOKS 100

struct Book {
    char title[50];
    char author[50];
    int borrowed;
};

struct Book library[MAX_BOOKS];
int bookCount = 0;

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Library is full. Cannot add more books.\n");
        return;
    }

    struct Book newBook;

    printf("Enter the title of the book: ");
    scanf("%s", &newBook.title);

    printf("Enter the author of the book: ");
    scanf("%s", &newBook.author);

    newBook.borrowed = 0;

    library[bookCount] = newBook;
    bookCount++;

    printf("Book added to the library.\n");
}

void borrowBook() {
    char title[50];
    int i;

    printf("Enter the title of the book to borrow: ");
    scanf("%s", &title);

    for (i = 0; i < bookCount; i++) {
        if (strcmp(title, library[i].title) == 0) {
            if (library[i].borrowed=1) {
                printf("Sorry, the book is already borrowed.\n");
            } else {
                library[i].borrowed =1;
                printf("Book borrowed successfully.\n");
            }
            return;
        }
    }

    printf("Book not found in the library.\n");
}

void returnBook() {
    char title[50];
    int i;

    printf("Enter the title of the book to return: ");
    scanf("%s", &title);

    for (i = 0; i < bookCount; i++) {
        if (strcmp(title, library[i].title) == 0) {
            if (library[i].borrowed) {
                library[i].borrowed = 0;
                printf("Book returned successfully.\n");
            } else {
                printf("The book is already in the library.\n");
            }
            return;
        }
    }

    printf("Book not found in the library.\n");
}

void displayInventory() {
    int i;

    printf("Current inventory:\n");

    if (bookCount == 0) {
        printf("No books in the library.\n");
    } else {
        for (i = 0; i < bookCount; i++) {
            printf("Book %d\n", i + 1);
            printf("Title: %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("Status: %s\n", library[i].borrowed ? "Borrowed" : "Available");
            printf("-------------------\n");
        }
    }
}

int main() {
    int choice;

    do {
        printf("\nLibrary Management System\n");
        printf("1. Add a book\n");
        printf("2. Borrow a book\n");
        printf("3. Return a book\n");
        printf("4. Display inventory\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("Exiting the program. Goodbye!\n");
                break;
            case 1:
                addBook();
                break;
            case 2:
                borrowBook();
                break;
            case 3:
                returnBook();
                break;
            case 4:
                displayInventory();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

