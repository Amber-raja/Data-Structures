#include <iostream>
#include <string>

using namespace std;

class Date
{
private:
    int year;
    int month;
    int day;

public:
    Date(int y, int m, int d)
        : year(y), month(m), day(d) {}

    int getYear() const
    {
        return year;
    }

    int getMonth() const
    {
        return month;
    }

    int getDay() const
    {
        return day;
    }
};

class Book
{
private:
    string isbn;
    string author;
    string title;
    string genre;
    Date publicationDate;

public:
    Book(const string &i, const string &a, const string &t, const string &g, const Date &d)
        : isbn(i), author(a), title(t), genre(g), publicationDate(d) {}

    const string &getISBN() const
    {
        return isbn;
    }

    const string &getAuthor() const
    {
        return author;
    }

    const string &getTitle() const
    {
        return title;
    }

    const string &getGenre() const
    {
        return genre;
    }

    const Date &getPublicationDate() const
    {
        return publicationDate;
    }
};

class Node
{
public:
    Book book;
    Node *next;

    Node(const Book &b)
        : book(b), next(nullptr) {}
};

class LinkedList
{
private:
    Node *head;

    void insertInSortedOrder(const Book &book)
    {
        Node *newNode = new Node(book);

        if (head == nullptr || book.getPublicationDate().getYear() < head->book.getPublicationDate().getYear())
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node *curr = head;
        while (curr->next != nullptr && book.getPublicationDate().getYear() > curr->next->book.getPublicationDate().getYear())
        {
            curr = curr->next;
        }

        if (curr->next == nullptr)
        {
            curr->next = newNode;
        }
        else
        {
            newNode->next = curr->next;
            curr->next = newNode;
        }
    }

public:
    LinkedList()
        : head(nullptr) {}

    void addBook(const Book &book)
    {
        insertInSortedOrder(book);
    }

    Node *searchByISBN(const string &isbn)
    {
        Node *curr = head;
        while (curr != nullptr)
        {
            if (curr->book.getISBN() == isbn)
            {
                return curr;
            }
            curr = curr->next;
        }
        return nullptr;
    }

    void displayBooks()
    {
        Node *curr = head;
        while (curr != nullptr)
        {
            cout << "ISBN: " << curr->book.getISBN() << endl;
            cout << "Author: " << curr->book.getAuthor() << endl;
            cout << "Title: " << curr->book.getTitle() << endl;
            cout << "Genre: " << curr->book.getGenre() << endl;
            const Date &publicationDate = curr->book.getPublicationDate();
            cout << "Publication Date: " << publicationDate.getYear() << "-" << publicationDate.getMonth() << "-" << publicationDate.getDay() << endl;
            cout << endl;
            curr = curr->next;
        }
    }

    void filterByAuthor(const string &author)
    {
        Node *curr = head;
        bool found = false;
        while (curr != nullptr)
        {
            if (curr->book.getAuthor() == author)
            {
                cout << "ISBN: " << curr->book.getISBN() << endl;
                cout << "Author: " << curr->book.getAuthor() << endl;
                cout << "Title: " << curr->book.getTitle() << endl;
                cout << "Genre: " << curr->book.getGenre() << endl;
                const Date &publicationDate = curr->book.getPublicationDate();
                cout << "Publication Date: " << publicationDate.getYear() << "-" << publicationDate.getMonth() << "-" << publicationDate.getDay() << endl;
                cout << endl;
                found = true;
            }
            curr = curr->next;
        }

        if (!found)
        {
            cout << "No books found by the author." << endl;
        }
    }

    void recommendRelatedBooks(const string &bookTitle)
    {
        Node *curr = head;
        int recommendationCount = 0;
        while (curr != nullptr && recommendationCount < 3)
        {
            if (curr->book.getTitle() != bookTitle && curr->book.getGenre() == getBookGenre(bookTitle))
            {
                cout << "ISBN: " << curr->book.getISBN() << endl;
                cout << "Author: " << curr->book.getAuthor() << endl;
                cout << "Title: " << curr->book.getTitle() << endl;
                cout << "Genre: " << curr->book.getGenre() << endl;
                const Date &publicationDate = curr->book.getPublicationDate();
                cout << "Publication Date: " << publicationDate.getYear() << "-" << publicationDate.getMonth() << "-" << publicationDate.getDay() << endl;
                cout << endl;
                recommendationCount++;
            }
            curr = curr->next;
        }

        if (recommendationCount == 0)
        {
            cout << "No related books found." << endl;
        }
    }

    void deleteBook(const string &isbn)
    {
        if (head == nullptr)
        {
            return;
        }

        if (head->book.getISBN() == isbn)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node *curr = head;
        while (curr->next != nullptr)
        {
            if (curr->next->book.getISBN() == isbn)
            {
                Node *temp = curr->next;
                curr->next = temp->next;
                delete temp;
                return;
            }
            curr = curr->next;
        }
    }

private:
    string getBookGenre(const string &bookTitle)
    {
        Node *curr = head;
        while (curr != nullptr)
        {
            if (curr->book.getTitle() == bookTitle)
            {
                return curr->book.getGenre();
            }
            curr = curr->next;
        }
        return "";
    }
};

int main()
{
    LinkedList bookList;

    bookList.addBook(Book("9780061120084", "Harper Lee", "To Kill a Mockingbird", "Fiction", Date(1960, 7, 11)));

    Node *book = bookList.searchByISBN("9780061120084");

    bookList.displayBooks();

    bookList.filterByAuthor("Harper Lee");

    bookList.recommendRelatedBooks("To Kill a Mockingbird");

    bookList.deleteBook("9780061120084");

    return 0;
}