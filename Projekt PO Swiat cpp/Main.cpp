#include <iostream>
#include "conio2.h"
#include <vector>
#include "PrzygotowanieGry.h"
#include "Swiat.h"
#include "Antylopa.h"
#include "Barszcz.h"
#include "Guarana.h"
#include "Lis.h"
#include "Mlecz.h"
#include "Owca.h"
#include "Trawa.h"
#include "WilczeJagody.h"
#include "Wilk.h"
#include "Zolw.h"
#define PODSTAWOWY_KOLOR_TEKSTU 7
#define PODSTAWOWY_KOLOR_TLA 0
#define MAKSYMALNA_LICZBA_MOZLIWOSCI_ROZPRZESTRZENIENIA 8


void dodajOrganizmyDoSwiata(vector<Organizm*>& noweOrganizmy, Swiat& swiat) {
	for (Organizm* o : noweOrganizmy) {
		for (int i = 0; i < swiat.getWymiarMapyX() * swiat.getWymiarMapyY() - swiat.getLiczbaOrganizmow(); i++) {
			int polozenieX = rand() % swiat.getWymiarMapyX();
			int polozenieY = rand() % swiat.getWymiarMapyY();
			if (swiat.organizmy[polozenieY][polozenieX] == nullptr) {
				o->setPolozenieX(polozenieX);
				o->setPolozenieY(polozenieY);
				o->setWiek(swiat.getLiczbaOrganizmow() + 1);
				swiat.dodajOrganizm(o, o->getPolozenieX(), o->getPolozenieY());
				break;
			}
		}
	}
}


void przeprowadzGre(char& akcja, Swiat& swiat, PrzygotowanieGry& przygotowanieGry) {
	vector<Organizm*> noweOrganizmy;
	noweOrganizmy.push_back(new Lis(0, 0, 0));
	noweOrganizmy.push_back(new Antylopa(0, 0, 0));
	noweOrganizmy.push_back(new Zolw(0, 0, 0));
	noweOrganizmy.push_back(new Owca(0, 0, 0));
	noweOrganizmy.push_back(new Wilk(0, 0, 0));
	noweOrganizmy.push_back(new Trawa(0, 0, 0));
	noweOrganizmy.push_back(new Barszcz(0, 0, 0));
	noweOrganizmy.push_back(new Guarana(0, 0, 0));
	noweOrganizmy.push_back(new Mlecz(0, 0, 0));
	noweOrganizmy.push_back(new WilczeJagody(0, 0, 0));
	dodajOrganizmyDoSwiata(noweOrganizmy, swiat);

	przygotowanieGry.przygotujEkran();
	swiat.rysujSwiat();

	while (akcja != 'q') { // q czyli koniec gry
		cin >> akcja;
		if (akcja == 'n') // n czyli nowa tura
		{
			przygotowanieGry.przygotujEkran();
			swiat.wykonajTure();
			swiat.rysujSwiat();
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
		if (akcja == 'p') przeprowadzGre(akcja, *swiat, *przygotowanieGry);
		else cin >> akcja;
	}
	
	delete przygotowanieGry;
	delete swiat;
	return 0;
}