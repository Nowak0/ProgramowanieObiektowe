#pragma once
#include <iostream>
#include <time.h>
#include "Swiat.h"
using namespace std;


class Swiat;


class Organizm {
private:
	int sila;
	int inicjatywa;
	int wiek;
	int polozenieX;
	int polozenieY;

public:
	virtual void akcja(Swiat& swiat) = 0;
	virtual void kolizja(Swiat& swiat) = 0;
	//virtual void rysowanie() = 0;
	virtual bool czyOdbilAtak(Organizm& atakujacy) = 0;
	virtual char getSymbol() = 0;
	int getSila() const;
	int getInicjatywa() const;
	int getWiek() const;
	int getPolozenieX() const;
	int getPolozenieY() const;
	void setSila(int sila);
	void setInicjatywa(int inicjatywa);
	void setWiek(int wiek);
	void setPolozenieX(int polozenieX);
	void setPolozenieY(int polozenieY);
	virtual ~Organizm();
};