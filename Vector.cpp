// include stuff
// implement methods
#include "Vector.h"
#include <cmath>
#include <iostream>

int Vector::getComponentX() const {
  int x = vectorCoordinates[3] - vectorCoordinates[0];
  return x;
};

int Vector::getComponentY() const {
  int y = vectorCoordinates[4] - vectorCoordinates[1];
  return y;
};

int Vector::getComponentZ() const {
  int z = vectorCoordinates[5] - vectorCoordinates[2];
  return z;
};

double Vector::calculateLength() const {
  double vectorLength =
      sqrt((pow(getComponentX(), 2)) + (pow(getComponentY(), 2)) +
           (pow(getComponentZ(), 2)));
  return vectorLength;
};

istream &operator>>(istream &input, Vector &coordinate) {
  for (int i = 0; i < 6; i++) {
    cout << "Please, enter the coordinate of the vector. Enter one integer"
         << endl;
    input >> coordinate.vectorCoordinates[i];
  }

  return input;
};

ostream &operator<<(ostream &output, const Vector &vector) {
  output << "The vector with coordinates (";
  for (int i = 0; i < 6; i++) {
    output << vector.vectorCoordinates[i];
    if (i < 5) // To avoid printing a comma after the last coordinate
      output << ", ";
  }
  output << ") has length " << vector.calculateLength() << ".";
  return output;
}

// Assignment
Vector &Vector::operator=(const Vector &rightHandObject) {
  if (this != &rightHandObject) {
    for (int i = 0; i < 6; i++) {
      this->vectorCoordinates[i] = rightHandObject.vectorCoordinates[i];
    }
  }
  return *this;
};

// Addition of two vectors
Vector &Vector::operator+(const Vector &rightHandObject) const {

    // jauns vektora objects are 6 koordinātēm
    // x1 = Ax1 + Bx1
    // x2 = Ax2 + Bx2
    // x3 = Ax3 + Bx3 u.tml.
};

// Subtraction of two vectors
Vector &Vector::operator-(const Vector &object) const {
    // some code
};

Vector &Vector::operator*(const Vector &object) const {
    // some code
};

// Comparison operators
bool Vector::operator>(const Vector &rightHandObject) const {
  return this->calculateLength() > rightHandObject.calculateLength();
};
bool Vector::operator<(const Vector &rightHandObject) const {
  return this->calculateLength() < rightHandObject.calculateLength();
};

bool Vector::operator>=(const Vector &rightHandObject) const {
  return !(*this < rightHandObject); // check this
};
bool Vector::operator<=(const Vector &rightHandObject) const {
  return !(*this > rightHandObject); // check this
};

bool Vector::operator==(const Vector &rightHandObject) const {
  return this->calculateLength() == rightHandObject.calculateLength();
};
bool Vector::operator!=(const Vector &rightHandObject) const {
  return !(*this == rightHandObject); // check this
};