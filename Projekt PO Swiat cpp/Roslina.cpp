#include "Roslina.h"


void Roslina::akcja(Swiat& swiat) {
	int rozsiewanie = rand() % 100 + 1;
	if (rozsiewanie <= 90) return;

	int wymiarMapyX = swiat.getWymiarMapyX(), wymiarMapyY = swiat.getWymiarMapyY(), polozenieX = getPolozenieX(), polozenieY = getPolozenieY();
	vector<vector<char>> mapa = swiat.getMapa();
	vector<int> mozliweMiejscaX;
	vector<int> mozliweMiejscaY;

	for (int y = polozenieY - 1; y <= polozenieY + 1; y++)
	{
		if (y < 0 || y >= swiat.getWymiarMapyY()) continue;
		for (int x = polozenieX - 1; x <= polozenieX + 1; x++)
		{
			if (x < 0 || x >= swiat.getWymiarMapyX()) continue;
			if (x == polozenieX && y == polozenieY) continue;
			if (mapa[y][x] == ' ') {
				mozliweMiejscaX.push_back(x);
				mozliweMiejscaY.push_back(y);
			}
		}
	}

	if (mozliweMiejscaX.size() == 0) return;

	int ruch = rand() % mozliweMiejscaX.size();
	int nowyX = mozliweMiejscaX[ruch], nowyY = mozliweMiejscaY[ruch];
	Organizm* nowaRoslina = this->stworzNowySklonowanyObiekt();
	nowaRoslina->setPolozenieX(nowyX);
	nowaRoslina->setPolozenieY(nowyY);
	nowaRoslina->setWiek(swiat.getLiczbaOrganizmow() + 1);
	swiat.dodajOrganizm(nowaRoslina, nowyX, nowyY);
}


Roslina::~Roslina() {}