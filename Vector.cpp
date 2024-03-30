// include stuff
// implement methods
#include "Vector.h"
#include <cmath>
#include <iostream>

Vector::Vector() {
  // new vectorCoordinates array;
}
Vector::~Vector() {
  // delete vectorCoordinates array;
}
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

// Assigning one vector to the other
Vector &Vector::operator=(const Vector &rightHandVector) {
  if (this != &rightHandVector) {
    for (int i = 0; i < 6; i++) {
      this->vectorCoordinates[i] = rightHandVector.vectorCoordinates[i];
    }
  }
  return *this;
};

// Addition of two vectors
Vector Vector::operator+(const Vector &rightHandVector) const {

  Vector additionResult;

  for (int i = 0; i < 6; i++) {
    additionResult.vectorCoordinates[i] =
        this->vectorCoordinates[i] + rightHandVector.vectorCoordinates[i];
  }

  return additionResult;
};

// Subtraction of two vectors
Vector Vector::operator-(const Vector &rightHandVector) const {
  Vector subtractionResult;

  for (int i = 0; i < 6; ++i) {
    subtractionResult.vectorCoordinates[i] =
        this->vectorCoordinates[i] - rightHandVector.vectorCoordinates[i];
  }

  return subtractionResult;
};

Vector Vector::operator*(const Vector &rightHandVector) const {
  /*
 Multiplying two vectors:
 1. Getting 3 components using the 2nd order determinant formula
 2. Returning the result - instance of Vector class - object
  */
  Vector multiplicationResult;

  int resultComponentX =
      (this->getComponentY() * rightHandVector.getComponentZ()) -
      (rightHandVector.getComponentY() * this->getComponentZ());
  int resultComponentY =
      (this->getComponentX() * rightHandVector.getComponentZ()) -
      (rightHandVector.getComponentX() * this->getComponentZ());
  int resultComponentZ =
      this->getComponentX() * rightHandVector.getComponentY() -
      (rightHandVector.getComponentX() * this->getComponentY());

  multiplicationResult.vectorCoordinates[0] = 0;
  multiplicationResult.vectorCoordinates[1] = 0;
  multiplicationResult.vectorCoordinates[2] = 0;
  multiplicationResult.vectorCoordinates[3] = resultComponentX;
  multiplicationResult.vectorCoordinates[4] = resultComponentY;
  multiplicationResult.vectorCoordinates[5] = resultComponentZ;

  return multiplicationResult;
};

// Comparison operators - comparing vector lengths
bool Vector::operator>(const Vector &rightHandVector) const {
  return this->calculateLength() > rightHandVector.calculateLength();
};
bool Vector::operator<(const Vector &rightHandVector) const {
  return this->calculateLength() < rightHandVector.calculateLength();
};

bool Vector::operator>=(const Vector &rightHandVector) const {
  return (this->calculateLength() >= rightHandVector.calculateLength());
};
bool Vector::operator<=(const Vector &rightHandVector) const {
  return (this->calculateLength() <= rightHandVector.calculateLength());
};

bool Vector::operator==(const Vector &rightHandVector) const {
  return this->calculateLength() == rightHandVector.calculateLength();
};
bool Vector::operator!=(const Vector &rightHandVector) const {
  return (this->calculateLength() != rightHandVector.calculateLength());
};