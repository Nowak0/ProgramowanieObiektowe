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

    def rysowanie(self):
        return "silver"
