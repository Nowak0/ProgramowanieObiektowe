package lab4.symulatorwycieczki.ludzie;

import lab4.symulatorwycieczki.Atrakcja;
import lab4.symulatorwycieczki.Wedrowka;

/**
 *
 * @author TB
 */
public class StudentKSG extends Student{

    public StudentKSG(String imie, String nazwisko, Plec plec) {
        super(imie, nazwisko, plec);
    }

    @Override
    public void reagujNaWedrowke(Wedrowka w, double czas) {
//        if(w instanceof PrzeprawaPrzezRzeke){
//            mow("Uuu! Przeprawa przez rzekę. Gdybym tylko miał podręczną sondę hydrologiczną, to mógłbym pomierzyć EC i pH do pracy magisterskiej.");
//            aktualizujZmeczenie(czas);
//        }
//        else
            super.reagujNaWedrowke(w, czas);
    }

    @Override
    public void reagujNaAtrakcje(Atrakcja a, double czas) {
//        if(w instanceof PrzeprawaPrzezRzeke){
//            mow("Uuu! Przeprawa przez rzekę. Gdybym tylko miał podręczną sondę hydrologiczną, to mógłbym pomierzyć EC i pH do pracy magisterskiej.");
//            aktualizujZmeczenie(czas);
//        }
//        else
        super.reagujNaAtrakcje(a, czas);
    }
    
    
}
