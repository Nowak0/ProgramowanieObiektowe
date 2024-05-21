package swiat.rosliny;

import swiat.Organizm;
import swiat.Swiat;

import java.awt.Color;

public class Guarana extends Roslina {
    public Guarana(final int polozenieX, final int polozenieY, final int wiek) {
        setNazwa("Guarana");
        setSymbol('G');
        setSila(0);
        setInicjatywa(0);
        setWiek(wiek);
        setPolozenieX(polozenieX);
        setPolozenieY(polozenieY);
        setNiesmiertelnosc(false);
    }


    public Guarana(final Organizm inny) {
       kopiujObiekt(inny);
    }


    @Override
    public Organizm stworzNowySklonowanyObiekt() {
        return new Guarana(this);
    }


    @Override
    public void kolizja(Swiat swiat, Organizm atakujacy) {
        int silaAtakujacego = atakujacy.getSila();
        int polozenieX = getPolozenieX(), polozenieY = getPolozenieY(), polozenieXAtak = atakujacy.getPolozenieX(), polozenieYAtak = atakujacy.getPolozenieY();

        setCzyZyje(false);
        swiat.usunOrganizm(this, polozenieX, polozenieY);
        atakujacy.setPolozenieX(polozenieX);
        atakujacy.setPolozenieY(polozenieY);
        atakujacy.setSila(silaAtakujacego + 3);
        swiat.dodajOrganizm(atakujacy, polozenieX, polozenieY);
        swiat.usunOrganizm(atakujacy, polozenieXAtak, polozenieYAtak);
        swiat.wypiszWiadomosc(atakujacy.getNazwa() + " zjada Guarana " + polozenieX + " " + polozenieY);
    }


    @Override
    public Color rysowanie() {
        return Color.pink;
    }
}
