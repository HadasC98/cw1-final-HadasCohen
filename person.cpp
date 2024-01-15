
#include "person.h"
#include "book.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <chrono>

/*
    person.cpp
    Author: Hadas Cohen <hc820@live.mdx.ac.uk>
    Created: 23/12/2023
    Updated: 15/01/2024
*/

void Person::setName(std::string n)
{
    name = n;
}
void Person::setAddress(std::string a)
{
    address = a;
}
void Person::setEmail(std::string e)
{
    email = e;
}
std::string Person::getName()
{
    return name;
}
std::string Person::getAddress()
{
    return address;
}
std::string Person::getEmail()
{
    return email;
}

Librarian::Librarian(int id, std::string staffName, std::string staffAddress, std::string staffEmail, int s)
{
    setStaffID(id);
    setName(staffName);
    setAddress(staffAddress);
    setEmail(staffEmail);
    setSalary(s);
}

void Librarian::addMember()
{
    // Implementation here
    // creating a new member and returning their details as successfull.
    // Use public member functions to set and retrieve member variables
    int memberId;
    std::string memberName, memberAddress, memberEmail;

    std::cout << "Enter the ID of the Member: ";
    std::cin >> memberId;

    std::cout << "Enter the Name of the Member: ";
    std::cin.ignore();
    std::getline(std::cin, memberName);
    setName(memberName);

    std::cout << "Enter the Address of the Member: ";
    std::getline(std::cin, memberAddress);
    setAddress(memberAddress);

    std::cout << "Enter the Email of the Member: ";
    std::cin >> memberEmail;
    setEmail(memberEmail);

    // Create a new Member object and add it to the vector
    Member newMember(memberId, memberName, memberAddress, memberEmail);
    members.push_back(newMember);

    // You can use the getter functions to retrieve and display member details
    std::cout << "Member added successfully:" << std::endl;
    std::cout << "Name: " << newMember.getName() << std::endl;
    std::cout << "Email: " << newMember.getEmail() << std::endl;
    std::cout << "Address: " << newMember.getAddress() << std::endl;
}

void Librarian::saveMemberDataToFile(std::string filename)
{
    std::ofstream outputFile(filename, std::ios::app);

    if (!outputFile.is_open())
    {
        std::cerr << "Failed to open the file: " << filename << std::endl;
        return;
    }
    for (Member &member : members)
    {
        outputFile << "Member Details" << std::endl;
        outputFile << "=========================================\n";
        outputFile << "ID: " << member.getMemberId() << std::endl;
        outputFile << "Name: " << member.getName() << std::endl;
        outputFile << "--------------------------------------" << std::endl;
    }
    std::cout << "Member data saved to file: " << filename << std::endl;

    outputFile.close();
}

bool Librarian::isMemberExist(Member member, std::string filename)
{
    std::ifstream inputFile(filename);

    if (!inputFile.is_open())
    {
        std::cout << "Failed to open the file: " << filename << std::endl;
        return false;
    }

    std::string line;
    std::string searchName = "Name: " + member.getName();
    std::string searchId = "ID: " + member.getMemberId();

    while (getline(inputFile, line))
    {
        if (line.find(searchName) != std::string::npos || line.find(searchId) != std::string::npos)
        {
            std::cout << "Member already exists." << std::endl;
            inputFile.close();
            return true;
        }
    }

    inputFile.close();
    return false;
}
 void Librarian::issueBook(int memberId, int bookId){

    bool failure = true;
    for (int i = 0; i < books.size(); i++)
    {
        if (bookId == books[i].getBookId() && memberId == members[i].getMemberId())
        {
            std::cout << "Book issued successfully:" << std::endl;
            std::cout << "Member ID: " << members[memberId - 1].getMemberId() << ", Member Name: " << members[memberId - 1].getName() << std::endl;
            std::cout << "Book ID: " << books[bookId - 1].getBookId() << ", Book Name: " << books[bookId - 1].getBookName() << std::endl;
            failure = false;
            break;
        }
    }
    if (failure)
    {
        std::cout << "Member or book not found." << std::endl;
    }

 }

void Librarian::returnBook(int memberId, int bookId)
{
     // Find the member and return the book
    for (Member& member : members) {
        if (member.getMemberId() == memberId) {
            if (member.returnBook(bookId)) {
                std::cout << "Book returned successfully!" << std::endl;
            } else {
                std::cout << "Member does not have this book." << std::endl;
            }
            return;
        }
    }

    std::cout << "Member not found." << std::endl;
   
}
   
void Librarian::diplayBorrowedBooks(int memberId)
{
    for ( Member member : members) {
        if (member.getMemberId() == memberId) {
            
            std::vector<Book> booksLoaned = member.getBooksBorrowed();

            if (booksLoaned.empty()) {
                std::cout << "Member has no borrowed books." << std::endl;
            } else {
                std::cout << "Borrowed books by Member ID " << memberId << ":" << std::endl;
                for (Book book : booksLoaned) {
                    std::cout << "Book ID: " << book.getBookId() << ", Book Name: " << book.getBookName() << std::endl;
                }
            }
            return;
        }
    }

    std::cout << "Member not found." << std::endl;
}
void Librarian::calcFine(int memberId)
{
}
void Librarian::setStaffID(int id)
{
    staffId = id;
}

int Librarian::getStaffID()
{
    return staffId;
}

void Librarian::setSalary(int s)
{
    salary = s;
}

int Librarian::getSalary()
{
    return salary;
}

void Librarian::setPassword(std::string p)
{
    password = p;
}

std::string Librarian::getPassword()
{
    return password;
}
// void Librarian::readDataFromCSV(std::string filename)
// {
//     std::ifstream file(filename);
//     if (!file.is_open())
//     {
//         std::cerr << "Error opening file: " << filename << std::endl;
//         return;
//     }

//     std::string line;
//     while (std::getline(file, line))
//     {
//         std::istringstream iss(line);
//         std::string token;

//         // Assuming CSV format: id,bookName,pageCount,authorFirstName,authorLastName,bookType
//         int id, pageCount;
//         std::string bookName, authorFirstName, authorLastName, bookType;

//         std::getline(iss, token, ',');
//         id = std::stoi(token);
//         std::getline(iss, id, ',');
//         std::getline(iss, bookName, ',');
//         std::getline(iss, pageCount, ',');
//         std::getline(iss, authorFirstName, ',');
//         std::getline(iss, authorLastName, ',');
//         std::getline(iss, bookType, ',');

//         std::getline(iss, token, ',');
//         pageCount = std::stoi(token);

//         Book book(id, bookName, authorFirstName, authorLastName);
//         books.push_back(book);
//     }

//     file.close();
// }

Member::Member(int id, std::string memberName, std::string memberAddress, std::string memberEmail)
    : memberId(id) // Initialize memberId in the initializer list
{
    setName(memberName);
    setAddress(memberAddress);
    setEmail(memberEmail);
}

void Member::setMemberId(int mId)
{
    memberId = mId;
}

int Member::getMemberId()
{
    return memberId;
}

bool Member::returnBook(int bookId) {
        for (int i = 0; i<booksLoaned.size(); i++) {
            if (bookId == booksLoaned[i].getBookId()) {
                booksLoaned.erase(booksLoaned.begin() + i);
                return true; // Book found and returned successfully
            }
        }
        return false; // Book not found in the member's list
}


void Member::setBooksBorrowed(Book book)
{
    booksLoaned.push_back(book);
}

std::vector<Book> Member::getBooksBorrowed(){
    return booksLoaned;
}

