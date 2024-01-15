#include "person.h"
// #include "include/library.h"
#include <string>
#include <vector>
#include <iostream>
#include <cassert>
#include <fstream>
#include <sstream>
#include <chrono> // for working with dates and time
#include "book.h"

/*
    book.cpp
    Author: Hadas Cohen <hc820@live.mdx.ac.uk>
    Created: 23/12/2023
    Updated: 15/01/2024
*/

void Book::setBookId(int bId)
{
    bookId = bId;
}

int Book::getBookId()
{
    return bookId;
}

std::string Book::getBookName()
{
    return bookName;
}
std::string Book::getAuthorFirstName()
{
    return authorFirstName;
}
std::string Book::getAuthorLastName()
{
    return authorLastName;
}

void Book::setDueDate(std::chrono::system_clock::time_point newDueDate)
{
    dueDate = newDueDate;
}
std::chrono::system_clock::time_point Book::getDueDate()
{
    return dueDate;
}
void Book::setBorrowed(bool borrowed)
{
    isBorrowed = borrowed;
}
void Book::returnBook()
{
    if (isBorrowed)
    {
        isBorrowed = false;
        std::cout << "Book returned successfully." << std::endl;
    }
    else
    {
        std::cout << "Error: The book is not checked out." << std::endl;
    }
}

void Book::borrowBook(std::string borrower, std::chrono::system_clock::time_point dueDate)
{
    if (!isBorrowed)
    {
        isBorrowed = true;
        this->borrower = std::move(borrower);
        this->dueDate = dueDate;
        std::cout << "Book borrowed successfully." << std::endl;
    }
    else
    {
        std::cout << "Sorry! Choose a different book: The book is already borrowed." << std::endl;
    }
}

Book::Book(int id, std::string bName, std::string aFirstName, std::string aLastName)
{
    setBookId(id);
    bookName = bName;
    authorFirstName = aFirstName;
    authorLastName = aLastName;
}