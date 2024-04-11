#include <iostream>
#include "conio2.h"
#include "PrzygotowanieGry.h"
#include "Swiat.h"
#include "Antylopa.h"
#include "Lis.h"
#define PODSTAWOWY_KOLOR_TEKSTU 7
#define PODSTAWOWY_KOLOR_TLA 0


void przeprowadzGre(char& akcja, Swiat* swiat, PrzygotowanieGry* przygotowanieGry) {
	Organizm* lis = new Lis(0, 0, 0);
	Organizm* lis2 = new Lis(18, 18, 1);
	Organizm* antylopa = new Antylopa(4, 4, 2);
	przygotowanieGry->przygotujEkran();
	swiat->dodajOrganizm(lis2, lis2->getPolozenieX(), lis2->getPolozenieY());
	swiat->dodajOrganizm(lis, lis->getPolozenieX(), lis->getPolozenieY());
	swiat->dodajOrganizm(antylopa, antylopa->getPolozenieX(), antylopa->getPolozenieY());
	swiat->rysujSwiat();

	while(akcja!='q') {
		cin >> akcja;
		if (akcja == 'n') // n czyli nowa tura
		{
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