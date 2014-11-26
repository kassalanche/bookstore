#include "book.h"

#include <iostream>
#include <string>

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

<<<<<<< HEAD
Book::Discount Book::get_discount() const {
=======
unsigned int Book::get_discount() const {
<<<<<<< Updated upstream
=======
<<<<<<< HEAD
>>>>>>> FETCH_HEAD
=======
>>>>>>> FETCH_HEAD
>>>>>>> Stashed changes
  return discount_;
}

void Book::set_price(const Price& new_price) {
  price_ = new_price;
}

void Book::set_discount(const Discount new_discount) {
  discount_ = new_discount;
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
