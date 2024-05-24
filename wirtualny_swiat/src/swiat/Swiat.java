package swiat;

import java.awt.*;
import javax.swing.*;
import java.util.*;
import java.util.List;

import swiat.grafika.*;
import swiat.zwierzeta.*;
import swiat.rosliny.*;


public class Swiat {
    private int wymiarMapyX;
    private int wymiarMapyY;
    private final int maxWymiarMapyX = 22;
    private final int maxWymiarMapyY = 28;
    private final int BRAK_RUCHU = -1;
    private boolean czlowiekZyje;
    private List<Organizm> posortowaneOrganizmy;
    private List<List<Organizm>> organizmy;
    private List<String> wiadomosci;
    private JFrame wyswietlanie;
    private Plansza plansza;


    public Swiat(final int x, final int y) {
        ustawianieRozmiaruMapy(x,y);
        this.czlowiekZyje = false;
        this.posortowaneOrganizmy = new ArrayList<>();
        this.wyswietlanie = new JFrame();
        this.wiadomosci = new ArrayList<>();
        uaktualnijGraniceMapy();
        List<Organizm> noweOrganizmy = new ArrayList<>();
        dodajOrganizmyRecznie(noweOrganizmy);
        dodajOrganizmyDoSwiataLosowo(noweOrganizmy);
    }


    public void ustawianieRozmiaruMapy(final int x, final int y) {
        this.wymiarMapyX = Math.min(x, maxWymiarMapyX);
        this.wymiarMapyY = Math.min(y, maxWymiarMapyY);
    }


    public void uaktualnijGraniceMapy() {
        if(organizmy!=null) posortowaneOrganizmy.clear();
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
        wiadomosci.clear();
        List<Organizm> tmp = new ArrayList<>();
        if (ruchCzlowieka != BRAK_RUCHU) ustawianieRuchuCzlowieka(ruchCzlowieka);

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
        wyswietlanie.setTitle("Wirtualny Swiat Jakub Nowak 197860");
        wyswietlanie.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        wyswietlanie.setSize(1920, 1080);
        wyswietlanie.setLayout(new GridLayout(1, 1, 0, 0));
        wyswietlanie.add(new SterowanieGra(this));
        plansza = new Plansza(this, organizmy);
        wyswietlanie.add(plansza);
        wyswietlanie.setVisible(true);
    }


    public int getWymiarMapyX() {
        return wymiarMapyX;
    }


    public int getWymiarMapyY() {
        return wymiarMapyY;
    }


    public int getLiczbaOrganizmow() {
        return posortowaneOrganizmy.size();
    }


    public Organizm getPosortowanyOrganizm(final int i) {
        return posortowaneOrganizmy.get(i);
    }

    public Organizm getOrganizm(final int polozenieX, final int polozenieY) {
        return organizmy.get(polozenieY).get(polozenieX);
    }


    public boolean czyCzlowiekZyje() {
        return czlowiekZyje;
    }


    public void dodajOrganizm(Organizm organizm, int polozenieX, int polozenieY) {
        if (organizm == null) return;

        if (organizm instanceof Czlowiek) czlowiekZyje = true;
        organizm.setCzyZyje(true);
        organizmy.get(polozenieY).set(polozenieX, organizm);
        dodajOrganizmDoPosortowanych(organizm);
    }


