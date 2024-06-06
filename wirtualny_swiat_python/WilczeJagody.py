from Roslina import Roslina


class WilczeJagody(Roslina):
    def __init__(self, x, y, wiek):
        super().__init__(x, y, wiek)
        self.setNazwa("WilczeJagody")
        self.setSymbol('J')
        self.setSila(99)
        self.setInicjatywa(0)
        self.setNiesmiertelnosc(False)

    def stworzNowySklonowanyObiekt(self):
        return WilczeJagody(0, 0, 0)

    def kolizja(self, swiat, atakujacy):
        self.setCzyZyje(False)
        swiat.usunOrganizm(self, self.polozenieX, self.polozenieY)
        swiat.wypiszWiadomosc(atakujacy.getNazwa() + " zjada Wilcze Jagody"
                              + self.wypiszPolozenie(self.polozenieX, self.polozenieY))

        if atakujacy.czyNiesmiertelny() is False:
            atakujacy.setCzyZyje(False)
            swiat.usunOrganizm(atakujacy, atakujacy.getPolozenieX(), atakujacy.getPolozenieY())
            swiat.wypiszWiadomosc("i umiera w wyniku ich zjedzenia")

    def rysowanie(self):
        return "mediumblue"
