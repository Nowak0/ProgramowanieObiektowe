#include "WilczeJagody.h"


WilczeJagody::WilczeJagody(const int polozenieX, const int polozenieY, const int wiek) {
	setNazwa("WilczeJagody");
	setSymbol('J');
	setSila(99);
	setInicjatywa(0);
	setWiek(wiek);
	setPolozenieX(polozenieX);
	setPolozenieY(polozenieY);
}


WilczeJagody::WilczeJagody(const Organizm& inny) {
	setNazwa(inny.getNazwa());
	setSymbol(inny.getSymbol());
	setSila(inny.getSila());
	setInicjatywa(inny.getInicjatywa());
	setWiek(inny.getWiek());
	setPolozenieX(inny.getPolozenieX());
	setPolozenieY(inny.getPolozenieY());
}


Organizm* WilczeJagody::stworzNowySklonowanyObiekt() {
	return new WilczeJagody(*this);
}


void WilczeJagody::akcja(Swiat& swiat) {
	Roslina::akcja(swiat);
}


void WilczeJagody::kolizja(Swiat& swiat, Organizm& atakujacy) {
	int polozenieX = getPolozenieX(), polozenieY = getPolozenieY(), polozenieXAtak = atakujacy.getPolozenieX(), polozenieYAtak = atakujacy.getPolozenieY();

	setWiek(NIEZYWY_ORGANIZM);
	atakujacy.setWiek(NIEZYWY_ORGANIZM);
	swiat.usunOrganizm(this, polozenieX, polozenieY);
	swiat.usunOrganizm(&atakujacy, polozenieXAtak, polozenieYAtak);
	swiat.wypiszWiadomosc(atakujacy.getNazwa() + " zjada Wilcze Jagody");
	swiat.wypiszWiadomosc(atakujacy.getNazwa() + " umiera w wyniku");
	swiat.wypiszWiadomosc("zjedzenia Wilczych Jagod");
}


char WilczeJagody::rysowanie() {
	textcolor(BLUE);
	return getSymbol();
}


WilczeJagody::~WilczeJagody() {}