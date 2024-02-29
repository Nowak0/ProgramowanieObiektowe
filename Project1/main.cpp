#include <iostream>
#include "Trojkat.h"
#include "Prostokat.h"
#include "Kolo.h"
#include "Stozek.h"
using namespace std;


int main() {
	double a, b, c, r, sr, h;
	cout << "Podaj odpowiednio: a, b, c, r, sr, h: ";
	cin >> a >> b >> c >> r >> sr >> h;

	Prostokat* rect = new Prostokat(a,b);
	rect->printOutput(rect->Pole(), rect->Obwod());
	delete rect;

	Trojkat* triangle = new Trojkat(a, b, c);
	triangle->printOutput(triangle->Pole(), triangle->Obwod());
	delete triangle;
	
	/*
	FiguraPlaska* figury[2] = { new Prostokat(a,b), new Trojkat(a,b,c) };
	figury[0]->printOutput(figury[0]->Pole(), figury[0]->Obwod());
	delete figury[0];
	delete figury[1];

	alternatywny sposob definiowania obiektow (dla prezentacji z tablica obiektow)
	*/
	{
		Kolo circle(r);
		circle.printOutput(circle.Pole(), circle.Obwod());
	}

	Stozek* stozek = new Stozek(sr,h);
	stozek->printOutput(stozek->PolePowierzchniBocznej(), stozek->PolePowierzchniCalkowitej(), stozek->TworzacaStozka());
	delete stozek;

	return 0;
}