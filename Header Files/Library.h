#pragma once
#include "Book.h"
#include "Member.h"
#include "BorrowRecord.h"

class Library
{
private:
    Book *books[500];

    Member *members[100];

    int bookcount = 0;

    int membercount = 0;

    BorrowRecord *records[100];

    int recordCount = 0;

public:
    Library();

    bool addBook(int id, std::string title, std::string author);

    bool addMember(int id, std::string name);

    void displayBooks();

    void displayMembers();

    bool removebook(int id);

    bool removeMember(int id);

    Book *searchbook(int id);

    bool updateBook(int id, std::string title, std::string author);

    ~Library();

    Member *searchMember(int id);

    bool borrowBook(int memberID, int bookID);

    bool returnbook(int memberID, int bookID);

    void saveBooks();

    void saveMembers();

    void saveRecords();

    void loadBooks();

    void loadMembers();

    void loadRecords();

    void loadData();
};