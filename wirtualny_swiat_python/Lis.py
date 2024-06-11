import random
from Zwierze import Zwierze


class Lis(Zwierze):
    def __init__(self, x, y, wiek):
        super().__init__(x, y, wiek)
        self.setNazwa("Lis")
        self.setSymbol('L')
        self.setSila(3)
        self.setInicjatywa(7)
        self.setNiesmiertelnosc(False)

    def stworzNowySklonowanyObiekt(self):
        return Lis(0, 0, 0)

    def akcja(self, swiat):
        mozliweMiejscaX = []
        mozliweMiejscaY = []

        for y in range(self.polozenieY - 1, self.polozenieY + 2):
            if y < 0 or y >= swiat.getWymiarMapyY():
                continue
            for x in range(self.polozenieX - 1, self.polozenieX + 2):
                if x < 0 or x >= swiat.getWymiarMapyX():
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

    def rysowanie(self):
        return "coral"
