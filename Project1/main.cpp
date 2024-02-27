#include <iostream>
#include "Prostokat.h"
using namespace std;


int main() {
	double a, b, c, r;
	cin >> a >> b;

	Prostokat rect(a, b);
	cout << rect.Pole() << endl;

	return 0;
}