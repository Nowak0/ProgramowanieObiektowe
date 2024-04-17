#include "Zolw.h"


Zolw::Zolw(const int polozenieX, const int polozenieY, const int wiek) {
	setNazwa("Zolw");
	setSymbol('Z');
	setSila(2);
	setInicjatywa(1);
	setWiek(wiek);
	setPolozenieX(polozenieX);
	setPolozenieY(polozenieY);
	setNiesmiertelnosc(false);
}


Zolw::Zolw(const Organizm& inny) {
	kopiujObiekt(inny);
}


Organizm* Zolw::stworzNowySklonowanyObiekt() {
	return new Zolw(*this);
}


void Zolw::akcja(Swiat& swiat) {
	int ruch = rand() % 100 + 1;
	if (ruch <= 75) return;
	else Zwierze::akcja(swiat);

}


void Zolw::kolizja(Swiat& swiat, Organizm& atakujacy) {
	int silaAtakujacego = atakujacy.getSila(), polozenieX = getPolozenieX(), polozenieY = getPolozenieY();
	int polozenieXAtak = atakujacy.getPolozenieX(), polozenieYAtak = atakujacy.getPolozenieY();
	bool czyPrzetrwal = czyOdbilAtak(atakujacy, *this);

	if (czyPrzetrwal) {
		swiat.wypiszWiadomosc("Zolw odpiera atak " + atakujacy.getNazwa());
		return;
	}

	else {
		setWiek(NIEZYWY_ORGANIZM);
		swiat.usunOrganizm(this, polozenieX, polozenieY);
		atakujacy.setPolozenieX(polozenieX);
		atakujacy.setPolozenieY(polozenieY);
		swiat.dodajOrganizm(&atakujacy, polozenieX, polozenieY);
		swiat.usunOrganizm(&atakujacy, polozenieXAtak, polozenieYAtak);
		swiat.wypiszWiadomosc(atakujacy.getNazwa() + " zabija Zolw");
	}
}


char Zolw::rysowanie() {
	textcolor(GREEN);
	return getSymbol();
}


bool Zolw::czyOdbilAtak(Organizm& atakujacy, Organizm& atakowany) {
	int silaAtakujacego = atakujacy.getSila();

	if (silaAtakujacego < 5) return true;
	else return false;
}


Zolw::~Zolw() {};