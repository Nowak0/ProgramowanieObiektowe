#pragma once
#include "Zwierze.h"


class Lis : public Zwierze {
public:
	Lis(const int polozenieX, const int polozenieY, const int wiek);
	void akcja(Swiat& swiat) override;
	void kolizja(Swiat& swiat, Organizm& atakujacy) override;
	void kopiujObiekt(const Organizm& inny) override;
	~Lis() override;
};