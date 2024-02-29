#include "FiguraPlaska.h"
#include <iostream>
using namespace std;


std::ostream& operator<<(std::ostream& os, const FiguraPlaska& figura) {
	figura.Wypisz(os);
	return os;
}

void FiguraPlaska::printOutput(const double field, const double perimeter) {
	cout << "Pole figury: " << field << endl;
	cout << "Obwod figury: " << perimeter << endl;
}

void FiguraPlaska::printOutput(const int field, const int perimeter) {
	cout << "Pole figury (int): " << field << endl;
	cout << "Obwod figury (int): " << perimeter << endl;
}

// powyzsze dwie funkcje przedstawiaja przeciazenie (overloading). polega on na podmianie dzialania funkcji ze wzgledu na typ przyjmowanych argumentow

double FiguraPlaska::Pole() {
	return 1;
}

FiguraPlaska::~FiguraPlaska() {}
