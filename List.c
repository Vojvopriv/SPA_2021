#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#include "List.h"


#define FILENAME "Book_data_custom.csv"
// Ime druge datoteke: "knjige.csv"

#define LINE_LENGTH 200


// Samo dodavaj jedno poslije drugog
void addBackend(Book **head, Book **tail, Book_info b2, int *num_of_books)
{
    Book *new_book = (Book*) calloc(1, sizeof(Book));
    new_book->b = b2;

    if (*head == NULL) {
        new_book->left = new_book->right = NULL;
        *head = *tail = new_book;
    }
    else
    {
        new_book->left  = *tail;
        new_book->right = NULL;

        (*(*tail)).right = new_book;
        *tail = new_book;
    }

    (*num_of_books)++;
}

// Dodavanje elementa na pocetak
void addNewHead(Book **head, Book_info new_info, int *num_of_books)
{
    Book *new_book = (Book*) calloc(1, sizeof(Book));
    new_book->b = new_info;

    new_book->right = *head;
    new_book->left = NULL;
    *head = new_book;

    (*num_of_books)++;
}

// Dodavanje iza zadatog elementa
void addBehind(Book *b, Book_info new_info, int *num_of_books)
{
    Book *new_book = (Book*) calloc(1, sizeof(Book));
    new_book->b = new_info;

    new_book->right = b->right;
    new_book->left = b;
    b->right = new_book;

    (*num_of_books)++;
}

// Demonstrativni ispis svih knjiga pocevsi od proslijedjene
void printOut(Book *head)
{
    printf("\n           ------------------\n                Biblioteka:\n           ------------------\n");

    while ( head != NULL )
    {
        printf("%s,%s,%s,%s,%s\n", head->b.ISBN, head->b.title, head->b.author, head->b.genre, head->b.year);
        head = head->right;
    }

    printf("\n           ------------------\n");
}

void askForBookInfo(Book_info *temp_book)
{
    printf("ISBN:   ");scanf("%s", temp_book->ISBN);
    printf("Title:  ");scanf("%s", temp_book->title);
    printf("Author: ");scanf("%s", temp_book->author);
    printf("Genre:  ");scanf("%s", temp_book->genre);
    printf("Year:   ");scanf("%s", temp_book->year);
}

void addToFile(Book_info book_info)
{
    FILE* fp = fopen(FILENAME, "a");

    if (!fp) {printf("Error appendix opening file.\n");}
	else
	{
	    char line[LINE_LENGTH] = "\n";

	    strcat(line,book_info.ISBN);
	    strcat(line,",");
        strcat(line,book_info.title);
        strcat(line,",");
        strcat(line,book_info.author);
        strcat(line,",");
        strcat(line,book_info.genre);
        strcat(line,",");
        strcat(line,book_info.year);



	    fputs(line, fp);
	}

	fclose(fp);
}

void terminateList(Book **head)
{
    while(*head)
    {
        Book *p = (*head)->right;
        free(*head);
        *head = p;
    }
}


