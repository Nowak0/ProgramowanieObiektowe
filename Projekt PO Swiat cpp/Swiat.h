#ifndef SWIAT_H
#define SWIAT_H
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
	//vector<char> organizmy;
public:
	vector<vector<Organizm>> organizmy;
	Swiat(const int x, const int y);
	void wykonajTure();
	void rysujSwiat();
	void setMapa(const char symbolOrganizmu, const int polozenieX, const int polozenieY);
	int getWymiarMapyX() const;
	int getWymiarMapyY() const;
	vector<vector<char>> getMapa() const;
	virtual ~Swiat();
};

#endif