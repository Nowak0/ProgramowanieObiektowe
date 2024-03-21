package lab4.symulatorwycieczki.gory.beskidy;

import lab4.symulatorwycieczki.Atrakcja;

public class Stadion extends Atrakcja {
    public Stadion(String miejscowosc) {
        super(3, miejscowosc);
    }

    @Override
    public String getNazwa() {
        return "Stadion";
    }


}
