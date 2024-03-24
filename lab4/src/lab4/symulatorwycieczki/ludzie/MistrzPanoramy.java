package lab4.symulatorwycieczki.ludzie;

import lab4.symulatorwycieczki.Atrakcja;
import lab4.symulatorwycieczki.Wedrowka;
import lab4.symulatorwycieczki.gory.beskidy.Panorama;

public class MistrzPanoramy extends Czlowiek{

    public MistrzPanoramy(String imie, String nazwisko, Plec plec) {
        super(imie, nazwisko, plec, 3, 18 ,12);
    }

    protected MistrzPanoramy(String imie, String nazwisko, Plec plec, double maksymalnaPredkosc) {
        super(imie, nazwisko, plec, maksymalnaPredkosc, 18, 12);
    }

    protected MistrzPanoramy(String imie, String nazwisko, Plec plec, double maksymalnaPredkosc, double czasPelnejRegeneracji, double czasPelnegoZmeczenia) {
        super(imie, nazwisko, plec, maksymalnaPredkosc, czasPelnejRegeneracji, czasPelnegoZmeczenia);
    }

    @Override
    public void reagujNaWedrowke(Wedrowka w, double czas) {
        aktualizujZmeczenie(czas);
        mow("wedruje sobie, jestem od panoramy");
    }

    @Override
    public void reagujNaAtrakcje(Atrakcja a, double czas) {
        if (a instanceof Panorama p) {
            regeneruj(czas*2);
            mow("Jestem na panoramie i bawie sie wybornie");
        }
        else {
            regeneruj(czas);
            mow("nie jestem na panoramie ale jestem mistrzyni panoramy");
        }
    }

    @Override
    public int getUmiejetnosciNawigacyjne() {
        return 2;
    }
}
