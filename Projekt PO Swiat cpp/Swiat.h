#pragma once
#include <iostream>
#include "Organizm.h"
#include "conio2.h"
#include <vector>
#include <functional>
#define POCZATKOWA_POZYCJA_Y 3
#define POCZATKOWA_POZYCJA_X 20
using namespace std;

class Organizm;

class Swiat {
private:
	int wymiarMapyX;
	int wymiarMapyY;
	vector<vector<char>> mapa;
public:
	Swiat(const int x, const int y);
	void wykonajTure();
	void rysujSwiat();
	int getWymiarMapyX() const;
	int getWymiarMapyY() const;
	vector<vector<char>> getMapa() const;
	void setMapa(const char symbolOrganizmu, const int polozenieX, const int polozenieY);
	vector<vector<Organizm*>> organizmy;
	void dodajOrganizm(Organizm* nowyOrganizm, int polozenieOrganizmuX, int polozenieOrganizmuY);
	void usunOrganizm(Organizm* staryOrganizm, int polozenieOrganizmuX, int polozenieOrganizmuY);
	virtual ~Swiat();
};
