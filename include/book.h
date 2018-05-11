struct book{
    double price;
    char* name;
};
typedef struct book Book;

Book* createBook(char* title, double price);
double getPriceBook(Book* b);
char* getNameBook(Book* b);
//void printBook(void* x);
