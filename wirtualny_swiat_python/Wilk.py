from Zwierze import Zwierze


class Wilk(Zwierze):
    def __init__(self, x, y, wiek):
        super().__init__(x, y, wiek)
        self.setNazwa("Wilk")
        self.setSymbol('W')
        self.setSila(9)
        self.setInicjatywa(5)
        self.setNiesmiertelnosc(False)

    def stworzNowySklonowanyObiekt(self):
        return Wilk(0, 0, 0)

    def kolizja(self, swiat, atakujacy):
        if isinstance(atakujacy, Wilk):
            super().kolizja(swiat, atakujacy)
            return

        czyPrzetrwal = super().czyOdbilAtak(atakujacy, self)
        if czyPrzetrwal:
            swiat.wypiszWiadomosc("Wilk zabija " + atakujacy.getNazwa()
                                  + super().wypiszPolozenie(self.polozenieX, self.polozenieY))
            atakujacy.setCzyZyje(False)
            swiat.usunOrganizm(atakujacy, atakujacy.getPolozenieX(), atakujacy.getPolozenieY())
        else:
            self.setCzyZyje(False)
            swiat.usunOrganizm(self, self.polozenieX, self.polozenieY)
            swiat.usunOrganizm(atakujacy, atakujacy.getPolozenieX(), atakujacy.getPolozenieY())
            atakujacy.setPolozenieX(self.polozenieX)
            atakujacy.setPolozenieY(self.polozenieY)
            swiat.dodajOrganizm(atakujacy, self.polozenieX, self.polozenieY)
            swiat.wypiszWiadomosc(atakujacy.getNazwa() + " zabija Wilk"
                                  + self.wypiszPolozenie(self.polozenieX, self.polozenieY))

    def rysowanie(self):
        return "silver"
