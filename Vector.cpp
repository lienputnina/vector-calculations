#include "Vector.h"
#include <cmath>
#include <iostream>
#include <limits>
#include <string>

Vector::Vector() {
  /*
 Allocating memory for the vectorCoordinates array to hold two 3D points
 (start and end points of the vector), each represented by three integers
 (x, y, z). The array is initialized with six 0s to ensure a clean state,
 representing a vector with no magnitude or direction as its default state.
 */
  vectorCoordinates = new int[6]{};
}

Vector::~Vector() {
  /*
   Deallocating the memory for the vectorCoordinates array to prevent memory
   leaks.
  */
  delete[] vectorCoordinates;
}

int Vector::getComponentX() const {
  /*
  Calculating the X component by subtracting the value of x1 from x2 (x2 - x1).
  */
  return vectorCoordinates[3] - vectorCoordinates[0];
};

int Vector::getComponentY() const {
  /*
 Calculating the Y component by subtracting the value of y1 from y2 (y2 -
 y1).
 */
  return vectorCoordinates[4] - vectorCoordinates[1];
};

int Vector::getComponentZ() const {
  /*
 Calculating the Z component by subtracting the value of z1 from z2 (z2 - z1).
 */
  return vectorCoordinates[5] - vectorCoordinates[2];
};

float Vector::getLength() const {
  /*
  Calculating the length (magnitude) of the vector using the Euclidean norm
  formula - taking the square root of the sum of the squares of its components
  (x, y, z).
  */
  float vectorLength =
      sqrt((pow(getComponentX(), 2)) + (pow(getComponentY(), 2)) +
           (pow(getComponentZ(), 2)));
  return vectorLength;
};

/*
Returning the name of each subsequent vector coordinate
*/
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

    // Tracking the validity of the user input
    bool inputIsValid = false;

    while (!inputIsValid) {

      cout << "Enter the " << coordinate.getCoordinateName(i)
           << " coordinate:" << std::endl;

      // Attempting to parse the input
      input >> coordinate.vectorCoordinates[i];
      if (input.fail()) {
        cout << "Invalid input. Please, enter an integer coordinate" << endl;
        // Clear error flags
        input.clear();
        // Ignore the rest of the line
        input.ignore(numeric_limits<streamsize>::max(), '\n');
      } else {
        // Setting the variable to true as the input is now valid
        inputIsValid = true;
      }
    }
    // Making sure no characters are left behind in the newline stream
    input.ignore(numeric_limits<streamsize>::max(), '\n');
  }

  return input;
};

ostream &operator<<(ostream &output, const Vector &vector) {
  output << "Coordinates: (";
  for (int i = 0; i < 6; i++) {
    output << vector.vectorCoordinates[i];
    if (i < 5) // To avoid printing a comma after the last coordinate
      output << ", ";
  }
  output << "). ";
  output << "Length: " << vector.getLength() << endl;
  return output;
}

// Overloading the + operator for adding two vectors
Vector Vector::operator+(const Vector &rightHandVector) const {

  // Initialize a new Vector object to store the result
  Vector resultingVector;

  for (int i = 0; i < 6; i++) {
    /*
    Loop through each coordinate, adding corresponding components of the two
    vectors
    */
    resultingVector.vectorCoordinates[i] =
        this->vectorCoordinates[i] + rightHandVector.vectorCoordinates[i];
  }

  /*
   The result is a new vector where each component is the sum of the
   corresponding components of the operand vectors
  */
  return resultingVector;
};

// Overloading the - operator for subtracting two vectors
Vector Vector::operator-(const Vector &rightHandVector) const {

  // Initialize a new Vector object to store the result
  Vector resultingVector;

  for (int i = 0; i < 6; ++i) {
    /*
     Loop through each coordinate, subtracting corresponding components of the
     two vectors
     */
    resultingVector.vectorCoordinates[i] =
        this->vectorCoordinates[i] - rightHandVector.vectorCoordinates[i];
  }

  return resultingVector;
};

// Overloading the * operator to compute the cross product of two vectors
Vector Vector::operator*(const Vector &rightHandVector) const {

  // Initialize a new Vector object to store the result
  Vector resultingVector;

  /*
  Multiplying the vectors by using the Cross Product formula (vektoriālais
  reizinājums).
  The cross product is calculated using the determinant method, which results in
  a vector perpendicular to the two input vectors. Each component of the
  resulting vector is calculated as follows:
  */
  int resultComponentX =
      (this->getComponentY() * rightHandVector.getComponentZ()) -
      (rightHandVector.getComponentY() * this->getComponentZ());
  int resultComponentY =
      -((this->getComponentX() * rightHandVector.getComponentZ()) -
        (rightHandVector.getComponentX() * this->getComponentZ()));
  int resultComponentZ =
      this->getComponentX() * rightHandVector.getComponentY() -
      (rightHandVector.getComponentX() * this->getComponentY());

  /*
  Since the cross product only makes sense for the components and not the
  original coordinates, we set the first three coordinates (x1, y1, z1) to zero,
  indicating the vector's position relative to the origin
  */
  resultingVector.vectorCoordinates[0] = 0;
  resultingVector.vectorCoordinates[1] = 0;
  resultingVector.vectorCoordinates[2] = 0;
  resultingVector.vectorCoordinates[3] = resultComponentX;
  resultingVector.vectorCoordinates[4] = resultComponentY;
  resultingVector.vectorCoordinates[5] = resultComponentZ;

  return resultingVector;
};

// Comparing the magnitude (length) of one vector to another vector's magnitude.
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
  for (int i = 0; i < 6; i++) {
    this->vectorCoordinates[i] = rightHandVector.vectorCoordinates[i];
  }
};