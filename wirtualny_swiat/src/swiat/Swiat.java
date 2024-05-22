package swiat;

import java.awt.*;
import javax.swing.*;
import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Objects;

import swiat.grafika.*;
import swiat.zwierzeta.*;
import swiat.rosliny.*;


public class Swiat {
    private int wymiarMapyX;
    private int wymiarMapyY;
    private final int BRAK_RUCHU = -1;
    private boolean czlowiekZyje;
    private List<Organizm> posortowaneOrganizmy;
    private List<List<Organizm>> organizmy;
    private List<String> wiadomosci;
    private final String plikZapisu = ".\\src\\swiat\\zapis.txt";
    public JFrame wyswietlanie;


    public Swiat(final int x, final int y) {
        this.wymiarMapyX = x;
        this.wymiarMapyY = y;
        this.czlowiekZyje = false;
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
        wyswietlanie.add(new Sterowanie(this));
        wyswietlanie.add(new Plansza(this, organizmy));
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


    public void dodajOrganizm(Organizm organizm, int polozenieX, int polozenieY) {
        if (organizm == null) return;

        if (organizm instanceof Czlowiek) czlowiekZyje = true;
        organizm.setCzyZyje(true);
        organizmy.get(polozenieY).set(polozenieX, organizm);
        dodajOrganizmDoPosortowanych(organizm);
    }


    public void dodajOrganizmDoPosortowanych(Organizm organizm) {
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
        //jakas graficzna zmiana
        System.out.println(wiadomosc);
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

        int i = 0;
        for (Organizm o : posortowaneOrganizmy) {
            if (o instanceof Czlowiek) return o;
            i++;
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


    public void zapiszGre() {
        StringBuilder wartosci = new StringBuilder();
        wartosci.append(wymiarMapyX).append(" ").append(wymiarMapyY).append("\n");
        for (Organizm o : posortowaneOrganizmy) {
            wartosci.append(o.getNazwa()).append(" ");
            wartosci.append(o.getSymbol()).append(" ");
            wartosci.append(o.getSila()).append(" ");
            wartosci.append(o.getInicjatywa()).append(" ");
            wartosci.append(o.getPolozenieX()).append(" ");
            wartosci.append(o.getPolozenieY()).append(" ");
            wartosci.append(o.getWiek()).append(" ");
            wartosci.append(o.czyNiesmiertelny()).append(" ");

            if (o instanceof Czlowiek) {
                wartosci.append(((Czlowiek) o).getLicznikTur()).append(" ");
                wartosci.append(((Czlowiek) o).getCzyMoznaAktywowacNiesmiertelnosc()).append(" ");
            }

            wartosci.append("\n");
        }

        try {
            zapiszDoPliku(wartosci);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }


    public void zapiszDoPliku(StringBuilder wartosci) throws IOException {
        String[] elementy = wartosci.toString().split("\n");
        File plik = new File(plikZapisu);
        if (!plik.exists()) plik.createNewFile();
        try (BufferedWriter zapis = new BufferedWriter(new FileWriter(plikZapisu))) {

            for (String element : elementy) {
                zapis.write(element);
                zapis.write("\n");
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    public void zaladujGre() {
        File plik = new File(plikZapisu);
        if (!plik.exists()) return;
        try (BufferedReader zapis = new BufferedReader(new FileReader(plikZapisu))) {
            wyzerujOrganizmy();
            String linia = zapis.readLine();
            String[] elementy = linia.split(" ");
            setWymiarMapyX(Integer.parseInt(elementy[0]));
            setWymiarMapyY(Integer.parseInt(elementy[1]));
            uaktualnijGraniceMapy();

            while ((linia = zapis.readLine()) != null) {
                elementy = linia.split(" ");
                //System.out.println(linia);
                dodajOrganizmyKonkretnie(elementy);
            }

            wyswietlanie.repaint();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }


    private void dodajOrganizmyKonkretnie(String[] elementy) {
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
                //((Czlowiek) nowy).setLicznikTur(Integer.parseInt(elementy[8]));
                //((Czlowiek) nowy).setCzyMoznaAktywowacNiesmiertelnosc((Objects.equals(elementy[9], "true")));
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


    private void wyzerujOrganizmy() {
        for (int y = 0; y < wymiarMapyY; y++) {
            for (int x = 0; x < wymiarMapyX; x++) {
                organizmy.get(y).set(x, null);
            }
        }
    }
}
