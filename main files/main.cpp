#include "../Header Files/Library.h"
#include "../Header Files/Admin.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{

    Library library;

    Admin admin;

    library.loadData();

    for (int i = 0; i < 500; i++)
    {

        int ID = 100001 + i;

        if (library.searchbook(ID) == nullptr)
        {

            string title = "Fictional Book " + to_string(i + 1);

            string author = "Fictional Author " + to_string(i + 1);

            library.addBook(ID, title, author);
        }
    }

    int role;

    do
    {

        system("cls");

        cout << "\n===== Library Management System =====\n";
        cout << "1. Admin\n";
        cout << "2. User\n";
        cout << "0. Exit\n";

        cout << "Choose your role: ";
        cin >> role;

        if (role == 1)
        {

            string username, password;

            system("cls");

            cout << "\n===== Admin Login =====\n";

            cout << "Username: ";
            cin >> username;

            cout << "Password: ";
            cin >> password;

            if (admin.login(username, password))
            {
                cout << "\nLogin Successful!\n";
                system("pause");

                int adminChoice;

                do
                {

                    system("cls");

                    cout << "\n========== Admin Menu ==========\n";
                    cout << "1. Display Books\n";
                    cout << "2. Display Members\n";
                    cout << "3. Add Book\n";
                    cout << "4. Add Member\n";
                    cout << "5. Remove Book\n";
                    cout << "6. Remove Member\n";
                    cout << "7. Search Book\n";
                    cout << "8. Update Book\n";
                    cout << "9. Borrow Book\n";
                    cout << "10. Return Book\n";
                    cout << "0. Logout\n";

                    cout << "Enter your choice: ";
                    cin >> adminChoice;

                    switch (adminChoice)
                    {
                    case 1:
                        library.displayBooks();
                        break;

                    case 2:
                        library.displayMembers();
                        break;

                    case 3:
                    {
                        int ID;
                        string title, author;

                        cout << "Enter Book ID: ";
                        cin >> ID;
                        cin.ignore();

                        cout << "Enter Book Title: ";
                        getline(cin, title);

                        cout << "Enter Author Name: ";
                        getline(cin, author);

                        if (library.addBook(ID, title, author))
                            cout << "Book Added Successfully!\n";
                        else
                            cout << "Book Addition Failed!\n";

                        break;
                    }

                    case 4:
                    {
                        int ID;
                        string name;

                        cout << "Enter Member ID: ";
                        cin >> ID;
                        cin.ignore();

                        cout << "Enter Member Name: ";
                        getline(cin, name);

                        if (library.addMember(ID, name))
                            cout << "Member Added Successfully!\n";
                        else
                            cout << "Member Addition Failed!\n";

                        break;
                    }

                    case 5:
                    {
                        int ID;

                        cout << "Enter Book ID: ";
                        cin >> ID;

                        if (library.removebook(ID))
                            cout << "Book Removed Successfully!\n";
                        else
                            cout << "Book Not Found!\n";

                        break;
                    }

                    case 6:
                    {
                        int ID;

                        cout << "Enter Member ID: ";
                        cin >> ID;

                        if (library.removeMember(ID))
                            cout << "Member Removed Successfully!\n";
                        else
                            cout << "Member Not Found!\n";

                        break;
                    }

                    case 7:
                    {
                        int ID;

                        cout << "Enter Book ID: ";
                        cin >> ID;

                        Book *book = library.searchbook(ID);

                        if (book != nullptr)
                            book->displayInfo();
                        else
                            cout << "Book Not Found!\n";

                        break;
                    }

                    case 8:
                    {
                        int ID;
                        string title, author;

                        cout << "Enter Book ID: ";
                        cin >> ID;
                        cin.ignore();

                        cout << "Enter New Title: ";
                        getline(cin, title);

                        cout << "Enter New Author: ";
                        getline(cin, author);

                        if (library.updateBook(ID, title, author))
                            cout << "Book Updated Successfully!\n";
                        else
                            cout << "Book Not Found!\n";

                        break;
                    }

                    case 9:
                    {
                        int memberID, bookID;

                        cout << "Enter Member ID: ";
                        cin >> memberID;

                        cout << "Enter Book ID: ";
                        cin >> bookID;

                        if (library.borrowBook(memberID, bookID))
                            cout << "Book Borrowed Successfully!\n";
                        else
                            cout << "Borrowing Failed!\n";

                        break;
                    }

                    case 10:
                    {
                        int memberID, bookID;

                        cout << "Enter Member ID: ";
                        cin >> memberID;

                        cout << "Enter Book ID: ";
                        cin >> bookID;

                        if (library.returnbook(memberID, bookID))
                            cout << "Book Returned Successfully!\n";
                        else
                            cout << "Returning Failed!\n";

                        break;
                    }

                    case 0:
                        cout << "Logging Out...\n";
                        break;

                    default:
                        cout << "Invalid Choice!\n";
                    }

                    if (adminChoice != 0)
                        system("pause");

                } while (adminChoice != 0);
            }

            else
            {

                cout << "\nInvalid Username or Password!\n";

                system("pause");
            }
        }

        else if (role == 2)
        {

            int userChoice;

            do
            {

                system("cls");

                cout << "\n========== User Menu ==========\n";
                cout << "1. Display Books\n";
                cout << "2. Borrow Book\n";
                cout << "3. Return Book\n";
                cout << "0. Back\n";

                cout << "Enter your choice: ";
                cin >> userChoice;

                switch (userChoice)
                {
                case 1:
                    library.displayBooks();
                    break;

                case 2:
                {
                    int memberID, bookID;

                    cout << "Enter Member ID: ";
                    cin >> memberID;

                    cout << "Enter Book ID: ";
                    cin >> bookID;

                    if (library.borrowBook(memberID, bookID))
                        cout << "Book Borrowed Successfully!\n";
                    else
                        cout << "Borrowing Failed!\n";

                    break;
                }

                case 3:
                {
                    int memberID, bookID;

                    cout << "Enter Member ID: ";
                    cin >> memberID;

                    cout << "Enter Book ID: ";
                    cin >> bookID;

                    if (library.returnbook(memberID, bookID))
                        cout << "Book Returned Successfully!\n";
                    else
                        cout << "Returning Failed!\n";

                    break;
                }

                case 0:
                    cout << "Going Back...\n";
                    break;

                default:
                    cout << "Invalid Choice!\n";
                }

                if (userChoice != 0)
                    system("pause");

            } while (userChoice != 0);
        }

        else if (role != 0)
        {

            cout << "Invalid Role!\n";

            system("pause");
        }

    } while (role != 0);

    library.saveBooks();

    library.saveMembers();

    library.saveRecords();

    system("cls");

    cout << "\nData Saved Successfully!\n";

    cout << "Thank You For Using Our Library System!\n";

    system("pause");

    return 0;
}