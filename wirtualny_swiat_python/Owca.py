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

    def rysowanie(self):
        return "white"
