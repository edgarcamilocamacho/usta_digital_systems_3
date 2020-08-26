#include <stdio.h>
#include <string.h>

struct Book{
    int     id;
    int     qty;
    char    title[50];
    char    author[50];
    char    subject[50];
};

Book book1;
Book book2;

Book *pb1, *pb2;

void restar_libro(Book *book){
    printf("book interno = %d\n", book->qty);
    if(book->qty>0)
        book->qty--;
    printf("book interno = %d\n", book->qty);
}

int main(int argc, char** argv){
    book1.id = 1;
    book1.qty = 10;
    strcpy(book1.title, "Programacion en C");
    strcpy(book1.author, "Camilo Camacho");
    strcpy(book1.subject, "Programar");

    book2.id = 2;
    book2.qty = 20;
    strcpy(book2.title, "Circuitos Electricos");
    strcpy(book2.author, "Edgar Poveda");
    strcpy(book2.subject, "Electricidad");

    pb1 = &book1;
    pb2 = &book2;

    printf("book1.id = %d\n", book1.id);
    printf("book1.title = %s\n", book1.title);

    printf("pb1 = 0x%x\n", pb1);
    printf("&book1.id = %d\n", &book1.id);
    printf("&book1.qty = %d\n", &book1.qty);
    printf("book1.title = %d\n", book1.title);
    printf("book1.title = %d\n\n\n", book1.author);

    printf("book1.qty = %d\n", book1.qty);
    restar_libro(&book1);
    printf("book1.qty = %d\n", book1.qty);

    return 0;
}
