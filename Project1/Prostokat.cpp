#include "Prostokat.h"
#include <iostream>
using namespace std;


Prostokat::Prostokat(double a, double b) : width(a), height(b) {
	cout << endl << "Konstruktor Prostokata(" << a << "," << b << ")" << endl;
	Wypisz(cout);
}

double Prostokat::GetA() const {
	return width;
}

double Prostokat::GetB() const {
	return height;
}

void Prostokat::SetA(double a) {
	this->width = a;
}

void Prostokat::SetB(double b) {
	this->height = b;
}

double Prostokat::Obwod() {
	return 2 * width + 2 * height;
}

double Prostokat::Pole() {
	return width * height;
}


void Prostokat::Wypisz(std::ostream& out) const {
	out << "Jest to prostokat o wymiarach " << width << " x " << height << endl;
}

Prostokat::~Prostokat() {
	cout << "Destruktor Prostokata(" << width << "," << height << ")" << endl;
}
