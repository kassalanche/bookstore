#pragma once

#include <iostream>
#include <string>

using std::ostream;
using std::string;

class Book {
private:
  const string author_;
  const string title_;
  double price_;
  unsigned int discount_;
public:
  Book(const string&, const string&, const double&, const unsigned int);

  string get_title() const;
  string get_author() const;
  double get_price() const;
  unsigned int get_discount() const;

  void set_price(const double&);
  void set_discount(const unsigned int);

  double get_real_price() const;

};

ostream& operator<<(ostream&, const Book&);
