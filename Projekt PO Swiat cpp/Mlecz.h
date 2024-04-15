#pragma once
#include "Roslina.h"


class Mlecz : public Roslina {
public:
	Mlecz(const int polozenieX, const int polozenieY, const int wiek);
	Mlecz(const Organizm& inny);
	void akcja(Swiat& swiat) override;
	void kolizja(Swiat& swiat, Organizm& atakujacy) override;
	char rysowanie() override;
	Organizm* stworzNowySklonowanyObiekt() override;
	~Mlecz() override;
};