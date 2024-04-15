#pragma once
#include "Roslina.h"


class WilczeJagody : public Roslina {
public:
	WilczeJagody(const int polozenieX, const int polozenieY, const int wiek);
	WilczeJagody(const Organizm& inny);
	void akcja(Swiat& swiat) override;
	void kolizja(Swiat& swiat, Organizm& atakujacy) override;
	char rysowanie() override;
	Organizm* stworzNowySklonowanyObiekt() override;
	~WilczeJagody() override;
};