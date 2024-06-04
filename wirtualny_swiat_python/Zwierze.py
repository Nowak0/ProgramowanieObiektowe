from abc import ABC
from Organizm import Organizm
import random


class Zwierze(Organizm, ABC):
    def akcja(self, swiat):
        wymiarMapyX = swiat.getWymiarMapyX()
        wymiarMapyY = swiat.getWymiarMapyY()
        polozenieX = self.getPolozenieX()
        polozenieY = self.getPolozenieY()
        mozliweMiejscaX = []
        mozliweMiejscaY = []

        for y in range(polozenieY - 1, polozenieY + 2):
            if y < 0 or y >= wymiarMapyY:
                continue
            for x in range(polozenieX - 1, polozenieX + 2):
                if x < 0 or x >= wymiarMapyX:
                    continue
                if x == polozenieX and y == polozenieY:
                    continue
                mozliweMiejscaX.append(x)
                mozliweMiejscaY.append(y)

        if len(mozliweMiejscaX) == 0:
            return

        ruch = random.randint(0, len(mozliweMiejscaX) - 1)
        nowyX = mozliweMiejscaX[ruch]
        nowyY = mozliweMiejscaY[ruch]

        if swiat.getOrganizm(nowyX, nowyY) is None:
            self.setPolozenieX(nowyX)
            self.setPolozenieY(nowyY)
            swiat.dodajOrganizm(swiat.getOrganizm(polozenieX, polozenieY), nowyX, nowyY)
            swiat.usunOrganizm(swiat.getOrganizm(polozenieX, polozenieY), polozenieX, polozenieY)

        elif swiat.getOrganizm(nowyX, nowyY).getSymbol() == self.symbol:
            noweZwierze = self.stworzNowySklonowanyObiekt()
            self.kolizja(swiat, noweZwierze)

        else:
            swiat.getOrganizm(nowyX, nowyY).kolizja(swiat, self)

    def kolizja(self, swiat, atakujacy):
        polozenieX = self.getPolozenieX()
        polozenieY = self.getPolozenieY()

        for y in range(polozenieY - 1, polozenieY + 2):
            if y < 0 or y >= swiat.getWymiarMapyY():
                continue
            for x in range(polozenieX - 1, polozenieX + 2):
                if x < 0 or x >= swiat.getWymiarMapyX():
                    continue
                if swiat.getOrganizm(x, y) is None:
                    atakujacy.setPolozenieX(x)
                    atakujacy.setPolozenieY(y)
                    atakujacy.setWiek(swiat.getLiczbaOrganizmow() + 1)
                    swiat.dodajOrganizm(atakujacy, x, y)
                    swiat.wypiszWiadomosc("Nowe zwierze " + atakujacy.getNazwa() + Organizm.wypiszPolozenie(x, y))
                    return
