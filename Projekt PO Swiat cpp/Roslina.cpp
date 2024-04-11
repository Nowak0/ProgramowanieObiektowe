#include "Roslina.h"


Roslina::Roslina() {
	setInicjatywa(0);
}


void Roslina::akcja(Swiat& swiat) {
	int rozsiewanie = rand() % 100;
	if (rozsiewanie < 75) return;

	int polozenieX = getPolozenieX(), polozenieY = getPolozenieY();
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
			if (mapa[y][x] == ' ') {
				mozliweMiejscaX.push_back(x);
				mozliweMiejscaY.push_back(y);
			}
		}
	}

	int ruch = rand() % mozliweMiejscaX.size();
	int nowyX = mozliweMiejscaX[ruch], nowyY = mozliweMiejscaY[ruch];
	swiat.setMapa(aktualnySymbolPostaci, nowyX, nowyY);
	//swiat.dodajOrganizm(swiat.getOrganizmy()[polozenieY][polozenieX], nowyX, nowyY);
}


Roslina::~Roslina() {}