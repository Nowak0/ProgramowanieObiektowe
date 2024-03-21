package lab4.symulatorwycieczki.gory.beskidy;

import lab4.symulatorwycieczki.Atrakcja;

public class DrewnianaCerkiew extends Atrakcja {
    public DrewnianaCerkiew(String miejscowosc) {
        super(1, miejscowosc);
    }

    @Override
    public String getNazwa() {
        return "Drewniana Cerkiew";
    }


}
