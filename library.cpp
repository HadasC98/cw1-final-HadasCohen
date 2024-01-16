#include "library.h"
#include "person.h"
#include "book.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <chrono>

/*
    library.cpp
    Author: Hadas Cohen <hc820@live.mdx.ac.uk>
    Created: 23/12/2023
    Updated: 15/01/2024
*/

class Librarian;

Library::Library() : librarians()
{
}

Library::Library(Librarian &librarian)
{
    librarians.push_back(librarian);
}
void Library::registerLibrarian()
{
    // Implementation here
    int id;
    std::string name, address, email;
    int salary;

    std::cout << "Enter Librarian Name: " << std::endl;
    std::cin.ignore();
    std::getline(std::cin, name);

    std::cout << "Enter Librarian Address: " << std::endl;
    std::getline(std::cin, address);

    std::cout << "Enter Librarian Email: " << std::endl;
    std::cin >> email;

    std::cout << "Enter Librarian ID: " << std::endl;
    std::cin >> id;

    std::cout << "Enter Librarian Salary: " << std::endl;
    std::cin >> salary;

    Librarian newLibrarian(id, name, address, email, salary);
    librarians.push_back(newLibrarian);

    std::cout << "Librarian registered. Librarian ID: " << id << std::endl;
}

bool Library::loginLibrarian(int librarianId)
{
    bool failure = true;
    for (int i = 0; i < librarians.size(); i++)
    {
        if (librarianId == librarians[i].getStaffID())
        {
            std::cout << "Login successfull!" << std::endl;
            failure = false;
        }
    }
    return failure;
}

void Library::saveLibrarianDataToFile(std::string filename)
{
    // Implementation here
    std::ofstream outputFile(filename, std::ios::app);

    if (!outputFile.is_open())
    {
        std::cerr << "Failed to open the file: " << filename << std::endl;
        return;
    }
    for (Librarian &librarian : librarians)
    {
        outputFile << "Librarian Details" << std::endl;
        outputFile << "=========================================\n";
        outputFile << "ID: " << librarian.getStaffID() << std::endl;
        outputFile << "Name: " << librarian.getName() << std::endl;
        outputFile << "--------------------------------------" << std::endl;
    }
    std::cout << "Librarian data saved to file: " << filename << std::endl;

    outputFile.close();
}
//
bool Library::isLibrarianExist(Librarian librarian, std::string filename)
{
    std::ifstream inputFile(filename);

    if (!inputFile.is_open())
    {
        std::cout << "Failed to open the file: " << filename << std::endl;
        return false;
    }

    std::string line;
    std::string searchName = "Name: " + librarian.getName();
    std::string searchId = "ID: " + librarian.getStaffID();

    while (getline(inputFile, line))
    {
        if (line.find(searchName) != std::string::npos || line.find(searchId) != std::string::npos)
        {
            std::cout << "Librarian already exists." << std::endl;
            inputFile.close();
            return true;
        }
    }

    inputFile.close();
    return false;
}

Librarian Library::getLibrarianById(int librarianId)
{
    for (int i = 0; i < librarians.size(); i++)
    {
        if (librarianId == librarians[i].getStaffID())
        {
            return librarians[i];
        }
    }
}


