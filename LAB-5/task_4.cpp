#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <iomanip> // for setw
#include <vector>

// Include the previously defined Book and Library classes
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
        std::cout << std::left << std::setw(30) << "Title" << std::setw(20) << "Author" << "Publication Year" << std::endl;
        for (const auto& book : books) {
            std::cout << std::left << std::setw(30) << book.getTitle() << std::setw(20) << book.getAuthor() << book.getPublicationYear() << std::endl;
        }
    }
};

void userInterface(Library& lib) {
    std::string command;
    while (true) {
        std::cout << "Enter command (add, remove, list, quit): ";
        std::getline(std::cin, command);

        if (command == "add") {
            std::string title, author;
            int publicationYear;

            std::cout << "Enter title: ";
            std::getline(std::cin, title);

            std::cout << "Enter author: ";
            std::getline(std::cin, author);

            std::cout << "Enter publication year: ";
            std::cin >> publicationYear;
            std::cin.ignore(); // Ignore newline character in input buffer

            lib.addBook(Book(title, author, publicationYear));
        } else if (command == "remove") {
            std::string title;
            std::cout << "Enter title of the book to remove: ";
            std::getline(std::cin, title);
            lib.removeBook(title);
        } else if (command == "list") {
            lib.listBooks();
        } else if (command == "quit") {
            break;
        } else {
            std::cout << "Invalid command. Please try again." << std::endl;
        }
    }
}

int main() {
    Library myLibrary;
    userInterface(myLibrary); // Implement this function
    return 0;
}
