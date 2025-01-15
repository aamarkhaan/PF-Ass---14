#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct library
{
    int id;
    int quantity;
    string title;
    string author;
};

const int maxBooks = 10;
library books[maxBooks];
int bookCount = 0;

void loadBookData()
{
    ifstream mybook("library.txt");
    if (mybook.is_open())
    {
        mybook >> bookCount;
        mybook.ignore();
        for (int i = 0; i < bookCount; i++)
        {
            mybook >> books[i].id;
            mybook.ignore();
            getline(mybook, books[i].title);
            getline(mybook, books[i].author);
            mybook >> books[i].quantity;
        }
    }
    else
    {
        cout << "Error Loading Data.";
    }
    mybook.close();
}

bool UniqueId(int userBookId)
{
    for (int i = 0; i < bookCount; i++)
    {
        if (userBookId == books[i].id)
        {
            return false;
        }
    }
    return true;
}

bool UniqueTitle(const string & userBookTitle)
{
    for (int i = 0; i < bookCount; i++)
    {
        if (userBookTitle == books[i].title)
        {
            return false;
        }
    }
    return true;
}

void AddBookData()
{
    cout <<endl;
    cout <<endl;
    cout << "--- Library Management System ---" << endl;

    if (bookCount >= maxBooks)
    {
        cout << "Database is full" << endl;
    }
    else
    {
        library book;
        cout << endl;
        cout << endl;
        cout << "Enter Book ID : ";
        cin >> book.id;
        if (UniqueId(book.id) == false)
        {
            cout << endl;
            cout << "This ID Already Exist" << endl;
            return;
        }

        cout << "Enter Book Title : ";
        cin.ignore();
        getline(cin, book.title);

        if (UniqueTitle(book.title) == false)
        {
            cout << endl;
            cout << "This Title Already Exist" << endl;
            return;
        }

        cout << "Enter Book Author : ";
        getline(cin, book.author);

        cout << "Enter Book Quantity : ";
        cin >> book.quantity;

        books[bookCount] = book;
        bookCount++;
    }
}

void searchBookData()
{
    int id;
    cout << "Enter Book ID : ";
    cin >> id;

    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].id == id)
        {
            cout << endl;
            cout << "Book Found" << endl;
            cout << endl;
            cout << "Book ID : " << books[i].id << endl;
            cout << "Book Title : " << books[i].title << endl;
            cout << "Book Author : " << books[i].author << endl;
            cout << "Book Quantity : " << books[i].quantity << endl;
            cout << endl;
        }
    }
}

void displayBooksData()
{
    for (int i = 0; i < bookCount; i++)
    {
        cout << endl;
        cout << "Book ID: " << books[i].id << endl;
        cout << "Book Title: " << books[i].title << endl;
        cout << "Book Author: " << books[i].author << endl;
        cout << "Book Quantity: " << books[i].quantity << endl;
        cout << endl;
    }
}

void saveBooksData()
{
    ofstream mybook("library.txt");
    if (mybook.is_open())
    {
        cout << endl;
        cout << "Saving Book's Data";
        mybook << bookCount << endl;

        for (int i = 0; i < bookCount; i++)
        {
            mybook << books[i].id << endl;
            mybook << books[i].title << endl;
            mybook << books[i].author << endl;
            mybook << books[i].quantity << endl;
        }
    }
    else
    {
        cout << "Error Saving Data";
    }
    mybook.close();
}


int main()
{

    int choice;
    do
    {
        cout <<endl;
        cout <<endl;
        cout << "---  Chose Option  ---" << endl;
        cout << endl;
        cout << "1. Add a new book to the inventory" << endl;
        cout << "2. Search for a book by Book ID " << endl;
        cout << "3. Display all available books" << endl;
        cout << "4.Exit" << endl;
        cout << endl;

        cout << "Enter you choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            AddBookData();
            break;
        case 2:
            searchBookData();
            break;
        case 3:
            displayBooksData();
            break;
        case 4:
            cout << "Closing...";
            break;

        default:
            cout << "Please select a valid option!";
            break;
        }

    } while (choice != 4);


    loadBookData();
    saveBooksData();
    return 0;
}