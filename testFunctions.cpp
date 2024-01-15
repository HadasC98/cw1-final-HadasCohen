#include <catch2/catch.hpp>
#include "book.cpp"
#include "person.cpp"

TEST_CASE("Book class tests", "[Book]") {
    SECTION("Book is available initially") {
        Book book(1, "Introduction to C++", "John Doe");
        REQUIRE(book.available == true);
    }

    SECTION("Borrowing and returning a book") {
        Book book(1, "Introduction to C++", "John Doe");
        Member member(1, "Alice");

        // Borrow the book
        book.borrowBook(member, std::chrono::system_clock::now() + std::chrono::hours(72));

        // Check book status
        REQUIRE(book.available == false);
        REQUIRE(book.borrower == &member);

        // Return the book
        book.returnBook();

        // Check book status after returning
        REQUIRE(book.available == true);
        REQUIRE(book.borrower == nullptr);
    }
}

TEST_CASE("Member class tests", "[Member]") {
    SECTION("Member starts with no borrowed books") {
        Member member(1, "Alice");
        REQUIRE(member.borrowedBooks.empty() == true);
    }

    SECTION("Borrowing and returning books") {
        Book book1(1, "Introduction to C++", "John Doe");
        Book book2(2, "Data Structures", "Jane Doe");
        Member member(1, "Alice");

        // Borrow books
        book1.borrowBook(member, std::chrono::system_clock::now() + std::chrono::hours(72));
        book2.borrowBook(member, std::chrono::system_clock::now() + std::chrono::hours(48));

        // Check borrowed books
        REQUIRE(member.borrowedBooks.size() == 2);

        // Return a book
        book1.returnBook();

        // Check borrowed books after returning
        REQUIRE(member.borrowedBooks.size() == 1);
    }
}