package swiat.rosliny;

import swiat.Organizm;
import swiat.Swiat;

import java.awt.*;

public class Trawa extends Roslina {
    public Trawa(final int polozenieX, final int polozenieY, final int wiek) {
        setNazwa("Trawa");
        setSymbol('T');
        setSila(0);
        setInicjatywa(0);
        setWiek(wiek);
        setPolozenieX(polozenieX);
        setPolozenieY(polozenieY);
        setNiesmiertelnosc(false);
    }


    public Trawa(final Organizm inny) {
        kopiujObiekt(inny);
    }


    @Override
    public Organizm stworzNowySklonowanyObiekt() {
        return new Trawa(this);
    }


    @Override
    public void kolizja(Swiat swiat, Organizm atakujacy) {
        int polozenieX = getPolozenieX(), polozenieY = getPolozenieY(), polozenieXAtak = atakujacy.getPolozenieX(), polozenieYAtak = atakujacy.getPolozenieY();

        setCzyZyje(false);
        swiat.usunOrganizm(this, polozenieX, polozenieY);
        atakujacy.setPolozenieX(polozenieX);
        atakujacy.setPolozenieY(polozenieY);
        swiat.dodajOrganizm(atakujacy, polozenieX, polozenieY);
        swiat.usunOrganizm(atakujacy, polozenieXAtak, polozenieYAtak);
        swiat.wypiszWiadomosc(atakujacy.getNazwa() + " zjada Trawa " + polozenieX + " " + polozenieY);
    }


    @Override
    public Color rysowanie() {
        return Color.green;
    }
}
