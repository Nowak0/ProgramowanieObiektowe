package lab4.symulatorwycieczki;

public abstract class Atrakcja implements ElementWycieczki {
    private double czasZwiedzaniaAtrakcji;
    private String miejscowosc;

    public Atrakcja(double value, String miejscowosc) {
        this.czasZwiedzaniaAtrakcji = value;
        this.miejscowosc = miejscowosc;
    }
    public double getCzasZwiedzania() {
        return czasZwiedzaniaAtrakcji;
    }

    public String getMiejscowosc() {
        return miejscowosc;
    }
}
