#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <chrono>
#include <vector>

class Member;

/*
    book.h
    Author: Hadas Cohen <hc820@live.mdx.ac.uk>
    Created: 23/12/2023
    Updated: 15/01/2024
*/

class Book
{

private:
  int bookId;
  std::string bookName;
  std::string authorFirstName;
  std::string authorLastName;
  std::string bookType;
  std::chrono::system_clock::time_point dueDate;
  std::string borrower;

public:
  int pageCount;
  Book(int id,std::string bName,std::string aFirstName, std::string aLastName);
  //void readDataFromCSV(std::string filename);
  void setBookId(int bId);
  int getBookId();
  std::string getBookName();
  std::string getAuthorFirstName();
  std::string getAuthorLastName();
  //Function sets due date
  void setDueDate(std::chrono::system_clock::time_point newDueDate);
  std::chrono::system_clock::time_point getDueDate();
//   void borrowBook(Member &borrower, std::chrono::system_clock::time_point newDueDate);
//   // Function to return the book
//   void returnBook();
};

#endif