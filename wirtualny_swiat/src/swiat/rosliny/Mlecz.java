package swiat.rosliny;

import swiat.Organizm;
import swiat.Swiat;

import java.awt.Color;

public class Mlecz extends Roslina {
    public Mlecz(final int polozenieX, final int polozenieY, final int wiek) {
        setNazwa("Mlecz");
        setSymbol('M');
        setSila(0);
        setInicjatywa(0);
        setWiek(wiek);
        setPolozenieX(polozenieX);
        setPolozenieY(polozenieY);
        setNiesmiertelnosc(false);
    }


    public Mlecz(final Organizm inny) {
        kopiujObiekt(inny);
    }


    @Override
    public Organizm stworzNowySklonowanyObiekt() {
        return new Mlecz(this);
    }


    @Override
    public void akcja(Swiat swiat) {
        super.akcja(swiat);
        super.akcja(swiat);
        super.akcja(swiat);
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
        swiat.wypiszWiadomosc(atakujacy.getNazwa() + " zjada Mlecz " + polozenieX + " " + polozenieY);
    }


    @Override
    public Color rysowanie() {
        return Color.yellow;
    }
}
