package lab4.symulatorwycieczki.ludzie;

import lab4.symulatorwycieczki.Atrakcja;
import lab4.symulatorwycieczki.Wedrowka;

public class Sportowiec extends Czlowiek{

    public Sportowiec(String imie, String nazwisko, Plec plec) {
        super(imie, nazwisko, plec, 10, 2,60);
    }

    protected Sportowiec(String imie, String nazwisko, Plec plec, double maksymalnaPredkosc) {
        super(imie, nazwisko, plec, maksymalnaPredkosc, 2, 64);
    }

    protected Sportowiec(String imie, String nazwisko, Plec plec, double maksymalnaPredkosc, double czasPelnejRegeneracji, double czasPelnegoZmeczenia) {
        super(imie, nazwisko, plec, maksymalnaPredkosc, czasPelnejRegeneracji, czasPelnegoZmeczenia);
    }

    @Override
    public void reagujNaWedrowke(Wedrowka w, double czas) {
        aktualizujZmeczenie(czas);
        mow("moglbym tak caly dzien chodzic po "+w.getNazwa());
    }

    @Override
    public void reagujNaAtrakcje(Atrakcja a, double czas) {
        regeneruj(czas);
        mow("atrakacja "+a.getNazwa() + " jest super, ale najchetniej to bym pobiegal teraz");
    }

    @Override
    public int getUmiejetnosciNawigacyjne() {
        return 3;
    }
}
