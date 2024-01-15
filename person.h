#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>
#include "book.h"
/*
    person.h
    Author: Hadas Cohen <hc820@live.mdx.ac.uk>
    Created: 23/12/2023
    Updated: 15/01/2024
*/
class Member;
class Book;

class Person
{
private:
    std::string name;
    std::string address;
    std::string email;

public:
    void setName(std::string n);
    void setAddress(std::string a);
    void setEmail(std::string e);
    std::string getName();
    std::string getAddress();
    std::string getEmail();
};




class Librarian : public Person
{
private:
        int staffId;
        std::string password;
        int salary;
        

public:
    std::vector<Member> members;
    std::vector<Book> books;
    Librarian(int id, std::string staffName, std::string staffAddress, std::string staffEmail, int s);
    void addMember();
    void saveMemberDataToFile(std::string filename);
    bool isMemberExist(Member member, std::string filename);
    void issueBook(int memberId,int bookId);
    void returnBook(int memberId, int bookId);
    void diplayBorrowedBooks(int memberId);
    void calcFine(int memberId);
    void setStaffID(int id);
    int getStaffID();
    void setSalary(int s);
    int getSalary();
    void setPassword(std::string p);
    std::string getPassword();
    
    //void readDataFromCSV(std::string filename);
};


class Member : public Person
{
    private:
    int memberId;
    std::vector<Book> booksLoaned;

public:
    Member(int id, std::string memberName, std::string memberAddress, std::string memberEmail);
    void setMemberId(int mId) ;
    int getMemberId() ;
    bool returnBook(int bookId);
    // void setBooksBorrowed(Book book);
    // Book getBooksBorrowed();
    
};

#endif