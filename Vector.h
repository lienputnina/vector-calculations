#ifndef Vector_h
#define Vector_h

#include <iostream>
#include <string>

using namespace std;

class Vector {

  /*
  Declaring friendly functions for input/output operators. This approach allows
  the Vector class to be directly input from and output to streams like
  'cin''and 'cout', which themselves are instances of 'istream' and 'ostream'
  classes.
  */
  friend istream &operator>>(istream &, Vector &);
  friend ostream &operator<<(ostream &, const Vector &);

private:
  /*
  A pointer to an array of 6 integers to store the coordinates of the vector -
  [x1, y1, z1, x2, y2, z2]
  */
  int *vectorCoordinates;

  /*
  A helper function that prints out the name of the specific coordinate that
  needs to be input - "x1", "y1" etc.
  */
  string getCoordinateName(int i) const;

public:
  Vector();
  ~Vector();

  /*
  Helper functions that calculate the components of the vector
  */
  int getComponentX() const;
  int getComponentY() const;
  int getComponentZ() const;

  /*
  Helper function that calculates the length of the vector by utilizing the
  component functions
  */
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