#ifndef Vector_h
#define Vector_h

#include <iostream>
#include <string>

using namespace std;

class Vector {

  friend istream &operator>>(istream &, Vector &);
  friend ostream &operator<<(ostream &, const Vector &);

private:
  int *vectorCoordinates;
  string getCoordinateName(int i) const;

public:
  Vector();
  ~Vector();

  int getComponentX() const;
  int getComponentY() const;
  int getComponentZ() const;
  float getLength() const;

  Vector operator+(const Vector &) const;
  Vector operator-(const Vector &) const;
  Vector operator*(const Vector &) const;

  bool operator>(const Vector &) const;
  bool operator<(const Vector &) const;

  bool operator>=(const Vector &) const;
  bool operator<=(const Vector &) const;

  bool operator==(const Vector &) const;
  bool operator!=(const Vector &) const;

  void operator=(const Vector &);
};

#endif