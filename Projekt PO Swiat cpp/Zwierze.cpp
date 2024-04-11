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
		setPolozenieX(nowyX);
		setPolozenieY(nowyY);
		swiat.dodajOrganizm(swiat.organizmy[polozenieY][polozenieX], nowyX, nowyY);
		swiat.usunOrganizm(swiat.organizmy[polozenieY][polozenieX], polozenieX, polozenieY);
	}

	else if (mapa[nowyY][nowyX] == mapa[polozenieY][polozenieX]) kolizja(swiat, *this);

}


void Zwierze::kolizja(Swiat& swiat, Organizm& atakujacy) {
	int polozenieX = atakujacy.getPolozenieX(), polozenieY = atakujacy.getPolozenieY();
	for (int y = polozenieY - 1; y <= polozenieY + 1; y++)
	{
		if (y < 0 || y > swiat.getWymiarMapyY()) continue;
		for (int x = polozenieX - 1; x <= polozenieX + 1; x++)
		{
			if (x < 0 || x > swiat.getWymiarMapyX()) continue;
			if (swiat.getMapa()[y][x] == ' ') {
				Organizm* nowyOrganizm = new Zwierze();
				nowyOrganizm->kopiujObiekt(atakujacy);
				nowyOrganizm->setPolozenieX(x);
				nowyOrganizm->setPolozenieY(y);
				nowyOrganizm->setWiek(swiat.getLiczbaOrganizmow() + 1);
				swiat.dodajOrganizm(nowyOrganizm, x, y);
				swiat.wypiszWiadomosc("Nowe zwierze " + nowyOrganizm->getNazwa());
				return;
			}
		}
	}
}


Zwierze::~Zwierze() {}