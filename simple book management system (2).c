#include <stdio.h>
#include <string.h>

// Define constants
#define MAX_BOOKS 100

// Define the Book structure
typedef struct {
    char title[51];
    char author[32];
    float price;
    int copies;
} Book;

// Declare global variables
Book books[MAX_BOOKS];
int bookCount = 0;

// Function prototypes
void showtheWelcomeMessage();
void showtheGoodByeMessage();
void showtheMenuOptions();
void showallBooks();
void addnewBook();
void searchfornewBook();
void showthetotalNumberOfBooks();

int main()
       {
    int choice;

    showWelcomeMessage();
    do {
        showMenuOptions();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: showBooks(); break;
            case 3: searchBook(); break;
            case 4: showNumberOfBooks(); break;
            case 5: printf("You chose Option 5.\n"); break;
            case 6: showGoodByeMessage(); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

// Display a custom welcome message
void showWelcomeMessage()
{
    printf("Welcome to the Simple Book Management System!\n");
}

// Display a custom goodbye message
void showGoodByeMessage()
{
    printf("Thanks for visiting this Book Management System!\n");
}

// Display menu options
void showMenuOptions()
{
    printf("\nMenu Options:\n");
    printf("1. add Book\n");
    printf("2. show All Books\n");
    printf("3. search Book by Title\n");
    printf("4. show Total Number of Book Copies\n");
    printf("5. [Optional Functionality]\n");
    printf("6. Exit\n");
}

// Add a new book
void addBook()
    {
    if (bookCount >= MAX_BOOKS) {
        printf("Book list is full. Cannot add more books.\n");
        return;
    }

    // Input the details for a new book
    printf("Enter the book title: ");
    getchar(); // Clear newline from buffer
    fgets(books[bookCount].title, 51, stdin);
    books[bookCount].title[strcspn(books[bookCount].title, "\n")] = '\0';

    printf("Enter the author's name: ");
    fgets(books[bookCount].author, 32, stdin);
    books[bookCount].author[strcspn(books[bookCount].author, "\n")] = '\0';

    printf("Enter the price: ");
    scanf("%f", &books[bookCount].price);

    printf("Enter the number of copies: ");
    scanf("%d", &books[bookCount].copies);

    bookCount++;
    printf("Book added successfully!\n");
}

// Show all books
void showBooks()
    {
    if (bookCount == 0) {
        printf("No books in the system.\n");
        return;
    }

    printf("\nList of Books:\n");
    for (int i = 0; i < bookCount; i++)
    {
        printf("Book %d:\n", i + 1);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Price: %.2f\n", books[i].price);
        printf("Copies: %d\n", books[i].copies);
        printf("\n");
    }
}

// Search for a book by title
void searchBook()
   {
    char searchTitle[51];
    int found = 0;

    printf("Enter the book title to search: ");
    getchar(); // Clear newline from buffer
    fgets(searchTitle, 51, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = '\0';

    for (int i = 0; i < bookCount; i++) {
        if (strcmp(books[i].title, searchTitle) == 0) {
            printf("Book found:\n");
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Price: %.2f\n", books[i].price);
            printf("Copies: %d\n", books[i].copies);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Book not found.\n");
    }
}

// Show the total number of book copies
void showNumberOfBooks()
    {
    int totalCopies = 0;

    for (int i = 0; i < bookCount; i++) {
        totalCopies += books[i].copies;
    }

    printf("Total number of book copies: %d\n", totalCopies);
    return 0;
}

