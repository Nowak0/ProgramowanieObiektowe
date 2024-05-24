package swiat.rosliny;

import swiat.Organizm;
import swiat.Swiat;

import java.awt.Color;

public class WilczeJagody extends Roslina {
    public WilczeJagody(final int polozenieX, final int polozenieY, final int wiek) {
        setNazwa("WilczeJagody");
        setSymbol('J');
        setSila(99);
        setInicjatywa(0);
        setWiek(wiek);
        setPolozenieX(polozenieX);
        setPolozenieY(polozenieY);
        setNiesmiertelnosc(false);
    }


    public WilczeJagody(final Organizm inny) {
        kopiujObiekt(inny);
    }


    @Override
    public Organizm stworzNowySklonowanyObiekt() {
        return new WilczeJagody(this);
    }


    @Override
    public void kolizja(Swiat swiat, Organizm atakujacy) {
        int polozenieX = getPolozenieX(), polozenieY = getPolozenieY(), polozenieXAtak = atakujacy.getPolozenieX(), polozenieYAtak = atakujacy.getPolozenieY();

        setCzyZyje(false);
        swiat.usunOrganizm(this, polozenieX, polozenieY);
        swiat.wypiszWiadomosc(atakujacy.getNazwa() + " zjada Wilcze Jagody" + wypiszPolozenie(polozenieX,polozenieY));

        if (!atakujacy.czyNiesmiertelny()) {
            atakujacy.setCzyZyje(false);
            swiat.usunOrganizm(atakujacy, polozenieXAtak, polozenieYAtak);
            swiat.wypiszWiadomosc("i umiera w wyniku ich zjedzenia");
        }
    }


    @Override
    public Color rysowanie() {
        return Color.blue;
    }
}