void Library::options()
{
    std::string librarianDataFile = "librarian_data.txt"; 
    std::string memberDataFile = "member_data.txt";
    std::vector<Member> members;
    bool running = true;
    int choice, librarianId;
    std::string password;
    Library mylibrary;
    std::string idInput;
    int id;
    std::string name, address, email;
    std::string salaryInput;
    int salary;
    bool error = false;

    std::cout << "Enter Librarian ID: ";
    std::cin >> idInput;

    std::cout << "Enter Librarian Name: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    std::cout << "Enter Librarian Address: ";
    std::getline(std::cin, address);

    std::cout << "Enter Librarian Email: ";
    std::cin >> email;

    std::cout << "Enter Librarian Salary: ";
    std::cin >> salary;

    Librarian loggedInLibrarian(id, name, address, email, salary);

    while (running)
    {
        std::cout << "Library Options:" << std::endl;
        std::cout << "1. Register Librarian" << std::endl;
        std::cout << "2. Login Librarian" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            mylibrary.registerLibrarian();
            if (!mylibrary.isLibrarianExist(loggedInLibrarian, "librarian_data.txt"))
                std::string librarianDataFile = "librarian_data.txt";
            mylibrary.saveLibrarianDataToFile(librarianDataFile);
            break;

        case 2:
            //once librarian is logged in they can select options
            std::cout << "Enter Librarian ID: ";
            std::cin >> librarianId;

            if (!mylibrary.loginLibrarian(librarianId))
            {
                // Set the loggedInLibrarian to the logged-in librarian
                loggedInLibrarian = mylibrary.getLibrarianById(librarianId);

                // Switch statement here should handle options for the logged-in librarian
                int librarianChoice;
                std::cout << "Logged in as Librarian ID: " << loggedInLibrarian.getStaffID() << std::endl;

                //librarian options
                std::cout << "1. Add Member" << std::endl;
                std::cout << "2. Issue A Book" << std::endl;
                std::cout << "3. Return A Book" << std::endl;
                std::cout << "4. Display Borrowed Books" << std::endl;
                std::cout << "5. Calculate A Fine" << std::endl;
                std::cout << "6. Logout" << std::endl;
                std::cout << "Enter your choice: ";
                std::cin >> librarianChoice;

                int selectedMemberID;
                int selectedBookID;

                switch (librarianChoice)
                {
                case 1:
                    loggedInLibrarian.addMember();
                    if (!loggedInLibrarian.isMemberExist(members[0], memberDataFile))
                        std::string memberDataFile = "member_data.txt";
                    loggedInLibrarian.saveMemberDataToFile(memberDataFile);
                    break;
                case 2:
                    std::cout << "Enter Member ID: " << std::endl;
                    std::cin >> selectedMemberID;
                    std::cout << " Enter Book ID:" << std::endl;
                    std::cin >> selectedBookID;
                    selectedBookID--;
                    selectedMemberID--;
                    loggedInLibrarian.issueBook(members[selectedMemberID - 1].getMemberId(), books[selectedBookID - 1].getBookId());
                    break;
                case 3:
                    std::cout << "Enter Member ID: " << std::endl;
                    std::cin >> selectedMemberID;
                    std::cout << " Enter Book ID:" << std::endl;
                    std::cin >> selectedBookID;
                    selectedBookID--;
                    selectedMemberID--;
                    loggedInLibrarian.returnBook(members[selectedMemberID - 1].getMemberId(), books[selectedBookID - 1].getBookId());
                case 4:
                    std::cout << "Enter Member ID: " << std::endl;
                    std::cin >> selectedMemberID;
                    selectedMemberID--;
                    loggedInLibrarian.diplayBorrowedBooks(members[selectedMemberID - 1].getMemberId());
                case 5:
                    std::cout << "Enter Member ID: " << std::endl;
                    std::cin >> selectedMemberID;
                    selectedMemberID--;
                    loggedInLibrarian.calcFine(members[selectedMemberID - 1].getMemberId());
                case 27:
                    std::cout << "Press Esc to logout..." << std::endl;
                    break;

                default:
                    std::cout << "Invalid librarian option" << std::endl;
                    break;
                }
            }
            else
            {
                std::cout << "Login failed. Incorrect ID." << std::endl;
                options();
            }
            break;

        case 4:
            std::cout << "Exiting program." << std::endl;
            running = false;
            break;

        default:
            std::cout << "Invalid option" << std::endl;
            break;
        }
    }
}

void Library::ignoreCommas(){
    
}

void Library::loadBooksFromFile(std::string filename)
{
    failed = false;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        failed = true;
        return;
    }
    
    std::string line = "";
  
    std::getline(file, line);
    line = "";

    while (std::getline(file, line)) {

        std::istringstream iss(line);
        // Parse CSV line and create Book objects;
        // Read values from iss and create a Book object

        // Assuming CSV format: id,bookName,pageCount,authorFirstName,authorLastName,bookType
        std::string strId, bookName, strPageCount, authorFirstName, authorLastName, bookType;

        std::getline(iss, strId, ',');
        std::getline(iss, bookName, ',');
        std::getline(iss, strPageCount, ',');
        std::getline(iss, authorFirstName, ',');
        std::getline(iss, authorLastName, ',');
        std::getline(iss, bookType, ',');
 
         // Iterate over characters in the line
        for (char c : line) {
            if (c == ',') {
                // Handle consecutive commas
                if (strId.empty()) {
                    strId = "0"; // Assuming default value for missing ID
                }
            } else {
                // Append non-comma characters to respective strings
                strId += c;
                // Add additional checks for other fields
            }
        }

        try {
            // Convert strings to integers, handling potential errors
            int id = (strId.empty()) ? 0 : std::stoi(strId);
            int pageCount = (strPageCount.empty()) ? 0 : std::stoi(strPageCount);

            // Create Book object and add to the books vector
            Book book(id, bookName, authorFirstName, authorLastName);
            books.push_back(book);
        } catch (const std::invalid_argument& e) {
            // Handle the error, log a message, or skip the problematic line
            std::cerr << "Error converting string to integer in line: " << line << std::endl;
        } catch (const std::out_of_range& e) {
            // Handle the out-of-range error
            std::cerr << "Error: " << e.what() << " in line: " << line << std::endl;
        }

        file.close();

    }
}
      