    public void dodajOrganizmDoPosortowanych(Organizm organizm) {
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


    public void usunOrganizm(Organizm organizm, final int polozenieX, final int polozenieY) {
        if (organizm instanceof Czlowiek && !organizm.getCzyZyje()) czlowiekZyje = false;
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
        wiadomosci.add(wiadomosc);
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

        for (Organizm o : posortowaneOrganizmy) {
            if (o instanceof Czlowiek) return o;
        }

        return null;
    }


    public void ustawianieRuchuCzlowieka(int kierunek) {
        for (Organizm o : posortowaneOrganizmy) {
            if (o instanceof Czlowiek) ((Czlowiek) o).setRuchCzlowieka(kierunek);
        }
    }


    public int getIloscWiadomosci() {
        return wiadomosci.size();
    }


    public void uaktualnijStanGry() {
        plansza.uaktualnijOrganizmy(organizmy);
        wyswietlanie.repaint();
    }


    public void dodajOrganizmyZapis(String[] elementy) {
        Organizm nowy;
        switch (elementy[0]) {
            case "Antylopa":
                nowy = new Antylopa(Integer.parseInt(elementy[4]), Integer.parseInt(elementy[5]), Integer.parseInt(elementy[6]));
                nowy.setNiesmiertelnosc((Objects.equals(elementy[7], "true")));
                dodajOrganizm(nowy, nowy.getPolozenieX(), nowy.getPolozenieY());
                break;
            case "Czlowiek":
                nowy = new Czlowiek(Integer.parseInt(elementy[4]), Integer.parseInt(elementy[5]), Integer.parseInt(elementy[6]));
                nowy.setNiesmiertelnosc((Objects.equals(elementy[7], "true")));
                ((Czlowiek) nowy).setLicznikTur(Integer.parseInt(elementy[8]));
                ((Czlowiek) nowy).setCzyMoznaAktywowacNiesmiertelnosc((Objects.equals(elementy[9], "true")));
                dodajOrganizm(nowy, nowy.getPolozenieX(), nowy.getPolozenieY());
                break;
            case "Lis":
                nowy = new Lis(Integer.parseInt(elementy[4]), Integer.parseInt(elementy[5]), Integer.parseInt(elementy[6]));
                nowy.setNiesmiertelnosc((Objects.equals(elementy[7], "true")));
                dodajOrganizm(nowy, nowy.getPolozenieX(), nowy.getPolozenieY());
                break;
            case "Owca":
                nowy = new Owca(Integer.parseInt(elementy[4]), Integer.parseInt(elementy[5]), Integer.parseInt(elementy[6]));
                nowy.setNiesmiertelnosc((Objects.equals(elementy[7], "true")));
                dodajOrganizm(nowy, nowy.getPolozenieX(), nowy.getPolozenieY());
                break;
            case "Wilk":
                nowy = new Wilk(Integer.parseInt(elementy[4]), Integer.parseInt(elementy[5]), Integer.parseInt(elementy[6]));
                nowy.setNiesmiertelnosc((Objects.equals(elementy[7], "true")));
                dodajOrganizm(nowy, nowy.getPolozenieX(), nowy.getPolozenieY());
                break;
            case "Zolw":
                nowy = new Zolw(Integer.parseInt(elementy[4]), Integer.parseInt(elementy[5]), Integer.parseInt(elementy[6]));
                nowy.setNiesmiertelnosc((Objects.equals(elementy[7], "true")));
                dodajOrganizm(nowy, nowy.getPolozenieX(), nowy.getPolozenieY());
                break;
            case "BarszczSosnowskiego":
                nowy = new Barszcz(Integer.parseInt(elementy[4]), Integer.parseInt(elementy[5]), Integer.parseInt(elementy[6]));
                nowy.setNiesmiertelnosc((Objects.equals(elementy[7], "true")));
                dodajOrganizm(nowy, nowy.getPolozenieX(), nowy.getPolozenieY());
                break;
            case "Guarana":
                nowy = new Guarana(Integer.parseInt(elementy[4]), Integer.parseInt(elementy[5]), Integer.parseInt(elementy[6]));
                nowy.setNiesmiertelnosc((Objects.equals(elementy[7], "true")));
                dodajOrganizm(nowy, nowy.getPolozenieX(), nowy.getPolozenieY());
                break;
            case "Mlecz":
                nowy = new Mlecz(Integer.parseInt(elementy[4]), Integer.parseInt(elementy[5]), Integer.parseInt(elementy[6]));
                nowy.setNiesmiertelnosc((Objects.equals(elementy[7], "true")));
                dodajOrganizm(nowy, nowy.getPolozenieX(), nowy.getPolozenieY());
                break;
            case "Trawa":
                nowy = new Trawa(Integer.parseInt(elementy[4]), Integer.parseInt(elementy[5]), Integer.parseInt(elementy[6]));
                nowy.setNiesmiertelnosc((Objects.equals(elementy[7], "true")));
                dodajOrganizm(nowy, nowy.getPolozenieX(), nowy.getPolozenieY());
                break;
            case "WilczeJagody":
                nowy = new WilczeJagody(Integer.parseInt(elementy[4]), Integer.parseInt(elementy[5]), Integer.parseInt(elementy[6]));
                nowy.setNiesmiertelnosc((Objects.equals(elementy[7], "true")));
                dodajOrganizm(nowy, nowy.getPolozenieX(), nowy.getPolozenieY());
                break;

        }
    }


    public void dodajOrganizmyDoSwiataLosowo(List<Organizm> noweOrganizmy) {
        Random random = new Random();
        int wolneMiejsca = getWymiarMapyX() * getWymiarMapyY();

        for (Organizm o : noweOrganizmy) {
            boolean dodano = false;

            while (!dodano && wolneMiejsca > 0)
            {
                int polozenieX = random.nextInt(getWymiarMapyX());
                int polozenieY = random.nextInt(getWymiarMapyY());
                if (getOrganizm(polozenieX, polozenieY) == null) {
                    o.setPolozenieX(polozenieX);
                    o.setPolozenieY(polozenieY);
                    o.setWiek(getLiczbaOrganizmow() + 1);
                    dodajOrganizm(o, o.getPolozenieX(), o.getPolozenieY());
                    wolneMiejsca--;
                    dodano = true;
                }
            }
        }
    }


    public void dodajOrganizmyDoSwiataLosowo(Organizm organizm) {
        Random random = new Random();
        int wolneMiejsca = getWymiarMapyX() * getWymiarMapyY();
        boolean dodano = false;

        while (!dodano && wolneMiejsca > 0)
        {
            int x = random.nextInt(getWymiarMapyX());
            int y = random.nextInt(getWymiarMapyY());
            if (getOrganizm(x, y) == null) {
                organizm.setPolozenieX(x);
                organizm.setPolozenieY(y);
                organizm.setWiek(getLiczbaOrganizmow() + 1);
                dodajOrganizm(organizm, organizm.getPolozenieX(), organizm.getPolozenieY());
                wolneMiejsca--;
                dodano = true;
                wyswietlanie.repaint();
                JOptionPane.showMessageDialog(
                        null,
                        "Dodano " + organizm.getNazwa() + " na pozycji " + x + " " + y,
                        null,
                        JOptionPane.INFORMATION_MESSAGE);
            }
        }
    }


    public void dodajOrganizmyRecznie(List<Organizm> noweOrganizmy) {
        noweOrganizmy.add(new Czlowiek(0, 0, 0));
        noweOrganizmy.add(new Lis(0, 0, 0));
        noweOrganizmy.add(new Antylopa(0, 0, 0));
        noweOrganizmy.add(new Zolw(0, 0, 0));
        noweOrganizmy.add(new Owca(0, 0, 0));
        noweOrganizmy.add(new Trawa(0, 0, 0));
        noweOrganizmy.add(new Barszcz(0, 0, 0));
        noweOrganizmy.add(new Guarana(0, 0, 0));
        noweOrganizmy.add(new Guarana(0, 0, 0));
        noweOrganizmy.add(new Mlecz(0, 0, 0));
        noweOrganizmy.add(new Mlecz(0, 0, 0));
        noweOrganizmy.add(new Wilk(0, 0, 0));
        noweOrganizmy.add(new WilczeJagody(0, 0, 0));
    }
}
