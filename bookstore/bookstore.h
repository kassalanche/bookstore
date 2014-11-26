#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "book.h"

using std::ostream;
using std::vector;
using std::string;

class BookStore {
public:
  BookStore(const string&);
  BookStore();

  string get_name() const;
  vector<Book> get_books() const;

  void add_book(const Book&);

  void set_books_discount(const Book::Discount);

  BookStore& operator+=(const Book&);

private:
  const string name_;
  vector<Book> books_;
};

ostream& operator<<(ostream& stream, const BookStore& bookstore);
