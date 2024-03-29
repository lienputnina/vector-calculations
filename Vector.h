#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
using namespace std;

class Vector {

  friend istream &operator>>(istream &, Vector &object);
  friend ostream &operator<<(ostream &, const Vector &);

public:
  int vectorCoordinates[6] = {};

  int getComponentX() const;
  int getComponentY() const;
  int getComponentZ() const;

  double calculateLength() const;

  Vector &operator=(const Vector &object);

  Vector &operator+(const Vector &object) const;
  Vector &operator-(const Vector &object) const;
  Vector &operator*(const Vector &object) const;

  bool operator>(const Vector &) const;
  bool operator<(const Vector &) const;

  bool operator>=(const Vector &) const;
  bool operator<=(const Vector &) const;

  bool operator==(const Vector &) const;
  bool operator!=(const Vector &) const;
};

#endif