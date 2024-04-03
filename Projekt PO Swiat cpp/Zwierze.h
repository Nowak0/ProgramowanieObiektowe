#include "Organizm.h"


class Zwierze : public Organizm {
public:
	Zwierze();
	virtual void akcja(const int wymiarMapyX, const int wymiarMapyY, Swiat& swiat) override;
	virtual void kolizja(Swiat& swiat) override;
	virtual ~Zwierze();
};