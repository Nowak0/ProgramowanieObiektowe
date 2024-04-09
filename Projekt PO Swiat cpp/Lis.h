#pragma once
#include "Zwierze.h"


class Lis : public Zwierze {
private:
	const char symbol = 'L';

public:
	Lis(const int polozenieX, const int polozenieY, const int wiek);
	void akcja(Swiat& swiat) override;
	void kolizja(Swiat& swiat, Organizm& atakujacy) override;
	char getSymbol() override;
	~Lis() override;
};