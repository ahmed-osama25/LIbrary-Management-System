#pragma once
#include <string>
class Member
{
private:
    int id;

    std::string name;

    int borrowedBooks;

public:
    Member(int id, std::string name);

    void displayInfo();

    void borrowBook();

    void returnBook();

    int getID();

    std::string getName();

    int getBorrowedBooks();

    void setBorrowedBooks(int count);
};