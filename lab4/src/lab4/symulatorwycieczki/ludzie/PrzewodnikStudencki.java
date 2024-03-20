package lab4.symulatorwycieczki.ludzie;

import lab4.symulatorwycieczki.Atrakcja;
import lab4.symulatorwycieczki.Wycieczka;
import lab4.symulatorwycieczki.gory.beskidy.DrewnianaCerkiew;
import lab4.symulatorwycieczki.gory.beskidy.Stadion;


/**
 *
 * @author TB
 */
public class PrzewodnikStudencki extends Student {

    public PrzewodnikStudencki(String imie, String nazwisko, Plec plec) {
        super(imie, nazwisko, plec, 5.0);
    }

    @Override
    public void opiszWycieczke(Wycieczka wycieczka) {
        mow("Szanowna grupo, proszę o uwagę. Teraz opowiem Wam o wycieczce.");
        super.opiszWycieczke(wycieczka);
    }

    @Override
    public int getUmiejetnosciNawigacyjne() {
        return 4;
    }

    @Override
    public void reagujNaAtrakcje(Atrakcja a, double czas) {
        if(a instanceof DrewnianaCerkiew cerkiewka) {
            mow("To jest drewniana cerkiew w miejcowości " + cerkiewka.getMiejscowosc() + ". Wiele taki można spotkać w Beskidach. Po mojej lewej widać wieżę o kontrukcji słupowo ramowej ...");
            regeneruj(czas);
        }
        else if(a instanceof Stadion stadion) {
            mow("To jest stadion druzyny z " + stadion.getMiejscowosc() + ". Co kilka dni zbiera się tutaj ogromna liczba fanów ...");
            regeneruj(czas);
        }
//        else if(a instanceof CmentarzZIWojny) {
//            CmentarzZIWojny cmentarz = (CmentarzZIWojny) a;
//            mow("Tutaj widzimy cmentarz z I Wojny Światowej w miejcowości "+cmentarz.getMiejscowosc()+". Takie cmentarze projektował m.in. Dušan Jurkovič.");
//            regeneruj(czas);
//        }
        else {
            super.reagujNaAtrakcje(a, czas);
        }
    }
    
    
    
}
