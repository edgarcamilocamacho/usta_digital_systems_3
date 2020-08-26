#include <iostream>
#include <string>

//using namespace std;

class Book{
   private:
      
   public:
      int id;
      int qty;
      std::string title;
      std::string author;
      
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

int main(int argc, char **argv) {
   Book book1(1, 10, "Programación en C", "Camilo Camacho");

   std::cout << "book1.id = " << book1.id << std::endl;
   std::cout << "book1.qty = " << book1.qty << std::endl;
   std::cout << "book1.title = " << book1.title << std::endl;
   std::cout << "book1.author = " << book1.author << std::endl;

    decrease_book(&book1);

    std::cout << "book1.id = " << book1.id << std::endl;
   std::cout << "book1.qty = " << book1.qty << std::endl;
   std::cout << "book1.title = " << book1.title << std::endl;
   std::cout << "book1.author = " << book1.author << std::endl;

   return 0;
}

