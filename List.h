#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

typedef struct book_info
{
	char ISBN[21];
	char title[51];
	char author[51];
	char genre[51];
	char year[21];
}Book_info;

typedef struct book
{
    Book_info b;
    struct book *left;
    struct book *right;
}Book;


#endif // LIST_H_INCLUDED
