#ifndef BOOKSTORE_BOOKSTORE_H
#define BOOKSTORE_BOOKSTORE_H

#include <vector>
#include <string>

#include "book.h"
#include "byte.h"

using std::vector;
using std::string;

class BookStore {
private:
  string name_;
  vector<Book> books_;
public:
  BookStore(const string&);

  string get_name() const;
  vector<Book> get_books() const;

  void set_name(const string&);
  void add_book(const Book&);

  void set_books_discount(const byte);

  BookStore& operator+=(const Book&);
};

#endif
