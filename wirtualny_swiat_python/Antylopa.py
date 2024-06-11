import random
from Zwierze import Zwierze


class Antylopa(Zwierze):
    def __init__(self, x, y, wiek):
        super().__init__(x, y, wiek)
        self.setNazwa("Antylopa")
        self.setSymbol('A')
        self.setSila(4)
        self.setInicjatywa(4)
        self.setNiesmiertelnosc(False)

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

        ruch = random.randint(0, len(mozliweMiejscaX) - 1)
        nowyX = mozliweMiejscaX[ruch]
        nowyY = mozliweMiejscaY[ruch]

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

    def kolizja(self, swiat, atakujacy):
        unik = random.randint(0, 1)
        if unik == 1:
            if self.unikAntylopy(swiat, atakujacy):
                return
        super().kolizja(swiat, atakujacy)

    def unikAntylopy(self, swiat, atakujacy):
        polozenieXAtak = atakujacy.getPolozenieX()
        polozenieYAtak = atakujacy.getPolozenieY()
        for y in range(self.polozenieY - 1, self.polozenieY + 2):
            if y < 0 or y >= swiat.getWymiarMapyY():
                continue
            for x in range(self.polozenieX - 1, self.polozenieX + 2):
                if x < 0 or x >= swiat.getWymiarMapyX():
                    continue
                if swiat.getOrganizm(x, y) is None:
                    swiat.usunOrganizm(self, self.polozenieX, self.polozenieY)
                    swiat.usunOrganizm(atakujacy, polozenieXAtak, polozenieYAtak)
                    atakujacy.setPolozenieX(self.polozenieX)
                    atakujacy.setPolozenieY(self.polozenieY)
                    swiat.dodajOrganizm(atakujacy, self.polozenieX, self.polozenieY)
                    self.setPolozenieX(x)
                    self.setPolozenieY(y)
                    swiat.dodajOrganizm(self, x, y)
                    swiat.wypiszWiadomosc("Antylopa unika ataku " + atakujacy.getNazwa()
                                          + self.wypiszPolozenie(self.polozenieX, self.polozenieY))
                    return True
        return False

    def rysowanie(self):
        return "sienna"
