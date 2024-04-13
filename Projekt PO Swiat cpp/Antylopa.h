#include "Zwierze.h"

class Antylopa : public Zwierze {
public:
	Antylopa(const int polozenieX, const int polozenieY, const int wiek);
	Antylopa(const Organizm& inny);
	void akcja(Swiat& swiat) override;
	void kolizja(Swiat& swiat, Organizm& atakujacy) override;
	Organizm* stworzNowySklonowanyObiekt() override;
	~Antylopa() override;
};
