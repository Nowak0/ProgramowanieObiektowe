package swiat.zwierzeta;

import swiat.Organizm;
import swiat.Swiat;

import java.awt.Color;

public class Wilk extends Zwierze {
    public Wilk(final int polozenieX, final int polozenieY, final int wiek) {
        setNazwa("Wilk");
        setSymbol('W');
        setSila(9);
        setInicjatywa(5);
        setWiek(wiek);
        setPolozenieX(polozenieX);
        setPolozenieY(polozenieY);
        setNiesmiertelnosc(false);
    }


    public Wilk(final Organizm inny) {
        kopiujObiekt(inny);
    }


    @Override
    public Organizm stworzNowySklonowanyObiekt() {
        return new Wilk(this);
    }


    @Override
    public void kolizja(Swiat swiat, Organizm atakujacy) {
        if(atakujacy instanceof Wilk) {
            super.kolizja(swiat, atakujacy);
            return;
        }

        int polozenieX = getPolozenieX(), polozenieY = getPolozenieY(), polozenieXAtak = atakujacy.getPolozenieX(), polozenieYAtak = atakujacy.getPolozenieY();
        boolean czyPrzetrwal = czyOdbilAtak(atakujacy, this);

        if (czyPrzetrwal) {
            atakujacy.setCzyZyje(false);
            swiat.wypiszWiadomosc("Wilk zabija " + atakujacy.getNazwa() + wypiszPolozenie(polozenieX,polozenieY));
            swiat.usunOrganizm(atakujacy, polozenieXAtak, polozenieYAtak);
        }

        else {
            setCzyZyje(false);
            swiat.usunOrganizm(this, polozenieX, polozenieY);
            atakujacy.setPolozenieX(polozenieX);
            atakujacy.setPolozenieY(polozenieY);
            swiat.dodajOrganizm(atakujacy, polozenieX, polozenieY);
            swiat.usunOrganizm(atakujacy, polozenieXAtak, polozenieYAtak);
            swiat.wypiszWiadomosc(atakujacy.getNazwa() + " zabija Wilk" + wypiszPolozenie(polozenieX,polozenieY));
        }
    }


    @Override
    public Color rysowanie() {
        return Color.darkGray;
    }
}
