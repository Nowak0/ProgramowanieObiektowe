#include "Swiat.h"


Swiat::Swiat(const int x, const int y) {
	this->wymiarMapyX = x;
	this->wymiarMapyY = y;
	this->liczbaWiadomosci = 0;
	this->posortowaneOrganizmy.resize(0);
	this->czlowiekZyje = false;
	uaktualnijGraniceMapy();
}


void Swiat::wykonajTure() {
	liczbaWiadomosci = 0;
	vector<Organizm*> tmp;
	nieZyjaceOrganizmy.clear();

	for (Organizm* o : posortowaneOrganizmy) {
		tmp.push_back(o);
		if (o!=nullptr && o->getNazwa() == "Czlowiek") sprawdzNiesmiertelnosc(*o);
	}

	for (Organizm* o : tmp) {
		if (o != nullptr && o->getWiek() != NIEZYWY_ORGANIZM) {
			o->akcja(*this);
		}
	}

	for (Organizm* o : nieZyjaceOrganizmy) {
		if (o != nullptr) delete o;
	}
}


void Swiat::rysujSwiat() {
	int pozycjaWyswietlaniaY = POCZATKOWA_POZYCJA_Y;
	gotoxy(POCZATKOWA_POZYCJA_X, pozycjaWyswietlaniaY);
	for (int y = -1; y <= wymiarMapyY; y++)
	{
		for (int x = -1; x <= wymiarMapyX; x++)
		{
			if ((x == -1 && y == -1) || (x == -1 && y == wymiarMapyY)) putch('<');
			else if ((x == wymiarMapyX && y == -1) || (x == wymiarMapyX && y == wymiarMapyY)) putch('>');
			else if (x == -1 || x == wymiarMapyX) putch('|');
			else if (y == -1 || y == wymiarMapyY) putch('-');
			else {
				if (organizmy[y][x] == nullptr) putch(' ');
				else {
					putch(organizmy[y][x]->rysowanie());
					textcolor(PODSTAWOWY_KOLOR_TEKSTU);
					textbackground(PODSTAWOWY_KOLOR_TLA);
				}
			}

			putch(' ');
		}
		pozycjaWyswietlaniaY += 1;
		gotoxy(POCZATKOWA_POZYCJA_X, pozycjaWyswietlaniaY);
	}

	gotoxy(POCZATKOWA_POZYCJA_X + 5, pozycjaWyswietlaniaY + 1);
	puts("N - nowa tura");
	gotoxy(POCZATKOWA_POZYCJA_X + 5, pozycjaWyswietlaniaY + 2);
	puts("K - niesmiertelnosc postaci");
	gotoxy(POCZATKOWA_POZYCJA_X + 5, pozycjaWyswietlaniaY + 3);
	puts("S - zapisz gre");
	gotoxy(POCZATKOWA_POZYCJA_X + 5, pozycjaWyswietlaniaY + 4);
	puts("Q - koniec");
	gotoxy(POCZATKOWA_POZYCJA_X + 5, pozycjaWyswietlaniaY + 5);
	puts("Poruszanie czlowiekiem (C) odbywa sie strzalkami");
}


int Swiat::getWymiarMapyX() const {
	return wymiarMapyX;
}


int Swiat::getWymiarMapyY() const {
	return wymiarMapyY;
}


int Swiat::getLiczbaWiadomsci() const {
	return liczbaWiadomosci;
}


int Swiat::getLiczbaOrganizmow() const {
	return (int)posortowaneOrganizmy.size();
}


Organizm* Swiat::getOrganizm(const int polozenieX, const int polozenieY) {
	return organizmy[polozenieY][polozenieX];
}


void Swiat::setWymiarMapyX(const int wymiar) {
	this->wymiarMapyX = wymiar;
}


void Swiat::setWymiarMapyY(const int wymiar) {
	this->wymiarMapyY = wymiar;
}


void Swiat::dodajOrganizm(Organizm* organizm, int polozenieOrganizmuX, int polozenieOrganizmuY) {
	if (organizm->getNazwa() == "Czlowiek") czlowiekZyje = true;
	organizmy[polozenieOrganizmuY][polozenieOrganizmuX] = organizm;
	dodajOrganizmDoPosortowanych(organizm);
}


void Swiat::usunOrganizm(Organizm* staryOrganizm, int polozenieOrganizmuX, int polozenieOrganizmuY) {
	usunOrganizmZPosortowanych(staryOrganizm);
	if (staryOrganizm->getWiek() == NIEZYWY_ORGANIZM) {
		nieZyjaceOrganizmy.push_back(staryOrganizm);
		if (staryOrganizm->getNazwa() == "Czlowiek") czlowiekZyje = false;
	}
	organizmy[polozenieOrganizmuY][polozenieOrganizmuX] = nullptr;
}


