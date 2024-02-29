#ifndef STOZEK_H
#define STOZEK_H
#include "Bryla.h"
#include "Kolo.h"
#include <iostream>


class Stozek : public Bryla {
private:
	double r, height;
	double pi = 3.14;

protected:
	void Wypisz(std::ostream& out) const override;

public:
	Stozek(double r, double height);
	void printOutput(const double baseField, const double fullField, const double l) override;
	double PolePowierzchniBocznej() override;
	double PolePowierzchniCalkowitej() override;
	double TworzacaStozka();
	~Stozek();
};

#endif