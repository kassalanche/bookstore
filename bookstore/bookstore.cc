#include "bookstore.h"

#include <iostream>
#include <vector>
#include <string>

using std::ostream;
using std::vector;
using std::string;

/**
 * Constructors.
 */

BookStore::BookStore(const string& name) : name_(name) { /* Empty. */ }

/**
 * Accessors and mutators.
 */

string BookStore::get_name() const {
  return name_;
}

vector<Book> BookStore::get_books() const {
  return books_;
}

void BookStore::add_book(const Book& new_book) {
  books_.push_back(new_book);
}

/**
 * Custom methods.
 */

void BookStore::set_books_discount(const unsigned int new_discount) {
  for (Book book : books_) {
    book.set_discount(new_discount);
  }
}

/**
 * Operators.
 */

BookStore& BookStore::operator+=(const Book& operand) {
  this->add_book(operand);
  return *this;
}
