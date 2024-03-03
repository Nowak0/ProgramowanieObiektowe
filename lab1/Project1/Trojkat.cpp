#include "Trojkat.h"
#include <iostream>
#include <math.h>
using namespace std;


Trojkat::Trojkat(double a, double b, double c) : a(a), b(b), c(c) {
	cout << endl << "Konstruktor Trojkata(" << a << "," << b << "," << c << ")" << endl;
	Wypisz(cout);
}

double Trojkat::GetA() const {
	return a;
}

double Trojkat::GetB() const {
	return b;
}

double Trojkat::GetC() const {
	return c;
}

void Trojkat::SetA(double a) {
	this->a = a;
}

void Trojkat::SetB(double b) {
	this->b = b;
}

void Trojkat::SetC(double c) {
	this->c = c;
}

double Trojkat::Obwod() {
	return a+b+c;
}

double Trojkat::Pole() {
	double p = 0.5 * (a + b + c);
	double result = sqrt(p * (p - a) * (p - b) * (p - c));
	return result;
}

void Trojkat::Wypisz(std::ostream& out) const {
	out << "Jest to trojkat o wymiarach " << a << " x " << b << " x " << c << endl;
}

Trojkat::~Trojkat() {
	cout << "Destruktor Trojkata(" << a << "," << b << "," << c << ")" << endl;
}