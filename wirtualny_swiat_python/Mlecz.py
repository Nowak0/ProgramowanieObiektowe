from Roslina import Roslina


class Mlecz(Roslina):
    def __init__(self, x, y, wiek):
        super().__init__(x, y, wiek)
        self.setNazwa("Mlecz")
        self.setSymbol('M')
        self.setSila(0)
        self.setInicjatywa(0)
        self.setNiesmiertelnosc(False)

    def stworzNowySklonowanyObiekt(self):
        return Mlecz(0, 0, 0)

    def akcja(self, swiat):
        super().akcja(swiat)
        super().akcja(swiat)
        super().akcja(swiat)

    def kolizja(self, swiat, atakujacy):
        self.setCzyZyje(False)
        swiat.usunOrganizm(self, self.polozenieX, self.polozenieY)
        swiat.usunOrganizm(atakujacy, atakujacy.getPolozenieX(), atakujacy.getPolozenieY())
        atakujacy.setPolozenieX(self.polozenieX)
        atakujacy.setPolozenieY(self.polozenieY)
        swiat.dodajOrganizm(atakujacy, self.polozenieX, self.polozenieY)
        swiat.wypiszWiadomosc(atakujacy.getNazwa() + " zjada Mlecz"
                              + self.wypiszPolozenie(self.polozenieX, self.polozenieY))

    def rysowanie(self):
        pass
