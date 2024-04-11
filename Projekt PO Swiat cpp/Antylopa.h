#include "Zwierze.h"

class Antylopa : public Zwierze {
public:
	Antylopa(const int polozenieX, const int polozenieY, const int wiek);
	void akcja(Swiat& swiat) override;
	void kolizja(Swiat& swiat, Organizm& atakujacy) override;
	void kopiujObiekt(const Organizm& inny) override;
	~Antylopa() override;
};
