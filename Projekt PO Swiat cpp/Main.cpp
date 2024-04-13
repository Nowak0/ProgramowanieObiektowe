#include <iostream>
#include "conio2.h"
#include "PrzygotowanieGry.h"
#include "Swiat.h"
#include "Antylopa.h"
#include "Lis.h"
#include "Owca.h"
#include "Wilk.h"
#include "Zolw.h"
#define PODSTAWOWY_KOLOR_TEKSTU 7
#define PODSTAWOWY_KOLOR_TLA 0


void przeprowadzGre(char& akcja, Swiat* swiat, PrzygotowanieGry* przygotowanieGry) {
	Organizm* lis = new Lis(0, 0, 0);
	Organizm* antylopa = new Antylopa(2, 2, 1);
	Organizm* zolw = new Zolw(2, 11, 2);
	Organizm* owca = new Owca(2, 10, 3);
	Organizm* wilk = new Wilk(2, 9, 4);
	przygotowanieGry->przygotujEkran();
	swiat->dodajOrganizm(lis, lis->getPolozenieX(), lis->getPolozenieY());
	swiat->dodajOrganizm(antylopa, antylopa->getPolozenieX(), antylopa->getPolozenieY());
	swiat->dodajOrganizm(zolw, zolw->getPolozenieX(), zolw->getPolozenieY());
	swiat->dodajOrganizm(owca, owca->getPolozenieX(), owca->getPolozenieY());
	swiat->dodajOrganizm(wilk, wilk->getPolozenieX(), wilk->getPolozenieY());
	swiat->rysujSwiat();

	while (akcja != 'q') { // q czyli koniec gry
		cin >> akcja;
		if (akcja == 'n') // n czyli nowa tura
		{
			przygotowanieGry->przygotujEkran();
			swiat->wykonajTure();
			swiat->rysujSwiat();
		}
	}
}


int main() {
#ifndef __cplusplus
	Conio2_Init();
#endif
	char akcja;
	srand(time(NULL));
	PrzygotowanieGry* przygotowanieGry = new PrzygotowanieGry();
	przygotowanieGry->przygotujEkran();
	przygotowanieGry->wyswietlEkranPoczatkowy();
	Swiat* swiat = new Swiat(20, 20);
	cin >> akcja;

	while (akcja != 'q') {
		if (akcja == 'p') przeprowadzGre(akcja, swiat, przygotowanieGry);
		else cin >> akcja;
	}
	
	delete przygotowanieGry;
	delete swiat;
	return 0;
}