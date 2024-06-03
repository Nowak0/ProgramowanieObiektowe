from Zwierze import Zwierze
import random


class Zolw(Zwierze):
    def __init__(self,x,y,wiek):
        super().__init__(x, y, wiek)
        self.setNazwa("Zolw")
        self.setSymbol('Z')
        self.setSila(2)
        self.setInicjatywa(1)
        self.setNiesmiertelnosc(False)

    def stworzNowySklonowanyObiekt(self):
        return Zolw(0,0,0)

    def akcja(self,swiat):
        ruch = random.randint(0,100)
        if ruch<=75:
            return
        else:
            super().akcja(swiat)

    def kolizja(self, swiat, atakujacy):
        if isinstance(self, Zolw):
            super().kolizja(swiat,atakujacy)
            return

        czyPrzetrwal = self.czyOdbilAtak(atakujacy, self)
        if czyPrzetrwal:
            swiat.wypiszWiadomosc("Zolw odpiera atak " + atakujacy.getNazwa()
                                  + self.wypiszPolozenie(self.polozenieX, self.polozenieY))
        else:
            self.setCzyZyje(False)
            swiat.usunOrganizm(self, self.polozenieX, self.polozenieY)
            atakujacy.setPolozenieX(self.polozenieX)
            atakujacy.setPolozenieY(self.polozenieY)
            swiat.dodajOrganizm(atakujacy, self.polozenieX, self.polozenieY)
            swiat.usunOrganizm(atakujacy, atakujacy.getPolozenieX(), atakujacy.getPolozenieY())
            swiat.wypiszWiadomosc(atakujacy.getNazwa() + " zabija Zolw"
                                + self.wypiszPolozenie(self.polozenieX, self.polozenieY))

    def rysowanie(self):
        pass
