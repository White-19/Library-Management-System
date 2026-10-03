#include<stdio.h>
#include<string.h>
#define MAX_BOOKS 100

struct Book {
    int id;
    char title[100];
    char author[100];
    int issued; //Available=0 & Issued=1
};

struct Book books[MAX_BOOKS];
int bookCount = 0;

void addBook();
void displayBooks();
void searchBook();
void issueBook();
void returnBook();
void deleteBook();

int main(void) {
    int choice;

    while (1) {
        printf("\n LIBRARY MANAGEMENT \n");
        printf("1.Add Books\n");
        printf("2.Disply Books\n");
        printf("3.Search Books\n");
        printf("4.Isuue Books\n");
        printf("5.Return Books\n");
        printf("6.Delete Books\n");
        printf("7.Exit\n");
        printf("\nEnter choice:\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;

            case 2:
                 displayBooks();
                break;

            case 3:
                searchBook();
                break;

            case 4:
                issueBook();
                break;

            case 5:
                returnBook();
                break;

            case 6:
                deleteBook();
                break;

            case 7:
                printf("\nThank you for using the Library Management System!\n");
                return 0;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Add a book
void addBook() {

    if (bookCount >= MAX_BOOKS) {
        printf("\nLibrary is full!\n");
        return;
    }

    printf("\nEnter Book ID: ");
    scanf("%d", &books[bookCount].id);

    printf("Enter Book Title: ");
    scanf(" %[^\n]", books[bookCount].title);

    printf("Enter Author Name: ");
    scanf(" %[^\n]", books[bookCount].author);

    books[bookCount].issued = 0;

    bookCount++;

    printf("\nBook added successfully!\n");
}


// Display all books
void displayBooks() {

    if (bookCount == 0) {
        printf("\nNo books available.\n");
        return;
    }

    printf("\n================ ALL BOOKS ================\n");

    for (int i = 0; i < bookCount; i++) {

        printf("\nBook ID     : %d\n", books[i].id);
        printf("Title       : %s\n", books[i].title);
        printf("Author      : %s\n", books[i].author);

        if (books[i].issued == 0)
            printf("Status      : Available\n");
        else
            printf("Status      : Issued\n");
    }
}


// Search a book
void searchBook() {

    int id;
    int found = 0;

    printf("\nEnter Book ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < bookCount; i++) {

        if (books[i].id == id) {

            printf("\nBook Found!\n");
            printf("Book ID : %d\n", books[i].id);
            printf("Title   : %s\n", books[i].title);
            printf("Author  : %s\n", books[i].author);

            if (books[i].issued == 0)
                printf("Status  : Available\n");
            else
                printf("Status  : Issued\n");

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nBook not found!\n");
    }
}


// Issue a book
void issueBook() {

    int id;

    printf("\nEnter Book ID to issue: ");
    scanf("%d", &id);

    for (int i = 0; i < bookCount; i++) {

        if (books[i].id == id) {

            if (books[i].issued == 1) {
                printf("\nBook is already issued!\n");
            }
            else {
                books[i].issued = 1;
                printf("\nBook issued successfully!\n");
            }

            return;
        }
    }

    printf("\nBook not found!\n");
}


// Return a book
void returnBook() {

    int id;

    printf("\nEnter Book ID to return: ");
    scanf("%d", &id);

    for (int i = 0; i < bookCount; i++) {

        if (books[i].id == id) {

            if (books[i].issued == 0) {
                printf("\nThis book was not issued.\n");
            }
            else {
                books[i].issued = 0;
                printf("\nBook returned successfully!\n");
            }

            return;
        }
    }

    printf("\nBook not found!\n");
}


// Delete a book
 void deleteBook() {

    int id;
    int found = 0;

    printf("\nEnter Book ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < bookCount; i++) {

        if (books[i].id == id) {

            found = 1;

            // Shift all books after this book one position left
            for (int j = i; j < bookCount - 1; j++) {
                books[j] = books[j + 1];
            }

            bookCount--;

            printf("\nBook deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("\nBook not found!\n");
    }
 }