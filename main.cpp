#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
private:
    string name;
    string author;
public:
    Book(const string name, const string author) {
        this->name = name;
        this->author = author;
    }
    const string getName() const {
        return name;
    }
    const string getAuthor() const {
        return author;
    }

    Book&operator = (const Book &book) {
        name = book.name;
        author = book.author;
        return *this;
    }

    friend ostream&operator << (ostream &out, const Book book) {
        return out << book.name << " - " << book.author << endl;
    }
};

class Library {
private:
    vector<Book> Books;
    int quantityOfBook;
public:
    explicit Library(vector<Book> &books) {
        Books = books;
    }

    Library(int _quantityOfBook) {
        quantityOfBook = _quantityOfBook;
    }

    ~Library() {
        Books.clear();
    }

    bool SearchBookName(string name){
        for(int i = 0; i < quantityOfBook; i++) {
            if(name == Books[i].getName()) {
                return true;
            }
        }
        return false;
    }

    bool SearchBookAuthor(string author){
        for(int i = 0; i < quantityOfBook; i++) {
            if(author == Books[i].getAuthor()) {
                return true;
            }
        }
        return false;
    }

    bool Search(const Book &book) {
        string name = book.getName();
        string author = book.getAuthor();
        for(int i = 0; i < quantityOfBook; i++) {
            if((name == Books[i].getName()) && (author == Books[i].getAuthor())) {
                return true;
            }
        }
        return false;
    }
};

class Librarian : public Library {
private:
    string nameLibrarian;
public:
    Librarian(vector<Book> Books, string name) : Library(Books) {
        nameLibrarian = nameLibrarian;
    }

     void GetBook(string name, string author) {
        cout << name << " " << author << endl;
        if(Search({name, author}) == true) {
            cout << "Here is your book ";
        }
        else {
            cout << "Unfortunately the book wasn't found ";
        }
    }
    void GetBookByName(string name) {
        cout << name << endl;
        if(SearchBookName(name) == true) {
            cout << "Here is your book ";
        }
        else {
            cout << "Unfortunately the book wasn't found ";
        }
    }
    void GetBookByAuthor(string author) {
        cout << author << endl;
        if(SearchBookAuthor(author) == true) {
            cout << "Here is your book ";
        }
        else {
            cout << "Unfortunately the book wasn't found ";
        }
    }
};

int main() {
    Library (10);
    Book book1{"Great Gatsby", "F. Scott Fitzgerald"};
    Book book2{"The picture of Dorian Gray", "O. Wilde"};
    Book book3{"Wuthering heights", "E. Bronte"};
    Book book4{"Lord of the Flies", "William Golding"};
    Book book5{"To kill a mockingbird", "H. Lee"};
    Book book6{"The hunchback of Notre Dame", "V. Hugo"};
    Book book7{"Crime and punishment", "F. Dostoevsky"};
    Book book8{"A brief history of time", "S. Hawking"};
    Book book9{"Fahrenheit 451", "R. Bradbury"};
    Book book10{"1984", "J. Orwell"};

    vector<Book> Books = {book1, book2, book3, book4, book5, book6, book7, book8, book9, book10};
    Library library(Books);

    Librarian Frank(Books, "Frank");
    Frank.GetBook("To kill a mockingbird", "H. Lee");
    Frank.GetBook("1984","J. Orwell");
    Frank.GetBookByName("The picture of Dorian Gray");

    return 0;
}
