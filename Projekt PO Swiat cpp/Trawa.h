#pragma once
#include "Roslina.h"


class Trawa : public Roslina {
public:
	Trawa(const int polozenieX, const int polozenieY, const int wiek);
	Trawa(const Organizm& inny);
	void akcja(Swiat& swiat) override;
	void kolizja(Swiat& swiat, Organizm& atakujacy) override;
	char rysowanie() override;
	Organizm* stworzNowySklonowanyObiekt() override;
	~Trawa() override;
};