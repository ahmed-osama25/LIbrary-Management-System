#pragma once
#include <string>

class Book
{
private:
    int id;

    std::string title;

    std::string author;

    bool isAvailable;

public:
    void displayInfo();

    bool borrowBook();

    void returnBook();

    Book(int id, std::string title, std::string author);

    int getID();

    void setTitle(std::string title);

    void setAuthor(std::string author);

    std::string getTitle();

    std::string getAuthor();

    bool getAvailability();

    void setAvailability(bool availability);
};