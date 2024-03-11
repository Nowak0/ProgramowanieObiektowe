#include <iostream>
#include "input&output.h"
using namespace std;

#define ARRAY_LENGTH 4


InputOutput::InputOutput() {
	array = new double[ARRAY_LENGTH];
}


double* InputOutput::insertStartingVariables() {
	cout << "insert: a, b, c, r: ";
	cin >> array[0] >> array[1] >> array[2] >> array[3];
	return array;
}


char InputOutput::insertOperation(char operation) {
	cout << "insert operation - view (v), next (n), previous (p), end (e): " << endl;
	cin >> operation;
	return operation;
}


void InputOutput::infoProgramEnd() {
	cout << "the end of the program" << endl;
}


InputOutput::~InputOutput() {
	delete[] array;
}