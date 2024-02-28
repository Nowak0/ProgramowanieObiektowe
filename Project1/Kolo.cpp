#include "Kolo.h"
#include <iostream>
using namespace std;


Kolo::Kolo(double r) : r(r) {
	cout << endl << "Konstruktor Kola(" << r << ")" << endl;
	Wypisz(cout);
}

double Kolo::GetR() const {
	return r;
}

double Kolo::GetPi() const {
	return pi;
}

void Kolo::SetR(double r) {
	this->r = r;
}

double Kolo::Obwod() {
	return 2*pi*r;
}

double Kolo::Pole() {
	return pi*r*r;
}

void Kolo::Wypisz(std::ostream& out) const {
	out << "Jest to kolo o promieniu " << r << endl;
}

Kolo::~Kolo() {
	cout << "Destruktor Kola(" << r << ")" << endl;
}
