#include <iostream>
#include <time.h>
#include "Swiat.h"
using namespace std;

class Organizm {
private:
	

protected:
	int sila;
	int inicjatywa;
	int polozenieX;
	int polozenieY;
	int getSila() const;
	int getInicjatywa() const;
	int getPolozenieX() const;
	int getPolozenieY() const;
	void setSila(int sila);
	void setInicjatywa(int inicjatywa);
	void setPolozenieX(int polozenieX);
	void setPolozenieY(int polozenieY);

public:
	Organizm();
	virtual void akcja(const int wymiarMapyX, const int wymiarMapyY, Swiat& swiat) = 0;
	virtual void kolizja(Swiat& swiat) = 0;
	virtual void rysowanie() = 0;
	virtual bool czySieObronil(Organizm& atakujacy) = 0;
	virtual ~Organizm();
};