package lab4.symulatorwycieczki.ludzie;

import lab4.symulatorwycieczki.Atrakcja;
import lab4.symulatorwycieczki.Wedrowka;

public class Emeryt extends Czlowiek{

    public Emeryt(String imie, String nazwisko, Plec plec) {
        super(imie, nazwisko, plec, 2, 25 ,10);
    }

    protected Emeryt(String imie, String nazwisko, Plec plec, double maksymalnaPredkosc) {
        super(imie, nazwisko, plec, maksymalnaPredkosc, 25, 10);
    }

    protected Emeryt(String imie, String nazwisko, Plec plec, double maksymalnaPredkosc, double czasPelnejRegeneracji, double czasPelnegoZmeczenia) {
        super(imie, nazwisko, plec, maksymalnaPredkosc, czasPelnejRegeneracji, czasPelnegoZmeczenia);
    }

    @Override
    public void reagujNaWedrowke(Wedrowka w, double czas) {
        aktualizujZmeczenie(czas);
        mow("ehhh plecy mnie bola od tego chodzenia w : "+w.getNazwa());
    }

    @Override
    public void reagujNaAtrakcje(Atrakcja a, double czas) {
        regeneruj(czas);
        mow("jak dobrze mi siedzi, gdy wtenczas ogladam "+a.getNazwa() + " za moich czasow nie bylo takich atrakcji");
    }

    @Override
    public int getUmiejetnosciNawigacyjne() {
        return 2;
    }
}
