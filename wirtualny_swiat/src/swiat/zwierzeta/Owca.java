package swiat.zwierzeta;

import swiat.Organizm;
import swiat.Swiat;

import java.awt.*;

public class Owca extends Zwierze {
    public Owca(final int polozenieX, final int polozenieY, final int wiek) {
        setNazwa("Owca");
        setSymbol('O');
        setSila(4);
        setInicjatywa(4);
        setWiek(wiek);
        setPolozenieX(polozenieX);
        setPolozenieY(polozenieY);
        setNiesmiertelnosc(false);
    }


    public Owca(final Organizm inny) {
        kopiujObiekt(inny);
    }


    @Override
    public Organizm stworzNowySklonowanyObiekt() {
        return new Owca(this);
    }


    @Override
    public void kolizja(Swiat swiat, Organizm atakujacy) {
        if(atakujacy instanceof Owca) {
            super.kolizja(swiat, atakujacy);
            return;
        }

        int polozenieX = getPolozenieX(), polozenieY = getPolozenieY(), polozenieXAtak = atakujacy.getPolozenieX(), polozenieYAtak = atakujacy.getPolozenieY();
        boolean czyPrzetrwal = czyOdbilAtak(atakujacy, this);

        if (czyPrzetrwal) {
            swiat.wypiszWiadomosc("Owca zabija " + atakujacy.getNazwa() + wypiszPolozenie(polozenieX,polozenieY));
            atakujacy.setCzyZyje(false);
            swiat.usunOrganizm(atakujacy, polozenieXAtak, polozenieYAtak);
        }
        else {
            setCzyZyje(false);
            swiat.usunOrganizm(this, polozenieX, polozenieY);
            atakujacy.setPolozenieX(polozenieX);
            atakujacy.setPolozenieY(polozenieY);
            swiat.dodajOrganizm(atakujacy, polozenieX, polozenieY);
            swiat.usunOrganizm(atakujacy, polozenieXAtak, polozenieYAtak);
            swiat.wypiszWiadomosc(atakujacy.getNazwa() + " zabija Owca" + wypiszPolozenie(polozenieX,polozenieY));
        }
    }


    @Override
    public Color rysowanie() {
        return Color.WHITE;
    }
}
