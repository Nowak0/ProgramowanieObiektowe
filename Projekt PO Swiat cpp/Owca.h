#pragma once
#include "Zwierze.h"


class Owca : public Zwierze {
public:
	Owca(const int polozenieX, const int polozenieY, const int wiek);
	Owca(const Organizm& inny);
	void akcja(Swiat& swiat) override;
	void kolizja(Swiat& swiat, Organizm& atakujacy) override;
	Organizm* stworzNowySklonowanyObiekt() override;
	~Owca() override;
};
