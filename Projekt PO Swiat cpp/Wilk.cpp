#include "Wilk.h"


Wilk::Wilk(const int polozenieX, const int polozenieY, const int wiek) {
	setNazwa("Wilk");
	setSymbol('W');
	setSila(9);
	setInicjatywa(5);
	setWiek(wiek);
	setPolozenieX(polozenieX);
	setPolozenieY(polozenieY);
	setNiesmiertelnosc(false);
}


Wilk::Wilk(const Organizm& inny) {
	kopiujObiekt(inny);
}


Organizm* Wilk::stworzNowySklonowanyObiekt() {
	return new Wilk(*this);
}


void Wilk::akcja(Swiat& swiat) {
	Zwierze::akcja(swiat);
}


void Wilk::kolizja(Swiat& swiat, Organizm& atakujacy) {
	int polozenieX = getPolozenieX(), polozenieY = getPolozenieY(), polozenieXAtak = atakujacy.getPolozenieX(), polozenieYAtak = atakujacy.getPolozenieY();
	bool czyPrzetrwal = czyOdbilAtak(atakujacy, *this);

	if (czyPrzetrwal) {
		atakujacy.setWiek(NIEZYWY_ORGANIZM);
		swiat.wypiszWiadomosc("Wilk zabija " + atakujacy.getNazwa());
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
		swiat.wypiszWiadomosc(atakujacy.getNazwa() + " zabija Wilk");
	}
}


char Wilk::rysowanie() {
	textcolor(DARKGRAY);
	return getSymbol();
}


Wilk::~Wilk() {};