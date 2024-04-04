#include "Organizm.h"


class Roslina : public Organizm {
private:

public:
	Roslina();
	virtual void akcja(const int wymiarMapyX, const int wymiarMapyY, Swiat& swiat);
	//virtual void kolizja(Swiat& swiat) override;
	virtual ~Roslina();
};