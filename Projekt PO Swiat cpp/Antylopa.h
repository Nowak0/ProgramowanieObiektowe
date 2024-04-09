#include "Zwierze.h"

class Antylopa : public Zwierze {
private:
	const char symbol = 'A';

public:
	Antylopa(const int polozenieX, const int polozenieY, const int wiek);
	void akcja(Swiat& swiat) override;
	void kolizja(Swiat& swiat, Organizm& atakujacy) override;
	char getSymbol() override;
	~Antylopa() override;
};
