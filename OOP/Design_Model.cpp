/*
simple library system using object-oriented programming (OOP) principles. 
The code defines classes for Author, Book, Library, and Member, allowing you to represent authors, books, a library collection, and members. 
The main function demonstrates the creation of authors, books, and a library, and it adds books to the library.
*/

#include<iostream>
#include<vector>
using namespace std;

// Forward Declarations
class Author;
class Book;
class Member;

// Class Repersenting Author

class Author{
    private :
      string name;
      string biography;

    public:
      Author(const string &name,const string &biography) : name(name) , biography(biography) {}

      string GetName() const {
        return name;
      }
};

class Book{
    private:
      string title;
      string isbn;
      const Author &author;

    public:
     
    Book(const string & title,const string & isbn,const Author &author) : title(title),isbn(isbn),author(author){}

    string GetTitle() const{
        return title;
    }

    string GetISBN() const{
        return isbn;
    }

    const Author& GetAuthor() const{
        return author;
    }
};

class Library{
    private:
      vector<Book> books;

    public:
      void AddBook(const Book& book){
        books.push_back(book);
      }

      void displayBooks(){
        cout << "Library Collection :\n";
        for(const Book& book : books){
            cout << "Title: " << book.GetTitle() << ", ISBN: " << book.GetISBN() << " Author: " << book.GetAuthor().GetName() << endl;
        }
      }
};

class Member{
    private:
      string name;
      string contactInfo;

    public:
      Member(const string & name,const string &contactInfo): name(name),contactInfo(contactInfo){}

      string GetName() const{
        return name;
      }
};

// Main function 

int main(){
    Author author1("Author one","Biography for Author One");
    Author author2("John Smith", "Biography for John Smith");
    Author author3("Jane Doe", "Biography for Jane Doe");

    // Create Books

    Book book1("Book One","ISBN1",author1);
    Book book2("Mystical Adventures", "ISBN6", author2);
    Book book3("Fantastic Journey", "ISBN5", author3);

    // Create library
    Library library;

    library.AddBook(book1);
    library.AddBook(book2);
    library.AddBook(book3);

    // Display books to library
    library.displayBooks();

    return 0;
}
