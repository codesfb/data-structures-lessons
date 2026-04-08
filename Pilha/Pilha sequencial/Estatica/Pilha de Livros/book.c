#include <stdio.h>
#include <string.h>
#include <stdlib.h>  
#include "book.h"

struct book{
    char title[100];
    char autor[100];
    char Editora[100];
    int year;
};

Book *createBook(char *title,char *autor, char *Editora, int year){
    Book *b =(Book*)malloc(sizeof(Book));
    if(!b) return ERROR;
    strcpy(b->title, title);
    strcpy(b->autor, autor);
	strcpy(b->Editora, Editora);
	b->year = year;
    return b;
};

char *getTitle(Book *b){
	if(!b) return ERROR;
	return b->title;
};
char *c(Book *b){
	 if(!b) return ERROR;
	 return b->Editora; 
};
char *getAutor(Book *b){
	 if(!b) return ERROR;
	 return b->autor;
};

char *getEditora(Book *b){
	if(!b) return ERROR;
	return b->Editora;

};

int getYear(Book *b){
	if(!b) return ERROR;
	return b->year;
	};
