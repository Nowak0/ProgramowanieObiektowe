#include <iostream>
#include "conio2.h"
#include "PrzygotowanieGry.h"
#define PODSTAWOWY_KOLOR_TEKSTU 7
#define PODSTAWOWY_KOLOR_TLA 0


int main() {
#ifndef __cplusplus
	Conio2_Init();
#endif
	srand(time(NULL));
	PrzygotowanieGry startGry;
	startGry.przygotujEkran();
	startGry.wyswietlEkranPoczatkowy();
	return 0;
}