#include "PrzygotowanieGry.h"
#include <string>

PrzygotowanieGry::PrzygotowanieGry() {
	settitle("Jakub Nowak 197860");
}


void PrzygotowanieGry::ustawKolory() {
	textcolor(PODSTAWOWY_KOLOR_TEKSTU); // ustaw podstawowy kolor tekstu
	textbackground(PODSTAWOWY_KOLOR_TLA); // ustaw podstawowy kolor tla
}


void PrzygotowanieGry::przygotujEkran() {
	_setcursortype(_NOCURSOR); // schowaj kursor
	ustawKolory(); // ustaw glowne kolory do gry
	clrscr(); // wyczysc ekran
}


void PrzygotowanieGry::wyswietlEkranPoczatkowy() {
	int pozycjaWyswietlaniaY = POCZATKOWA_POZYCJA_Y;
	gotoxy(POCZATKOWA_POZYCJA_X, pozycjaWyswietlaniaY);
	for (int y = 0; y < ROZMIAR_MENU_Y; y++)
	{
		for (int x = 0; x < ROZMIAR_MENU_X; x++)
		{
			putch(ekranPoczatkowy[y][x]);
		}
		pozycjaWyswietlaniaY += 1;
		gotoxy(POCZATKOWA_POZYCJA_X, pozycjaWyswietlaniaY);
	}

}


PrzygotowanieGry::~PrzygotowanieGry() {}