void Swiat::setLiczbaWiadomosci() {
	liczbaWiadomosci++;
}


void Swiat::wypiszWiadomosc(string wiadomosc) {
	if (getLiczbaWiadomsci() > getWymiarMapyY()) {
		gotoxy(POCZATKOWA_POZYCJA_X + 3 * getWymiarMapyX() + 3, POCZATKOWA_POZYCJA_Y);
		liczbaWiadomosci = 0;
	}
	else gotoxy(POCZATKOWA_POZYCJA_X + 3 * getWymiarMapyX() + 3, POCZATKOWA_POZYCJA_Y + getLiczbaWiadomsci());
	cout << wiadomosc;
	setLiczbaWiadomosci();
}


void Swiat::dodajOrganizmDoPosortowanych(Organizm* organizm) {
	if (organizm == nullptr) return;

	int n = posortowaneOrganizmy.size();
	int i = 0, inicjatywaOrganizmu = organizm->getInicjatywa(), wiekOrganizmu = organizm->getWiek();
	for (Organizm* o : posortowaneOrganizmy) {
		if (o == nullptr || &o == &organizm) continue;
		if (inicjatywaOrganizmu > o->getInicjatywa()) {
			posortowaneOrganizmy.resize(n + 1);
			posortowaneOrganizmy.insert(posortowaneOrganizmy.begin() + i, organizm);
			return;
		}
		else if (inicjatywaOrganizmu == o->getInicjatywa() && wiekOrganizmu < o->getWiek()) {
			posortowaneOrganizmy.resize(n + 1);
			posortowaneOrganizmy.insert(posortowaneOrganizmy.begin() + i, organizm);
			return;
		}
		i++;
	}

	posortowaneOrganizmy.push_back(organizm); // jezeli nie znaleziono miejsca w srodku, to dodaj organizm na koniec
}


void Swiat::usunOrganizmZPosortowanych(Organizm* organizm) {
	int i = 0;
	for (Organizm* o : posortowaneOrganizmy) {
		if (o != nullptr && o->getWiek() == organizm->getWiek()) {
			posortowaneOrganizmy[i] = nullptr;
			break;
		}
		i++;
	}

	usunNullPTR(i);
}


void Swiat::usunNullPTR(const int i) {
	auto o = posortowaneOrganizmy.begin() + i;
	if (*o == nullptr) o = posortowaneOrganizmy.erase(o);
}


void Swiat::sprawdzNiesmiertelnosc(Organizm& organizm) {
	organizm.sprawdzLiczenieTur();
	if (organizm.czyNiesmiertelny()) wypiszWiadomosc("niesmiertelnosc aktywna");
	else wypiszWiadomosc("niesmiertelnosc nieaktywna");
}


void Swiat::zapiszStanGry() {
	FILE* plik;
	plik = fopen("zapisGry.txt", "w");
	wstawIntDoPliku(getWymiarMapyX(), plik);
	wstawIntDoPliku(getWymiarMapyY(), plik);
	fputc('\n', plik);

	for (Organizm* o : posortowaneOrganizmy) {
		if (o == nullptr) continue;
		fputc(o->getSymbol(), plik);
		fputc(' ', plik);
		wstawIntDoPliku(o->getWiek(), plik);
		wstawIntDoPliku(o->getPolozenieX(), plik);
		wstawIntDoPliku(o->getPolozenieY(), plik);
		fputc('\n', plik);
	}

	fputc(KONIEC_PLIKU, plik);
	fclose(plik);
	wypiszWiadomosc("zapisano stan gry");
}


void Swiat::wstawIntDoPliku(int liczba, FILE* plik) {
	vector<int> wynik;

	if (liczba != 0) {
		while (liczba != 0) {
			wynik.push_back(liczba % 10);
			liczba /= 10;
		}
	}
	else wynik.push_back(liczba);

	for (int i = wynik.size() - 1; i >= 0; i--) {
		fputc(wynik[i] + '0', plik);
	}

	fputc(' ', plik);
}


void Swiat::uaktualnijGraniceMapy() {
	organizmy.resize(wymiarMapyY);
	for (int i = 0; i < wymiarMapyY; i++) {
		organizmy[i].resize(wymiarMapyX, nullptr);
	}
}


bool Swiat::czyCzlowiekZyje() {
	return czlowiekZyje;
}


Swiat::~Swiat() {
	for (int i = 0; i < organizmy.size(); i++) {
		for (int j = 0; j < organizmy[i].size(); j++) {
			if (organizmy[i][j] != nullptr) delete organizmy[i][j];
		}
	}
}