#include "Zwierze.h"


class Czlowiek : public Zwierze {
public:
	Czlowiek(const int polozenieX, const int polozenieY, const int wiek);
	void akcja(Swiat& swiat) override;
	void kolizja(Swiat& swiat, Organizm& atakujacy) override;
	char rysowanie() override;
	Organizm* stworzNowySklonowanyObiekt() override;
	~Czlowiek() override;
};