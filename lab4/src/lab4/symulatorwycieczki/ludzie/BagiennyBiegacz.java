package lab4.symulatorwycieczki.ludzie;

import lab4.symulatorwycieczki.Atrakcja;
import lab4.symulatorwycieczki.Wedrowka;
import lab4.symulatorwycieczki.gory.Bagno;

public class BagiennyBiegacz extends Czlowiek{

    public BagiennyBiegacz(String imie, String nazwisko, Plec plec) {
        super(imie, nazwisko, plec, 4, 10 ,22);
    }

    protected BagiennyBiegacz(String imie, String nazwisko, Plec plec, double maksymalnaPredkosc) {
        super(imie, nazwisko, plec, maksymalnaPredkosc, 10, 22);
    }

    protected BagiennyBiegacz(String imie, String nazwisko, Plec plec, double maksymalnaPredkosc, double czasPelnejRegeneracji, double czasPelnegoZmeczenia) {
        super(imie, nazwisko, plec, maksymalnaPredkosc, czasPelnejRegeneracji, czasPelnegoZmeczenia);
    }

    @Override
    public void reagujNaWedrowke(Wedrowka w, double czas) {
        if (w instanceof Bagno b) {
            w.modyfikujPredkoscGrupy(getBazowaPredkosc()*2);
            aktualizujZmeczenie(czas/2);
            mow("Biegam po bagnie i jest wspaniale");
        }
        else {
            aktualizujZmeczenie(czas);
            mow("nie jestem w bagnie");
        }
    }

    @Override
    public void reagujNaAtrakcje(Atrakcja a, double czas) {
        regeneruj(czas);
        mow("ja jestem biegaczem");
    }

    @Override
    public int getUmiejetnosciNawigacyjne() {
        return 4;
    }
}
