#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
using namespace std;

class Vector {

  friend istream &operator>>(istream &, Vector &coordinate);
  friend ostream &operator<<(ostream &, const Vector &);

public:
  Vector();
  ~Vector();

  int vectorCoordinates[6] = {};

  int getComponentX() const;
  int getComponentY() const;
  int getComponentZ() const;

  double calculateLength() const;

  Vector &operator=(const Vector &rightHandObject);

  Vector operator+(const Vector &rightHandObject) const;
  Vector operator-(const Vector &rightHandObject) const;
  Vector operator*(const Vector &rightHandObject) const;

  bool operator>(const Vector &) const;
  bool operator<(const Vector &) const;

  bool operator>=(const Vector &) const;
  bool operator<=(const Vector &) const;

  bool operator==(const Vector &) const;
  bool operator!=(const Vector &) const;
};

#endif