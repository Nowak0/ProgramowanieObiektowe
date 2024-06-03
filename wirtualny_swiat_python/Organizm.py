from abc import ABC, abstractmethod
from Swiat import Swiat


class Organizm(ABC):
    RUCH_NIEAKTYWNY = -1
    RUCH_PRAWO = 1
    RUCH_LEWO = 2
    RUCH_GORA = 3
    RUCH_DOL = 4

    def __init__(self, x, y, wiek):
        self.nazwa = ""
        self.symbol = ""
        self.sila = 0
        self.inicjatywa = 0
        self.wiek = wiek
        self.polozenieX = x
        self.polozenieY = y
        self.aktywnaNiesmiertelnosc = False
        self.czyZyje = False

    @staticmethod
    def wypiszPolozenie(x, y):
        return " ({},{})".format(x, y)

    @staticmethod
    def czyOdbilAtak(atakujacy, atakowany):
        silaAtakowanego = atakowany.getSila()
        silaAtakujacego = atakujacy.getSila
        return silaAtakujacego < silaAtakowanego

    @abstractmethod
    def akcja(self, swiat):
        pass

    @abstractmethod
    def kolizja(self, swiat, atakujacy):
        pass

    @abstractmethod
    def rysowanie(self):
        pass

    @abstractmethod
    def stworzNowySklonowowanyObiekt(self):
        pass

    def kopiujObiekt(self, innyOrganizm):
        self.nazwa = innyOrganizm.getNazwa()
        self.symbol = innyOrganizm.getSymbol()
        self.sila = innyOrganizm.getSila()
        self.inicjatywa = innyOrganizm.getInicjatywa()
        self.wiek = innyOrganizm.getWiek()
        self.polozenieX = innyOrganizm.getPolozenieX()
        self.polozenieY = innyOrganizm.getPolozenieY()

    def getNazwa(self):
        return self.nazwa

    def getSymbol(self):
        return self.symbol

    def getSila(self):
        return self.sila

    def getInicjatywa(self):
        return self.inicjatywa

    def getWiek(self):
        return self.wiek

    def getPolozenieX(self):
        return self.polozenieX

    def getPolozenieY(self):
        return self.polozenieY

    def getCzyZyje(self):
        return self.czyZyje

    def czyNiesmiertelny(self):
        return self.aktywnaNiesmiertelnosc

    def setNazwa(self, nazwa):
        self.nazwa = nazwa

    def setSymbol(self, symbol):
        self.symbol = symbol

    def setSila(self, sila):
        self.sila = sila

    def setInicjatywa(self, inicjatywa):
        self.inicjatywa = inicjatywa

    def setWiek(self, wiek):
        self.wiek = wiek

    def setPolozenieX(self, x):
        self.polozenieX = x

    def setPolozenieY(self, y):
        self.polozenieY = y

    def setCzyZyje(self, wyrazenie):
        self.czyZyje = wyrazenie

    def setNiesmiertelnosc(self, wyrazenie):
        self.aktywnaNiesmiertelnosc = wyrazenie
