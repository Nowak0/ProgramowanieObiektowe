package lab4;

import lab4.symulatorwycieczki.*;
import lab4.symulatorwycieczki.gory.Droga;
import lab4.symulatorwycieczki.gory.Las;
import lab4.symulatorwycieczki.gory.PrzeprawaPrzezRzeke;
import lab4.symulatorwycieczki.gory.beskidy.DrewnianaCerkiew;
import lab4.symulatorwycieczki.gory.beskidy.Stadion;
import lab4.symulatorwycieczki.ludzie.*;

import java.util.HashSet;
import java.util.Set;

/**
 *
 * @author TB
 */
public class JavaLab2 {
    public static void main(String[] args) {
        Wycieczka w = doFiladelfii();
        
        PrzewodnikStudencki przewodnik = new PrzewodnikStudencki("Stefan", "Długonogi", Czlowiek.Plec.MEZCZYZNA);
        Set<Uczestnik> uczestnicy = new HashSet<>();
        uczestnicy.add(new Student("Alojzy", "Mechanik", Czlowiek.Plec.MEZCZYZNA));
        uczestnicy.add(new Przedszkolak("Ada", "Lovelace", Czlowiek.Plec.KOBIETA));
        uczestnicy.add(new Noworodek("Jan", "Elektronik", Czlowiek.Plec.MEZCZYZNA));
        uczestnicy.add(new StudentKSG("Piotr","Teledetekcyjny", Czlowiek.Plec.MEZCZYZNA));
        uczestnicy.add(new Sportowiec("Jakub","Pilkarzyk", Czlowiek.Plec.MEZCZYZNA));
        uczestnicy.add(new Emeryt("Kazimierz","Kowalski", Czlowiek.Plec.MEZCZYZNA));

        Grupa g = new Grupa(przewodnik, uczestnicy);
        
        SymulatorWycieczki symulator = new SymulatorWycieczki(g, w);
        symulator.dodajSluchacza(symulator.klasaWewnetrzna());
        symulator.symuluj();
    }
    
    public static Wycieczka doDydiowki() {
        Wycieczka ret = new Wycieczka("Do Dydiówki");
        ret.dodajElementWycieczki(new Droga(1.0));
        ret.dodajElementWycieczki(new DrewnianaCerkiew("Smolnik"));
        ret.dodajElementWycieczki(new Droga(4.0));
//        ret.dodajElementWycieczki(new PrzeprawaPrzezRzeke(1.0));
//        ret.dodajElementWycieczki(new GestyLas(2.0));
        ret.dodajElementWycieczki(new Las(2.0));
        ret.dodajElementWycieczki(new Droga(5.0));
        
        return ret;
    }

    public static Wycieczka doFiladelfii() {
        Wycieczka ret = new Wycieczka("Do Filadelfii");
        ret.dodajElementWycieczki(new Las(3.0));
        ret.dodajElementWycieczki(new PrzeprawaPrzezRzeke(2.0));
        ret.dodajElementWycieczki(new DrewnianaCerkiew("Delaware"));
        ret.dodajElementWycieczki(new Droga(4.0));
        ret.dodajElementWycieczki(new PrzeprawaPrzezRzeke(1.0));
//        ret.dodajElementWycieczki(new GestyLas(2.0));
        ret.dodajElementWycieczki(new Las(2.0));
        ret.dodajElementWycieczki(new Droga(6.0));
        ret.dodajElementWycieczki(new Stadion("Wells Fargo Center"));

        return ret;
    }
   
}
