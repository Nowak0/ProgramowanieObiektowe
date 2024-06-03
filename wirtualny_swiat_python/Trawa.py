from Roslina import Roslina


class Trawa(Roslina):
    def __init__(self, x, y, wiek):
        super().__init__(x, y, wiek)
        self.setNazwa("Trawa")
        self.setSymbol('T')
        self.setSila(0)
        self.setInicjatywa(0)
        self.setNiesmiertelnosc(False)

    def stworzNowySklonowanyObiekt(self):
        return Trawa(0, 0, 0)

    def kolizja(self, swiat, atakujacy):
        self.setCzyZyje(False)
        swiat.usunOrganizm(self, self.polozenieX, self.polozenieY)
        atakujacy.setPolozenieX(self.polozenieX)
        atakujacy.setPolozenieY(self.polozenieY)
        swiat.dodajOrganizm(atakujacy, self.polozenieX, self.polozenieY)
        swiat.usunOrganizm(atakujacy, atakujacy.getPolozenieX(), atakujacy.getPolozenieY())
        swiat.wypiszWiadomosc(atakujacy.getNazwa() + " zjada Trawa"
                              + self.wypiszPolozenie(self.polozenieX, self.polozenieY))

    def rysowanie(self):
        pass
