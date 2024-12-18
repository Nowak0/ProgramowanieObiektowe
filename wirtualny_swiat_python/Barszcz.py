from Roslina import Roslina
from CyberOwca import CyberOwca


class Barszcz(Roslina):
    def __init__(self, x, y, wiek):
        super().__init__(x, y, wiek)
        self.setNazwa("BarszczSosnowskiego")
        self.setSymbol('B')
        self.setSila(10)
        self.setInicjatywa(0)
        self.setNiesmiertelnosc(False)

    def stworzNowySklonowanyObiekt(self):
        return Barszcz(0, 0, 0)

    def akcja(self, swiat):
        for y in range(self.polozenieY - 1, self.polozenieY + 2):
            if y < 0 or y >= swiat.wymiarMapyY:
                continue
            for x in range(self.polozenieX - 1, self.polozenieX + 2):
                if x < 0 or x >= swiat.wymiarMapyX:
                    continue
                if x == self.polozenieX and y == self.polozenieY:
                    continue
                if swiat.getOrganizm(x, y) is None:
                    continue
                elif self.sprawdzWarunkiDoAkcji(swiat, x, y):
                    tmpX = swiat.getOrganizm(x, y).getPolozenieX()
                    tmpY = swiat.getOrganizm(x, y).getPolozenieY()
                    swiat.getOrganizm(x, y).setCzyZyje(False)
                    swiat.wypiszWiadomosc(swiat.getOrganizm(x, y).getNazwa() + " zostaje zabity")
                    swiat.wypiszWiadomosc("przez Barszcz Sosnowskiego" + self.wypiszPolozenie(tmpX, tmpY))
                    swiat.usunOrganizm(swiat.getOrganizm(x, y), x, y)

    def sprawdzWarunkiDoAkcji(self, swiat, x, y):
        if (swiat.getOrganizm(x, y).getInicjatywa() > 0
                and swiat.getOrganizm(x, y).czyNiesmiertelny() is False
                and isinstance(swiat.getOrganizm(x, y), CyberOwca) is False):
            return True
        else:
            return False

    def kolizja(self, swiat, atakujacy):
        self.setCzyZyje(False)
        swiat.usunOrganizm(self, self.polozenieX, self.polozenieY)
        swiat.wypiszWiadomosc(atakujacy.getNazwa() + " zjada Barszcz Sosnowskiego"
                              + self.wypiszPolozenie(self.polozenieX, self.polozenieY))

        if atakujacy.czyNiesmiertelny() is False and isinstance(atakujacy, CyberOwca) is False:
            atakujacy.setCzyZyje(False)
            swiat.usunOrganizm(atakujacy, atakujacy.getPolozenieX(), atakujacy.getPolozenieY())
            swiat.wypiszWiadomosc("i umiera w wyniku jego zjedzenia")

        if isinstance(atakujacy, CyberOwca):
            swiat.usunOrganizm(atakujacy, atakujacy.getPolozenieX(), atakujacy.getPolozenieY())
            atakujacy.setPolozenieX(self.polozenieX)
            atakujacy.setPolozenieY(self.polozenieY)
            swiat.dodajOrganizm(atakujacy, self.polozenieX, self.polozenieY)

    def rysowanie(self):
        return "greenyellow"
