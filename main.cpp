#include <iostream>
#include "person.h"
#include "library.h"
#include "book.h"
#include <string>
#include <vector>
#include <chrono>
#include <fstream>

/*
    main.cpp
    Author: Hadas Cohen <hc820@live.mdx.ac.uk>
    Created: 13/01/2023
    Updated: 15/01/2024
*/

int main()
{
    
    Librarian newLibrarian(1, "Samson Davidson", "No. 1 Somewhere Road", "davgam12345@talktalk.net", 5500);
    newLibrarian.setPassword("Password1");

    Library myLibrary(newLibrarian);

    //Enter the filename
    std::cout << "Enter the filename of the CSV file: ";
    std::string filename;
    std::cin >> filename;
    
    // Load books from the specified file
    myLibrary.loadBooksFromFile(filename);

    myLibrary.options();
    //Only if the file has successfully loaded it will allow the librarian to ongo with options
    // if(){

    // }else{
    //     std::cout << "Enter the filename of the CSV file: ";
    //     std::string filename;
    //     std::cin >> filename;
    // }
    

    return 0;
}