#include "Swiat.h"


Swiat::Swiat(const int x, const int y) : mapa(y, vector<char>(x)) {
	this->wymiarMapyX = x;
	this->wymiarMapyY = y;
	this->liczbaWiadomosci = 0;
	for (int y = 0; y < wymiarMapyY; y++)
	{
		for (int x = 0; x < wymiarMapyX; x++)
		{
			mapa[y][x] = ' ';
		}
	}
	organizmy.resize(wymiarMapyY);
	for (int i = 0; i < wymiarMapyY; i++) {
		organizmy[i].resize(wymiarMapyX, nullptr);
	}
}


void Swiat::wykonajTure() {
	liczbaWiadomosci = 0;
	for (int y = 0; y < organizmy.size(); y++)
	{
		for (int x = 0; x < organizmy[y].size(); x++)
		{
			if (organizmy[y][x] != nullptr) organizmy[y][x]->akcja(*this);
		}
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
			else putch(mapa[y][x]);

			putch(' ');
		}
		pozycjaWyswietlaniaY += 1;
		gotoxy(POCZATKOWA_POZYCJA_X, pozycjaWyswietlaniaY);
	}
}


void Swiat::setMapa(const char symbolOrganizmu, const int polozenieX, const int polozenieY) {
	this->mapa[polozenieY][polozenieX] = symbolOrganizmu;
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


vector<vector<char>> Swiat::getMapa() const {
	return mapa;
}


void Swiat::dodajOrganizm(Organizm* organizm, int polozenieOrganizmuX, int polozenieOrganizmuY) {
	//wypiszWiadomosc("dodano " + organizm->getNazwa());
	organizmy[polozenieOrganizmuY][polozenieOrganizmuX] = organizm;
	mapa[polozenieOrganizmuY][polozenieOrganizmuX] = organizm->getSymbol();
}


void Swiat::usunOrganizm(Organizm* staryOrganizm, int polozenieOrganizmuX, int polozenieOrganizmuY) {
	//organizmy[polozenieOrganizmuY].erase(organizmy[polozenieOrganizmuY].begin() + polozenieOrganizmuX);
	//wypiszWiadomosc("usunieto " + staryOrganizm->getNazwa());
	organizmy[polozenieOrganizmuY][polozenieOrganizmuX] = nullptr;
	mapa[polozenieOrganizmuY][polozenieOrganizmuX] = ' ';
}


void Swiat::setLiczbaWiadomosci() {
	liczbaWiadomosci++;
}


void Swiat::wypiszWiadomosc(string wiadomosc) {
	gotoxy(POCZATKOWA_POZYCJA_X + 3 * getWymiarMapyX(), POCZATKOWA_POZYCJA_Y + getLiczbaWiadomsci());
	cout << wiadomosc;
	setLiczbaWiadomosci();
}


Swiat::~Swiat() {
	for (int i = 0; i < organizmy.size(); i++) {
		for (int j = 0; j < organizmy[i].size(); j++) {
			if (organizmy[i][j] != nullptr) delete organizmy[i][j];
		}
	}
}