from Antylopa import Antylopa
from Barszcz import Barszcz
from Czlowiek import Czlowiek
import random
from Lis import Lis
from Owca import Owca
from WilczeJagody import WilczeJagody
from Wilk import Wilk
from Zolw import Zolw
from Trawa import Trawa
from Mlecz import Mlecz
from Guarana import Guarana
from Grafika import Grafika
from tkinter import messagebox


class Swiat:
    MAX_WYMIAR_MAPY_X = 22
    MAX_WYMIAR_MAPY_Y = 20
    RUCH_NIEAKTYWNY = -1

    def __init__(self, x, y):
        self.wymiarMapyX = 0
        self.wymiarMapyY = 0
        self.ustawianieRozmiaruMapy(x, y)
        self.czlowiekZyje = False
        self.posortowaneOrganizmy = []
        self.wyswietlanie = None
        self.wiadomosci = []
        self.organizmy = [[None for _ in range(x)] for _ in range(y)]
        self.noweOrganizmy = []
        self.dodajOrganizmyRecznie()
        self.dodajOrganizmyDoSwiataLosowo()
        self.grafika = None

    def ustawianieRozmiaruMapy(self, x, y):
        self.wymiarMapyX = min(x, Swiat.MAX_WYMIAR_MAPY_X)
        self.wymiarMapyY = min(y, Swiat.MAX_WYMIAR_MAPY_Y)

    def uaktualnijGraniceMapy(self):
        self.posortowaneOrganizmy.clear()
        self.organizmy = [[None for _ in range(self.wymiarMapyX)] for _ in range(self.wymiarMapyY)]

    def wykonajTure(self, ruchCzlowieka):
        self.wiadomosci.clear()
        tmp = []
        if ruchCzlowieka != Swiat.RUCH_NIEAKTYWNY:
            self.ustawianieRuchuCzlowieka(ruchCzlowieka)

        for o in self.posortowaneOrganizmy:
            tmp.append(o)
            if isinstance(o, Czlowiek):
                self.sprawdzNiesmiertelnosc(o)

        for o in tmp:
            if o is not None and o.getCzyZyje():
                o.akcja(self)

    def rysujSwiat(self):
        self.grafika = Grafika(self)
        self.grafika.rysujSwiat()
        self.grafika.dodajPrzyciski()
        self.grafika.utrzymajStan()

    def getWymiarMapyX(self):
        return self.wymiarMapyX

    def getWymiarMapyY(self):
        return self.wymiarMapyY

    def getLiczbaOrganizmow(self):
        return len(self.posortowaneOrganizmy)

    def getPosortowaneOrganizmy(self):
        return self.posortowaneOrganizmy

    def getOrganizm(self, x, y):
        return self.organizmy[y][x]

    def czyCzlowiekZyje(self):
        return self.czlowiekZyje

    def dodajOrganizm(self, organizm, x, y):
        if organizm is None:
            return

        if isinstance(organizm, Czlowiek):
            self.czlowiekZyje = True

        organizm.setCzyZyje(True)
        self.organizmy[y][x] = organizm
        self.dodajOrganizmDoPosortowanych(organizm)

    def dodajOrganizmDoPosortowanych(self, organizm):
        i = 0
        inicjatywaOrganizmu = organizm.getInicjatywa()
        wiekOrganizmu = organizm.getWiek()

        for o in self.posortowaneOrganizmy:
            if o is organizm:
                continue
            if inicjatywaOrganizmu > o.getInicjatywa():
                self.posortowaneOrganizmy.insert(i, organizm)
                return
            elif inicjatywaOrganizmu == o.getInicjatywa() and wiekOrganizmu < o.getWiek():
                self.posortowaneOrganizmy.insert(i, organizm)
                return
            i += 1

        self.posortowaneOrganizmy.append(organizm)

    def usunOrganizm(self, organizm, x, y):
        if isinstance(organizm, Czlowiek) and organizm.getCzyZyje() is False:
            self.czlowiekZyje = False

        self.usunOrganizmZPosortowanych(organizm)
        self.organizmy[y][x] = None

    def usunOrganizmZPosortowanych(self, organizm):
        i = 0
        for o in self.posortowaneOrganizmy:
            if o is None:
                del self.posortowaneOrganizmy[i]
            elif o == organizm:
                del self.posortowaneOrganizmy[i]
                break
            i += 1

    def wypiszWiadomosc(self, wiadomosc):
        self.wiadomosci.append(wiadomosc)

    def getWiadomosc(self, indeks):
        return self.wiadomosci[indeks]

    def sprawdzNiesmiertelnosc(self, organizm):
        organizm.sprawdzLiczenieTur()
        if organizm.czyNiesmiertelny():
            self.wypiszWiadomosc("niesmiertelnosc aktywna")
        else:
            self.wypiszWiadomosc("niesmiertelnosc nieaktywna")

    def znajdzCzlowieka(self):
        if self.czlowiekZyje is False:
            return None

        for o in self.posortowaneOrganizmy:
            if isinstance(o, Czlowiek):
                return o

        return None

    def ustawianieRuchuCzlowieka(self, kierunek):
        for o in self.posortowaneOrganizmy:
            if isinstance(o, Czlowiek):
                o.setRuchCzlowieka(kierunek)

    def getIloscWiadomosci(self):
        return len(self.wiadomosci)

    def dodajOrganizmyDoSwiataLosowo(self):
        wolneMiejsca = self.wymiarMapyX * self.wymiarMapyY

        for o in self.noweOrganizmy:
            dodano = False
            while dodano is False and wolneMiejsca > 0:
                polozenieX = random.randint(0, self.wymiarMapyX - 1)
                polozenieY = random.randint(0, self.wymiarMapyY - 1)
                if self.organizmy[polozenieY][polozenieX] is None:
                    o.setPolozenieX(polozenieX)
                    o.setPolozenieY(polozenieY)
                    o.setWiek(self.getLiczbaOrganizmow() + 1)
                    self.dodajOrganizm(o, polozenieX, polozenieY)
                    wolneMiejsca -= 1
                    dodano = True

    def dodajOrganizmDoSwiataLosowo(self, organizm):
        wolneMiejsca = self.wymiarMapyX * self.wymiarMapyY - len(self.posortowaneOrganizmy)

        if wolneMiejsca == 0:
            messagebox.showinfo(title="Błąd!", message="Nie ma miejsca na swiecie")
            return

        while True:
            polozenieX = random.randint(0, self.wymiarMapyX - 1)
            polozenieY = random.randint(0, self.wymiarMapyY - 1)
            if self.organizmy[polozenieY][polozenieX] is None:
                organizm.setPolozenieX(polozenieX)
                organizm.setPolozenieY(polozenieY)
                organizm.setWiek(self.getLiczbaOrganizmow() + 1)
                self.dodajOrganizm(organizm, polozenieX, polozenieY)
                self.grafika.rysujSwiat()
                messagebox.showinfo(title="Udalo sie!",
                                    message=f"Dodano do swiata {organizm.getNazwa()} ({organizm.getPolozenieX()}, "
                                            f"{organizm.getPolozenieY()})")
                return

    def sprecyzujDodanyOrganizm(self, nazwa):
        if nazwa == "Antylopa":
            self.dodajOrganizmDoSwiataLosowo(Antylopa(0, 0, 0))
        elif nazwa == "Lis":
            self.dodajOrganizmDoSwiataLosowo(Lis(0, 0, 0))
        elif nazwa == "Owca":
            self.dodajOrganizmDoSwiataLosowo(Owca(0, 0, 0))
        elif nazwa == "Wilk":
            self.dodajOrganizmDoSwiataLosowo(Wilk(0, 0, 0))
        elif nazwa == "Zolw":
            self.dodajOrganizmDoSwiataLosowo(Zolw(0, 0, 0))
        elif nazwa == "Barszcz Sosnowskiego":
            self.dodajOrganizmDoSwiataLosowo(Barszcz(0, 0, 0))
        elif nazwa == "Guarana":
            self.dodajOrganizmDoSwiataLosowo(Guarana(0, 0, 0))
        elif nazwa == "Mlecz":
            self.dodajOrganizmDoSwiataLosowo(Mlecz(0, 0, 0))
        elif nazwa == "Trawa":
            self.dodajOrganizmDoSwiataLosowo(Trawa(0, 0, 0))
        elif nazwa == "Wilcze Jagody":
            self.dodajOrganizmDoSwiataLosowo(WilczeJagody(0, 0, 0))

    def dodajOrganizmyRecznie(self):
        self.noweOrganizmy.append(Czlowiek(0, 0, 0))
        self.noweOrganizmy.append(Lis(0, 0, 0))
        self.noweOrganizmy.append(Antylopa(0, 0, 0))
        self.noweOrganizmy.append(Zolw(0, 0, 0))
        self.noweOrganizmy.append(Owca(0, 0, 0))
        self.noweOrganizmy.append(Trawa(0, 0, 0))
        self.noweOrganizmy.append(Barszcz(0, 0, 0))
        self.noweOrganizmy.append(Guarana(0, 0, 0))
        self.noweOrganizmy.append(Guarana(0, 0, 0))
        self.noweOrganizmy.append(Mlecz(0, 0, 0))
        self.noweOrganizmy.append(Mlecz(0, 0, 0))
        self.noweOrganizmy.append(Wilk(0, 0, 0))
        self.noweOrganizmy.append(WilczeJagody(0, 0, 0))
