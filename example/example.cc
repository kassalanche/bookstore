#include <iostream>

#include "../bookstore/bookstore.h"
#include "../bookstore/book.h"

using std::cin;
using std::cout;
using std::endl;

int main() {

  BookStore bookstore("Biblio-globus");

  /**
   * Add some interesting books into our awesome bookstore.
   */

  Book some_book = {"Shen A.", "How not to fail exams", 750, 10};
  bookstore += some_book;

  bookstore += Book("Tatiana M.", "C++ for dummies", 125, 25);

  bookstore.add_book(Book("Author who wrote", "The cheapest book", 1, 0));

  /**
   * Print all books.
   */

  cout << "----------------------------------------" << endl
       << "Bookstore: " <<   bookstore.get_name()    << endl
       << "----------------------------------------" << endl;
  cout << bookstore;

  /**
   * Set new discount to all books in bookstore.
   */

  bookstore.set_books_discount(50);

  /**
   * Find the cheapest book in bookstore and print information about it.
   */

  cout << endl
       << "----------------------------------------" << endl
       << "The cheapest book in bookstore is:"       << endl
       << bookstore.get_cheapest_book(true);

  return 0;
}
