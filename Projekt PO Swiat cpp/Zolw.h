#pragma once
#include "Zwierze.h"


class Zolw : public Zwierze {
public:
	Zolw(const int polozenieX, const int polozenieY, const int wiek);
	Zolw(const Organizm& inny);
	void akcja(Swiat& swiat) override;
	void kolizja(Swiat& swiat, Organizm& atakujacy) override;
	char rysowanie() override;
	bool czyOdbilAtak(Organizm& atakujacy, Organizm& atakowany) override;
	Organizm* stworzNowySklonowanyObiekt() override;
	~Zolw() override;
};