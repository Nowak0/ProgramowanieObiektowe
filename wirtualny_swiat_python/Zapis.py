from Antylopa import Antylopa
from Barszcz import Barszcz
from Czlowiek import Czlowiek
from CyberOwca import CyberOwca
from Lis import Lis
from Owca import Owca
from WilczeJagody import WilczeJagody
from Wilk import Wilk
from Zolw import Zolw
from Trawa import Trawa
from Mlecz import Mlecz
from Guarana import Guarana
from tkinter import messagebox


class Zapis:
    def __init__(self, swiat):
        self.swiat = swiat

    def zapiszDoPliku(self):
        plik = open("zapis.txt", "w")
        plik.write(f"{self.swiat.getWymiarMapyX()} {self.swiat.getWymiarMapyY()}\n")

        for o in self.swiat.getPosortowaneOrganizmy():
            if isinstance(o, Czlowiek):
                plik.write(f"{o.getNazwa()} {o.getPolozenieX()} {o.getPolozenieY()} {o.getWiek()} "
                           f"{o.czyNiesmiertelny()} {o.getLicznikTur()} {o.getCzyMoznaAktywowacNiesmiertelnosc()}")
            else:
                plik.write(f"{o.getNazwa()} {o.getPolozenieX()} {o.getPolozenieY()} {o.getWiek()} "
                           f"{o.czyNiesmiertelny()}")
            plik.write("\n")

        plik.close()

    def zaladujPlik(self):
        try:
            plik = open("zapis.txt", "r")
            self.wczytajDaneZPliku(plik)
            plik.close()
        except FileNotFoundError:
            messagebox.showinfo(title="Błąd", message="Plik z zapisem nie istnieje")
        except IOError:
            messagebox.showinfo(title="Błąd", message="Błąd podczas otwierania pliku!")

    def wczytajDaneZPliku(self, plik):
        czyPierwszaLinia = True
        for linia in plik:
            argumenty = linia.split()
            if czyPierwszaLinia:
                self.swiat.ustawianieRozmiaruMapy(int(argumenty[0]), int(argumenty[1]))
                self.swiat.uaktualnijGraniceMapy()
                czyPierwszaLinia = False
            else:
                self.dodajOrganizmZPliku(argumenty)

    def dodajOrganizmZPliku(self, linia):
        linia[4] = self.odczytajBool(linia[4])

        if linia[0] == "Antylopa":
            nowy = Antylopa(int(linia[1]), int(linia[2]), int(linia[3]))
            nowy.setNiesmiertelnosc(linia[4])
            self.swiat.dodajOrganizm(nowy, nowy.getPolozenieX(), nowy.getPolozenieY())
        elif linia[0] == "Czlowiek":
            nowy = Czlowiek(int(linia[1]), int(linia[2]), int(linia[3]))
            nowy.setNiesmiertelnosc(linia[4])
            nowy.setLicznikTur(int(linia[5]))
            nowy.setCzyMoznaAktywowacNiesmiertelnosc(self.odczytajBool(linia[6]))
            self.swiat.dodajOrganizm(nowy, nowy.getPolozenieX(), nowy.getPolozenieY())
        elif linia[0] == "CyberOwca":
            nowy = CyberOwca(int(linia[1]), int(linia[2]), int(linia[3]))
            nowy.setNiesmiertelnosc(linia[4])
            self.swiat.dodajOrganizm(nowy, nowy.getPolozenieX(), nowy.getPolozenieY())
        elif linia[0] == "Lis":
            nowy = Lis(int(linia[1]), int(linia[2]), int(linia[3]))
            nowy.setNiesmiertelnosc(linia[4])
            self.swiat.dodajOrganizm(nowy, nowy.getPolozenieX(), nowy.getPolozenieY())
        elif linia[0] == "Owca":
            nowy = Owca(int(linia[1]), int(linia[2]), int(linia[3]))
            nowy.setNiesmiertelnosc(linia[4])
            self.swiat.dodajOrganizm(nowy, nowy.getPolozenieX(), nowy.getPolozenieY())
        elif linia[0] == "Wilk":
            nowy = Wilk(int(linia[1]), int(linia[2]), int(linia[3]))
            nowy.setNiesmiertelnosc(linia[4])
            self.swiat.dodajOrganizm(nowy, nowy.getPolozenieX(), nowy.getPolozenieY())
        elif linia[0] == "Zolw":
            nowy = Zolw(int(linia[1]), int(linia[2]), int(linia[3]))
            nowy.setNiesmiertelnosc(linia[4])
            self.swiat.dodajOrganizm(nowy, nowy.getPolozenieX(), nowy.getPolozenieY())
        elif linia[0] == "BarszczSosnowskiego":
            nowy = Barszcz(int(linia[1]), int(linia[2]), int(linia[3]))
            nowy.setNiesmiertelnosc(linia[4])
            self.swiat.dodajOrganizm(nowy, nowy.getPolozenieX(), nowy.getPolozenieY())
        elif linia[0] == "Guarana":
            nowy = Guarana(int(linia[1]), int(linia[2]), int(linia[3]))
            nowy.setNiesmiertelnosc(linia[4])
            self.swiat.dodajOrganizm(nowy, nowy.getPolozenieX(), nowy.getPolozenieY())
        elif linia[0] == "Mlecz":
            nowy = Mlecz(int(linia[1]), int(linia[2]), int(linia[3]))
            nowy.setNiesmiertelnosc(linia[4])
            self.swiat.dodajOrganizm(nowy, nowy.getPolozenieX(), nowy.getPolozenieY())
        elif linia[0] == "Trawa":
            nowy = Trawa(int(linia[1]), int(linia[2]), int(linia[3]))
            nowy.setNiesmiertelnosc(linia[4])
            self.swiat.dodajOrganizm(nowy, nowy.getPolozenieX(), nowy.getPolozenieY())
        elif linia[0] == "WilczeJagody":
            nowy = WilczeJagody(int(linia[1]), int(linia[2]), int(linia[3]))
            nowy.setNiesmiertelnosc(linia[4])
            self.swiat.dodajOrganizm(nowy, nowy.getPolozenieX(), nowy.getPolozenieY())

    def odczytajBool(self, wyrazenie):
        if wyrazenie == "False":
            return False
        else:
            return True
