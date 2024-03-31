// include stuff
#include "Vector.h"
#include <iostream>
#include <limits>

using namespace std;

/*
Helper function that checks the user input for restarting the program or leaving
it
*/
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

  /*
  Program can be repeated until an exit condition is reached
  */

  do {
    Vector vector2;

    cout << "Creating the first vector:" << endl;
    Vector vector1;
    cin >> vector1;
    cout << vector1 << endl;

    cout << "Creating the second vector:" << endl;
    cin >> vector2;
    cout << endl;
    cout << vector2 << endl;

    cout << "Vector1 + Vector2:" << endl;
    Vector vectorSum = vector1 + vector2;
    cout << vectorSum << endl;

    cout << "Vector1 - Vector2:" << endl;
    Vector vectorDifference = vector1 - vector2;
    cout << vectorDifference << endl;

    cout << "Vector1 * Vector2:" << endl;
    Vector vectorProduct = vector1 * vector2;
    cout << vectorProduct << endl;

    cout << "Vector1 < Vector2: " << (vector1 < vector2) << endl;
    cout << "Vector1 > Vector2: " << (vector1 > vector2) << endl;
    cout << "\n";

    cout << "Vector1 <= Vector2: " << (vector1 <= vector2) << endl;
    cout << "Vector1 >= Vector2: " << (vector1 >= vector2) << endl;
    cout << "\n";

    cout << "Vector1 == Vector2: " << (vector1 == vector2) << endl;
    cout << "Vector1 != Vector2: " << (vector1 != vector2) << endl;
    cout << "\n";

    cout << "Vector1 = Vector2" << endl;
    vector1 = vector2;
    cout << vector1;
    cout << vector2;
    cout << "\n";

    cout << "Enter 1 to start again or 0 to quit: " << endl;

    // Validating user input for breaking the loop
    repeatExecution = getIntInput();

  } while (repeatExecution != 0);

  return 0;
}