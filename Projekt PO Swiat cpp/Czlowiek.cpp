#include "Czlowiek.h"


Czlowiek::Czlowiek(const int polozenieX, const int polozenieY, const int wiek) {
	setNazwa("Czlowiek");
	setSymbol('C');
	setSila(5);
	setInicjatywa(4);
	setWiek(wiek);
	setPolozenieX(polozenieX);
	setPolozenieY(polozenieY);
	this->ruch = RUCH_NIEAKTYWNY;
	this->licznikTur = LICZBA_TUR;
	setNiesmiertelnosc(false);
	this->czyMoznaAktywowacNiesmiertelnosc = true;
}


void Czlowiek::akcja(Swiat& swiat) {
	sprawdzLiczenieTur(swiat);

	if (ruch == RUCH_PRAWO && getPolozenieX() + 1 < swiat.getWymiarMapyX()) {
		if (swiat.getOrganizm(getPolozenieX() + 1, getPolozenieY()) == nullptr) { // przesun czlowieka jezeli jest wolne miejsca
			swiat.usunOrganizm(this, getPolozenieX(), getPolozenieY());
			setPolozenieX(getPolozenieX() + 1);
			swiat.dodajOrganizm(this, getPolozenieX(), getPolozenieY());
		}

		else if (!czyNiesmiertelny() || swiat.getOrganizm(getPolozenieX() + 1, getPolozenieY())->getSila() <= getSila()) {
			swiat.getOrganizm(getPolozenieX() + 1, getPolozenieY())->kolizja(swiat, *this);
		}
	}

	else if (ruch == RUCH_LEWO && getPolozenieX() - 1 >= 0) {
		if (swiat.getOrganizm(getPolozenieX() - 1, getPolozenieY()) == nullptr) {
			swiat.usunOrganizm(this, getPolozenieX(), getPolozenieY());
			setPolozenieX(getPolozenieX() - 1);
			swiat.dodajOrganizm(this, getPolozenieX(), getPolozenieY());
		}

		else if (!czyNiesmiertelny() || swiat.getOrganizm(getPolozenieX() - 1, getPolozenieY())->getSila() <= getSila()) {
			swiat.getOrganizm(getPolozenieX() - 1, getPolozenieY())->kolizja(swiat, *this);
		}
	}

	else if (ruch == RUCH_DOL && getPolozenieY() + 1 < swiat.getWymiarMapyY()) {
		if (swiat.getOrganizm(getPolozenieX(), getPolozenieY() + 1) == nullptr) {
			swiat.usunOrganizm(this, getPolozenieX(), getPolozenieY());
			setPolozenieY(getPolozenieY() + 1);
			swiat.dodajOrganizm(this, getPolozenieX(), getPolozenieY());
		}

		else if (!czyNiesmiertelny() || swiat.getOrganizm(getPolozenieX(), getPolozenieY() + 1)->getSila() <= getSila()) {
			swiat.getOrganizm(getPolozenieX(), getPolozenieY() + 1)->kolizja(swiat, *this);
		}
	}

	else if (ruch == RUCH_GORA && getPolozenieY() - 1 >= 0) {
		if (swiat.getOrganizm(getPolozenieX(), getPolozenieY() - 1) == nullptr) {
			swiat.usunOrganizm(this, getPolozenieX(), getPolozenieY());
			setPolozenieY(getPolozenieY() - 1);
			swiat.dodajOrganizm(this, getPolozenieX(), getPolozenieY());
		}

		else if (!czyNiesmiertelny() || swiat.getOrganizm(getPolozenieX(), getPolozenieY() - 1)->getSila() <= getSila()) {
			swiat.getOrganizm(getPolozenieX(), getPolozenieY() - 1)->kolizja(swiat, *this);
		}
	}

	setRuchCzlowieka(RUCH_NIEAKTYWNY);
}


