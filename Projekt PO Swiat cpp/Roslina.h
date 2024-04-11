#ifndef ROSLINA_H
#define ROSLINA_H
#include "Organizm.h"


class Roslina : public Organizm {
protected:
	//int inicjatywa = 0;

public:
	Roslina();
	virtual void akcja(Swiat& swiat) override;
	//virtual void kolizja(Swiat& swiat) override;
	virtual ~Roslina() override;
};

#endif