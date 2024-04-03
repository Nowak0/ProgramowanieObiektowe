#include "Zwierze.h"


Zwierze::Zwierze() {}


void Zwierze::akcja(const int wymiarMapyX, const int wymiarMapyY, Swiat& swiat) {
	srand(time(NULL));
	int ruch = rand() % 4;

	if (ruch == 0 && polozenieX - 1 > 0) polozenieX -= 1;
	if (ruch == 1 && polozenieX + 1 < wymiarMapyX) polozenieX += 1;
	if (ruch == 2 && polozenieY - 1 > 0) polozenieY -= 1;
	if (ruch == 3 && polozenieY + 1 < wymiarMapyY) polozenieY += 1;
	
}


Zwierze::~Zwierze() {}