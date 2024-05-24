package swiat;
import java.awt.Color;

public abstract class Organizm {
    private String nazwa;
    private char symbol;
    private int sila;
    private int inicjatywa;
    private int wiek;
    private int polozenieX;
    private int polozenieY;
    private boolean aktywnaNiesmiertelnosc;
    private boolean czyZyje;
    public final int RUCH_NIEAKTYWNY = -1;
    public final int RUCH_PRAWO = 1;
    public final int RUCH_LEWO = 2;
    public final int RUCH_GORA = 3;
    public final int RUCH_DOL = 4;
    public abstract void akcja(Swiat swiat);
    public abstract void kolizja(Swiat swiat, Organizm atakujacy);
    public abstract Color rysowanie();
    public abstract Organizm stworzNowySklonowanyObiekt();


    public void kopiujObiekt(final Organizm innyOrganizm) {
        this.nazwa = innyOrganizm.getNazwa();
        this.symbol = innyOrganizm.getSymbol();
        this.sila = innyOrganizm.getSila();
        this.inicjatywa = innyOrganizm.getInicjatywa();
        this.wiek = innyOrganizm.getWiek();
        this.polozenieX = innyOrganizm.getPolozenieX();
        this.polozenieY = innyOrganizm.getPolozenieY();
    }


    public boolean czyOdbilAtak(Organizm atakujacy, Organizm atakowany) {
        int silaAtakowanego = atakowany.getSila();
        int silaAtakujacego = atakujacy.getSila();

        return silaAtakujacego < silaAtakowanego;
    }


    public String getNazwa() {
        return nazwa;
    }


    public char getSymbol() {
        return symbol;
    }


    public int getSila() {
        return sila;
    }


    public int getInicjatywa() {
        return inicjatywa;
    }


    public int getWiek() {
        return wiek;
    }


    public  int getPolozenieX() {
        return polozenieX;
    }


    public  int getPolozenieY() {
        return polozenieY;
    }


    public boolean czyNiesmiertelny() {
        return aktywnaNiesmiertelnosc;
    }


    public boolean getCzyZyje() {
        return czyZyje;
    }


    public void setNazwa(String nazwa) {
        this.nazwa = nazwa;
    }


    public void setSymbol(char symbol) {
        this.symbol = symbol;
    }


    public void setSila(int sila) {
        this.sila = sila;
    }


    public void setInicjatywa(int inicjatywa) {
        this.inicjatywa = inicjatywa;
    }


    public  void setWiek(int wiek) {
        this.wiek = wiek;
    }


    public void setCzyZyje(boolean wyrazenie) {
        this.czyZyje = wyrazenie;
    }


    public void setPolozenieX(int polozenieX) {
        this.polozenieX = polozenieX;
    }


    public void setPolozenieY(int polozenieY) {
        this.polozenieY = polozenieY;
    }


    public void setNiesmiertelnosc(boolean wyrazenie) {
        this.aktywnaNiesmiertelnosc = wyrazenie;
    }


    public static String wypiszPolozenie(final int polozenieX, final int polozenieY) {
        return " ("+polozenieX+","+polozenieY+")";
    }
}
