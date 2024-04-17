#include "Trawa.h"


Trawa::Trawa(const int polozenieX, const int polozenieY, const int wiek) {
	setNazwa("Trawa");
	setSymbol('T');
	setSila(0);
	setInicjatywa(0);
	setWiek(wiek);
	setPolozenieX(polozenieX);
	setPolozenieY(polozenieY);
	setNiesmiertelnosc(false);
}


Trawa::Trawa(const Organizm& inny) {
	setNazwa(inny.getNazwa());
	setSymbol(inny.getSymbol());
	setSila(inny.getSila());
	setInicjatywa(inny.getInicjatywa());
	setWiek(inny.getWiek());
	setPolozenieX(inny.getPolozenieX());
	setPolozenieY(inny.getPolozenieY());
}


Organizm* Trawa::stworzNowySklonowanyObiekt() {
	return new Trawa(*this);
}


void Trawa::akcja(Swiat& swiat) {
	Roslina::akcja(swiat);
}


void Trawa::kolizja(Swiat& swiat, Organizm& atakujacy) {
	int polozenieX = getPolozenieX(), polozenieY = getPolozenieY(), polozenieXAtak = atakujacy.getPolozenieX(), polozenieYAtak = atakujacy.getPolozenieY();

	setWiek(NIEZYWY_ORGANIZM);
	swiat.usunOrganizm(this, polozenieX, polozenieY);
	atakujacy.setPolozenieX(polozenieX);
	atakujacy.setPolozenieY(polozenieY);
	swiat.dodajOrganizm(&atakujacy, polozenieX, polozenieY);
	swiat.usunOrganizm(&atakujacy, polozenieXAtak, polozenieYAtak);
	swiat.wypiszWiadomosc(atakujacy.getNazwa() + " zjada Trawa");
}


char Trawa::rysowanie() {
	textcolor(LIGHTGREEN);
	return getSymbol();
}


Trawa::~Trawa() {}