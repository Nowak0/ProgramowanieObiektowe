#include "Roslina.h"


Roslina::Roslina() {}


void Roslina::akcja(const int wymiarMapyX, const int wymiarMapyY, Swiat& swiat) {
	int rozsiewanie = rand() % 100;
	if (rozsiewanie < 75) return;

	//if (rozsiewanie == 0 && polozenieX - 1 > 0) //stworz nowy obiekt rosliny i dodaj w podanym miejscu do swiata
	//if (rozsiewanie == 1 && polozenieX + 1 < wymiarMapyX) //stworz nowy obiekt rosliny i dodaj w podanym miejscu do swiata
	//if (rozsiewanie == 2 && polozenieY - 1 > 0) //stworz nowy obiekt rosliny i dodaj w podanym miejscu do swiata
	//if (rozsiewanie == 3 && polozenieY + 1 < wymiarMapyY) //stworz nowy obiekt rosliny i dodaj w podanym miejscu do swiata
}


Roslina::~Roslina() {}