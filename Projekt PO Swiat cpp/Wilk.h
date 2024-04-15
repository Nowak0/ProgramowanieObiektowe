#pragma once
#include "Zwierze.h"


class Wilk : public Zwierze {
public:
	Wilk(const int polozenieX, const int polozenieY, const int wiek);
	Wilk(const Organizm& inny);
	void akcja(Swiat& swiat) override;
	void kolizja(Swiat& swiat, Organizm& atakujacy) override;
	char rysowanie() override;
	Organizm* stworzNowySklonowanyObiekt() override;
	~Wilk() override;
};
