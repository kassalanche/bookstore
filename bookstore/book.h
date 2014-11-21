#ifndef BOOKSTORE_BOOK_H
#define BOOKSTORE_BOOK_H

#include <iostream>
#include <string>

#include "byte.h"

using std::ostream;
using std::string;

class Book {
private:
  string title_,
         author_;
  double price_;
  byte discount_;
public:
  Book(const string&, const string&, const double&, const byte);

  string get_title() const;
  string get_author() const;
  double get_price() const;
  byte get_discount() const;

  void set_title(const string&);
  void set_author(const string&);
  void set_price(const double&);
  void set_discount(const byte);

  double get_real_price() const;

  friend ostream& operator<<(ostream&, const Book&);
};

#endif
