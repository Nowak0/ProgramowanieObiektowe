#include "Swiat.h"


Swiat::Swiat(const int x, const int y) : mapa(y, vector<char>(x)) {
	this->wymiarMapyX = x;
	this->wymiarMapyY = y;
	for (int y = 0; y < wymiarMapyY; y++)
	{
		for (int x = 0; x < wymiarMapyX; x++)
		{
			mapa[y][x] = ' ';
		}
	}
}


void Swiat::wykonajTure() {}


void Swiat::rysujSwiat() {
	for (int y = 0; y < wymiarMapyY; y++)
	{
		for (int x = 0; x < wymiarMapyX; x++)
		{
			cout << mapa[y][x] << " ";
		}
		cout << endl;
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


vector<vector<char>> Swiat::getMapa() const {
	return mapa;
}


//vector<vector<Organizm>> Swiat::getOrganizmy() const {
//	return organizmy;
//}
//
//
void Swiat::dodajOrganizm(Organizm& organizm, int polozenieOrganizmuX, int polozenieOrganizmuY) {
	organizmy[polozenieOrganizmuY][polozenieOrganizmuX] = organizm;
}
//
//
void Swiat::usunOrganizm(Organizm& staryOrganizm, int polozenieOrganizmuX, int polozenieOrganizmuY) {
	organizmy[polozenieOrganizmuY].erase(organizmy[polozenieOrganizmuY].begin() + polozenieOrganizmuX);
}


Swiat::~Swiat() {}