package swiat.zwierzeta;

import swiat.Organizm;
import swiat.Swiat;

import java.awt.*;
import java.util.Random;

public class Zolw extends Zwierze {
    public Zolw(final int polozenieX, final int polozenieY, final int wiek) {
        setNazwa("Zolw");
        setSymbol('Z');
        setSila(2);
        setInicjatywa(1);
        setWiek(wiek);
        setPolozenieX(polozenieX);
        setPolozenieY(polozenieY);
        setNiesmiertelnosc(false);
    }


    public Zolw(final Organizm inny) {
        kopiujObiekt(inny);
    }


    @Override
    public Organizm stworzNowySklonowanyObiekt() {
        return new Zolw(this);
    }


    @Override
    public void akcja(Swiat swiat) {
        Random random = new Random();
        int ruch = random.nextInt(101);
        if (ruch <= 75) return;
        else super.akcja(swiat);
    }


    @Override
    public void kolizja(Swiat swiat, Organizm atakujacy) {
        if(atakujacy instanceof Zolw) {
            super.kolizja(swiat, atakujacy);
            return;
        }

        int polozenieX = getPolozenieX(), polozenieY = getPolozenieY();
        int polozenieXAtak = atakujacy.getPolozenieX(), polozenieYAtak = atakujacy.getPolozenieY();
        boolean czyPrzetrwal = czyOdbilAtak(atakujacy, this);

        if (czyPrzetrwal) {
            swiat.wypiszWiadomosc("Zolw odpiera atak " + atakujacy.getNazwa() + " " + polozenieX + " " + polozenieY);
        }
        else {
            setCzyZyje(false);
            swiat.usunOrganizm(this, polozenieX, polozenieY);
            atakujacy.setPolozenieX(polozenieX);
            atakujacy.setPolozenieY(polozenieY);
            swiat.dodajOrganizm(atakujacy, polozenieX, polozenieY);
            swiat.usunOrganizm(atakujacy, polozenieXAtak, polozenieYAtak);
            swiat.wypiszWiadomosc(atakujacy.getNazwa() + " zabija Zolw  " + polozenieX + " " + polozenieY);
        }
    }


    @Override
    public Color rysowanie() {
        return Color.getHSBColor(150/360.0f,1.0f,0.5f);
    }


    @Override
    public boolean czyOdbilAtak(Organizm atakujacy, Organizm atakowany) {
        int silaAtakujacego = atakujacy.getSila();
        return silaAtakujacego < 5;
    }
}
