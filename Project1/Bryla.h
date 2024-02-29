#ifndef BRYLA_H
#define BRYLA_H
#include <iostream>


class Bryla {

protected:
	virtual void Wypisz(std::ostream& out) const = 0;
	friend std::ostream& operator<<(std::ostream& os, const Bryla& figura);
public:
	virtual double PolePowierzchniBocznej() = 0;
	virtual double PolePowierzchniCalkowitej() = 0;
	virtual void printOutput(const double baseField, const double fullField, const double thirdParameter) = 0;
	virtual void printOutput(const double baseField, const double fullField);
	virtual ~Bryla();
};


#endif
