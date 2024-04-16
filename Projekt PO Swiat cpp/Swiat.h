#pragma once
#include <iostream>
#include "Organizm.h"
#include <string>
#include <vector>
#define POCZATKOWA_POZYCJA_Y 3
#define POCZATKOWA_POZYCJA_X 20
#define NIEZYWY_ORGANIZM -1
#define PODSTAWOWY_KOLOR_TEKSTU 7
#define PODSTAWOWY_KOLOR_TLA 0
using namespace std;

class Organizm;

class Swiat {
private:
	int wymiarMapyX;
	int wymiarMapyY;
	int liczbaWiadomosci;
	vector<Organizm*> posortowaneOrganizmy;
	vector<Organizm*> nieZyjaceOrganizmy;
	vector<vector<Organizm*>> organizmy;
	void usunOrganizmZPosortowanych(Organizm* organizm);
	void usunNullPTR(const int i);
	void dodajOrganizmDoPosortowanych(Organizm* organizm);
public:
	Swiat(const int x, const int y);
	void wykonajTure();
	void rysujSwiat();
	int getWymiarMapyX() const;
	int getWymiarMapyY() const;
	int getLiczbaWiadomsci() const;
	int getLiczbaOrganizmow() const;
	Organizm* getOrganizm(const int polozenieX, const int polozenieY);
	void setLiczbaWiadomosci();
	void dodajOrganizm(Organizm* nowyOrganizm, int polozenieOrganizmuX, int polozenieOrganizmuY);
	void usunOrganizm(Organizm* staryOrganizm, int polozenieOrganizmuX, int polozenieOrganizmuY);
	void wypiszWiadomosc(string wiadomosc);
	virtual ~Swiat();
};
