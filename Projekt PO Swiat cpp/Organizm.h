#pragma once
#include <iostream>
#include <time.h>
#include "conio2.h"
#include "Swiat.h"
#define NIEZYWY_ORGANIZM -1
#define RUCH_PRAWO 0x4d
#define RUCH_LEWO 0x4b
#define RUCH_GORA 0x48
#define RUCH_DOL 0x50
#define RUCH_NIEAKTYWNY 1
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
	bool aktywnaNiesmiertelnosc;

public:
	virtual void akcja(Swiat& swiat) = 0;
	virtual void kolizja(Swiat& swiat, Organizm& atakujacy) = 0;
	virtual char rysowanie() = 0;
	virtual Organizm* stworzNowySklonowanyObiekt() = 0;
	virtual bool czyOdbilAtak(Organizm& atakujacy, Organizm& atakowany);
	virtual void kopiujObiekt(const Organizm& innyOrganizm);
	virtual void setRuchCzlowieka(const int ruch);
	virtual bool aktywujNiesmiertelnoscCzlowieka();
	virtual void sprawdzLiczenieTur();
	string getNazwa() const;
	char getSymbol() const;
	int getSila() const;
	int getInicjatywa() const;
	int getWiek() const;
	int getPolozenieX() const;
	int getPolozenieY() const;
	bool czyNiesmiertelny() const;
	void setNazwa(string nazwa);
	void setSymbol(char symbol);
	void setSila(int sila);
	void setInicjatywa(int inicjatywa);
	void setWiek(int wiek);
	void setPolozenieX(int polozenieX);
	void setPolozenieY(int polozenieY);
	void setNiesmiertelnosc(bool wyrazenie);
	virtual ~Organizm();
};