package swiat;

import java.util.ArrayList;
import java.util.List;

import swiat.zwierzeta.*;
import swiat.rosliny.*;

public class Swiat {
    private int wymiarMapyX;
    private int wymiarMapyY;
    private int liczbaWiadomosci;
    private List<Organizm> posortowaneOrganizmy;
    private List<List<Organizm>> organizmy;

    //private void UsunOrganizmZPosortowanych(Organizm organizm);
    //private void usunNull(final int i );
    //private void dodajOrganizmDoPosortowanych(Organizm organizm);
    public Swiat(final int x, final int y) {
        this.wymiarMapyX = x;
        this.wymiarMapyY = y;
        this.liczbaWiadomosci = 0;
        this.posortowaneOrganizmy = new ArrayList<>();
        uaktualnijGraniceMapy();
    }

    public void uaktualnijGraniceMapy() {
        organizmy = new ArrayList<>(wymiarMapyY);
        for (int i = 0; i < wymiarMapyY; i++) {
            List<Organizm> wiersz = new ArrayList<>(wymiarMapyX);
            for (int j = 0; j < wymiarMapyX; j++) {
                wiersz.add(null);
            }
            organizmy.add(wiersz);
        }
    }

    public void wykonajTure() {
        liczbaWiadomosci = 0;
        List<Organizm> tmp = new ArrayList<>();

        for (Organizm o : posortowaneOrganizmy) {
            tmp.add(o);
            if (o instanceof Czlowiek) {
            }//sprawdzNiesmiertelnosc(o);
        }

        for (Organizm o : tmp) {
            if (o != null && o.getCzyZyje()) o.akcja(this);
        }
    }

    public void rysujSwiat() {

    }

    public int getWymiarMapyX() {
        return wymiarMapyX;
    }

    public int getWymiarMapyY() {
        return wymiarMapyY;
    }

    public int getLiczbaWiadomosci() {
        return liczbaWiadomosci;
    }

    public int getLiczbaOrganizmow() {
        return posortowaneOrganizmy.size();
    }

    Organizm getOrganizm(final int polozenieX, final int polozenieY) {
        return organizmy.get(polozenieY).get(polozenieX);
    }

    void setWymiarMapyX(final int wymiar) {
        this.wymiarMapyX = wymiar;
    }

    void setWymiarMapyY(final int wymiar) {
        this.wymiarMapyY = wymiar;
    }

    void setLiczbaWiadomosci() {
        liczbaWiadomosci++;
    }

    void dodajOrganizm(Organizm organizm, int polozenieX, int polozenieY) {
        organizmy.get(polozenieY).set(polozenieX, organizm);
        dodajOrganizmDoPosortowanych(organizm);
    }

    void dodajOrganizmDoPosortowanych(Organizm organizm) {
        if (organizm == null) return;

        int n = posortowaneOrganizmy.size();
        int i = 0, inicjatywaOrganizmu = organizm.getInicjatywa(), wiekOrganizmu = organizm.getWiek();
        for (Organizm o : posortowaneOrganizmy) {
            if (o == organizm) continue;
            if (inicjatywaOrganizmu > o.getInicjatywa()) {
                posortowaneOrganizmy.add(i, organizm);
                return;
            } else if (inicjatywaOrganizmu == o.getInicjatywa() && wiekOrganizmu < o.getWiek()) {
                posortowaneOrganizmy.add(i, organizm);
                return;
            }
            i++;
        }

        posortowaneOrganizmy.add(organizm);
    }

    void usunOrganizm(Organizm organizm, final int polozenieX, final int polozenieY) {
        usunOrganizmZPosortowanych(organizm);
        organizmy.get(polozenieY).set(polozenieX, null);
    }

    void usunOrganizmZPosortowanych(Organizm organizm) {
        int i = 0;
        for (Organizm o : posortowaneOrganizmy) {
            if (o != null && o == organizm) {
                posortowaneOrganizmy.remove(i);
                break;
            }
            i++;
        }
    }

    void wypiszWiadomosc(String wiadomomosc) {
        if (getLiczbaWiadomosci() > getWymiarMapyY()) liczbaWiadomosci = 0;
        //jakas graficzna zmiana
        System.out.println(wiadomomosc);
        setLiczbaWiadomosci();
    }

    void sprawdzNiesmiertelnosc(Organizm organizm) {
        organizm.sprawdzLiczenieTur();
        if (organizm.czyNiesmiertelny()) wypiszWiadomosc("niesmiertelnosc aktywna");
        else wypiszWiadomosc("niesmiertelnosc nieaktywna");
    }

}
