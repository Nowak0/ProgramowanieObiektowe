#include <iostream>
#include "conio2.h"
#include "PrzygotowanieGry.h"
#include "Swiat.h"
#include "Antylopa.h"
#include "Lis.h"
#define PODSTAWOWY_KOLOR_TEKSTU 7
#define PODSTAWOWY_KOLOR_TLA 0


int main() {
#ifndef __cplusplus
	Conio2_Init();
#endif
	char action;
	srand(time(NULL));
	PrzygotowanieGry* przygotowanieGry = new PrzygotowanieGry();
	przygotowanieGry->przygotujEkran();
	przygotowanieGry->wyswietlEkranPoczatkowy();
	cin >> action;
	Swiat* swiat = new Swiat(20, 20);
	Organizm* lis = new Lis(1, 1, 1);
	Organizm* lis2 = new Lis(2, 2, 1);
	//Organizm* antylopa = new Antylopa(2, 2, 2);
	if (action == 'p')
	{
		przygotowanieGry->przygotujEkran();
		swiat->dodajOrganizm(lis, lis->getPolozenieX(), lis->getPolozenieY());
		swiat->dodajOrganizm(lis2, lis2->getPolozenieX(), lis2->getPolozenieY());
		lis->akcja(*swiat);
		//swiat->wykonajTure();
		//lis2->akcja(*swiat);
		swiat->rysujSwiat();
	}
	
	delete przygotowanieGry;
	delete swiat;
	return 0;
}