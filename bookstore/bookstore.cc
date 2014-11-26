#include "bookstore.h"

#include <stdexcept>
#include <iostream>
#include <vector>
#include <string>

using std::out_of_range;
using std::ostream;
using std::vector;
using std::string;

/**
 * Constructors.
 */

BookStore::BookStore(const string& name) : name_(name) { /* Empty */ }
BookStore::BookStore() : BookStore("Unknown bookstore") { /* Empty */ }

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

void BookStore::set_books_discount(const Book::Discount new_discount) {
  for (Book& book : books_) {
    book.set_discount(new_discount);
  }
}

Book BookStore::get_cheapest_book(const bool search_by_real_price) const {
  if (books_.size() == 0) {
    throw out_of_range("No books in bookstore.");
  } else {
    Book const* cheapest_book = &books_[0];
    Book::Price lowest_price;

    if (search_by_real_price) {
      lowest_price = books_[0].get_real_price();

      for (Book book : books_) {
        if (book.get_real_price() < lowest_price) {
          lowest_price = book.get_real_price();
          cheapest_book = &book;
        }
      }
    } else {
      lowest_price = books_[0].get_price();

      for (Book book : books_) {
        if (book.get_price() < lowest_price) {
          lowest_price = book.get_price();
          cheapest_book = &book;
        }
      }
    }

    return *cheapest_book;
  }
}

/**
 * Operators.
 */

BookStore& BookStore::operator+=(const Book& operand) {
  this->add_book(operand);
  return *this;
}

ostream& operator<<(ostream& stream, const BookStore& bookstore) {
  for (Book book : bookstore.get_books()) {
    stream << book;
  }

  return stream;
}
