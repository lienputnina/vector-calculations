#include "Vector.h"
#include <cmath>
#include <iostream>
#include <limits>
#include <string>

Vector::Vector() {
  /*
  Allocating memory for the vectorCoordinates array by creating a new instance
  of an array with 6 int elements that will be initialized to 0
  */
  vectorCoordinates = new int[6]{};
}

Vector::~Vector() {
  // Deallocating the memory for the vectorCoordinates array
  delete[] vectorCoordinates;
}

int Vector::getComponentX() const {
  return vectorCoordinates[3] - vectorCoordinates[0];
};

int Vector::getComponentY() const {
  return vectorCoordinates[4] - vectorCoordinates[1];
};

int Vector::getComponentZ() const {
  return vectorCoordinates[5] - vectorCoordinates[2];
};

float Vector::getLength() const {
  float vectorLength =
      sqrt((pow(getComponentX(), 2)) + (pow(getComponentY(), 2)) +
           (pow(getComponentZ(), 2)));
  return vectorLength;
};

string Vector::getCoordinateName(int i) const {
  switch (i) {
  case 0:
    return "x1";
  case 1:
    return "y1";
  case 2:
    return "z1";
  case 3:
    return "x2";
  case 4:
    return "y2";
  case 5:
    return "z2";
  default:
    return "";
  }
}

istream &operator>>(istream &input, Vector &coordinate) {
  for (int i = 0; i < 6; i++) {
    cout << "Enter the " << coordinate.getCoordinateName(i)
         << " coordinate:" << std::endl;

    while (!(input >> coordinate.vectorCoordinates[i])) {
      if (input.fail()) {
        cout << "Invalid input. Please, enter an integer\n";
        // Clear error flags
        input.clear();
        // Ignore the rest of the line
        input.ignore(numeric_limits<streamsize>::max(), '\n');
        // Retry the input
        continue;
      }
    }
    input.ignore(numeric_limits<streamsize>::max(), '\n');
  }

  return input;
};

ostream &operator<<(ostream &output, const Vector &vector) {
  output << " Vector's coordinates: (";
  for (int i = 0; i < 6; i++) {
    output << vector.vectorCoordinates[i];
    if (i < 5) // To avoid printing a comma after the last coordinate
      output << ", ";
  }
  output << "). ";
  output << "Vector's length: " << vector.getLength() << endl;
  return output;
}

Vector Vector::operator+(const Vector &rightHandVector) const {

  Vector resultingVector;

  for (int i = 0; i < 6; i++) {
    resultingVector.vectorCoordinates[i] =
        this->vectorCoordinates[i] + rightHandVector.vectorCoordinates[i];
  }

  return resultingVector;
};

Vector Vector::operator-(const Vector &rightHandVector) const {
  Vector resultingVector;

  for (int i = 0; i < 6; ++i) {
    resultingVector.vectorCoordinates[i] =
        this->vectorCoordinates[i] - rightHandVector.vectorCoordinates[i];
  }

  return resultingVector;
};

Vector Vector::operator*(const Vector &rightHandVector) const {
  Vector resultingVector;

  int resultComponentX =
      (this->getComponentY() * rightHandVector.getComponentZ()) -
      (rightHandVector.getComponentY() * this->getComponentZ());
  int resultComponentY =
      -((this->getComponentX() * rightHandVector.getComponentZ()) -
        (rightHandVector.getComponentX() * this->getComponentZ()));
  int resultComponentZ =
      this->getComponentX() * rightHandVector.getComponentY() -
      (rightHandVector.getComponentX() * this->getComponentY());

  resultingVector.vectorCoordinates[0] = 0;
  resultingVector.vectorCoordinates[1] = 0;
  resultingVector.vectorCoordinates[2] = 0;
  resultingVector.vectorCoordinates[3] = resultComponentX;
  resultingVector.vectorCoordinates[4] = resultComponentY;
  resultingVector.vectorCoordinates[5] = resultComponentZ;

  return resultingVector;
};

bool Vector::operator>(const Vector &rightHandVector) const {
  return this->getLength() > rightHandVector.getLength();
};

bool Vector::operator<(const Vector &rightHandVector) const {
  return this->getLength() < rightHandVector.getLength();
};

bool Vector::operator>=(const Vector &rightHandVector) const {
  return (this->getLength() >= rightHandVector.getLength());
};

bool Vector::operator<=(const Vector &rightHandVector) const {
  return (this->getLength() <= rightHandVector.getLength());
};

bool Vector::operator==(const Vector &rightHandVector) const {
  return this->getLength() == rightHandVector.getLength();
};

bool Vector::operator!=(const Vector &rightHandVector) const {
  return (this->getLength() != rightHandVector.getLength());
};

void Vector::operator=(const Vector &rightHandVector) {
  if (this != &rightHandVector) {
    for (int i = 0; i < 6; i++) {
      this->vectorCoordinates[i] = rightHandVector.vectorCoordinates[i];
    }
  }
};