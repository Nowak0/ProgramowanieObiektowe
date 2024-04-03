#include "Organizm.h"


class Roslina : public Organizm {
public:
	Roslina();
	virtual void akcja(const int wymiarMapyX, const int wymiarMapyY, Swiat& swiat) override;
	virtual void kolizja(Swiat& swiat) override;
	virtual ~Roslina();
};