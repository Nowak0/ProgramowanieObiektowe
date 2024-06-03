from abc import ABC
from Organizm import Organizm
import random


class Roslina(ABC, Organizm):
    def akcja(self, swiat):
        rozsiewanie = random.randint(0, 101)
        if (rozsiewanie <= 90):
            return

        wymiarMapyX = swiat.getWymiarMapyX()
        wymiarMapyY = swiat.getWymiarMapyY()
        polozenieX = super().getPolozenieX()
        polozenieY = super().getPolozenieY()
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

        ruch = random.randint(0, len(mozliweMiejscaX))
        nowyX = mozliweMiejscaX[ruch]
        nowyY = mozliweMiejscaY[ruch]

        nowaRoslina = self.stworzNowySklonowowanyObiekt()
        nowaRoslina.setPolozenieX(nowyX)
        nowaRoslina.setPolozenieY(nowyY)
        nowaRoslina.setWiek(swiat.getLiczbaOrganizmow() + 1)
        swiat.dodajOrganizm(nowaRoslina, nowyX, nowyY)
