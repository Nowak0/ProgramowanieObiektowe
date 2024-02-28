#ifndef KOLO_H
#define KOLO_H
#include "FiguraPlaska.h"

class Kolo : public FiguraPlaska {
private:
	double r;
	const double pi = 3.14;
protected:
	void Wypisz(std::ostream& out) const override;
public:
	Kolo(double r);
	double GetR() const;
	void SetR(double a);
	double GetPi() const;
	double Obwod() override;
	double Pole() override;
	~Kolo() override;
};


#endif