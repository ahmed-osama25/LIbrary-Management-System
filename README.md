# 📚 Library Management System

A console-based **Library Management System** developed in C++ using Object-Oriented Programming (OOP). The project allows administrators to manage books and members, while users can browse books and borrow or return them.

## ✨ Features

### 🔐 Admin
- Admin login authentication.
- Add new books.
- Remove books.
- Search for books by ID.
- Update book information.
- Display all books.
- Add and remove library members.
- Display all members.

### 👤 User
- View available books.
- Borrow books.
- Return borrowed books.

### 💾 Data Management
- Save books, members, and borrowing records to text files.
- Load saved data automatically when the program starts.
- Maintain book availability and borrowing records.

## 🛠️ Technologies Used

- **C++**
- Object-Oriented Programming (OOP)
- File Handling
- Pointers and Dynamic Memory Allocation
- Arrays
- Standard Template Library (STL)

## 📁 Project Structure

```text
Library Management System/
│
├── .vscode/
│
├── data/
│   ├── books.txt
│   ├── members.txt
│   └── records.txt
│
├── Header Files/
│   ├── Admin.h
│   ├── Book.h
│   ├── BorrowRecord.h
│   ├── Library.h
│   └── Member.h
│
├── Source Files/
│   ├── Admin.cpp
│   ├── Book.cpp
│   ├── BorrowRecord.cpp
│   ├── Library.cpp
│   └── Member.cpp
│
└── main files/
    └── main.cpp
```

## ⚙️ Requirements

- Windows OS
- Visual Studio Code (recommended)
- C++ Compiler (GCC / MinGW)
- PowerShell Terminal

## 🚀 How to Run

**1. Clone the repository**

```bash
git clone YOUR_REPOSITORY_LINK
```

**2. Open the project folder in VS Code.**

**3. Compile the project using PowerShell**

Run this command from the main project directory:

```powershell
g++ -I"Header Files" "main files/main.cpp" "Source Files/Admin.cpp" "Source Files/Book.cpp" "Source Files/BorrowRecord.cpp" "Source Files/Library.cpp" "Source Files/Member.cpp" -o Library.exe
```

**4. Run the program**

```powershell
.\Library.exe
```

## 🔑 Admin Login

The project includes an admin authentication system.

The demo credentials are defined in `Admin.h`. Change them before publishing or using the project in a real environment.

## 🎯 Project Purpose

This project was created to practice and demonstrate C++ programming concepts, especially Object-Oriented Programming, file handling, data management, and working with multiple classes across separate header and source files.

## 👨‍💻 Author

**Ahmed Osama**

---

⭐ If you find this project useful, feel free to star the repository!
