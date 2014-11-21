#include "book.h"

#include <iostream>
#include <string>

#include "byte.h"

using std::ostream;
using std::string;

/**
 * Constructors.
 */

Book::Book(const string& author, const string& title, const double& price,
           const byte discount = 0) {
  this->set_author(author);
  this->set_title(title);
  this->set_price(price);
  this->set_discount(discount);
}

/**
 * Accessors and mutators.
 */

string Book::get_title() const {
  return title_;
}

string Book::get_author() const {
  return author_;
}

double Book::get_price() const {
  return price_;
}

byte Book::get_discount() const {
  return discount_;
}

void Book::set_title(const string& new_title) {
  title_ = new_title;
}

void Book::set_author(const string& new_author) {
  author_ = new_author;
}

void Book::set_price(const double& new_price) {
  price_ = new_price;
}

void Book::set_discount(const byte new_discount) {
  discount_ = new_discount;
}

/**
 * Custom methods.
 */

double Book::get_real_price() const {
  return (price_ - (price_ / 100 * discount_));
}

/**
 * Operators.
 */

// Returns a string like "author - title | price !! discount% | real_price".
ostream& operator<<(ostream& stream, const Book& book) {
  stream << book.get_author()
         << " - "
         << book.get_title()
         << " | "
         << book.get_price()
         << " !! "
         << book.get_discount()
         << "% | "
         << book.get_real_price();
  return stream;
}
