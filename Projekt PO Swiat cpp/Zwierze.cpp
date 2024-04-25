#include "Zwierze.h"


void Zwierze::akcja(Swiat& swiat) {
	int wymiarMapyX = swiat.getWymiarMapyX(), wymiarMapyY = swiat.getWymiarMapyY(), polozenieX = getPolozenieX(), polozenieY = getPolozenieY();
	vector<int> mozliweMiejscaX;
	vector<int> mozliweMiejscaY;

	for (int y = polozenieY - 1; y <= polozenieY + 1; y++)
	{
		if (y < 0 || y >= swiat.getWymiarMapyY()) continue;
		for (int x = polozenieX - 1; x <= polozenieX + 1; x++)
		{
			if (x < 0 || x >= swiat.getWymiarMapyX()) continue;
			if (x == polozenieX && y == polozenieY) continue;
			mozliweMiejscaX.push_back(x);
			mozliweMiejscaY.push_back(y);
		}
	}

	if (mozliweMiejscaX.size() == 0) return;

	int ruch = rand() % mozliweMiejscaX.size();
	int nowyX = mozliweMiejscaX[ruch], nowyY = mozliweMiejscaY[ruch];

	if (swiat.getOrganizm(nowyX,nowyY) == nullptr) {
		setPolozenieX(nowyX);
		setPolozenieY(nowyY);
		swiat.dodajOrganizm(swiat.getOrganizm(polozenieX, polozenieY) , nowyX, nowyY);
		swiat.usunOrganizm(swiat.getOrganizm(polozenieX, polozenieY), polozenieX, polozenieY);
	}

	else if (swiat.getOrganizm(nowyX, nowyY)->getSymbol() == swiat.getOrganizm(polozenieX, polozenieY)->getSymbol()) {
		Organizm* noweZwierze = this->stworzNowySklonowanyObiekt();
		Zwierze::kolizja(swiat, *noweZwierze);
	}

	else {
		swiat.getOrganizm(nowyX, nowyY)->kolizja(swiat, *this);
	}
}


void Zwierze::kolizja(Swiat& swiat, Organizm& atakujacy) { 
	// nazwa atakujacy jest dla zachowania ciaglosci nazw, jednakze jest to nowy organizm, ktory ma sie dopiero urodzic. Organizm ten ma ustawiony te same parametry co rodzic
	int polozenieX = atakujacy.getPolozenieX(), polozenieY = atakujacy.getPolozenieY();
	for (int y = polozenieY - 1; y <= polozenieY + 1; y++)
	{
		if (y < 0 || y >= swiat.getWymiarMapyY()) continue;
		for (int x = polozenieX - 1; x <= polozenieX + 1; x++)
		{
			if (x < 0 || x >= swiat.getWymiarMapyX()) continue;
			if (swiat.getOrganizm(x, y) == nullptr) {
				atakujacy.setPolozenieX(x);
				atakujacy.setPolozenieY(y);
				atakujacy.setWiek(swiat.getLiczbaOrganizmow() + 1);
				swiat.dodajOrganizm(&atakujacy, x, y);
				swiat.wypiszWiadomosc("Nowe zwierze " + atakujacy.getNazwa());
				return;
			}
		}
	}

	delete& atakujacy; //jezeli nie znaleziono miejsca dla rozmnozonego zwierzecia to nalezy usunac obiekt 
}


Zwierze::~Zwierze() {}