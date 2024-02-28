#ifndef PROSTOKAT_H
#define PROSTOKAT_H
#include "FiguraPlaska.h"

class Prostokat : public FiguraPlaska {
private:
	double a, b;

protected:
	void Wypisz(std::ostream& out) const override;

public:
	Prostokat(double a, double b);
	double GetA() const;
	void SetA(double a);
	double GetB() const;
	void SetB(double b);
	double Obwod() override;
	double Pole() override;
	// gdy zakomentarzuje powyzsza linie, Pole() nie zostanie nadpisane poprzez plik Prostokat.cpp, 
	// w wyniku czego bedzie wypisywac 1 (tak jak napisane w FiguraPlaska) dla obiektu Prostokat
	~Prostokat() override;
};


#endif
