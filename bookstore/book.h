#pragma once

#include <iostream>
#include <string>

using std::ostream;
using std::string;

class Book {
public:
  typedef unsigned short Discount;
  typedef double Price;

  Book(const string&, const string&, const Price&, const Discount);
  Book(const string&, const string&, const Price&);

  string get_title() const;
  string get_author() const;
  Price get_price() const;
  Discount get_discount() const;

  void set_price(const Price&);
  void set_discount(const Discount);

  double get_real_price() const;

private:
  const string author_;
  const string title_;
  Price price_;
  Discount discount_;
};

ostream& operator<<(ostream&, const Book&);
