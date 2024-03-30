// include stuff
#include "Vector.h"
#include <iostream>
#include <limits>

using namespace std;

int getIntInput() {
  int inputNumber;
  bool continueLoop = true;
  while (continueLoop) {
    cin >> inputNumber;

    if (cin.fail()) {
      cout << "Invalid input. Please, enter an integer\n";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } else {
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      continueLoop = false;
    }
  }

  return inputNumber;
}

int main() {
  int repeatExecution = 0;

  do {
    Vector vector1;
    Vector vector2;
    Vector vector3; // not initialized, so 0

    cout << "Enter the coordinates of two vectors. Each will have 6 "
            "coordinate "
            "points."
         << endl;

    cin >> vector1;
    cout << endl;
    cout << "Vector1 created." << vector1 << endl;

    cin >> vector2;
    cout << "Vector2 created." << vector2 << endl;

    cout << "Would you like to equalize the vectors? (1 for Yes, 0 "
            "for No): "
         << endl;

    int equalizeVectors;
    equalizeVectors = getIntInput();
    if (equalizeVectors == 1) {
      vector1 = vector2;
      cout << "\nAfter equalizing the states of Vector1 and Vector2 are: "
           << vector1 << "and " << vector2 << endl;
    };

    cout << "Adding the vectors." << endl;
    vector3 = vector1 + vector2;
    cout << "The result is a new vector." << vector3 << endl;

    cout << "Subtracting the vectors." << endl;
    vector3 = vector1 - vector2;
    cout << "The result is a new vector." << vector3 << endl;

    cout << "Multiplying the vectors." << endl;
    vector3 = vector1 * vector2; // why no work?
    cout << "The result is a new vector" << vector3 << endl;

    cout << "Comparing the vectors: " << endl;
    if (vector1 > vector2) {
      cout << "Vector1 > Vector2" << endl;
    } else if (vector1 < vector2) {
      cout << "Vector1 < Vector2" << endl;
    };

    if (vector1 >= vector2) {
      cout << "Vector 1 >= than Vector2" << endl;
    } else if (vector1 <= vector2) {
      cout << "Vector 1 <= Vector2" << endl;
    };

    if (vector1 == vector2) {
      cout << "Vector1 == Vector2" << endl;
    } else if (vector1 != vector2) {
      cout << "Vector1 != Vector2" << endl;
    };

    cout << "Enter 1 to continue or 0 to quit: " << endl;
    repeatExecution = getIntInput();

  } while (repeatExecution != 0);

  return 0;
}