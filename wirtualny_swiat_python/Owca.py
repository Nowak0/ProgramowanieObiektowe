from Zwierze import Zwierze


class Owca(Zwierze):
    def __init__(self, x, y, wiek):
        super().__init__(x, y, wiek)
        self.setNazwa("Owca")
        self.setSymbol('O')
        self.setSila(4)
        self.setInicjatywa(4)
        self.setNiesmiertelnosc(False)

    def stworzNowySklonowanyObiekt(self):
        return Owca(0, 0, 0)

    def kolizja(self, swiat, atakujacy):
        if isinstance(atakujacy, Owca):
            super().kolizja(swiat, atakujacy)
            return

        czyPrzetrwal = super().czyOdbilAtak(atakujacy, self)
        if czyPrzetrwal:
            swiat.wypiszWiadomosc("Owca zabija " + atakujacy.getNazwa()
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
            swiat.wypiszWiadomosc(atakujacy.getNazwa() + " zabija Owca"
                                  + self.wypiszPolozenie(self.polozenieX, self.polozenieY))

    def rysowanie(self):
        pass
