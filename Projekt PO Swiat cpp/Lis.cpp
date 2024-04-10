#include "Lis.h"


Lis::Lis(const int polozenieX, const int polozenieY, const int wiek) {
	setNazwa("Lis");
	setSymbol('L');
	setSila(3);
	setInicjatywa(7);
	setWiek(wiek);
	setPolozenieX(polozenieX);
	setPolozenieY(polozenieY);
}


void Lis::kopiujObiekt(const Organizm& inny) {
	Organizm::kopiujObiekt(inny);
}


void Lis::akcja(Swiat& swiat) {
	
	int wymiarMapyX = swiat.getWymiarMapyX(), wymiarMapyY = swiat.getWymiarMapyY(), polozenieX = getPolozenieX(), polozenieY = getPolozenieY();
	vector<vector<char>> mapa = swiat.getMapa();
	vector<int> mozliweMiejscaX;
	vector<int> mozliweMiejscaY;
	for (int y = polozenieY - 1; y <= polozenieY + 1; y++)
	{
		if (y < 0 || y > swiat.getWymiarMapyY()) continue;
		for (int x = polozenieX - 1; x <= polozenieX + 1; x++)
		{
			if (x < 0 || x > swiat.getWymiarMapyX()) continue;
			else if (x == polozenieX && y == polozenieY) continue;
			else if (mapa[y][x] == ' ' || this->getSila() >= swiat.organizmy[y][x]->getSila()) {
				mozliweMiejscaX.push_back(x);
				mozliweMiejscaY.push_back(y);
			}
		}
	}

	int ruch = rand() % mozliweMiejscaX.size();
	int nowyX = mozliweMiejscaX[ruch], nowyY = mozliweMiejscaY[ruch];
	
	if (mapa[nowyY][nowyX] == ' ') {
		swiat.usunOrganizm(this, polozenieX, polozenieY);
		setPolozenieX(nowyX);
		setPolozenieY(nowyY);
		swiat.dodajOrganizm(this, nowyX, nowyY);
	}

	else if (mapa[nowyY][nowyX] == mapa[polozenieY][polozenieX]) Zwierze::kolizja(swiat, *this);

	else {
		swiat.organizmy[nowyY][nowyX]->kolizja(swiat, *this);
	}
}


void Lis::kolizja(Swiat& swiat, Organizm& atakujacy) {
	int polozenieX = getPolozenieX(), polozenieY = getPolozenieY(), polozenieXAtak = atakujacy.getPolozenieX(), polozenieYAtak = atakujacy.getPolozenieY();
	bool czyPrzetrwal = czyOdbilAtak(atakujacy, *this);

	if (czyPrzetrwal) {
		swiat.wypiszWiadomosc("Lis zabija " + atakujacy.getNazwa());
		swiat.usunOrganizm(&atakujacy, polozenieXAtak, polozenieYAtak);
	}
	else {
		swiat.usunOrganizm(this, polozenieX, polozenieY);
		atakujacy.setPolozenieX(polozenieX);
		atakujacy.setPolozenieY(polozenieY);
		swiat.dodajOrganizm(&atakujacy, polozenieX, polozenieY);
		swiat.usunOrganizm(swiat.organizmy[polozenieYAtak][polozenieXAtak], polozenieXAtak, polozenieYAtak);
		swiat.wypiszWiadomosc(atakujacy.getNazwa() + " zabija Lis");
	}
}


//Lis& Lis::operator=(const Organizm& other) {
//	setNazwa(other.getNazwa());
//	setSymbol(other.getSymbol());
//	setSila(other.getSila());
//	setInicjatywa(other.getInicjatywa());
//	setWiek(other.getWiek());
//	setPolozenieX(other.getPolozenieX());
//	setPolozenieY(other.getPolozenieY());
//	return *this;
//}


Lis::~Lis() {}