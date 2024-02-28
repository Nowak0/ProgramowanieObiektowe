#include <iostream>
#include "Trojkat.h"
#include "Prostokat.h"
#include "Kolo.h"
using namespace std;


void printOutput(const double field, const double perimeter) {
	cout << "Pole figury: " << field << endl;
	cout << "Obwod figury: " << perimeter << endl;
}


int main() {
	double a, b, c, r;
	cin >> a >> b >> c >> r;

	Prostokat* rect = new Prostokat(a, b);
	printOutput(rect->Pole(), rect->Obwod());
	delete rect;

	Trojkat* triangle = new Trojkat(a, b, c);
	printOutput(triangle->Pole(), triangle->Obwod());
	delete triangle;

	Kolo* circle = new Kolo(r);
	printOutput(circle->Pole(), circle->Obwod());
	delete circle;

	return 0;
}