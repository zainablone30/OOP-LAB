#include <iostream>
#include <vector>
// Book class representing individual books
class Book {
private:
    std::string title;
    std::string author;
    int publicationYear;

public:
    // Constructor
    Book(const std::string& title, const std::string& author, int publicationYear);

    // Getters
    std::string getTitle() const;
    std::string getAuthor() const;
    int getPublicationYear() const;
};

// Library class to manage a collection of books
class Library {
private:
    std::vector<Book> books;

public:
    // Function to add a book to the library
    void addBook(const Book& book);

    // Function to remove a book from the library
    void removeBook(const std::string& title);

    // Function to list all books in the library
    void listBooks() const;
};
int main() {
    // Create a library
    Library myLibrary;

    // Add books to the library
    myLibrary.addBook(Book("The Catcher in the Rye", "J.D. Salinger", 1951));
    myLibrary.addBook(Book("To Kill a Mockingbird", "Harper Lee", 1960));
    myLibrary.addBook(Book("1984", "George Orwell", 1949));
    myLibrary.addBook(Book("Animal Farm", "George Orwell", 1945));

    // List all books in the library
    myLibrary.listBooks();

    // Remove a book from the library
    myLibrary.removeBook("1984");

    // List all books in the library
    myLibrary.listBooks();

    return 0;
}