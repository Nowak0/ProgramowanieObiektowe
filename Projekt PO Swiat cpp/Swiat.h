#ifndef SWIAT_H
#define SWIAT_H
#include <iostream>
#include <vector>
using namespace std;


class Swiat {
private:
	int wymiarMapyX;
	int wymiarMapyY;
	vector<vector<char>> mapa;
	//vector<char> organizmy;
public:
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