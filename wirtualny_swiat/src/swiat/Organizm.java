package swiat;

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

    public abstract void akcja(Swiat swiat);
    public abstract void kolizja(Swiat swiat, Organizm atakujacy);
    public abstract char rysowanie();
    public abstract Organizm stworzNowySklonowanyObiekt();
    public abstract void kopiujObiekt(final Organizm innyOrganizm);
    public abstract boolean czyOdbilAtak(Organizm atakujacy, Organizm atakowany);
    //public abstract void setRuchCzlowieka(final int ruch);
    //public abstract boolean aktywujNiesmiertelnoscCzlowieka();
    public abstract void sprawdzLiczenieTur();

    String getNazwa() {
        return nazwa;
    }

    char getSymbol() {
        return symbol;
    }

    int getSila() {
        return sila;
    }

    int getInicjatywa() {
        return inicjatywa;
    }

    int getWiek() {
        return wiek;
    }

    int getPolozenieX() {
        return polozenieX;
    }

    int getPolozenieY() {
        return polozenieY;
    }

    boolean czyNiesmiertelny() {
        return aktywnaNiesmiertelnosc;
    }

    boolean getCzyZyje() {
        return czyZyje;
    }

    void setNazwa(String nazwa) {
        this.nazwa = nazwa;
    }

    void setSymbol(char symbol) {
        this.symbol = symbol;
    }

    void setSila(int sila) {
        this.sila = sila;
    }

    void setInicjatywa(int inicjatywa) {
        this.inicjatywa = inicjatywa;
    }

    void setWiek(int wiek) {
        this.wiek = wiek;
    }

    void setCzyZyje(boolean wyrazenie) {
        this.czyZyje = wyrazenie;
    }

    void setPolozenieX(int polozenieX) {
        this.polozenieX = polozenieX;
    }

    void setPolozenieY(int polozenieY) {
        this.polozenieY = polozenieY;
    }

    void setNiesmiertelnosc(boolean wyrazenie) {
        this.aktywnaNiesmiertelnosc = wyrazenie;
    }




}
