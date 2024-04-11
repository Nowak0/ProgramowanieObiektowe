#include <iostream>
#include "conio2.h"
#define PODSTAWOWY_KOLOR_TEKSTU 7
#define PODSTAWOWY_KOLOR_TLA 0
#define ROZMIAR_MENU_Y 8
#define ROZMIAR_MENU_X 28
#define POCZATKOWA_POZYCJA_Y 3
#define POCZATKOWA_POZYCJA_X 20
using namespace std;


class PrzygotowanieGry {
private:
	const char ekranPoczatkowy[ROZMIAR_MENU_Y][ROZMIAR_MENU_X] = {
		"       S  W  I  A  T       ",
		"<<=======================>>",
		"||                       ||",
		"||    Start   Gry - P    ||",
		"||    Zaladuj Gre - L    ||",
		"||    Zakoncz Gre - Q    ||",
		"||                       ||",
		"<<=======================>>"
	};

public:
	PrzygotowanieGry();
	void przygotujEkran();
	void ustawKolory();
	void wyswietlEkranPoczatkowy();
	~PrzygotowanieGry();
};