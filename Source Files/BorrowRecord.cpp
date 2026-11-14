#include "BorrowRecord.h"

BorrowRecord::BorrowRecord(int memberID, int bookID)
{

    this->memberID = memberID;

    this->bookID = bookID;
}

int BorrowRecord::getMemberID()
{

    return memberID;
}

int BorrowRecord::getBookID()
{

    return bookID;
}