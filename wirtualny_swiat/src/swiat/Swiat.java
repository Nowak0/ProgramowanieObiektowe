package swiat;

import java.awt.*;
import javax.swing.*;
import java.util.ArrayList;
import java.util.List;

import swiat.grafika.*;
import swiat.zwierzeta.Czlowiek;

public class Swiat {
    private int wymiarMapyX;
    private int wymiarMapyY;
    private int liczbaWiadomosci;
    public final int BRAK_RUCHU = -1;
    public final int BRAK_CZLOWIEKA = -1;
    public final int RUCH_PRAWO = 1;
    public final int RUCH_LEWO = 2;
    public final int RUCH_GORA = 3;
    public final int RUCH_DOL = 4;
    private boolean czlowiekZyje;
    private List<Organizm> posortowaneOrganizmy;
    private List<List<Organizm>> organizmy;
    private List<String> wiadomosci;
    public JFrame wyswietlanie;


    public Swiat(final int x, final int y) {
        this.wymiarMapyX = x;
        this.wymiarMapyY = y;
        this.czlowiekZyje = false;
        this.liczbaWiadomosci = 0;
        this.posortowaneOrganizmy = new ArrayList<>();
        this.wyswietlanie = new JFrame();
        this.wiadomosci = new ArrayList<>();
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


    public void wykonajTure(int ruchCzlowieka) {
        liczbaWiadomosci = 0;
        wiadomosci.clear();
        List<Organizm> tmp = new ArrayList<>();
        if(ruchCzlowieka != BRAK_RUCHU) ustawianieRuchuCzlowieka(ruchCzlowieka);

        for (Organizm o : posortowaneOrganizmy) {
            tmp.add(o);
            if (o instanceof Czlowiek) sprawdzNiesmiertelnosc(o);
        }

        for (Organizm o : tmp) {
            if (o != null && o.getCzyZyje()) o.akcja(this);
        }

        wyswietlanie.repaint();
    }


    public void rysujSwiat() {
        Ekran ekran = new Ekran(wyswietlanie, this,organizmy);
        InfoObokEkranu info = new InfoObokEkranu(this);
        wyswietlanie.setTitle("Wirtualny Swiat Jakub Nowak 197860");
        wyswietlanie.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        wyswietlanie.setLayout(new GridLayout(1,1,0,0));
        wyswietlanie.setSize(1920,1080);
        wyswietlanie.add(ekran);
        wyswietlanie.add(info);
        ekran.setVisible(true);
        info.setVisible(true);
        wyswietlanie.setVisible(true);
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


    public Organizm getOrganizm(final int polozenieX, final int polozenieY) {
        return organizmy.get(polozenieY).get(polozenieX);
    }


    public boolean czyCzlowiekZyje() {
        return czlowiekZyje;
    }


    public void setWymiarMapyX(final int wymiar) {
        this.wymiarMapyX = wymiar;
    }


    public void setWymiarMapyY(final int wymiar) {
        this.wymiarMapyY = wymiar;
    }


    public void setLiczbaWiadomosci() {
        liczbaWiadomosci++;
    }


    public void dodajOrganizm(Organizm organizm, int polozenieX, int polozenieY) {
        if (organizm instanceof Czlowiek) czlowiekZyje = true;
        organizm.setCzyZyje(true);
        organizmy.get(polozenieY).set(polozenieX, organizm);
        dodajOrganizmDoPosortowanych(organizm);
    }


    public void dodajOrganizmDoPosortowanych(Organizm organizm) {
        if (organizm == null) return;

        int n = posortowaneOrganizmy.size();
        int i = 0, inicjatywaOrganizmu = organizm.getInicjatywa(), wiekOrganizmu = organizm.getWiek();
        for (Organizm o : posortowaneOrganizmy) {
            if (o == organizm) continue;
            if (inicjatywaOrganizmu > o.getInicjatywa()) {
                posortowaneOrganizmy.add(i, organizm);
                return;
            }
            else if (inicjatywaOrganizmu == o.getInicjatywa() && wiekOrganizmu < o.getWiek()) {
                posortowaneOrganizmy.add(i, organizm);
                return;
            }
            i++;
        }

        posortowaneOrganizmy.add(organizm);
    }


    public void usunOrganizm(Organizm organizm, final int polozenieX, final int polozenieY) {
        if (organizm instanceof Czlowiek) czlowiekZyje = false;
        usunOrganizmZPosortowanych(organizm);
        organizmy.get(polozenieY).set(polozenieX, null);
    }


    public void usunOrganizmZPosortowanych(Organizm organizm) {
        int i = 0;
        for (Organizm o : posortowaneOrganizmy) {
            if (o != null && o == organizm) {
                posortowaneOrganizmy.remove(i);
                break;
            }
            i++;
        }
    }


    public void wypiszWiadomosc(String wiadomosc) {
        if (getLiczbaWiadomosci() > getWymiarMapyY()) liczbaWiadomosci = 0;
        //jakas graficzna zmiana
        System.out.println(wiadomosc);
        wiadomosci.add(wiadomosc);
        setLiczbaWiadomosci();
    }


    public String getWiadomosci(int indeks) {
        return wiadomosci.get(indeks);
    }


    public void sprawdzNiesmiertelnosc(Organizm organizm) {
        ((Czlowiek) organizm).sprawdzLiczenieTur();
        if (organizm.czyNiesmiertelny()) wypiszWiadomosc("niesmiertelnosc aktywna");
        else wypiszWiadomosc("niesmiertelnosc nieaktywna");
    }


    public Organizm znajdzCzlowieka() {
        if (!czlowiekZyje) return null;

        int i = 0;
        for (Organizm o : posortowaneOrganizmy) {
            if (o instanceof Czlowiek) return o;
            i++;
        }

        return null;
    }


    public void ustawianieRuchuCzlowieka(int kierunek) {
        for (Organizm o : posortowaneOrganizmy) {
            if(o instanceof Czlowiek) ((Czlowiek) o).setRuchCzlowieka(kierunek);
        }
    }
}
