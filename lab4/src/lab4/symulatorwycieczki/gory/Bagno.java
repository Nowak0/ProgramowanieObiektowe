package lab4.symulatorwycieczki.gory;

import lab4.symulatorwycieczki.Wedrowka;

/**
 *
 * @author TB
 */
public class Bagno extends Wedrowka{

    public Bagno(double odleglosc) {
        super(odleglosc);
    }

    @Override
    public double modyfikujPredkoscGrupy(double predkosc) {
        return predkosc;
    }

    @Override
    public int getTrudnoscNawigacyjna() {
        return 4;
    }

    @Override
    public String getNazwa() {
        return "Bagno";
    }

}
