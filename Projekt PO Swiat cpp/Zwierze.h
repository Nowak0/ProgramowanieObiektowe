#ifndef ZWIERZE_H
#define ZWIERZE_H
#include "Organizm.h"


class Zwierze : public Organizm {
public:
	virtual void akcja(Swiat& swiat) override;
	virtual void kolizja(Swiat& swiat) override;
	virtual bool czyOdbilAtak(Organizm& atakujacy) override;
	virtual ~Zwierze() override;
};

#endif