#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "conio2.h"
#include <vector>
#include "PrzygotowanieGry.h"
#include "Swiat.h"
#include "Antylopa.h"
#include "Barszcz.h"
#include "Czlowiek.h"
#include "Guarana.h"
#include "Lis.h"
#include "Mlecz.h"
#include "Owca.h"
#include "Trawa.h"
#include "WilczeJagody.h"
#include "Wilk.h"
#include "Zolw.h"
#define BRAK_CZLOWIEKA_NA_SWIECIE -1


int wczytajIntZPliku(FILE* plik) {
	string liczba;
	int element = fgetc(plik);
	if (element == ' ') element = fgetc(plik); // pomijamy spacje

	while (element != ' ' && element != EOF && element != '\n') {
		liczba.push_back(element);
		element = fgetc(plik);
	}

	return stoi(liczba); //funkcja zamieniajaca string na int
}


void wczytajPlik(Swiat& swiat, vector<Organizm*>& noweOrganizmy) {
	FILE* plik;
	plik = fopen("zapisGry.txt", "r");

	swiat.setWymiarMapyX(wczytajIntZPliku(plik));
	swiat.setWymiarMapyY(wczytajIntZPliku(plik));
	swiat.uaktualnijGraniceMapy();

	int element;
	element = fgetc(plik);
	while (element != KONIEC_PLIKU) {
		while (element == ' ' || element == '\n') element = fgetc(plik);
		if (element == KONIEC_PLIKU) break;

		Organizm* o = nullptr;
		if (element == 'A') o = new Antylopa(0, 0, 0);
		if (element == 'B') o = new Barszcz(0, 0, 0);
		if (element == 'C') o = new Czlowiek(0, 0, 0);
		if (element == 'G') o = new Guarana(0, 0, 0);
		if (element == 'L') o = new Lis(0, 0, 0);
		if (element == 'M') o = new Mlecz(0, 0, 0);
		if (element == 'O') o = new Owca(0, 0, 0);
		if (element == 'T') o = new Trawa(0, 0, 0);
		if (element == 'J') o = new WilczeJagody(0, 0, 0);
		if (element == 'W') o = new Wilk(0, 0, 0);
		if (element == 'Z') o = new Zolw(0, 0, 0);

		if (o != nullptr) {
			o->setWiek(wczytajIntZPliku(plik));
			o->setPolozenieX(wczytajIntZPliku(plik));
			o->setPolozenieY(wczytajIntZPliku(plik));
			noweOrganizmy.push_back(o);
		}

		element = fgetc(plik);
	}

	fclose(plik);
}


void dodajOrganizmyDoSwiataKonkretnie(Swiat& swiat, vector<Organizm*>& noweOrganizmy) {
	for (Organizm* o : noweOrganizmy) {
		swiat.dodajOrganizm(o, o->getPolozenieX(), o->getPolozenieY());
	}
}


void dodajOrganizmyDoSwiataLosowo(Swiat& swiat, vector<Organizm*>& noweOrganizmy) {
	int wolneMiejsca = swiat.getWymiarMapyX() * swiat.getWymiarMapyY();

	for (Organizm* o : noweOrganizmy) {
		bool dodano = false;

		while (!dodano && wolneMiejsca > 0)
		{
			int polozenieX = rand() % swiat.getWymiarMapyX();
			int polozenieY = rand() % swiat.getWymiarMapyY();
			if (swiat.getOrganizm(polozenieX, polozenieY) == nullptr) {
				o->setPolozenieX(polozenieX);
				o->setPolozenieY(polozenieY);
				o->setWiek(swiat.getLiczbaOrganizmow() + 1);
				swiat.dodajOrganizm(o, o->getPolozenieX(), o->getPolozenieY());
				wolneMiejsca--;
				dodano = true;
			}
		}
	}
}


