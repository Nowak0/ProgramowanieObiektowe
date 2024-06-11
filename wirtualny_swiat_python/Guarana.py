from Roslina import Roslina


class Guarana(Roslina):
    def __init__(self, x, y, wiek):
        super().__init__(x, y, wiek)
        self.setNazwa("Guarana")
        self.setSymbol('G')
        self.setSila(0)
        self.setInicjatywa(0)
        self.setNiesmiertelnosc(False)

    def stworzNowySklonowanyObiekt(self):
        return Guarana(0, 0, 0)

    def kolizja(self, swiat, atakujacy):
        atakujacy.setSila(atakujacy.getSila() + 3)
        super().kolizja(swiat, atakujacy)

    def rysowanie(self):
        return "hotpink"