void Czlowiek::kolizja(Swiat& swiat, Organizm& atakujacy) {
	if (czyNiesmiertelny() && atakujacy.getSila() >= getSila()) kolizjaNiesmiertelnosc(swiat, atakujacy);
	else kolizjaBezNiesmiertelnosci(swiat, atakujacy);
}


void Czlowiek::kolizjaNiesmiertelnosc(Swiat& swiat, Organizm& atakujacy) {
	int polozenieX = getPolozenieX(), polozenieY = getPolozenieY(), polozenieXAtak = atakujacy.getPolozenieX(), polozenieYAtak = atakujacy.getPolozenieY();
	swiat.wypiszWiadomosc("czlowiek jest niesmiertelny");
	for (int y = polozenieY - 1; y <= polozenieY + 1; y++)
	{
		if (y < 0 || y >= swiat.getWymiarMapyY()) continue;
		for (int x = polozenieX - 1; x <= polozenieX + 1; x++)
		{
			if (x < 0 || x >= swiat.getWymiarMapyX()) continue;
			if (swiat.getOrganizm(x, y) == nullptr) {
				swiat.usunOrganizm(this, polozenieX, polozenieY);
				swiat.usunOrganizm(&atakujacy, polozenieXAtak, polozenieYAtak);
				setPolozenieX(x);
				setPolozenieY(y);
				atakujacy.setPolozenieX(polozenieX);
				atakujacy.setPolozenieY(polozenieY);
				swiat.dodajOrganizm(this, x, y);
				swiat.dodajOrganizm(&atakujacy, polozenieX, polozenieY);
				swiat.wypiszWiadomosc("Czlowiek unika ataku " + atakujacy.getNazwa());
				return;
			}
		}
	}

	swiat.wypiszWiadomosc("Czlowiek unika ataku " + atakujacy.getNazwa());
}


void Czlowiek::kolizjaBezNiesmiertelnosci(Swiat& swiat, Organizm& atakujacy) {
	int polozenieX = getPolozenieX(), polozenieY = getPolozenieY(), polozenieXAtak = atakujacy.getPolozenieX(), polozenieYAtak = atakujacy.getPolozenieY();
	bool czyPrzetrwal = czyOdbilAtak(atakujacy, *this);

	if (czyPrzetrwal) {
		atakujacy.setWiek(NIEZYWY_ORGANIZM);
		swiat.wypiszWiadomosc("Czlowiek zabija " + atakujacy.getNazwa());
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
		swiat.wypiszWiadomosc(atakujacy.getNazwa() + " zabija Czlowieka");
	}
}


char Czlowiek::rysowanie() {
	textcolor(WHITE);
	textbackground(MAGENTA);
	return getSymbol();
}


Organizm* Czlowiek::stworzNowySklonowanyObiekt() {
	return nullptr;
}


void Czlowiek::setRuchCzlowieka(const int ruch) {
	if (ruch == RUCH_PRAWO || ruch == RUCH_LEWO || ruch == RUCH_GORA || ruch == RUCH_DOL) this->ruch = ruch;
	else this->ruch = RUCH_NIEAKTYWNY;
}


void Czlowiek::aktywujNiesmiertelnoscCzlowieka(Swiat& swiat) {
	if (czyMoznaAktywowacNiesmiertelnosc) {
		swiat.wypiszWiadomosc("aktywowano niesmiertelnosc");
		setNiesmiertelnosc(true);
		licznikTur = 5;
	}
}


void Czlowiek::sprawdzLiczenieTur(Swiat& swiat) {
	if (licznikTur == 0) {
		swiat.wypiszWiadomosc("wylaczono niesmiertelnosc");
		setNiesmiertelnosc(false);
		czyMoznaAktywowacNiesmiertelnosc = false;
	}
	else if (licznikTur == LICZBA_TUR) {
		czyMoznaAktywowacNiesmiertelnosc = true;
	}

	if (czyNiesmiertelny()) licznikTur--;
	else if (!czyNiesmiertelny() && !czyMoznaAktywowacNiesmiertelnosc) licznikTur++;

}


Czlowiek::~Czlowiek() {}