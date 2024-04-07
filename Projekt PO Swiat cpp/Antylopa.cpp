#include "Antylopa.h"


Antylopa::Antylopa(int polozenieX, int polozenieY, int wiek) {
	setSila(4);
	setInicjatywa(4);
	setWiek(wiek);
	setPolozenieX(polozenieX);
	setPolozenieY(polozenieY);
}


int Antylopa::getSymbol() const {
	return symbol;
}


void Antylopa::akcja(Swiat& swiat) {
	int wymiarMapyX = swiat.getWymiarMapyX(), wymiarMapyY = swiat.getWymiarMapyY(), polozenieX = getPolozenieX(), polozenieY = getPolozenieY();
	vector<vector<char>> mapa = swiat.getMapa();
	vector<int> mozliweMiejscaX;
	vector<int> mozliweMiejscaY;

	for (int y = polozenieY - 2; y <= polozenieY + 2; y += 2)
	{
		if (y <= 0 || y >= swiat.getWymiarMapyY()) continue;
		for (int x = polozenieX - 2; x <= polozenieX + 2; x+=2)
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
		swiat.setMapa(symbol, nowyX, nowyY);
		swiat.setMapa(' ', polozenieX, polozenieY);
		//swiat.dodajOrganizm(swiat.organizmy[polozenieY][polozenieX], nowyX, nowyY);
		swiat.dodajOrganizm(*this, nowyX, nowyY);
		swiat.usunOrganizm(swiat.organizmy[polozenieY][polozenieX], polozenieX, polozenieY);
		setPolozenieX(nowyX);
		setPolozenieY(nowyY);
	}

	else if (mapa[nowyY][nowyX] == mapa[polozenieY][polozenieX]) Zwierze::kolizja(swiat);

	else {
		swiat.setMapa(' ', polozenieX, polozenieY); // usuwam dotychczasowe polozenie antylopy
		swiat.usunOrganizm(swiat.organizmy[polozenieY][polozenieX], polozenieX, polozenieY);
		setPolozenieX(nowyX);
		setPolozenieY(nowyY); // ustawiam nowe polozenie antylopy (mimo ze okupowane jest przez kogos innego)
		kolizja(swiat);
	}


}


void Antylopa::kolizja(Swiat& swiat) {
	int polozenieX = getPolozenieX(), polozenieY = getPolozenieY();
	bool czyPrzetrwal = czyOdbilAtak(swiat.organizmy[polozenieY][polozenieX]);
	if (!czyPrzetrwal) {
		return;
	}

	for (int y = polozenieY - 1; y <= polozenieY + 1; y++)
	{
		if (y <= 0 || y >= swiat.getWymiarMapyY()) continue;
		for (int x = polozenieX - 1; x <= polozenieX + 1; x++)
		{
			if (x <= 0 || x >= swiat.getWymiarMapyX()) continue;
			if (swiat.getMapa()[y][x] == ' ') {
				swiat.setMapa(symbol, x, y);
				setPolozenieX(x);
				setPolozenieY(y);
				swiat.dodajOrganizm(*this, x, y);
				return;
			}
		}
	}
}


bool Antylopa::czyOdbilAtak(Organizm& atakujacy) {
	int unik = rand() % 2;
	if (unik == 1) return true;
	else return false;
}


Antylopa::~Antylopa() {}