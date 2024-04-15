#pragma once
#include <iostream>
#include "Organizm.h"
#include <string>
#include <vector>
#define POCZATKOWA_POZYCJA_Y 3
#define POCZATKOWA_POZYCJA_X 20
#define NIEZYWY_ORGANIZM -1
using namespace std;

class Organizm;

class Swiat {
private:
	int wymiarMapyX;
	int wymiarMapyY;
	int liczbaWiadomosci;
	vector<vector<char>> mapa;
	vector<Organizm*> posortowaneOrganizmy;
	vector<Organizm*> nieZyjaceOrganizmy;
	void usunOrganizmZPosortowanych(Organizm* organizm);
	void usunNullPTR(const int i);
	void dodajOrganizmDoPosortowanych(Organizm* organizm);
public:
	Swiat(const int x, const int y);
	vector<vector<Organizm*>> organizmy;
	void wykonajTure();
	void rysujSwiat();
	int getWymiarMapyX() const;
	int getWymiarMapyY() const;
	int getLiczbaWiadomsci() const;
	int getLiczbaOrganizmow() const;
	vector<vector<char>> getMapa() const;
	void setMapa(const char symbolOrganizmu, const int polozenieX, const int polozenieY);
	void setLiczbaWiadomosci();
	void dodajOrganizm(Organizm* nowyOrganizm, int polozenieOrganizmuX, int polozenieOrganizmuY);
	void usunOrganizm(Organizm* staryOrganizm, int polozenieOrganizmuX, int polozenieOrganizmuY);
	void wypiszWiadomosc(string wiadomosc);
	virtual ~Swiat();
};
