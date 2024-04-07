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
	swiat->rysujSwiat();
	Organizm* lis = new Lis(2, 2, 1);
	Organizm* antylopa = new Antylopa(1, 1, 2);
	if (action == 'p')
	{
		przygotowanieGry->przygotujEkran();
		swiat->dodajOrganizm(lis, lis->getPolozenieX(), lis->getPolozenieY());
		swiat->dodajOrganizm(antylopa, antylopa->getPolozenieX(), antylopa ->getPolozenieY());
		swiat->wykonajTure();
		swiat->rysujSwiat();
	}
	
	delete przygotowanieGry;
	delete swiat;
	return 0;
}