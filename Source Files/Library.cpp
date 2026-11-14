#include "Library.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Library::Library()
{

    for (int i = 0; i < 500; i++)
    {

        books[i] = nullptr;
    }

    for (int i = 0; i < 100; i++)
    {

        books[i] = nullptr;

        members[i] = nullptr;

        records[i] = nullptr;
    }
}

bool Library::addBook(int id, string title, string author)
{

    if (bookcount < 500)
    {

        books[bookcount] = new Book(id, title, author);

        bookcount++;

        return true;
    }

    return false;
}

bool Library::addMember(int id, string name)
{

    if (membercount < 100)
    {
        members[membercount] = new Member(id, name);

        membercount++;

        return true;
    }

    return false;
}

void Library::displayBooks()
{

    if (bookcount == 0)
    {

        cout << "No books available in the library.\n";

        return;
    }

    for (int i = 0; i < bookcount; i++)
    {

        books[i]->displayInfo();
    }
}

void Library::displayMembers()
{

    if (membercount == 0)
    {

        cout << "No members registerd.\n";

        return;
    }

    for (int i = 0; i < membercount; i++)
    {

        members[i]->displayInfo();
    }
}

bool Library::removebook(int id)
{

    for (int i = 0; i < bookcount; i++)
    {

        if (books[i]->getID() == id)
        {

            delete books[i];

            for (int j = i; j < bookcount - 1; j++)
            {

                books[j] = books[j + 1];
            }

            books[bookcount - 1] = nullptr;

            bookcount--;

            return true;
        }
    }

    return false;
}
bool Library::removeMember(int id)
{

    for (int i = 0; i < membercount; i++)
    {

        if (members[i]->getID() == id)
        {

            delete members[i];

            for (int j = i; j < membercount; j++)
            {

                members[j] = members[j + 1];
            }

            members[membercount - 1] = nullptr;

            membercount--;

            return true;
        }
    }

    return false;
}

Book *Library::searchbook(int id)
{

    for (int i = 0; i < bookcount; i++)
    {

        if (books[i]->getID() == id)
        {

            return books[i];
        }
    }

    return nullptr;
}

bool Library::updateBook(int id, string title, string author)
{

    Book *book = searchbook(id);

    if (book != nullptr)
    {

        book->setTitle(title);

        book->setAuthor(author);

        return true;
    }

    return false;
}

Library::~Library()
{

    for (int i = 0; i < bookcount; i++)
    {

        delete books[i];
    }

    for (int i = 0; i < membercount; i++)
    {

        delete members[i];
    }

    for (int i = 0; i < recordCount; i++)
    {

        delete records[i];
    }
}

Member *Library::searchMember(int id)
{
    for (int i = 0; i < membercount; i++)
    {

        if (members[i]->getID() == id)
        {

            return members[i];
        }
    }

    return nullptr;
}
bool Library::borrowBook(int memberId, int bookId)
{

    Member *member = searchMember(memberId);

    Book *book = searchbook(bookId);

    if (member != nullptr && book != nullptr && recordCount < 100)
    {

        if (book->borrowBook())
        {

            member->borrowBook();

            records[recordCount] = new BorrowRecord(memberId, bookId);

            recordCount++;

            return true;
        }
    }

    return false;
}
bool Library::returnbook(int memberID, int bookID)
{

    Member *member = searchMember(memberID);

    Book *book = searchbook(bookID);

    if (member == nullptr || book == nullptr)
    {

        return false;
    }

    for (int i = 0; i < recordCount; i++)
    {

        if (records[i]->getMemberID() == memberID && records[i]->getBookID() == bookID)
        {

            book->returnBook();

            member->returnBook();

            delete records[i];

            for (int j = i; j < recordCount - 1; j++)
            {

                records[j] = records[j + 1];
            }

            records[recordCount - 1] = nullptr;

            recordCount--;

            return true;
        }
    }

    return false;
}

void Library::saveBooks()
{

    ofstream file("data/books.txt");

    file << "ID | Title | Author | Availability\n";
    file << "----------------------------------------\n";

    for (int i = 0; i < bookcount; i++)
    {

        file << books[i]->getID() << " | "
             << books[i]->getTitle() << " | "
             << books[i]->getAuthor() << " | "
             << (books[i]->getAvailability() ? "Available" : "Borrowed")
             << endl;
    }

    file.close();
}

void Library::saveMembers()
{

    ofstream file("data/members.txt");

    file << "ID | Name | Borrowed Books\n";
    file << "----------------------------------------\n";

    for (int i = 0; i < membercount; i++)
    {

        file << members[i]->getID() << " | "
             << members[i]->getName() << " | "
             << members[i]->getBorrowedBooks()
             << endl;
    }

    file.close();
}

void Library::saveRecords()
{

    ofstream file("data/records.txt");

    file << "Member ID | Book ID\n";
    file << "--------------------\n";

    for (int i = 0; i < recordCount; i++)
    {

        file << records[i]->getMemberID() << " | "
             << records[i]->getBookID() << endl;
    }

    file.close();
}

void Library::loadBooks()
{

    ifstream file("data/books.txt");

    string line;

    getline(file, line);

    getline(file, line);

    while (getline(file, line) && bookcount < 500)

    {

        stringstream ss(line);

        string ID, title, author, availability;

        getline(ss, ID, '|');

        getline(ss, title, '|');

        getline(ss, author, '|');

        getline(ss, availability, '|');

        int bookID = stoi(ID);

        Book *book = new Book(bookID, title, author);

        book->setAvailability(availability.find("Available") != string::npos);

        books[bookcount] = book;

        bookcount++;
    }

    file.close();
}

void Library::loadMembers()
{

    ifstream file("data/members.txt");

    string line;

    getline(file, line);

    getline(file, line);

    while (getline(file, line))
    {

        stringstream ss(line);

        string id, name, borrowedBooks;

        getline(ss, id, '|');

        getline(ss, name, '|');

        getline(ss, borrowedBooks, '|');

        int memberId = stoi(id);

        Member *member = new Member(memberId, name);

        member->setBorrowedBooks(stoi(borrowedBooks));

        members[membercount] = member;

        membercount++;
    }

    file.close();
}

void Library::loadRecords()
{

    ifstream file("data/records.txt");

    string line;

    getline(file, line);

    getline(file, line);

    while (getline(file, line))
    {

        stringstream ss(line);

        string memberID, bookID;

        getline(ss, memberID, '|');

        getline(ss, bookID, '|');

        records[recordCount] = new BorrowRecord(stoi(memberID), stoi(bookID));

        recordCount++;
    }

    file.close();
}

void Library::loadData()
{

    loadBooks();

    loadMembers();

    loadRecords();
}