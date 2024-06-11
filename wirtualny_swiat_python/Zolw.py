from Zwierze import Zwierze
import random


class Zolw(Zwierze):
    def __init__(self, x, y, wiek):
        super().__init__(x, y, wiek)
        self.setNazwa("Zolw")
        self.setSymbol('Z')
        self.setSila(2)
        self.setInicjatywa(1)
        self.setNiesmiertelnosc(False)

    def stworzNowySklonowanyObiekt(self):
        return Zolw(0, 0, 0)

    def akcja(self, swiat):
        ruch = random.randint(0, 100)
        if ruch <= 75:
            return
        else:
            super().akcja(swiat)

    def rysowanie(self):
        return "darkgreen"
