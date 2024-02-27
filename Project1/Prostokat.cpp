#include "Prostokat.h"
#include <iostream>
using namespace std;


Prostokat::Prostokat(double a, double b) : a(a), b(b) {
	cout << "Konstruktor Prostokata(" << a << "," << b << ")" << endl;
}

double Prostokat::GetA() const {
	return a;
}

double Prostokat::GetB() const {
	return b;
}

void Prostokat::SetA(double a) {
	this->a = a;
}

void Prostokat::SetB(double b) {
	this->b = b;
}

double Prostokat::Obwod() { //TODO1
	return 2 * a + 2 * b;
}

double Prostokat::Pole() { //TODO2
	return a * b;
}

void Prostokat::Wypisz(std::ostream& out) const { //TODO3
	out << "Jest to prostokat o wymiarach " << a << " x " << b << endl;
}

Prostokat::~Prostokat() { //TODO4
	cout << "Destruktor Prostokata(" << a << "," << b << ")" << endl;
}
