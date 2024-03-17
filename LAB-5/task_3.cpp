#include <iostream>
#include <string>
#include <vector>

// Book class representing individual books
class Book {
private:
    std::string title;
    std::string author;
    int publicationYear;

public:
    // Constructor
    Book(const std::string& title, const std::string& author, int publicationYear)
        : title(title), author(author), publicationYear(publicationYear) {}

    // Getters
    const std::string& getTitle() const { return title; }
    const std::string& getAuthor() const { return author; }
    int getPublicationYear() const { return publicationYear; }
};

// Library class to manage a collection of books
class Library {
private:
    std::vector<Book> books;

public:
    // Function to add a book to the library
    void addBook(const Book& book) { books.push_back(book); }

    // Function to remove a book from the library
    void removeBook(const std::string& title) {
        auto it = std::find_if(books.begin(), books.end(), [&](const Book& b) {
            return b.getTitle() == title;
        });
        if (it != books.end()) {
            books.erase(it);
        }
    }

    // Function to list all books in the library
    void listBooks() const {
        std::cout << "Books in the library:" << std::endl;
        for (const auto& book : books) {
            std::cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor()
                      << ", Publication Year: " << book.getPublicationYear() << std::endl;
        }
    }
};

int main() {
    // Create a library and add some books
    Library library;
    library.addBook(Book("The Great Gatsby", "F. Scott Fitzgerald", 1925));
    library.addBook(Book("To Kill a Mockingbird", "Harper Lee", 1960));
    library.addBook(Book("1984", "George Orwell", 1949));

    // List all books
    library.listBooks();

    // Remove a book
    library.removeBook("To Kill a Mockingbird");

    // List all books again
    library.listBooks();

    return 0;
}
