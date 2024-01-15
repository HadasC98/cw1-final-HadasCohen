#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <vector>
#include <algorithm>
#include "book.h"
#include "person.h"

/*
    library.h
    Author: Hadas Cohen <hc820@live.mdx.ac.uk>
    Created: 23/12/2023
    Updated: 15/01/2024
*/

class Librarian;
class Member;

class Library
{
    private:
        std::vector<Librarian> librarians;
        std::vector<Book> books;

    public:
        bool failed;
        Library();
        //Constructor
        Library(Librarian &librarian);
        //librarian options : here the librarian registers/logs in and 
        void options();
        void ignoreCommas();
        void loadBooksFromFile(std::string filename);
        Librarian getLibrarianById(int librarianId);
        //Registration
        void registerLibrarian();
        //Login
        bool loginLibrarian(int librarianId);
        //Saving librarian details in file
        void saveLibrarianDataToFile(std::string filename);
        //Checking if librarian exists, it wont save the same librarian twice 
        bool isLibrarianExist(Librarian librarian, std::string filename);
};

#endif
