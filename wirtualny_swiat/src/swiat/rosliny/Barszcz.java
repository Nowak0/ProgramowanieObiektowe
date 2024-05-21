package swiat.rosliny;

import swiat.Organizm;
import swiat.Swiat;

import java.awt.*;
import java.util.Objects;

public class Barszcz extends Roslina {
    public Barszcz(final int polozenieX, final int polozenieY, final int wiek) {
        setNazwa("BarszczSosnowskiego");
        setSymbol('B');
        setSila(10);
        setInicjatywa(0);
        setWiek(wiek);
        setPolozenieX(polozenieX);
        setPolozenieY(polozenieY);
        setNiesmiertelnosc(false);
    }


    public Barszcz(final Organizm inny) {
        kopiujObiekt(inny);
    }


    @Override
    public Organizm stworzNowySklonowanyObiekt() {
        return new Barszcz(this);
    }


    @Override
    public void akcja(Swiat swiat) {
        int wymiarMapyX = swiat.getWymiarMapyX(), wymiarMapyY = swiat.getWymiarMapyY(), polozenieX = getPolozenieX(), polozenieY = getPolozenieY();
        for (int y = polozenieY - 1; y <= polozenieY + 1; y++)
        {
            if (y < 0 || y >= wymiarMapyY) continue;
            for (int x = polozenieX - 1; x <= polozenieX + 1; x++)
            {
                if (x < 0 || x >= wymiarMapyX) continue;
                else if (x == polozenieX && y == polozenieY || swiat.getOrganizm(x, y) == null) continue;
                else if (swiat.getOrganizm(x, y).getSila() > 0 && !(swiat.getOrganizm(x, y) instanceof WilczeJagody) && !swiat.getOrganizm(x, y).czyNiesmiertelny()) {
                    int tmpX = swiat.getOrganizm(x, y).getPolozenieX();
                    int tmpY = swiat.getOrganizm(x, y).getPolozenieY();
                    swiat.getOrganizm(x, y).setCzyZyje(false);
                    swiat.wypiszWiadomosc(swiat.getOrganizm(x, y).getNazwa() + " zostaje zabity");
                    swiat.wypiszWiadomosc("przez Barszcz Sosnowskiego"  + " " + tmpX + " " + tmpY);
                    swiat.usunOrganizm(swiat.getOrganizm(x, y), x, y);
                }
            }
        }
    }


    @Override
    public void kolizja(Swiat swiat, Organizm atakujacy) {
        int polozenieX = getPolozenieX(), polozenieY = getPolozenieY(), polozenieXAtak = atakujacy.getPolozenieX(), polozenieYAtak = atakujacy.getPolozenieY();

        setCzyZyje(false);
        swiat.usunOrganizm(this, polozenieX, polozenieY);
        swiat.wypiszWiadomosc(atakujacy.getNazwa() + " zjada Barszcz Sosnowskiego" + polozenieX + " " + polozenieY );

        if (!atakujacy.czyNiesmiertelny()) {
            atakujacy.setCzyZyje(false);
            swiat.usunOrganizm(atakujacy, polozenieXAtak, polozenieYAtak);
            swiat.wypiszWiadomosc("i umiera w wyniku jego zjedzenia");
        }
    }


    @Override
    public Color rysowanie() {
        return Color.MAGENTA;
    }
}
