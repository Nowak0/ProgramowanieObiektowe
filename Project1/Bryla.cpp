#include "Bryla.h"
#include <iostream>
using namespace std;


std::ostream& operator<<(std::ostream& os, const Bryla& figura) {
	figura.Wypisz(os);
	return os;
}

void Bryla::printOutput(const double baseField, const double fullField) {
	cout << "Pole powierzchni bocznej bryly: " << baseField << endl;
	cout << "Pole powierzchni calkowitej: " << fullField << endl;
}

Bryla::~Bryla() {}
