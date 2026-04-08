#define ERROR 0
#define SUCCESS 1

typedef struct book Book;

Book *createBook(char *title,char *autor, char *Editora, int year);
char *getTitle(Book *b);
char *getName(Book *b);
char *getAutor(Book *b);
char *getEditora(Book *b);
int getYear(Book *b);

