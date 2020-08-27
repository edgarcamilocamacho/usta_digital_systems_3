#include <iostream>
#include <string>

//using namespace std;

#define NUM_BOOKS 10

class Book{
   private:
      // static int book_counter = 0;
   public:
      int id;
      int qty;
      std::string title;
      std::string author;

      Book(){
         id = 0;
         // book_counter++;
         qty = 10;
         title = "_title";
         author = "_author";
      }
      
      Book(int _id, int _qty, std::string _title, std::string _author){
         id = _id;
         qty = _qty;
         title = _title;
         author = _author;
      }
};

void decrease_book(Book *book){
    book->qty--;
}

// std::vector<Book> books;

int main(int argc, char **argv) {
   Book *books;
   books = new Book[NUM_BOOKS];

   for(int i=0; i<NUM_BOOKS; i++){
      books[i].id = i;
      printf("books[%d].id = %d\n", i, books[i].id);
   }

   return 0;
}

