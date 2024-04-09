#include "Organizm.h"


bool Organizm::czyOdbilAtak(Organizm& atakujacy, Organizm& atakowany) {
	int silaAtakowanego = atakowany.getSila();
	int silaAtakujacego = atakujacy.getSila();

	if (silaAtakujacego >= silaAtakowanego) return false;
	else return true;
}

string Organizm::getNazwa() const {
	return nazwa;
}


int Organizm::getSila() const {
	return sila;
}


int Organizm::getInicjatywa() const {
	return inicjatywa;
}


int Organizm::getWiek() const {
	return wiek;
}


int Organizm::getPolozenieX() const {
	return polozenieX;
}


int Organizm::getPolozenieY() const {
	return polozenieY;
}


void Organizm::setNazwa(string nazwa) {
	this->nazwa = nazwa;
}


void Organizm::setSila(int sila) {
	this->sila = sila;
}


void Organizm::setInicjatywa(int inicjatywa) {
	this->inicjatywa = inicjatywa;
}


void Organizm::setWiek(int wiek) {
	this->wiek = wiek;
}


void Organizm::setPolozenieX(int polozenieX) {
	this->polozenieX = polozenieX;
}


void Organizm::setPolozenieY(int polozenieY) {
	this->polozenieY = polozenieY;
}


Organizm::~Organizm() {}