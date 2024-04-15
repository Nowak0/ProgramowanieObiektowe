#pragma once
#include "Zwierze.h"


class Lis : public Zwierze {
public:
	Lis(const int polozenieX, const int polozenieY, const int wiek);
	Lis(const Organizm& inny);
	void akcja(Swiat& swiat) override;
	void kolizja(Swiat& swiat, Organizm& atakujacy) override;
	char rysowanie() override;
	Organizm* stworzNowySklonowanyObiekt() override;
	~Lis() override;
};