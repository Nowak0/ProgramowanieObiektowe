#include "Barszcz.h"


Barszcz::Barszcz(const int polozenieX, const int polozenieY, const int wiek) {
	setNazwa("BarszczSosnowskiego");
	setSymbol('B');
	setSila(10);
	setInicjatywa(0);
	setWiek(wiek);
	setPolozenieX(polozenieX);
	setPolozenieY(polozenieY);
}


Barszcz::Barszcz(const Organizm& inny) {
	setNazwa(inny.getNazwa());
	setSymbol(inny.getSymbol());
	setSila(inny.getSila());
	setInicjatywa(inny.getInicjatywa());
	setWiek(inny.getWiek());
	setPolozenieX(inny.getPolozenieX());
	setPolozenieY(inny.getPolozenieY());
}


Organizm* Barszcz::stworzNowySklonowanyObiekt() {
	return new Barszcz(*this);
}


void Barszcz::akcja(Swiat& swiat) {
	int wymiarMapyX = swiat.getWymiarMapyX(), wymiarMapyY = swiat.getWymiarMapyY(), polozenieX = getPolozenieX(), polozenieY = getPolozenieY();
	vector<vector<char>> mapa = swiat.getMapa();
	for (int y = polozenieY - 1; y <= polozenieY + 1; y++)
	{
		if (y < 0 || y >= wymiarMapyY) continue;
		for (int x = polozenieX - 1; x <= polozenieX + 1; x++)
		{
			if (x < 0 || x >= wymiarMapyX) continue;
			else if (x == polozenieX && y == polozenieY) continue;
			else if (mapa[y][x] != ' ' && swiat.organizmy[y][x]->getSila() > 0 && swiat.organizmy[y][x]->getNazwa() != "WilczeJagody") {
				swiat.organizmy[y][x]->setWiek(NIEZYWY_ORGANIZM);
				swiat.wypiszWiadomosc(swiat.organizmy[y][x]->getNazwa() + " zostaje zabity");
				swiat.wypiszWiadomosc("przez Barszcz Sosnowskiego");
				swiat.usunOrganizm(swiat.organizmy[y][x], x, y);
			}
		}
	}
}


void Barszcz::kolizja(Swiat& swiat, Organizm& atakujacy) {
	int polozenieX = getPolozenieX(), polozenieY = getPolozenieY(), polozenieXAtak = atakujacy.getPolozenieX(), polozenieYAtak = atakujacy.getPolozenieY();

	setWiek(NIEZYWY_ORGANIZM);
	atakujacy.setWiek(NIEZYWY_ORGANIZM);
	swiat.usunOrganizm(this, polozenieX, polozenieY);
	swiat.usunOrganizm(&atakujacy, polozenieXAtak, polozenieYAtak);
	swiat.wypiszWiadomosc(atakujacy.getNazwa() + " zjada Barszcz Sosnowskiego");
	swiat.wypiszWiadomosc(atakujacy.getNazwa() + " umiera w wyniku zjedzenia Barszczu Sosnowskiego");
}


char Barszcz::rysowanie() {
	textcolor(MAGENTA);
	return getSymbol();
}


Barszcz::~Barszcz() {}