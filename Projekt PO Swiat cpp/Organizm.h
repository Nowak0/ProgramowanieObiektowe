#pragma once
#include <iostream>
#include <time.h>
#include "conio2.h"
#include "Swiat.h"
#define NIEZYWY_ORGANIZM -1
using namespace std;


class Swiat;


class Organizm {
private:
	string nazwa;
	char symbol;
	int sila;
	int inicjatywa;
	int wiek;
	int polozenieX;
	int polozenieY;

public:
	virtual void akcja(Swiat& swiat) = 0;
	virtual void kolizja(Swiat& swiat, Organizm& atakujacy) = 0;
	virtual char rysowanie() = 0;
	virtual Organizm* stworzNowySklonowanyObiekt() = 0;
	virtual bool czyOdbilAtak(Organizm& atakujacy, Organizm& atakowany);
	virtual void kopiujObiekt(const Organizm& innyOrganizm);
	string getNazwa() const;
	char getSymbol() const;
	int getSila() const;
	int getInicjatywa() const;
	int getWiek() const;
	int getPolozenieX() const;
	int getPolozenieY() const;
	void setNazwa(string nazwa);
	void setSymbol(char symbol);
	void setSila(int sila);
	void setInicjatywa(int inicjatywa);
	void setWiek(int wiek);
	void setPolozenieX(int polozenieX);
	void setPolozenieY(int polozenieY);
	virtual ~Organizm();
};