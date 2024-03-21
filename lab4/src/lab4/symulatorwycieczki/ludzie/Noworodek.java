package lab4.symulatorwycieczki.ludzie;

import lab4.symulatorwycieczki.Atrakcja;
import lab4.symulatorwycieczki.Wedrowka;

public class Noworodek extends Czlowiek{

    public Noworodek(String imie, String nazwisko, Plec plec) {
        super(imie, nazwisko, plec, 4, 30 ,4);
    }

    protected Noworodek(String imie, String nazwisko, Plec plec, double maksymalnaPredkosc) {
        super(imie, nazwisko, plec, maksymalnaPredkosc, 30, 4);
    }

    protected Noworodek(String imie, String nazwisko, Plec plec, double maksymalnaPredkosc, double czasPelnejRegeneracji, double czasPelnegoZmeczenia) {
        super(imie, nazwisko, plec, maksymalnaPredkosc, czasPelnejRegeneracji, czasPelnegoZmeczenia);
    }

    @Override
    public void reagujNaWedrowke(Wedrowka w, double czas) {
        aktualizujZmeczenie(czas);
        mow("beeeeeeeeeeee");
    }

    @Override
    public void reagujNaAtrakcje(Atrakcja a, double czas) {
        regeneruj(czas);
        mow("gu gu gu");
    }

    @Override
    public int getUmiejetnosciNawigacyjne() {
        return 0;
    }
}
