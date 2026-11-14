#pragma once

class BorrowRecord
{
private:
    int memberID;

    int bookID;

public:
    BorrowRecord(int memberID, int bookID);

    int getMemberID();

    int getBookID();
};