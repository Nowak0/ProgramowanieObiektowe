#pragma once
#include "Roslina.h"


class Guarana : public Roslina {
public:
	Guarana(const int polozenieX, const int polozenieY, const int wiek);
	Guarana(const Organizm& inny);
	void akcja(Swiat& swiat) override;
	void kolizja(Swiat& swiat, Organizm& atakujacy) override;
	char rysowanie() override;
	Organizm* stworzNowySklonowanyObiekt() override;
	~Guarana() override;
};