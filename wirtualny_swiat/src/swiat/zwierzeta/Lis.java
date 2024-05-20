package swiat.zwierzeta;

import swiat.Organizm;
import swiat.Swiat;

import java.awt.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Lis extends Zwierze {
    Random random = new Random();


    public Lis(final int polozenieX, final int polozenieY, final int wiek) {
        setNazwa("Lis");
        setSymbol('L');
        setSila(3);
        setInicjatywa(7);
        setWiek(wiek);
        setPolozenieX(polozenieX);
        setPolozenieY(polozenieY);
        setNiesmiertelnosc(false);
    }


    public Lis(final Organizm inny) {
        kopiujObiekt(inny);
    }


    @Override
    public Organizm stworzNowySklonowanyObiekt() {
        return new Lis(this);
    }


    @Override
    public void akcja(Swiat swiat) {
        int wymiarMapyX = swiat.getWymiarMapyX(), wymiarMapyY = swiat.getWymiarMapyY(), polozenieX = getPolozenieX(), polozenieY = getPolozenieY();
        List<Integer> mozliweMiejscaX = new ArrayList<>();
        List<Integer> mozliweMiejscaY = new ArrayList<>();
        for (int y = polozenieY - 1; y <= polozenieY + 1; y++) {
            if (y < 0 || y >= wymiarMapyY) continue;
            for (int x = polozenieX - 1; x <= polozenieX + 1; x++) {
                if (x < 0 || x >= wymiarMapyX) continue;
                else if (x == polozenieX && y == polozenieY) continue;
                else if (swiat.getOrganizm(x, y) == null || this.getSila() >= swiat.getOrganizm(x, y).getSila()) {
                mozliweMiejscaX.add(x);
                mozliweMiejscaY.add(y);
                }
            }
        }

        if (mozliweMiejscaX.size() == 0) return;

        int ruch = random.nextInt(mozliweMiejscaX.size());
        int nowyX = mozliweMiejscaX.get(ruch), nowyY = mozliweMiejscaY.get(ruch);

        if (swiat.getOrganizm(nowyX, nowyY) == null) {
            swiat.usunOrganizm(this, polozenieX, polozenieY);
            setPolozenieX(nowyX);
            setPolozenieY(nowyY);
            swiat.dodajOrganizm(this, nowyX, nowyY);
        }

        else if (swiat.getOrganizm(nowyX, nowyY).getSymbol() == swiat.getOrganizm(polozenieX, polozenieY).getSymbol()) {
            Organizm nowyLis = new Lis(this);
            super.kolizja(swiat, nowyLis);
        }

        else {
            swiat.getOrganizm(nowyX, nowyY).kolizja(swiat, this);
        }
    }


    @Override
    public void kolizja(Swiat swiat, Organizm atakujacy) {
        int polozenieX = getPolozenieX(), polozenieY = getPolozenieY(), polozenieXAtak = atakujacy.getPolozenieX(), polozenieYAtak = atakujacy.getPolozenieY();
        boolean czyPrzetrwal = czyOdbilAtak(atakujacy, this);

        if (czyPrzetrwal) {
            swiat.wypiszWiadomosc("Lis zabija " + atakujacy.getNazwa());
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
            swiat.wypiszWiadomosc(atakujacy.getNazwa() + " zabija Lis");
        }
    }


    @Override
    public Color rysowanie() {
        return Color.red;
    }
}
