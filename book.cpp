#include "person.h"
//#include "include/library.h"
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
// Function sets due date
void Book::setDueDate(std::chrono::system_clock::time_point newDueDate)
{
    dueDate = newDueDate;
}
std::chrono::system_clock::time_point Book::getDueDate()
{
    return dueDate;
}
// void Book::borrowBook(Member &borrower, std::chrono::system_clock::time_point newDueDate)
// {
//     // checking if the book can be borrowed
//     if (!available)
//     {
//         std::cout << "Book not available for borrowing." << std::endl;
//         return;
//     }

//     available = false;
//     setDueDate(newDueDate);
//     borrower.booksLoaned.push_back(this);

//     std::cout << "Book ID " << bookId << " borrowed by Member ID " << borrower.memberId
//               << " due on " << std::chrono::system_clock::to_time_t(dueDate) << std::endl;
// }

// // Function to return the book
// void Book::returnBook()
// {
//     if (borrower == nullptr)
//     {
//         std::cout << "Book is not currently borrowed." << std::endl;
//         return;
//     }

//     available = true;
//     borrower->removeBorrowedBook(this);
//     borrower = nullptr;

//     std::cout << "Book ID " << bookId << " returned." << std::endl;
// }
 Book::Book(int id,std::string bName,std::string aFirstName, std::string aLastName){
    setBookId(id);
    bookName = bName;
    authorFirstName = aFirstName;
    authorLastName = aLastName;
}