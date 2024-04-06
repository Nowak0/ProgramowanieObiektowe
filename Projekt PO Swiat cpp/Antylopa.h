#include "Zwierze.h"

class Antylopa : public Zwierze {
private:
	const int symbol = 'A';

public:
	Antylopa(int polozenieX, int polozenieY, int wiek);
	void akcja(Swiat& swiat) override;
	void kolizja(Swiat& swiat) override;
	bool czyOdbilAtak(Organizm& atakujacy) override;
	int getSymbol() const;
	~Antylopa() override;
};
