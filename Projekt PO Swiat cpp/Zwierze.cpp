#include "Zwierze.h"


void Zwierze::akcja(Swiat& swiat) {
	int wymiarMapyX = swiat.getWymiarMapyX(), wymiarMapyY = swiat.getWymiarMapyY(), polozenieX = getPolozenieX(), polozenieY = getPolozenieY();
	vector<vector<char>> mapa = swiat.getMapa();
	vector<int> mozliweMiejscaX;
	vector<int> mozliweMiejscaY;
	char aktualnySymbolPostaci = mapa[polozenieY][polozenieX];

	for (int y = polozenieY - 1; y <= polozenieY + 1; y++)
	{
		if (y <= 0 || y >= swiat.getWymiarMapyY()) continue;
		for (int x = polozenieX - 1; x <= polozenieX + 1; x++)
		{
			if (x <= 0 || x >= swiat.getWymiarMapyX()) continue;
			if (x == polozenieX && y == polozenieY) continue;
			mozliweMiejscaX.push_back(x);
			mozliweMiejscaY.push_back(y);
		}
	}

	int ruch = rand() % mozliweMiejscaX.size();
	int nowyX = mozliweMiejscaX[ruch], nowyY = mozliweMiejscaY[ruch];

	if (mapa[nowyY][nowyX] == ' ') {
		swiat.setMapa(aktualnySymbolPostaci, nowyX, nowyY);
		swiat.setMapa(' ', polozenieX, polozenieY);
		setPolozenieX(nowyX);
		setPolozenieY(nowyY);
	}

	else if (mapa[nowyY][nowyX] == mapa[polozenieY][polozenieX]) kolizja(swiat);

}


void Zwierze::kolizja(Swiat& swiat) {
	int polozenieX = getPolozenieX(), polozenieY = getPolozenieY();
	char aktualnySymbolPostaci = swiat.getMapa()[polozenieY][polozenieX];
	for (int y = polozenieY - 1; y <= polozenieY + 1; y++)
	{
		if (y <= 0 || y >= swiat.getWymiarMapyY()) continue;
		for (int x = polozenieX - 1; x <= polozenieX + 1; x++)
		{
			if (x <= 0 || x >= swiat.getWymiarMapyX()) continue;
			if (swiat.getMapa()[y][x] == ' ') {
				swiat.setMapa(aktualnySymbolPostaci, x, y);
				return;
			}
		}
	}
}


bool Zwierze::czyOdbilAtak(Organizm& atakujacy) {
	return true;
}


Zwierze::~Zwierze() {}