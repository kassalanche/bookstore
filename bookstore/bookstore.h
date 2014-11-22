#pragma once

#include <vector>
#include <string>

#include "book.h"

using std::vector;
using std::string;

class BookStore {
private:
  const string name_;
  vector<Book> books_;
public:
  BookStore(const string&);

  string get_name() const;
  vector<Book> get_books() const;

  void add_book(const Book&);

  void set_books_discount(const unsigned int);

  BookStore& operator+=(const Book&);
};
