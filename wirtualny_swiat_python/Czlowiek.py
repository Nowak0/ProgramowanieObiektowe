from Zwierze import Zwierze


class Czlowiek(Zwierze):
    LICZBA_TUR_NIESMIERTELNOSC = 5

    def __init__(self, x, y, wiek):
        super().__init__(x, y, wiek)
        self.setNazwa("Czlowiek")
        self.setSymbol('C')
        self.setSila(5)
        self.setInicjatywa(4)
        self.setNiesmiertelnosc(False)
        self.ruch = Zwierze.RUCH_NIEAKTYWNY
        self.licznikTur = Czlowiek.LICZBA_TUR_NIESMIERTELNOSC
        self.czyMoznaAktywowacNiesmiertelnosc = True

    def stworzNowySklonowanyObiekt(self):
        return None

    def akcja(self, swiat):
        if self.ruch == Zwierze.RUCH_PRAWO and self.polozenieX + 1 < swiat.getWymiarMapyX():
            self.akcjaRuchWPrawo(swiat)

        elif self.ruch == Zwierze.RUCH_LEWO and self.polozenieX - 1 >= 0:
            self.akcjaRuchWLewo(swiat)

        elif self.ruch == Zwierze.RUCH_DOL and self.polozenieY + 1 < swiat.getWymiarMapyY():
            self.akcjaRuchWDol(swiat)

        elif self.ruch == Zwierze.RUCH_GORA and self.polozenieY - 1 >= 0:
            self.akcjaRuchWGore(swiat)

    def akcjaRuchWPrawo(self, swiat):
        if swiat.getOrganizm(self.polozenieX + 1, self.polozenieY) is None:
            swiat.usunOrganizm(self, self.polozenieX, self.polozenieY)
            self.setPolozenieX(self.polozenieX + 1)
            swiat.dodajOrganizm(self, self.polozenieX, self.polozenieY)

        elif (self.czyNiesmiertelny() is False or
              swiat.getOrganizm(self.polozenieX + 1, self.polozenieY).getSila() <= self.sila):
            swiat.getOrganizm(self.polozenieX + 1, self.polozenieY).kolizja(swiat, self)

    def akcjaRuchWLewo(self, swiat):
        if swiat.getOrganizm(self.polozenieX - 1, self.polozenieY) is None:
            swiat.usunOrganizm(self, self.polozenieX, self.polozenieY)
            self.setPolozenieX(self.polozenieX - 1)
            swiat.dodajOrganizm(self, self.polozenieX, self.polozenieY)

        elif (self.czyNiesmiertelny() is False or
              swiat.getOrganizm(self.polozenieX - 1, self.polozenieY).getSila() <= self.sila):
            swiat.getOrganizm(self.polozenieX - 1, self.polozenieY).kolizja(swiat, self)

    def akcjaRuchWDol(self, swiat):
        if swiat.getOrganizm(self.polozenieX, self.polozenieY + 1) is None:
            swiat.usunOrganizm(self, self.polozenieX, self.polozenieY)
            self.setPolozenieY(self.polozenieY + 1)
            swiat.dodajOrganizm(self, self.polozenieX, self.polozenieY)

        elif (self.czyNiesmiertelny() is False or
              swiat.getOrganizm(self.polozenieX, self.polozenieY + 1).getSila() <= self.sila):
            swiat.getOrganizm(self.polozenieX, self.polozenieY + 1).kolizja(swiat, self)

    def akcjaRuchWGore(self, swiat):
        if swiat.getOrganizm(self.polozenieX, self.polozenieY - 1) is None:
            swiat.usunOrganizm(self, self.polozenieX, self.polozenieY)
            self.setPolozenieY(self.polozenieY - 1)
            swiat.dodajOrganizm(self, self.polozenieX, self.polozenieY)

        elif (self.czyNiesmiertelny() is False or
              swiat.getOrganizm(self.polozenieX, self.polozenieY - 1).getSila() <= self.sila):
            swiat.getOrganizm(self.polozenieX, self.polozenieY - 1).kolizja(swiat, self)

    def setRuchCzlowieka(self, ruch):
        if ruch == Zwierze.RUCH_PRAWO or ruch == Zwierze.RUCH_LEWO or ruch == Zwierze.RUCH_DOL or ruch == Zwierze.RUCH_GORA:
            self.ruch = ruch
        else:
            self.ruch = Zwierze.RUCH_NIEAKTYWNY

    def kolizja(self, swiat, atakujacy):
        if self.czyNiesmiertelny() and atakujacy.getSila() >= self.sila:
            self.kolizjaNiesmiertelnosc(swiat, atakujacy)
        else:
            self.kolizjaBezNiesmiertelnosci(swiat, atakujacy)

    def kolizjaNiesmiertelnosc(self, swiat, atakujacy):
        tmpX = self.polozenieX
        tmpY = self.polozenieY

        for y in range(self.polozenieY - 1, self.polozenieY + 2):
            if y < 0 or y >= swiat.getWymiarMapyY():
                continue
            for x in range(self.polozenieX - 1, self.polozenieX + 2):
                if x < 0 or x >= swiat.getWymiarMapyX():
                    continue
                if x == self.polozenieX and y == self.polozenieY:
                    continue
                if swiat.getOrganizm(x, y) is None:
                    swiat.usunOrganizm(self, self.polozenieX, self.polozenieY)
                    swiat.usunOrganizm(atakujacy, atakujacy.getPolozenieX(), atakujacy.getPolozenieY())
                    self.setPolozenieX(x)
                    self.setPolozenieY(y)
                    atakujacy.setPolozenieX(self.polozenieX)
                    atakujacy.setPolozenieY(self.polozenieY)
                    swiat.dodajOrganizm(self, x, y)
                    swiat.dodajOrganizm(atakujacy, tmpX, tmpY)

    def kolizjaBezNiesmiertelnosci(self, swiat, atakujacy):
        czyPrzetrwal = self.czyOdbilAtak(atakujacy, self)

        if czyPrzetrwal:
            atakujacy.setCzyZyje(False)
            swiat.wypiszWiadomosc("Czlowiek zabija " + atakujacy.getNazwa()
                                  + self.wypiszPolozenie(self.polozenieX, self.polozenieY))
            swiat.usunOrganizm(atakujacy, atakujacy.getPolozenieX(), atakujacy.getPolozenieY())
        else:
            self.setCzyZyje(False)
            swiat.usunOrganizm(self, self.polozenieX, self.polozenieY)
            swiat.usunOrganizm(atakujacy, atakujacy.getPolozenieX(), atakujacy.getPolozenieY())
            atakujacy.setPolozenieX(self.polozenieX)
            atakujacy.setPolozenieY(self.polozenieY)
            swiat.dodajOrganizm(atakujacy, self.polozenieX, self.polozenieY)
            swiat.wypiszWiadomosc(atakujacy.getNazwa() + " zabija Czlowiek"
                                  + self.wypiszPolozenie(self.polozenieX, self.polozenieY))

    def rysowanie(self):
        return "bisque"

    def aktywujNiesmiertelnoscCzlowieka(self):
        if self.czyMoznaAktywowacNiesmiertelnosc is True and self.czyNiesmiertelny() is False:
            self.setNiesmiertelnosc(True)
            self.setCzyMoznaAktywowacNiesmiertelnosc(False)
            self.setLicznikTur(Czlowiek.LICZBA_TUR_NIESMIERTELNOSC)
            return True

        return False

    def sprawdzLiczenieTur(self):
        if self.licznikTur == 0:
            self.setNiesmiertelnosc(False)
            self.setCzyMoznaAktywowacNiesmiertelnosc(False)
        elif self.licznikTur == Czlowiek.LICZBA_TUR_NIESMIERTELNOSC and self.czyNiesmiertelny() is False:
            self.setCzyMoznaAktywowacNiesmiertelnosc(True)

        if self.czyNiesmiertelny():
            self.licznikTur -= 1
        elif self.czyNiesmiertelny() is False and self.czyMoznaAktywowacNiesmiertelnosc is False:
            self.licznikTur += 1

    def getLicznikTur(self):
        return self.licznikTur

    def setLicznikTur(self, licznikTur):
        self.licznikTur = licznikTur

    def getCzyMoznaAktywowacNiesmiertelnosc(self):
        return self.czyMoznaAktywowacNiesmiertelnosc

    def setCzyMoznaAktywowacNiesmiertelnosc(self, wyrazenie):
        self.czyMoznaAktywowacNiesmiertelnosc = wyrazenie
