#include "Lis.h"


Lis::Lis(const int polozenieX, const int polozenieY, const int wiek) {
	setSila(3);
	setInicjatywa(7);
	setWiek(wiek);
	setPolozenieX(polozenieX);
	setPolozenieY(polozenieY);
}


char Lis::getSymbol() {
	return symbol;
}


void Lis::akcja(Swiat& swiat) {
	int wymiarMapyX = swiat.getWymiarMapyX(), wymiarMapyY = swiat.getWymiarMapyY(), polozenieX = getPolozenieX(), polozenieY = getPolozenieY();
	vector<vector<char>> mapa = swiat.getMapa();
	vector<int> mozliweMiejscaX;
	vector<int> mozliweMiejscaY;
	for (int y = polozenieY - 1; y <= polozenieY + 1; y++)
	{
		if (y <= 0 || y >= swiat.getWymiarMapyY()) continue;
		for (int x = polozenieX - 1; x <= polozenieX + 1; x ++)
		{
			if (x <= 0 || x >= swiat.getWymiarMapyX()) continue;
			if (x == polozenieX && y == polozenieY) continue;
			if (mapa[y][x] == ' ' || swiat.organizmy[y][x]->getSila() <= getSila()) {
				mozliweMiejscaX.push_back(x);
				mozliweMiejscaY.push_back(y);
			}
		}
	}

	int ruchX = rand() % mozliweMiejscaX.size(), ruchY = rand() % mozliweMiejscaY.size();
	int nowyX = mozliweMiejscaX[ruchX], nowyY = mozliweMiejscaY[ruchY];

	if (mapa[nowyY][nowyX] == ' ') {
		setPolozenieX(nowyX);
		setPolozenieY(nowyY);
		//swiat.setMapa(symbol, nowyX, nowyY);
		//swiat.setMapa(' ', polozenieX, polozenieY);
		//swiat.dodajOrganizm(swiat.organizmy[polozenieY][polozenieX], nowyX, nowyY);
		swiat.dodajOrganizm(this, nowyX, nowyY);
		swiat.usunOrganizm(swiat.organizmy[polozenieY][polozenieX], polozenieX, polozenieY);
	}

	else if (mapa[nowyY][nowyX] == mapa[polozenieY][polozenieX]) Zwierze::kolizja(swiat);

	else {
		setPolozenieX(nowyX);
		setPolozenieY(nowyY);
		//swiat.setMapa(' ', polozenieX, polozenieY);
		swiat.usunOrganizm(this, polozenieX, polozenieY);
		kolizja(swiat);
	}
}


void Lis::kolizja(Swiat& swiat) {
	int polozenieX = getPolozenieX(), polozenieY = getPolozenieY();
	swiat.usunOrganizm(swiat.organizmy[polozenieY][polozenieX], polozenieX, polozenieY);
	swiat.dodajOrganizm(this, polozenieX, polozenieY);
	//swiat.setMapa(symbol, polozenieX, polozenieY);
	gotoxy(POCZATKOWA_POZYCJA_X + 3 * swiat.getWymiarMapyX(), POCZATKOWA_POZYCJA_Y);
	cputs("Lis zabil");
}


bool Lis::czyOdbilAtak(Organizm& atakujacy) {
	return true;
}


Lis::~Lis() {}