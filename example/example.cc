//#define NDEBUG

#include <iostream>
#include <string>
#include <sstream>
#include <assert.h>

#include "../bookstore/bookstore.h"
#include "../bookstore/book.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ostringstream;

int main() {

  ostringstream oss;
  const char* assert_string = "";

  BookStore bookstore("Biblio-globus");

  /**
   * Add some interesting books into our awesome bookstore.
   */

  Book some_book = {"Shen A.", "How not to fail exams", 750, 10};
  bookstore += some_book;

  bookstore += Book("Tatiana M.", "C++ for dummies", 125, 25);

  bookstore.add_book(Book("Author who wrote", "The cheapest book", 1, 0));

  /**
   * Print the name of bookstore.
   */

  oss << "----------------------------------------" << endl
      << "Bookstore: " <<   bookstore.get_name()    << endl
      << "----------------------------------------" << endl;

  assert_string = "----------------------------------------\n"
                  "Bookstore: Biblio-globus\n"
                  "----------------------------------------\n";

  assert(oss.str() == assert_string);
  cout << oss.str();

  assert_string = "";
  oss.str("");

  /**
   * Print all books in bookstore;
   */

  oss << bookstore;

  assert_string = "----------------------------------------\n"
                  "Author: Shen A.\n"
                  "Title: How not to fail exams\n"
                  "Price: 750\n"
                  "Discount: 10%\n"
                  "Real price: 675\n"
                  "----------------------------------------\n"
                  "----------------------------------------\n"
                  "Author: Tatiana M.\n"
                  "Title: C++ for dummies\n"
                  "Price: 125\n"
                  "Discount: 25%\n"
                  "Real price: 93.75\n"
                  "----------------------------------------\n";

  assert(oss.str() == assert_string);
  cout << oss.str();

  assert_string = "";
  oss.str("");

  /**
   * Set new discount to all books in bookstore.
   */

  bookstore.set_books_discount(50);

  /**
   * Find the cheapest book in bookstore and print information about it.
   */

  oss << endl
       << "----------------------------------------" << endl
       << "The cheapest book in bookstore is:"       << endl
       << bookstore.get_cheapest_book(true);

  assert_string = "----------------------------------------\n"
                  "Author: Author who wrote\n"
                  "Title: The cheapest book\n"
                  "Price: 1\n"
                  "Discount: 0%\n"
                  "Real price: 1\n"
                  "----------------------------------------\n";

  assert(oss.str() == assert_string);
  cout << oss.str();

  assert_string = "";
  oss.str("");

  return 0;
}