void dodajOrganizmyRecznie(vector<Organizm*>& noweOrganizmy) {
	noweOrganizmy.push_back(new Czlowiek(0, 0, 0));
	noweOrganizmy.push_back(new Lis(0, 0, 0));
	noweOrganizmy.push_back(new Antylopa(0, 0, 0));
	noweOrganizmy.push_back(new Zolw(0, 0, 0));
	noweOrganizmy.push_back(new Owca(0, 0, 0));
	noweOrganizmy.push_back(new Trawa(0, 0, 0));
	noweOrganizmy.push_back(new Barszcz(0, 0, 0));
	noweOrganizmy.push_back(new Guarana(0, 0, 0));
	noweOrganizmy.push_back(new Guarana(0, 0, 0));
	noweOrganizmy.push_back(new Mlecz(0, 0, 0));
	noweOrganizmy.push_back(new Mlecz(0, 0, 0));
	noweOrganizmy.push_back(new WilczeJagody(0, 0, 0));
	noweOrganizmy.push_back(new WilczeJagody(0, 0, 0));
}


int znajdzIndeksCzlowieka(Swiat& swiat, vector<Organizm*>& noweOrganizmy) {
	if (!swiat.czyCzlowiekZyje()) return BRAK_CZLOWIEKA_NA_SWIECIE;

	int i = 0;
	for (i; i < noweOrganizmy.size(); i++) {
		if (noweOrganizmy[i]->getNazwa() == "Czlowiek") return i;
	}

	return BRAK_CZLOWIEKA_NA_SWIECIE;
}


void przeprowadzGre(int& akcja, Swiat& swiat, PrzygotowanieGry& przygotowanieGry, vector<Organizm*>& noweOrganizmy) {
	if (noweOrganizmy.size() == 0) {
		dodajOrganizmyRecznie(noweOrganizmy);
		dodajOrganizmyDoSwiataLosowo(swiat, noweOrganizmy);
	}
	else dodajOrganizmyDoSwiataKonkretnie(swiat, noweOrganizmy);

	przygotowanieGry.przygotujEkran();
	swiat.rysujSwiat();

	while (akcja != 'q') { // q czyli koniec gry
		int indeksCzlowieka = znajdzIndeksCzlowieka(swiat, noweOrganizmy);
		akcja = getch();

		if (akcja == 0) { // uzytkownik mozliwe ze chce wykonac ruch 
			akcja = getch();
			if(indeksCzlowieka != BRAK_CZLOWIEKA_NA_SWIECIE) noweOrganizmy[indeksCzlowieka]->setRuchCzlowieka(akcja);
		}

		if (akcja == 'k') { // k czyli aktywacja niesmiertelnosci
			if (indeksCzlowieka != BRAK_CZLOWIEKA_NA_SWIECIE && noweOrganizmy[indeksCzlowieka]->aktywujNiesmiertelnoscCzlowieka()) swiat.wypiszWiadomosc("aktywowano niesmiertelnosc");
			else swiat.wypiszWiadomosc("nie mozna aktywowac niesmiertelnosci");
		}

		if (akcja == 's') { // s czyli zapisywanie gry
			swiat.zapiszStanGry();
		}

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
	srand(time(NULL));
	Swiat* swiat = new Swiat(20, 20);
	PrzygotowanieGry* przygotowanieGry = new PrzygotowanieGry();
	przygotowanieGry->przygotujEkran();
	przygotowanieGry->wyswietlEkranPoczatkowy();
	vector<Organizm*> noweOrganizmy;
	int akcja = getch();

	while (akcja != 'q') {
		if (akcja == 'p') przeprowadzGre(akcja, *swiat, *przygotowanieGry, noweOrganizmy);
		else if (akcja == 'l') {
			wczytajPlik(*swiat, noweOrganizmy);
			przeprowadzGre(akcja, *swiat, *przygotowanieGry, noweOrganizmy);
		}
		else akcja = getch();
	}
	
	delete przygotowanieGry;
	delete swiat;
	return 0;
}