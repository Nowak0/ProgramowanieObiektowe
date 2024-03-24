package lab4.symulatorwycieczki.gory.beskidy;

import lab4.symulatorwycieczki.Atrakcja;

/**
 *
 * @author TB
 */
public class Panorama extends Atrakcja {
    public Panorama(String miejscowosc) {
        super(1, miejscowosc);
    }

    @Override
    public String getNazwa() {
        return "Panorama";
    }


}
