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
      double data1[65535];
      double data2[65535];
      double data3[65535];
      double data4[65535];
      double data5[65535];
      double data6[65535];
      double data7[65535];
      double data8[65535];
      double data9[65535];
      
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
   Book *book1;
   
   for(int j=0; j<65535; j++){
      for(int i=0; i<65535; i++){
         book1 = new Book(i+1, (i+1)*10, "Programación en C", "Camilo Camacho");
         printf("%d\n",book1->id);
         delete book1;
      }
   }
   

   return 0;
}

