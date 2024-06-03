from abc import ABC
from Organizm import Organizm
import random


class Roslina(Organizm, ABC):
    def akcja(self, swiat):
        rozsiewanie = random.randint(0, 100)
        if rozsiewanie <= 90:
            return

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

        nowaRoslina = self.stworzNowySklonowanyObiekt()
        nowaRoslina.setPolozenieX(nowyX)
        nowaRoslina.setPolozenieY(nowyY)
        nowaRoslina.setWiek(swiat.getLiczbaOrganizmow() + 1)
        swiat.dodajOrganizm(nowaRoslina, nowyX, nowyY)
