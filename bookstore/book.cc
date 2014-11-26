#include "book.h"

#include <stdexcept>
#include <iostream>
#include <string>

using std::invalid_argument;
using std::ostream;
using std::endl;
using std::string;

/**
 * Constructors.
 */

Book::Book(const string& author, const string& title, const Price& price,
           const Discount discount) : author_(author), title_(title) {
  this->set_price(price);
  this->set_discount(discount);
}

Book::Book(const string& author, const string& title, const Price& price) :
           author_(author), title_(title) {
  this->set_price(price);
  this->set_discount(0);
}

Book::Book(const Book& copy) : author_(copy.author_),
                              title_(copy.title_),
                              price_(copy.price_),
                              discount_(copy.discount_) {
  /* Empty */
  
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

Book::Price Book::get_price() const {
  return price_;
}

Book::Discount Book::get_discount() const {
  return discount_;
}

void Book::set_price(const Price& new_price) {
  if (new_price < 0) {
    throw invalid_argument("Incorrect price.");
  } else {
    price_ = new_price;
  }
}

void Book::set_discount(const Discount new_discount) {
  if (new_discount < 0 || new_discount > 100) {
    throw invalid_argument("Incorrect discount.");
  } else {
    discount_ = new_discount;
  }
}

/**
 * Custom methods.
 */

Book::Price Book::get_real_price() const {
  return (price_ - (price_ / 100 * discount_));
}

/**
 * Operators.
 */

ostream& operator<<(ostream& stream, const Book& book) {
  stream << "----------------------------------------"   << endl
         << "Author: "     << book.get_author()          << endl
         << "Title: "      << book.get_title()           << endl
         << "Price: "      << book.get_price()           << endl
         << "Discount: "   << book.get_discount() << '%' << endl
         << "Real price: " << book.get_real_price()      << endl
         << "----------------------------------------"   << endl;
  return stream;
}
