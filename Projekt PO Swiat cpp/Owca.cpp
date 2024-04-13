#include "Owca.h"


Owca::Owca(const int polozenieX, const int polozenieY, const int wiek) {
	setNazwa("Owca");
	setSymbol('O');
	setSila(4);
	setInicjatywa(4);
	setWiek(wiek);
	setPolozenieX(polozenieX);
	setPolozenieY(polozenieY);
}


Owca::Owca(const Organizm& inny) {
	kopiujObiekt(inny);
}


Organizm* Owca::stworzNowySklonowanyObiekt() {
	return new Owca(*this);
}


void Owca::akcja(Swiat& swiat) {
	Zwierze::akcja(swiat);
}


void Owca::kolizja(Swiat& swiat, Organizm& atakujacy) {
	int polozenieX = getPolozenieX(), polozenieY = getPolozenieY(), polozenieXAtak = atakujacy.getPolozenieX(), polozenieYAtak = atakujacy.getPolozenieY();
	bool czyPrzetrwal = czyOdbilAtak(atakujacy, *this);

	if (czyPrzetrwal) {
		swiat.wypiszWiadomosc("Owca zabija " + atakujacy.getNazwa());
		atakujacy.setWiek(NIEZYWY_ORGANIZM);
		swiat.usunOrganizm(&atakujacy, polozenieXAtak, polozenieYAtak);
	}
	else {
		setWiek(NIEZYWY_ORGANIZM);
		swiat.usunOrganizm(this, polozenieX, polozenieY);
		atakujacy.setPolozenieX(polozenieX);
		atakujacy.setPolozenieY(polozenieY);
		swiat.dodajOrganizm(&atakujacy, polozenieX, polozenieY);
		swiat.usunOrganizm(swiat.organizmy[polozenieYAtak][polozenieXAtak], polozenieXAtak, polozenieYAtak);
		swiat.wypiszWiadomosc(atakujacy.getNazwa() + " zabija Owca");
	}
}


Owca::~Owca() {};