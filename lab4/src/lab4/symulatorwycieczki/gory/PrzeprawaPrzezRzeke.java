package lab4.symulatorwycieczki.gory;

import lab4.symulatorwycieczki.Wedrowka;

/**
 *
 * @author TB
 */
public class PrzeprawaPrzezRzeke extends Wedrowka{

    public PrzeprawaPrzezRzeke(double odleglosc) {
        super(odleglosc);
    }

    @Override
    public double modyfikujPredkoscGrupy(double predkosc) {
        //Brak modyfikacji
        return predkosc;
    }

    @Override
    public int getTrudnoscNawigacyjna() {
        return 1;
    }

    @Override
    public String getNazwa() {
        return "Przeprawa Przez Rzeke";
    }

}