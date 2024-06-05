from tkinter import *
from tkinter import messagebox
from Zapis import Zapis


class Grafika:
    RUCH_NIEAKTYWNY = -1
    RUCH_PRAWO = 1
    RUCH_LEWO = 2
    RUCH_GORA = 3
    RUCH_DOL = 4
    ROZMIAR_POLA = 40

    def __init__(self, swiat):
        self.swiat = swiat
        self.okno = Tk()
        self.okno.title("Wirtualny Swiat Python Jakub Nowak 197860")
        self.okno.geometry('1920x1080')
        self.okno.tk.call('tk', 'scaling', 2.0)
        self.plansza = None
        self.budujPlansze()
        self.przypiszDzialaniaStrzalkom()

    def przypiszDzialaniaStrzalkom(self):
        self.okno.bind("<Right>", self.nacisniecieStrzalek)
        self.okno.bind("<Left>", self.nacisniecieStrzalek)
        self.okno.bind("<Down>", self.nacisniecieStrzalek)
        self.okno.bind("<Up>", self.nacisniecieStrzalek)

    def nacisniecieStrzalek(self, wydarzenie):
        if wydarzenie.keysym == 'Right':
            self.wyczyscPoleZWiadomosciami()
            self.swiat.wykonajTure(Grafika.RUCH_PRAWO)
            self.rysujSwiat()
            self.wypiszWiadomosci()
        elif wydarzenie.keysym == 'Left':
            self.wyczyscPoleZWiadomosciami()
            self.swiat.wykonajTure(Grafika.RUCH_LEWO)
            self.rysujSwiat()
            self.wypiszWiadomosci()
        elif wydarzenie.keysym == 'Down':
            self.wyczyscPoleZWiadomosciami()
            self.swiat.wykonajTure(Grafika.RUCH_DOL)
            self.rysujSwiat()
            self.wypiszWiadomosci()
        elif wydarzenie.keysym == 'Up':
            self.wyczyscPoleZWiadomosciami()
            self.swiat.wykonajTure(Grafika.RUCH_GORA)
            self.rysujSwiat()
            self.wypiszWiadomosci()

    def budujPlansze(self):
        wymiarX = self.swiat.getWymiarMapyX()
        wymiarY = self.swiat.getWymiarMapyY()
        self.plansza = Canvas(self.okno, width=wymiarX * Grafika.ROZMIAR_POLA, height=wymiarY * Grafika.ROZMIAR_POLA)
        self.plansza.pack()
        self.plansza.grid(column=6, row=1)

    def rysujSwiat(self):
        wymiarX = self.swiat.getWymiarMapyX()
        wymiarY = self.swiat.getWymiarMapyY()

        for y in range(wymiarY):
            for x in range(wymiarX):
                x1 = x * Grafika.ROZMIAR_POLA
                y1 = y * Grafika.ROZMIAR_POLA
                x2 = x1 + Grafika.ROZMIAR_POLA
                y2 = y1 + Grafika.ROZMIAR_POLA
                if self.swiat.getOrganizm(x, y) is None:
                    kolor = 'grey'
                    tekst = ""
                else:
                    kolor = self.swiat.getOrganizm(x, y).rysowanie()
                    tekst = self.swiat.getOrganizm(x, y).getSymbol()
                self.plansza.create_rectangle(x1, y1, x2, y2, fill=kolor, outline='black')
                self.plansza.create_text((x1 + x2) / 2, (y1 + y2) / 2, text=tekst, fill='black')

    def dodajPrzyciski(self):
        przyciskNowaTura = Button(self.okno, text="Nowa Tura", command=self.akcjaPrzyciskNowaTura)
        przyciskNowaTura.grid(column=1, row=0)
        niesmiertelnosc = Button(self.okno, text="Aktywuj Niesmiertelnosc", command=self.akcjaPrzyciskNiesmiertelnosc)
        niesmiertelnosc.grid(column=2, row=0)
        przyciskZapisz = Button(self.okno, text="Zapisz Gre", command=self.akcjaPrzyciskZapisz)
        przyciskZapisz.grid(column=3, row=0)
        przyciskZaladuj = Button(self.okno, text="Zaladuj Gre", comman=self.akcjaPrzyciskZaladuj)
        przyciskZaladuj.grid(column=4, row=0)
        przyciskZakoncz = Button(self.okno, text="Zakoncz Gre", command=self.akcjaPrzyciskZakoncz)
        przyciskZakoncz.grid(column=5, row=0)

    def akcjaPrzyciskNowaTura(self):
        self.wyczyscPoleZWiadomosciami()
        self.swiat.wykonajTure(-1)
        self.rysujSwiat()
        self.wypiszWiadomosci()

    def akcjaPrzyciskNiesmiertelnosc(self):
        if self.swiat.czyCzlowiekZyje() is False:
            return
        self.aktywowanieNiesmiertelnosci()

    def aktywowanieNiesmiertelnosci(self):
        czlowiek = self.swiat.znajdzCzlowieka()
        if czlowiek.aktywujNiesmiertelnoscCzlowieka():
            messagebox.showinfo(title="Udalo sie!", message="Aktywowano niesmiertelnosc")
        else:
            messagebox.showinfo(title="Nie udalo sie :(", message="Nie mozna aktywowac niesmiertelnosci")

    def akcjaPrzyciskZapisz(self):
        zapisywanie = Zapis(self.swiat)
        zapisywanie.zapiszDoPliku()

    def akcjaPrzyciskZaladuj(self):
        ladowanie = Zapis(self.swiat)
        ladowanie.zaladujPlik()

    def akcjaPrzyciskZakoncz(self):
        self.okno.destroy()

    def wypiszWiadomosci(self):
        for i in range(self.swiat.getIloscWiadomosci()):
            wiadomosc = Label(self.okno, text=self.swiat.getWiadomosc(i), font=("Arial", 12))
            wiadomosc.grid(column=7, row=(i + 2))

    def wyczyscPoleZWiadomosciami(self):
        for i in range(self.swiat.getIloscWiadomosci()):
            tekst = " " * 2 * len(self.swiat.getWiadomosc(i))
            wiadomosc = Label(self.okno, text=tekst, font=("Arial", 12))
            wiadomosc.grid(column=7, row=(i + 2))

    def utrzymajStan(self):
        self.okno.mainloop()
