#include "Roslina.h"


Roslina::Roslina() {
	setInicjatywa(0);
}


void Roslina::akcja(Swiat& swiat) {
	int rozsiewanie = rand() % 100, polozenieX = getPolozenieX(), polozenieY = getPolozenieY();
	if (rozsiewanie < 75) return;

	int ruch = rozsiewanie % 4, wymiarMapyX = swiat.getWymiarMapyX(), wymiarMapyY = swiat.getWymiarMapyY();
	vector<vector<char>> mapa = swiat.getMapa();

	if (ruch == 0 && polozenieX - 1 > 0) //stworz nowy obiekt rosliny i dodaj w podanym miejscu do swiata
	{
		if (mapa[polozenieY][polozenieX-1] == ' ') {
			swiat.setMapa(mapa[polozenieY][polozenieX], polozenieX - 1, polozenieY);
		}
	}

	if (ruch == 1 && polozenieX + 1 < wymiarMapyX)
	{
		if (mapa[polozenieY][polozenieX + 1] == ' ') {
			swiat.setMapa(mapa[polozenieY][polozenieX], polozenieX + 1, polozenieY);
		}
	}

	if (ruch == 2 && polozenieY - 1 > 0)
	{
		if (mapa[polozenieY - 1][polozenieX] == ' ') {
			swiat.setMapa(mapa[polozenieY][polozenieX], polozenieX, polozenieY - 1);
		}
	}

	if (ruch == 3 && polozenieY + 1 < wymiarMapyY)
	{
		if (mapa[polozenieY + 1][polozenieX] == ' ') {
			swiat.setMapa(mapa[polozenieY][polozenieX], polozenieX, polozenieY + 1);
		}
	}
}


Roslina::~Roslina() {}