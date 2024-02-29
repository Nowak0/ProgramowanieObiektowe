#include "Stozek.h"
#include <iostream>
#include <math.h>
using namespace std;


Stozek::Stozek(double r, double h) : r(r), height(h) {
	cout << endl << "Konstruktor stozka" << endl;
	Wypisz(cout);
}

void Stozek::Wypisz(std::ostream& out) const {
	cout << "Stozek (" << r << ", " << height << ")" << endl;
}

double Stozek::TworzacaStozka() {
	double l = sqrt(r * r + height * height);
	return l;
}

double Stozek::PolePowierzchniBocznej() {
	double result = pi * r * height;
	return result;
}

double Stozek::PolePowierzchniCalkowitej() {
	Kolo* circle = new Kolo(r);
	double result = circle->Pole() + Stozek::PolePowierzchniBocznej();

	delete circle;
	return result;
}

void Stozek::printOutput(const double baseField, const double fullField, const double l) {
	cout << "Tworzaca stozka: " << l << endl;
	cout << "Pole powierzchni bocznej: " << baseField << endl;
	cout << "Pole powierzchni calkowitej: " << fullField << endl;
}

Stozek::~Stozek() {
	cout << "Destruktor Stozka(" << r << "," << height << ")" << endl;
}