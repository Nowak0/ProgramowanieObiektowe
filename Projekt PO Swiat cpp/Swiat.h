#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Organizm.h"
#include <string>
#include <vector>
#define POCZATKOWA_POZYCJA_Y 3
#define POCZATKOWA_POZYCJA_X 20
#define NIEZYWY_ORGANIZM -1
#define PODSTAWOWY_KOLOR_TEKSTU 7
#define PODSTAWOWY_KOLOR_TLA 0
#define KONIEC_PLIKU 'E'
using namespace std;

class Organizm;

class Swiat {
private:
	int wymiarMapyX;
	int wymiarMapyY;
	int liczbaWiadomosci;
	bool czlowiekZyje;
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
	void setWymiarMapyX(const int wymiar);
	void setWymiarMapyY(const int wymiar);
	void setLiczbaWiadomosci();
	void dodajOrganizm(Organizm* nowyOrganizm, int polozenieOrganizmuX, int polozenieOrganizmuY);
	void usunOrganizm(Organizm* staryOrganizm, int polozenieOrganizmuX, int polozenieOrganizmuY);
	void wypiszWiadomosc(string wiadomosc);
	void sprawdzNiesmiertelnosc(Organizm& organizm);
	void zapiszStanGry();
	static void wstawIntDoPliku(int liczba, FILE* plik);
	void uaktualnijGraniceMapy();
	bool czyCzlowiekZyje();
	~Swiat();
};
