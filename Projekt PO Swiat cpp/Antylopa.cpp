#include "Antylopa.h"


Antylopa::Antylopa(const int polozenieX, const int polozenieY, const int wiek) {
	setNazwa("Antylopa");
	setSymbol('A');
	setSila(4);
	setInicjatywa(4);
	setWiek(wiek);
	setPolozenieX(polozenieX);
	setPolozenieY(polozenieY);
	setNiesmiertelnosc(false);
}


Antylopa::Antylopa(const Organizm& inny) {
	kopiujObiekt(inny);
}


Organizm* Antylopa::stworzNowySklonowanyObiekt() {
	return new Antylopa(*this);
}


void Antylopa::akcja(Swiat& swiat) {
	int wymiarMapyX = swiat.getWymiarMapyX(), wymiarMapyY = swiat.getWymiarMapyY(), polozenieX = getPolozenieX(), polozenieY = getPolozenieY();
	vector<int> mozliweMiejscaX;
	vector<int> mozliweMiejscaY;

	for (int y = polozenieY - 2; y <= polozenieY + 2; y += 2)
	{
		if (y < 0 || y >= wymiarMapyY) continue;
		for (int x = polozenieX - 2; x <= polozenieX + 2; x+=2)
		{
			if (x < 0 || x >= wymiarMapyX) continue;
			if (x == polozenieX && y == polozenieY) continue;
			mozliweMiejscaX.push_back(x);
			mozliweMiejscaY.push_back(y);
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
		Organizm* nowaAntylopa = new Antylopa(*this);
		Zwierze::kolizja(swiat, *nowaAntylopa);
	}

	else {
		swiat.getOrganizm(nowyX, nowyY)->kolizja(swiat, *this);
	}


}


void Antylopa::kolizja(Swiat& swiat, Organizm& atakujacy) {
	int polozenieX = getPolozenieX(), polozenieY = getPolozenieY(), unik = rand() % 2, polozenieXAtak = atakujacy.getPolozenieX(), polozenieYAtak = atakujacy.getPolozenieY();
	
	if (unik == 1) { 
		if (unikAntylopy(swiat, atakujacy)) return;
	}

	bool czyPrzetrwal = czyOdbilAtak(atakujacy, *this);
	if (czyPrzetrwal) {
		swiat.wypiszWiadomosc("Antylopa zabija " + atakujacy.getNazwa());
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
		swiat.wypiszWiadomosc(atakujacy.getNazwa() + " zabija Antylopa");
	}
}


bool Antylopa::unikAntylopy(Swiat& swiat, Organizm& atakujacy) {
	int polozenieX = getPolozenieX(), polozenieY = getPolozenieY(), polozenieXAtak = atakujacy.getPolozenieX(), polozenieYAtak = atakujacy.getPolozenieY();
	for (int y = polozenieY - 1; y <= polozenieY + 1; y++)
	{
		if (y < 0 || y >= swiat.getWymiarMapyY()) continue;
		for (int x = polozenieX - 1; x <= polozenieX + 1; x++)
		{
			if (x < 0 || x >= swiat.getWymiarMapyX()) continue;
			if (swiat.getOrganizm(x, y) == nullptr) {
				swiat.usunOrganizm(this, polozenieX, polozenieY);
				setPolozenieX(x);
				setPolozenieY(y);
				atakujacy.setPolozenieX(polozenieX);
				atakujacy.setPolozenieY(polozenieY);
				swiat.dodajOrganizm(this, x, y);
				swiat.dodajOrganizm(&atakujacy, polozenieX, polozenieY);
				swiat.usunOrganizm(&atakujacy, polozenieXAtak, polozenieYAtak);
				swiat.wypiszWiadomosc("Antylopa unika ataku " + atakujacy.getNazwa());
				return true;
			}
		}
	}
	return false;
}


char Antylopa::rysowanie() {
	textcolor(BROWN);
	return getSymbol();
}


Antylopa::~Antylopa() {}