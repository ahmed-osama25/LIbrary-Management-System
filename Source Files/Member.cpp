#include "Member.h"
#include <iostream>

using namespace std;

Member::Member(int id, string name)
{

    this->id = id;

    this->name = name;

    borrowedBooks = 0;
}

void Member::displayInfo()
{

    cout << "\n========== Member Information ==========\n";
    cout << "Member ID: " << id << endl;
    cout << "Member Name: " << name << endl;
    cout << "Borrowed Books: " << borrowedBooks << endl;
    cout << "\n========================================\n";
}
void Member::borrowBook()
{

    borrowedBooks++;
}

void Member::returnBook()

{

    if (borrowedBooks > 0)
    {

        borrowedBooks--;
    }
}

int Member::getID()
{

    return id;
}

string Member::getName()
{

    return name;
}

int Member::getBorrowedBooks()
{

    return borrowedBooks;
}

void Member::setBorrowedBooks(int count)
{

    borrowedBooks = count;
}