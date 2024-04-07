#include "Organizm.h"


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


//void Organizm::dodajOrganizm(Organizm& organizm, int polozenieOrganizmuX, int polozenieOrganizmuY) {
//	//organizmy[polozenieOrganizmuY][polozenieOrganizmuX] = organizm;
//}
//
//
//void Organizm::usunOrganizm(Organizm& staryOrganizm, int polozenieOrganizmuX, int polozenieOrganizmuY) {
//	//organizmy[polozenieOrganizmuY].erase(organizmy[polozenieOrganizmuY].begin() + polozenieOrganizmuX);
//}


Organizm::~Organizm() {}