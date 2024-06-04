from tkinter import *
from tkinter import messagebox


class Grafika:
    def __init__(self, swiat):
        self.swiat = swiat
        self.okno = Tk()
        self.okno.title("Wirtualny Swiat Python Jakub Nowak 197860")
        self.okno.geometry('1920x1080')
        self.okno.tk.call('tk', 'scaling', 2.0)
        self.plansza = None
        self.budujPlansze()

    def budujPlansze(self):
        rozmiarPola = 75
        wymiarX = self.swiat.getWymiarMapyX()
        wymiarY = self.swiat.getWymiarMapyY()
        self.plansza = Canvas(self.okno, width=wymiarX * rozmiarPola, height=wymiarY * rozmiarPola)
        self.plansza.pack()
        self.plansza.grid(column=5, row=1)

    def rysujSwiat(self):
        rozmiarPola = 75
        wymiarX = self.swiat.getWymiarMapyX()
        wymiarY = self.swiat.getWymiarMapyY()

        for y in range(wymiarY):
            for x in range(wymiarX):
                x1 = x * rozmiarPola
                y1 = y * rozmiarPola
                x2 = x1 + rozmiarPola
                y2 = y1 + rozmiarPola
                if self.swiat.getOrganizm(x, y) is None:
                    kolor = 'grey'
                    tekst = ""
                else:
                    kolor = 'red'
                    tekst = self.swiat.getOrganizm(x, y).getSymbol()
                self.plansza.create_rectangle(x1, y1, x2, y2, fill=kolor, outline='black')
                self.plansza.create_text((x1 + x2) / 2, (y1 + y2) / 2, text=tekst, fill='black')

    def dodajPrzyciski(self):
        przyciskNowaTura = Button(self.okno, text="Nowa Tura", command=self.akcjaPrzyciskNowaTura)
        przyciskNowaTura.grid(column=1, row=0)
        przyciskZapisz = Button(self.okno, text="Zapisz Gre")
        przyciskZapisz.grid(column=2,row=0)
        przyciskZaladuj = Button(self.okno, text="Zaladuj Gre")
        przyciskZaladuj.grid(column=3, row=0)
        przyciskZakoncz = Button(self.okno, text="Zakoncz Gre", command=self.akcjaPrzyciskZakoncz)
        przyciskZakoncz.grid(column=4, row=0)

    def akcjaPrzyciskNowaTura(self):
        self.swiat.wykonajTure(-1)
        self.rysujSwiat()

    def akcjaPrzyciskZakoncz(self):
        self.okno.destroy()

    def utrzymajStan(self):
        self.okno.mainloop()
