#include "Organizm.h"


Organizm::Organizm(Swiat& danySwiat) : swiat(danySwiat) {
	this->sila = 0;
	this->inicjatywa = 0;
	this->polozenieX = 0;
	this->polozenieY = 0;
}


int Organizm::getSila() const {
	return sila;
}


int Organizm::getInicjatywa() const {
	return inicjatywa;
}


int Organizm::getPolozenieX() const {
	return polozenieX;
}


int Organizm::getPolozenieY() const {
	return polozenieY;
}


void Organizm::setSila(int sila) {
	this->sila = sila;
}


void Organizm::setInicjatywa(int inicjatywa) {
	this->inicjatywa = inicjatywa;
}


void Organizm::setPolozenieX(int polozenieX) {
	this->polozenieX = polozenieX;
}


void Organizm::setPolozenieY(int polozenieY) {
	this->polozenieY = polozenieY;
}


void Organizm::dodajNowyOrganizm(char symbolOrganizmu) {
	swiat.setMapa(symbolOrganizmu, polozenieX, polozenieY);
}


Organizm::~Organizm() {}