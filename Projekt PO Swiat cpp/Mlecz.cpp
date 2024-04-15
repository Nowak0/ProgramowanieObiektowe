#include "Mlecz.h"


Mlecz::Mlecz(const int polozenieX, const int polozenieY, const int wiek) {
	setNazwa("Mlecz");
	setSymbol('M');
	setSila(0);
	setInicjatywa(0);
	setWiek(wiek);
	setPolozenieX(polozenieX);
	setPolozenieY(polozenieY);
}


Mlecz::Mlecz(const Organizm& inny) {
	setNazwa(inny.getNazwa());
	setSymbol(inny.getSymbol());
	setSila(inny.getSila());
	setInicjatywa(inny.getInicjatywa());
	setWiek(inny.getWiek());
	setPolozenieX(inny.getPolozenieX());
	setPolozenieY(inny.getPolozenieY());
}


Organizm* Mlecz::stworzNowySklonowanyObiekt() {
	return new Mlecz(*this);
}


void Mlecz::akcja(Swiat& swiat) {
	Roslina::akcja(swiat);
	Roslina::akcja(swiat);
	Roslina::akcja(swiat);
}


void Mlecz::kolizja(Swiat& swiat, Organizm& atakujacy) {
	int polozenieX = getPolozenieX(), polozenieY = getPolozenieY(), polozenieXAtak = atakujacy.getPolozenieX(), polozenieYAtak = atakujacy.getPolozenieY();
	
	setWiek(NIEZYWY_ORGANIZM);
	swiat.usunOrganizm(this, polozenieX, polozenieY);
	atakujacy.setPolozenieX(polozenieX);
	atakujacy.setPolozenieY(polozenieY);
	swiat.dodajOrganizm(&atakujacy, polozenieX, polozenieY);
	swiat.usunOrganizm(&atakujacy, polozenieXAtak, polozenieYAtak);
	swiat.wypiszWiadomosc(atakujacy.getNazwa() + " zjada Mlecz");
}


char Mlecz::rysowanie() {
	textcolor(YELLOW);
	return getSymbol();
}


Mlecz::~Mlecz() {}