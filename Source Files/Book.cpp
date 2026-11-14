#include "Book.h"
#include <iostream>

using namespace std;

Book::Book(int id, string title, string author)
{

    this->id = id;

    this->title = title;

    this->author = author;

    isAvailable = true;
}
void Book::displayInfo()
{

    cout << "\n========== Book Information ==========\n";
    cout << "Book ID: " << id << endl;
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Availability: " << (isAvailable ? "Available" : "Borrowed") << endl;
    cout << "\n======================================\n";
}

bool Book::borrowBook()
{
    if (isAvailable == true)
    {

        isAvailable = false;

        return true;
    }

    else
    {

        return false;
    }
}

void Book::returnBook()
{

    isAvailable = true;
}

int Book::getID()
{

    return id;
}

void Book::setTitle(std::string title)
{

    this->title = title;
}

void Book::setAuthor(std::string author)
{

    this->author = author;
}

string Book::getTitle()
{

    return title;
}

string Book::getAuthor()
{

    return author;
}

bool Book::getAvailability()
{

    return isAvailable;
}

void Book::setAvailability(bool availability)
{

    isAvailable = availability;
}