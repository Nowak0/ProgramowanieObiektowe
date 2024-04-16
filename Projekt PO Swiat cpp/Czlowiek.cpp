#include "Czlowiek.h"


Czlowiek::Czlowiek(const int polozenieX, const int polozenieY, const int wiek) {
	setNazwa("Czlowiek");
	setSymbol('C');
	setSila(5);
	setInicjatywa(4);
	setWiek(wiek);
	setPolozenieX(polozenieX);
	setPolozenieY(polozenieY);
}


void Czlowiek::akcja(Swiat& swiat) {

}


void Czlowiek::kolizja(Swiat& swiat, Organizm& atakujacy) {
}


char Czlowiek::rysowanie() {
	textcolor(WHITE);
	textbackground(BLUE);
	return getSymbol();
}


Organizm* Czlowiek::stworzNowySklonowanyObiekt() {
	return nullptr;
}


Czlowiek::~Czlowiek() {}