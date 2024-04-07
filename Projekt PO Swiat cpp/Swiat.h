#pragma once
#include <iostream>
#include "Organizm.h"
#include <vector>
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
	void setMapa(const char symbolOrganizmu, const int polozenieX, const int polozenieY);
	int getWymiarMapyX() const;
	int getWymiarMapyY() const;
	vector<vector<Organizm>> organizmy;
	//vector<vector<Organizm>> getOrganizmy() const;
	vector<vector<char>> getMapa() const;
	void dodajOrganizm(Organizm& nowyOrganizm, int polozenieOrganizmuX, int polozenieOrganizmuY);
	void usunOrganizm(Organizm& staryOrganizm, int polozenieOrganizmuX, int polozenieOrganizmuY);
	virtual ~Swiat();
};
