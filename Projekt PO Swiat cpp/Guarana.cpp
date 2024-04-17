#include "Guarana.h"


Guarana::Guarana(const int polozenieX, const int polozenieY, const int wiek) {
	setNazwa("Guarana");
	setSymbol('G');
	setSila(0);
	setInicjatywa(0);
	setWiek(wiek);
	setPolozenieX(polozenieX);
	setPolozenieY(polozenieY);
	setNiesmiertelnosc(false);
}


Guarana::Guarana(const Organizm& inny) {
	setNazwa(inny.getNazwa());
	setSymbol(inny.getSymbol());
	setSila(inny.getSila());
	setInicjatywa(inny.getInicjatywa());
	setWiek(inny.getWiek());
	setPolozenieX(inny.getPolozenieX());
	setPolozenieY(inny.getPolozenieY());
}


Organizm* Guarana::stworzNowySklonowanyObiekt() {
	return new Guarana(*this);
}


void Guarana::akcja(Swiat& swiat) {
	Roslina::akcja(swiat);
}


void Guarana::kolizja(Swiat& swiat, Organizm& atakujacy) {
	int silaAtakujacego = atakujacy.getSila();
	int polozenieX = getPolozenieX(), polozenieY = getPolozenieY(), polozenieXAtak = atakujacy.getPolozenieX(), polozenieYAtak = atakujacy.getPolozenieY();

	setWiek(NIEZYWY_ORGANIZM);
	swiat.usunOrganizm(this, polozenieX, polozenieY);
	atakujacy.setPolozenieX(polozenieX);
	atakujacy.setPolozenieY(polozenieY);
	atakujacy.setSila(silaAtakujacego + 3);
	swiat.dodajOrganizm(&atakujacy, polozenieX, polozenieY);
	swiat.usunOrganizm(&atakujacy, polozenieXAtak, polozenieYAtak);
	swiat.wypiszWiadomosc(atakujacy.getNazwa() + " zjada Guarana");
}


char Guarana::rysowanie() {
	textcolor(LIGHTRED);
	return getSymbol();
}


Guarana::~Guarana() {}