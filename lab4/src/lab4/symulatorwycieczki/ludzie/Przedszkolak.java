package lab4.symulatorwycieczki.ludzie;

import lab4.symulatorwycieczki.Atrakcja;
import lab4.symulatorwycieczki.Wedrowka;

public class Przedszkolak extends Czlowiek{

    public Przedszkolak(String imie, String nazwisko, Plec plec) {
        super(imie, nazwisko, plec, 2, 8 ,14);
    }

    protected Przedszkolak(String imie, String nazwisko, Plec plec, double maksymalnaPredkosc) {
        super(imie, nazwisko, plec, maksymalnaPredkosc, 8, 14);
    }

    protected Przedszkolak(String imie, String nazwisko, Plec plec, double maksymalnaPredkosc, double czasPelnejRegeneracji, double czasPelnegoZmeczenia) {
        super(imie, nazwisko, plec, maksymalnaPredkosc, czasPelnejRegeneracji, czasPelnegoZmeczenia);
    }

    @Override
    public void reagujNaWedrowke(Wedrowka w, double czas) {
        aktualizujZmeczenie(czas);
        mow("tato tato ile jeszcze bedziemy w "+w.getNazwa() + "?!");
    }

    @Override
    public void reagujNaAtrakcje(Atrakcja a, double czas) {
        regeneruj(czas);
        mow("mamo mamo a co to za miejsce: "+a.getNazwa() + "?? mamo mamo a dlaczego to... a dlaczego tamto?");
    }

    @Override
    public int getUmiejetnosciNawigacyjne() {
        return 1;
    }
}
