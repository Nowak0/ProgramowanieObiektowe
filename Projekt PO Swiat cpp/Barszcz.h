#pragma once
#include "Roslina.h"


class Barszcz : public Roslina {
public:
	Barszcz(const int polozenieX, const int polozenieY, const int wiek);
	Barszcz(const Organizm& inny);
	void akcja(Swiat& swiat) override;
	void kolizja(Swiat& swiat, Organizm& atakujacy) override;
	char rysowanie() override;
	Organizm* stworzNowySklonowanyObiekt() override;
	~Barszcz() override;
};