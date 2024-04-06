#ifndef ORGANIZM_H
#define ORGANIZM_H
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

protected:
	//vector<vector<Organizm>> organizmy;
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

public:
	virtual void akcja(Swiat& swiat) = 0;
	virtual void kolizja(Swiat& swiat) = 0;
	virtual void rysowanie() = 0;
	virtual bool czyOdbilAtak(Organizm& atakujacy) = 0;
	void dodajOrganizm(Organizm& nowyOrganizm, int polozenieOrganizmuX, int polozenieOrganizmuY);
	void usunOrganizm(Organizm& staryOrganizm, int polozenieOrganizmuX, int polozenieOrganizmuY);
	virtual ~Organizm();
};

#endif