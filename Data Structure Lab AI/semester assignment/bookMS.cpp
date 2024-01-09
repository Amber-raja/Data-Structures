#include <iostream>
using namespace std;

class date
{
public:
    int day;
    int month;
    int year;

    date(int d = 0, int m = 0, int y = 0)
    {
        day = d;
        month = m;
        year = y;
    }

    void setDay(int day)
    {
        this->day = day;
    }

    void setMonth(int m)
    {
        month = m;
    }

    void setYear(int y)
    {
        year = y;
    }

    int getDay()
    {
        return day;
    }

    int getMonth()
    {
        return month;
    }

    int getYear()
    {
        return year;
    }
};

class node
{
public:
    date d;
    int isbn;
    string author;
    string title;
    string genre;
    node *next;
    node *prev;

    node(int isbn = 0, string author = "", string title = "", string genre = "", int d = 0, int m = 0, int y = 0) : d(d, m, y)
    {
        next = NULL;
        prev = NULL;
        this->isbn = isbn;
        this->author = author;
        this->title = title;
        this->genre = genre;
    }
};

class linkedlist
{
public:
    node *head;
    int length;

    linkedlist()
    {
        head = NULL;
    }

    void insert(int isbn, string author, string title, string genre, int day, int month, int year)
    {
        node *n = new node(isbn, author, title, genre, day, month, year);

        if (head == NULL)
        {
            head = n;
        }
        else
        {
            node *current = head;
            if (current->next != NULL && n->d.year == current->d.year && n->d.month > current->d.month)
            {
                n->next = current;
                current->prev = n;
            }
            else if (current->next != NULL && n->d.year == current->d.year && n->d.month == current->d.month && n->d.day > current->d.day)
            {
                n->next = current;
                n->prev = current->prev;
                current->prev->next = n;
            }
            else if (current->next != NULL && n->d.year == current->d.year && n->d.month == current->d.month && n->d.day == current->d.day)
            {
                n->next = current;
                current->prev = n;
            }
            else if (current->next != NULL && n->d.year > current->d.year)
            {
                n->next = current;
                current->prev = n;
            }
            else
            {
                current->next = n;
                n->prev = current;
            }
        }
    }

    void search(int find_isbn)
    {
        node *current = head;
        while (current != NULL)
        {
            if (current->isbn == find_isbn)
            {
                cout << "Book found" << endl;
            }
            current = current->next;
        }
    }

    void filter_books(string authorr)
    {
        node *temp = head;
        while (temp != NULL)
        {
            if (temp->author == authorr)
            {
                cout << "Books by " << temp->author;
                cout << "Book:  " << temp->title << endl;
            }
            temp = temp->next;
        }
    }

    void delete_Book(int isbn)
    {
        node *current = head;
        while (current != NULL)
        {
            if (current->isbn == isbn)
            {
                cout << "Book found and deleted" << endl;
                if (current->prev != NULL)
                {
                    current->prev->next = current->next;
                }
                else
                {
                    head = current->next;
                }

                if (current->next != NULL)
                {
                    current->next->prev = current->prev;
                }

                delete current;
                return;
            }
            current = current->next;
        }

        cout << "Book not found" << endl;
    }

    void display()
    {
        node *current = head;
        while (current != NULL)
        {
            cout << "Title:  " << current->title << endl;
            cout << "Author:  " << current->author << endl;
            cout << "ISBN:  " << current->isbn << endl;
            cout << "Genre:  " << current->genre << endl;
            cout << "Day:  " << current->d.day << endl;
            cout << "Month:  " << current->d.month << endl;
            cout << "Year:  " << current->d.year << endl;
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    linkedlist l;
    int choice;

    do
    {
        cout << "1. Insert a book\n";
        cout << "2. Search for a book\n";
        cout << "3. Filter books by author\n";
        cout << "4. Delete a book\n";
        cout << "5. Display all books\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        while (choice != 6)
        {
            if (choice == 1)
            {
                int isbn, day, month, year;
                string author, title, genre;

                cout << "Enter ISBN: ";
                cin >> isbn;
                cout << "Enter Author: ";
                cin >> author;
                cout << "Enter Title: ";
                cin >> title;
                cout << "Enter Genre: ";
                cin >> genre;
                cout << "Enter Day: ";
                cin >> day;
                cout << "Enter Month: ";
                cin >> month;
                cout << "Enter Year: ";
                cin >> year;

                l.insert(isbn, author, title, genre, day, month, year);
                break;
            }
            else if (choice == 2)
            {
                int search_isbn;
                cout << "Enter ISBN to search: ";
                cin >> search_isbn;
                l.search(search_isbn);
                break;
            }

            else if (choice == 3)
            {
                string author_filter;
                cout << "Enter author to filter: ";
                cin >> author_filter;
                l.filter_books(author_filter);
                break;
            }
            else if (choice == 4)
            {
                int delete_isbn;
                cout << "Enter ISBN to delete: ";
                cin >> delete_isbn;
                l.delete_Book(delete_isbn);
                break;
            }
            else if (choice == 5)
            {
                l.display();
                break;
            }
            else if (choice == 6)
            {
                cout << "Exiting program.\n";
                break;
            }
        }
       
            
    } while (choice != 6);
  //  return 0;
}