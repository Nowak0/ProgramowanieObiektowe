from Swiat import Swiat
from tkinter import *
from functools import partial


def rozpocznijGre(wymiarX, wymiarY, otwarteOkno):
    x = int(wymiarX.get())
    y = int(wymiarY.get())
    otwarteOkno.destroy()
    swiat = Swiat(x, y)
    swiat.rysujSwiat()


okno = Tk()
okno.geometry("600x400")
wymiarMapyX = StringVar()
wymiarMapyY = StringVar()

xNapis = Label(okno, text='Podaj wymiar mapy X', font=('Arial', 10, 'bold'))
xWejscie = Entry(okno, textvariable=wymiarMapyX, font=('Arial', 10, 'normal'))
yNapis = Label(okno, text='Podaj wymiar mapy Y', font=('Arial', 10, 'bold'))
yWejscie = Entry(okno, textvariable=wymiarMapyY, font=('Arial', 10, 'normal'))

rozpoczynanie = partial(rozpocznijGre, wymiarMapyX, wymiarMapyY, okno)
potwierdz = Button(okno, text='Potwierdz', command=rozpoczynanie)

xNapis.grid(row=0, column=0)
xWejscie.grid(row=0, column=1)
yNapis.grid(row=1, column=0)
yWejscie.grid(row=1, column=1)
potwierdz.grid(row=2, column=1)
okno.mainloop()
