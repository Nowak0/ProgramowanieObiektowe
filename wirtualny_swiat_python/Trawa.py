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

    def rysowanie(self):
        return "forestgreen"
