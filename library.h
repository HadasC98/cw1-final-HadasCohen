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
        Library();
        Library(Librarian &librarian);
        void options();
        Librarian getLibrarianById(int librarianId);
        void registerLibrarian();
        bool loginLibrarian(int librarianId, const std::string &password);
        void saveLibrarianDataToFile(std::string &filename);
        bool isLibrarianExist(Librarian librarian, std::string filename);
};

#endif
