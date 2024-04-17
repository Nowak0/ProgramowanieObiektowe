#include "Lis.h"


Lis::Lis(const int polozenieX, const int polozenieY, const int wiek) {
	setNazwa("Lis");
	setSymbol('L');
	setSila(3);
	setInicjatywa(7);
	setWiek(wiek);
	setPolozenieX(polozenieX);
	setPolozenieY(polozenieY);
	setNiesmiertelnosc(false);
}


Lis::Lis(const Organizm& inny) {
	kopiujObiekt(inny);
}


Organizm* Lis::stworzNowySklonowanyObiekt() {
	return new Lis(*this);
}


void Lis::akcja(Swiat& swiat) {
	int wymiarMapyX = swiat.getWymiarMapyX(), wymiarMapyY = swiat.getWymiarMapyY(), polozenieX = getPolozenieX(), polozenieY = getPolozenieY();
	vector<int> mozliweMiejscaX;
	vector<int> mozliweMiejscaY;
	for (int y = polozenieY - 1; y <= polozenieY + 1; y++)
	{
		if (y < 0 || y >= wymiarMapyY) continue;
		for (int x = polozenieX - 1; x <= polozenieX + 1; x++)
		{
			if (x < 0 || x >= wymiarMapyX) continue;
			else if (x == polozenieX && y == polozenieY) continue;
			else if (swiat.getOrganizm(x, y) == nullptr || this->getSila() >= swiat.getOrganizm(x, y)->getSila()) {
				mozliweMiejscaX.push_back(x);
				mozliweMiejscaY.push_back(y);
			}
		}
	}

	if (mozliweMiejscaX.size() == 0) return;

	int ruch = rand() % mozliweMiejscaX.size();
	int nowyX = mozliweMiejscaX[ruch], nowyY = mozliweMiejscaY[ruch];
	
	if (swiat.getOrganizm(nowyX, nowyY) == nullptr) {
		swiat.usunOrganizm(this, polozenieX, polozenieY);
		setPolozenieX(nowyX);
		setPolozenieY(nowyY);
		swiat.dodajOrganizm(this, nowyX, nowyY);
	}

	else if (swiat.getOrganizm(nowyX, nowyY)->getSymbol() == swiat.getOrganizm(polozenieX, polozenieY)->getSymbol()) {
		Organizm* nowyLis = new Lis(*this);
		Zwierze::kolizja(swiat, *nowyLis);
	}

	else {
		swiat.getOrganizm(nowyX, nowyY)->kolizja(swiat, *this);
	}
}


void Lis::kolizja(Swiat& swiat, Organizm& atakujacy) {
	int polozenieX = getPolozenieX(), polozenieY = getPolozenieY(), polozenieXAtak = atakujacy.getPolozenieX(), polozenieYAtak = atakujacy.getPolozenieY();
	bool czyPrzetrwal = czyOdbilAtak(atakujacy, *this);

	if (czyPrzetrwal) {
		swiat.wypiszWiadomosc("Lis zabija " + atakujacy.getNazwa());
		atakujacy.setWiek(NIEZYWY_ORGANIZM);
		swiat.usunOrganizm(&atakujacy, polozenieXAtak, polozenieYAtak);
	}
	else {
		setWiek(NIEZYWY_ORGANIZM);
		swiat.usunOrganizm(this, polozenieX, polozenieY);
		atakujacy.setPolozenieX(polozenieX);
		atakujacy.setPolozenieY(polozenieY);
		swiat.dodajOrganizm(&atakujacy, polozenieX, polozenieY);
		swiat.usunOrganizm(&atakujacy, polozenieXAtak, polozenieYAtak);
		swiat.wypiszWiadomosc(atakujacy.getNazwa() + " zabija Lis");
	}
}


char Lis::rysowanie() {
	textcolor(RED);
	return getSymbol();
}


Lis::~Lis() {}