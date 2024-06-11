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

    def rysowanie(self):
        return "yellow"
