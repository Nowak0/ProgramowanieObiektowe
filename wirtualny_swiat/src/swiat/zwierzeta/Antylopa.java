package swiat.zwierzeta;

import swiat.Organizm;
import swiat.Swiat;

import java.awt.Color;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;


public class Antylopa extends Zwierze {
    Random random = new Random();

    public Antylopa(final int polozenieX, final int polozenieY, final int wiek) {
        setNazwa("Antylopa");
        setSymbol('A');
        setSila(4);
        setInicjatywa(4);
        setWiek(wiek);
        setPolozenieX(polozenieX);
        setPolozenieY(polozenieY);
        setNiesmiertelnosc(false);
    }


    public Antylopa(final Organizm inny) {
        kopiujObiekt(inny);
    }


    @Override
    public Organizm stworzNowySklonowanyObiekt() {
        return new Antylopa(this);
    }


    @Override
    public void akcja(Swiat swiat) {
        int wymiarMapyX = swiat.getWymiarMapyX(), wymiarMapyY = swiat.getWymiarMapyY(), polozenieX = getPolozenieX(), polozenieY = getPolozenieY();
        List<Integer> mozliweMiejscaX = new ArrayList<>();
        List<Integer> mozliweMiejscaY = new ArrayList<>();

        for (int y = polozenieY - 2; y <= polozenieY + 2; y += 2)
        {
            if (y < 0 || y >= wymiarMapyY) continue;
            for (int x = polozenieX - 2; x <= polozenieX + 2; x+=2)
            {
                if (x < 0 || x >= wymiarMapyX) continue;
                if (x == polozenieX && y == polozenieY) continue;
                mozliweMiejscaX.add(x);
                mozliweMiejscaY.add(y);
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
            Organizm nowaAntylopa = new Antylopa(this);
            super.kolizja(swiat, nowaAntylopa);
        }

        else {
            swiat.getOrganizm(nowyX, nowyY).kolizja(swiat, this);
        }
    }


    @Override
    public void kolizja(Swiat swiat, Organizm atakujacy) {
        int polozenieX = getPolozenieX(), polozenieY = getPolozenieY(), unik = random.nextInt(2);
        int polozenieXAtak = atakujacy.getPolozenieX(), polozenieYAtak = atakujacy.getPolozenieY();

        if (unik == 1) {
            if (unikAntylopy(swiat, atakujacy)) return;
        }

        boolean czyPrzetrwal = czyOdbilAtak(atakujacy, this);
        if (czyPrzetrwal) {
            swiat.wypiszWiadomosc("Antylopa zabija " + atakujacy.getNazwa() + " " + polozenieX + " " + polozenieY);
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
            swiat.wypiszWiadomosc(atakujacy.getNazwa() + " zabija Antylopa " + polozenieX + " " + polozenieY);
        }
    }


    public boolean unikAntylopy(Swiat swiat, Organizm atakujacy) {
        int polozenieX = getPolozenieX(), polozenieY = getPolozenieY(), polozenieXAtak = atakujacy.getPolozenieX(), polozenieYAtak = atakujacy.getPolozenieY();
        for (int y = polozenieY - 1; y <= polozenieY + 1; y++)
        {
            if (y < 0 || y >= swiat.getWymiarMapyY()) continue;
            for (int x = polozenieX - 1; x <= polozenieX + 1; x++)
            {
                if (x < 0 || x >= swiat.getWymiarMapyX()) continue;
                if (swiat.getOrganizm(x, y) == null) {
                    swiat.usunOrganizm(this, polozenieX, polozenieY);
                    setPolozenieX(x);
                    setPolozenieY(y);
                    atakujacy.setPolozenieX(polozenieX);
                    atakujacy.setPolozenieY(polozenieY);
                    swiat.dodajOrganizm(this, x, y);
                    swiat.dodajOrganizm(atakujacy, polozenieX, polozenieY);
                    swiat.usunOrganizm(atakujacy, polozenieXAtak, polozenieYAtak);
                    swiat.wypiszWiadomosc("Antylopa unika ataku " + atakujacy.getNazwa() + " " + polozenieX + " " + polozenieY);
                    return true;
                }
            }
        }
        return false;
    }


    @Override
    public Color rysowanie() {
        return Color.orange;
    }
}
