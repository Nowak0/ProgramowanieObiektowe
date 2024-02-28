#ifndef FIGURAPLASKA_H
#define FIGURAPLASKA_H
#include <iostream>


class FiguraPlaska {

protected:
	virtual void Wypisz(std::ostream& out) const = 0;
	friend std::ostream& operator<<(std::ostream& os, const FiguraPlaska& figura);
public:
	virtual double Pole();
	virtual double Obwod() = 0;
	virtual void printOutput(const double field, const double perimeter);
	virtual void printOutput(const int field, const int perimeter);
	virtual ~FiguraPlaska();
};


#endif
