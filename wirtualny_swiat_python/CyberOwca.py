import math
from Zwierze import Zwierze


class CyberOwca(Zwierze):
    def __init__(self, x, y, wiek):
        super().__init__(x, y, wiek)
        self.setNazwa("CyberOwca")
        self.setSymbol('CO')
        self.setSila(11)
        self.setInicjatywa(4)
        self.setNiesmiertelnosc(False)

    def stworzNowySklonowanyObiekt(self):
        return CyberOwca(0, 0, 0)

    def akcja(self, swiat):
        koordynatX, koordynatY, odleglosc = self.znajdzNajblizszyBarszcz(swiat)

        if odleglosc == swiat.getWymiarMapyX() * swiat.getWymiarMapyY():
            super().akcja(swiat)
            return

        self.zmienPozycjeOrganizmu(swiat, koordynatX, koordynatY)

    def znajdzNajblizszyBarszcz(self, swiat):
        koordynatX = -1
        koordynatY = -1
        odleglosc = swiat.getWymiarMapyX() * swiat.getWymiarMapyY()

        for i in range(swiat.getLiczbaOrganizmow()):
            x, y = swiat.getPolozenieOrganizmu(i)
            if swiat.getOrganizm(x, y) is None or swiat.getOrganizm(x, y).getSymbol() != 'B':
                continue
            tmpOdleglosc = int(math.sqrt((x - self.polozenieX) ** 2 + (x - self.polozenieY) ** 2))
            if tmpOdleglosc < odleglosc:
                koordynatX = x
                koordynatY = y
                odleglosc = tmpOdleglosc
        return koordynatX, koordynatY, odleglosc

    def zmienPozycjeOrganizmu(self, swiat, x, y):
        nowyX = self.polozenieX
        nowyY = self.polozenieY
        if self.polozenieX > x:
            nowyX -= 1
        elif self.polozenieX < x:
            nowyX += 1

        if self.polozenieY > y:
            nowyY -= 1
        elif self.polozenieY < y:
            nowyY += 1

        if swiat.getOrganizm(nowyX, nowyY) is None:
            swiat.usunOrganizm(self, self.polozenieX, self.polozenieY)
            self.setPolozenieX(nowyX)
            self.setPolozenieY(nowyY)
            swiat.dodajOrganizm(self, nowyX, nowyY)

        elif swiat.getOrganizm(nowyX, nowyY).getSymbol() == self.symbol:
            noweZwierze = self.stworzNowySklonowanyObiekt()
            super().kolizja(swiat, noweZwierze)

        else:
            swiat.getOrganizm(nowyX, nowyY).kolizja(swiat, self)

    def rysowanie(self):
        return "dodgerblue"
