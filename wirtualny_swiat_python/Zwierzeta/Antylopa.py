import random
from abc import ABC

from Organizm import Organizm


class Antylopa(Organizm):
    def __init__(self, x, y, wiek):
        super().__init__(x, y, wiek)
        super().setNazwa("Antylopa")
        super().setSymbol('A')
        super().setSila(4)
        super().setInicjatywa(4)
        super().setNiesmiertelnosc(False)

    def stworzNowySklonowanyObiekt(self):
        return Antylopa(0, 0, 0)

    def akcja(self, swiat):
        wymiarMapyX = swiat.getWymiarMapyX()
        wymiarMapyY = swiat.getWymiarMapyY()
        mozliweMiejscaX = []
        mozliweMiejscaY = []

        for y in range(self.polozenieY - 2, self.polozenieY + 3):
            if y < 0 or y >= wymiarMapyY:
                continue
            for x in range(self.polozenieX - 2, self.polozenieX + 3):
                if x < 0 or x >= wymiarMapyX:
                    continue
                if x == self.polozenieX and y == self.polozenieY:
                    continue
                mozliweMiejscaX.append(x)
                mozliweMiejscaY.append(y)

        if len(mozliweMiejscaX) == 0:
            return

        ruch = random.randint(0, len(mozliweMiejscaX))
        nowyX = mozliweMiejscaX[ruch]
        nowyY = mozliweMiejscaY[ruch]

        if swiat.getOrganizm(nowyX, nowyY) is None:
            super().setPolozenieX(nowyX)
            super().setPolozenieY(nowyY)
            swiat.dodajOrganizm(swiat.getOrganizm(self.polozenieX, self.polozenieY), nowyX, nowyY)
            swiat.usunOrganizm(swiat.getOrganizm(self.polozenieX, self.polozenieY), self.polozenieX, self.polozenieY)

        elif swiat.getOrganizm(nowyX, nowyY).getSymbol() == swiat.getOrganizm(self.polozenieX, self.polozenieY).getSymbol():
            noweZwierze = self.stworzNowySklonowanyObiekt()
            super().kolizja(swiat, noweZwierze)

        else:
            swiat.getOrganizm(nowyX, nowyY).kolizja(swiat, self)

    def kolizja(self, swiat, atakujacy):
        if isinstance(atakujacy, Antylopa):
            super().kolizja(swiat, atakujacy)
            return

        unik = random.randint(0, 2)
        if unik == 1:
            if self.unikAntylopy(swiat, atakujacy):
                return

        czyPrzetrwal = super().czyOdbilAtak(atakujacy, self)
        if czyPrzetrwal:
            swiat.wypiszWiadomosc("Antylopa zabija "
                                  + atakujacy.getNazwa()
                                  + super().wypiszPolozenie(self.polozenieX, self.polozenieY))
            atakujacy.setCzyZyje(False)
            swiat.usunOrganizm(atakujacy, atakujacy.getPolozenieX(), atakujacy.getPolozenieY())
        else:
            super().setCzyZyje(False)
            swiat.usunOrganizm(self, self.polozenieX, self.polozenieY)
            atakujacy.setPolozenieX(self.polozenieX)
            atakujacy.setPolozenieY(self.polozenieY)
            swiat.dodajOrganizm(atakujacy, self.polozenieX, self.polozenieY)
            swiat.usunOrganizm(atakujacy, atakujacy.getPolozenieX(), atakujacy.getPolozenieY())
            swiat.wypiszWiadomosc(atakujacy.getNazwa() + " zabija Antylopa "
                                  + super().wypiszPolozenie(self.polozenieX, self.polozenieY))

    def unikAntylopy(self, swiat, atakujacy):
        polozenieXAtak = atakujacy.getPolozenieX()
        polozenieYAtak = atakujacy.getPolozenieY()
        for y in range(self.polozenieY-1, self.polozenieY+2):
            if y < 0 or y >= swiat.getWymiarMapyY():
                continue
            for x in range(self.polozenieX-1, self.polozenieX+2):
                    if x < 0 or x >= swiat.getWymiarMapyX():
                        continue
                    if swiat.getOrganizm(x, y) is None:
                        swiat.usunOrganizm(self, self.polozenieX, self.polozenieY)
                        super().setPolozenieX(x)
                        super().setPolozenieY(y)
                        atakujacy.setPolozenieX(self.polozenieX)
                        atakujacy.setPolozenieY(self.polozenieY)
                        swiat.dodajOrganizm(self, x, y);
                        swiat.dodajOrganizm(atakujacy, self.polozenieX, self.polozenieY)
                        swiat.usunOrganizm(atakujacy, polozenieXAtak, polozenieYAtak);
                        swiat.wypiszWiadomosc("Antylopa unika ataku " + atakujacy.getNazwa()
                                              + super().wypiszPolozenie(self.polozenieX, self.polozenieY))
                        return True
        return False
