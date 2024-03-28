// include stuff
// declare class stuff - finish the deal
#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
using namespace std;

class Vector {

  friend istream &operator>>(istream &, Vector &);
  friend ostream &operator<<(ostream &, const Vector &);

private:
  int x;
  int y;

public:
  Vector(int x, int y);
  Vector(const Vector &object);

  Vector &operator=(const Vector &);

  Vector &operator+(const Vector &object) const;
  Vector &operator-(const Vector &object) const; // check this
  Vector &operator*(const Vector &object) const; // check this

  bool operator>(const Vector &) const;
  bool operator<(const Vector &) const;

  bool operator>=(const Vector &) const;
  bool operator<=(const Vector &) const;

  bool operator==(const Vector &) const;
  bool operator!=(const Vector &) const;
};

#endif