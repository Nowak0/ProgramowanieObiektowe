#include "Swiat.h"


Swiat::Swiat(const int x, const int y) {
	this->wymiarMapyX = x;
	this->wymiarMapyY = y;
	this->liczbaWiadomosci = 0;
	this->posortowaneOrganizmy.resize(0);
	organizmy.resize(wymiarMapyY);
	for (int i = 0; i < wymiarMapyY; i++) {
		organizmy[i].resize(wymiarMapyX, nullptr);
	}
}


void Swiat::wykonajTure() {
	liczbaWiadomosci = 0;
	vector<Organizm*> tmp;
	nieZyjaceOrganizmy.clear();

	for (Organizm* o : posortowaneOrganizmy) {
		tmp.push_back(o);
	}

	for (Organizm* o : tmp) {
		if (o != nullptr && o->getWiek() != NIEZYWY_ORGANIZM) {
			//wypiszWiadomosc("akcja dla " + o->getNazwa());
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

	gotoxy(POCZATKOWA_POZYCJA_X + 5, pozycjaWyswietlaniaY + 2);
	puts("N - nowa tura");
	gotoxy(POCZATKOWA_POZYCJA_X + 5, pozycjaWyswietlaniaY + 3);
	puts("Q - koniec");
	gotoxy(POCZATKOWA_POZYCJA_X + 5, pozycjaWyswietlaniaY + 4);
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


void Swiat::dodajOrganizm(Organizm* organizm, int polozenieOrganizmuX, int polozenieOrganizmuY) {
	organizmy[polozenieOrganizmuY][polozenieOrganizmuX] = organizm;
	dodajOrganizmDoPosortowanych(organizm);
}


void Swiat::usunOrganizm(Organizm* staryOrganizm, int polozenieOrganizmuX, int polozenieOrganizmuY) {
	usunOrganizmZPosortowanych(staryOrganizm);
	if (staryOrganizm->getWiek() == NIEZYWY_ORGANIZM) nieZyjaceOrganizmy.push_back(staryOrganizm);
	organizmy[polozenieOrganizmuY][polozenieOrganizmuX] = nullptr;
}


void Swiat::setLiczbaWiadomosci() {
	liczbaWiadomosci++;
}


void Swiat::wypiszWiadomosc(string wiadomosc) {
	gotoxy(POCZATKOWA_POZYCJA_X + 3 * getWymiarMapyX() + 3, POCZATKOWA_POZYCJA_Y + getLiczbaWiadomsci());
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


Swiat::~Swiat() {
	for (int i = 0; i < organizmy.size(); i++) {
		for (int j = 0; j < organizmy[i].size(); j++) {
			if (organizmy[i][j] != nullptr) delete organizmy[i][j];
		}
	}
}