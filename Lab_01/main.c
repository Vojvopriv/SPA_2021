#include "List.c"
#include "List.h"


int main()
{
    int num_of_books = 0;

	Book *head = NULL;
	Book *tail = NULL;

	char line[LINE_LENGTH];
	char *word;
	char odabir[11];

	FILE* fp = fopen(FILENAME, "r");


	if (!fp) {printf("Error opening file.\n");return 0;}
	else
	{
	    while (!feof(fp))
        {
            Book_info temp_book;

            fgets(line, LINE_LENGTH, fp);

            word = strtok(line, ",");
            strcpy(temp_book.ISBN, word);

            word = strtok(NULL, ",");
            strcpy(temp_book.title, word);

            word = strtok(NULL, ",");
            strcpy(temp_book.author, word);

            word = strtok(NULL, ",");
            strcpy(temp_book.genre, word);

            word = strtok(NULL, "\n");
            strcpy(temp_book.year, word);    // atoi funkcija je stvarala neke probleme, zbog toga je i godina u obliku stringa

            addBackend(&head, &tail, temp_book, &num_of_books);
        }
        printf("Knjige su uspjesno ucitane, ima ih: %d\n",num_of_books);
    }
    fclose(fp);

    // printOut(head); // Demonstrativni ispis




    printf("\n--Zelite li upisati jos knjiga u fajl?[Y/N]: ");
    scanf("%s", odabir);

    if(strcmp(odabir, "N") && strcmp(odabir, "Y"))
        {printf("Pogresan unos. Pokreni program ispocetka! \n"); return 0;} // Ako je uneseno nesto != Y ili N


    if(!strcmp(odabir, "Y"))
    {
        printf("\n\n--Unos novih knjiga--\n");
        do {
        printf("--izaberi opciju: (Dodaj na kraj[kr], Dodaj proizvoljno[pr], Dodaj na pocetak[po] ili Necu vise[KRAJ]): ");
        scanf("%s", odabir);


        if(!strcmp(odabir, "kr"))
        {
            Book_info temp_book;
            askForBookInfo(&temp_book);                          // Ucitaju se podaci

            addBackend(&head, &tail, temp_book, &num_of_books);// Dodaju se u listu

            addToFile(temp_book);                            // Dodaju se u fajl
            printf("GOTOVO\n");
        }
        else if(!strcmp(odabir, "pr"))
        {
            Book_info temp_book;
            askForBookInfo(&temp_book);                     // Ucitaju se podaci

            srand(time(0));
            int rand_n = rand() % num_of_books;
            Book *temp = head;

            for(int i=0; i<rand_n; i++)
                temp = temp->right;                     // Pomjeraj do n-tog clana liste

            addBehind(temp, temp_book, &num_of_books);// Dodaju se u listu

            addToFile(temp_book);                   // Dodaju se u fajl
            printf("GOTOVO\n");
        }
        else if(!strcmp(odabir, "po"))
        {
            Book_info temp_book;
            askForBookInfo(&temp_book);                    // Ucitaju se podaci

            addNewHead(&head, temp_book, &num_of_books); // Dodaju se u listu

            addToFile(temp_book);                      // Dodaju se u fajl
            printf("GOTOVO\n");
        }
        else if(strcmp(odabir, "KRAJ") != 0) {printf("Pogresan unos.\n");}

        }while(strcmp(odabir, "KRAJ") != 0);
    }



    // printOut(head); // Demonstrativni ispis nakon izmjena

    terminateList(&head);
	return 0;
}
