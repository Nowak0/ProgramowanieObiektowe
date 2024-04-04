#include "Swiat.h"


Swiat::Swiat(const int x, const int y) : mapa(y, vector<char>(x)) {
	this->wymiarMapyX = x;
	this->wymiarMapyY = y;
}


void Swiat::wykonajTure() {}


void Swiat::rysujSwiat() {
	for (int y = 0; y < wymiarMapyY; y++)
	{
		for (int x = 0; x < wymiarMapyX; x++)
		{
			cout << mapa[y][x] << " ";
		}
		cout << endl;
	}
}


void Swiat::setMapa(const char symbolOrganizmu, const int polozenieX, const int polozenieY) {
	this->mapa[polozenieY][polozenieX] = symbolOrganizmu;
}


Swiat::~Swiat() {}